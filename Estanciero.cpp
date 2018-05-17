#include "Estanciero.h"

#include <cstdlib>
#include <ctime>

#include "Parcela.h"
#include "Util.h"
#include <iostream>
#include "InOutEstanciero.h"

using namespace std;

Estanciero::Estanciero(){
	nroEstanciero=VACIO;
	terrenos=new Lista <Terreno*>;
	IVATerreno=VACIO;
	srand(time(NULL));
	tanqueAgua=TANQUE_CAPACIDAD_MAXIMA;
	credito=CREDITO_INICIAL;
	turnosTotalesGranjero=VACIO;
	turnosTranscurridos=VACIO;
	this->cultivosLeidos=NULL;
	this->destinosLeidos=NULL;
	estado=NO_COMENZADO;
}

void Estanciero::asignarNumeroEstanciero(ui numeroEstanciero){
	nroEstanciero=numeroEstanciero;
}

ui Estanciero::obtenerNumeroEstanciero(){
	return nroEstanciero;
}

void Estanciero::modificarEstado(Estado estadoDelJuego){
	this->estado=estadoDelJuego;
}

Estado Estanciero::obtenerEstado(){
	return estado;
}

void Estanciero::asignarCultivos(Vector <Cultivo>* cultivos){
	this->cultivosLeidos=cultivos;
}

void Estanciero::asignarDestinos(Vector <Destino>* destinos){
	this->destinosLeidos=destinos;
}

void Estanciero::asignarTotalDeTurnos(ui turnosTotales){
	this->turnosTotalesGranjero=turnosTotales;
}

ui Estanciero::obtenerTurnosTranscurridos(){
	return this->turnosTranscurridos;
}

void Estanciero::agregarTerreno(ui N,ui M){
	Terreno * terreno=new Terreno;
	terreno->asignarMedidas(N,M);
	terreno->inicializarParcelas();
	terrenos->agregar(terreno,1);
}

void Estanciero::pedirTerrenoInicial(){

	ui N=VACIO,M=VACIO;
	mostrarPedirTerrenoInicial(N,M);
	agregarTerreno(N,M);
}


ui Estanciero::elegirTerreno(Terreno * terrenoActual,bool mostrarValorTerreno){

	ui opcion;
	cout<<terrenos->obtenerCursor()->toString()<<endl;
	if(mostrarValorTerreno){
		cout<<"Valor $: "<<terrenos->obtenerCursor()->obtenerPrecioVenta()<<std::endl;
	}
    cout<<"1.Si" << std::endl << "2.No" << std::endl << std::endl;
	Util::pedirEntero(opcion,-1);

	return opcion;
}

ui Estanciero::seleccionarTerreno(bool & vender, bool mostrarValorTerreno){

	ui opcion =VACIO;
	ui posicion=VACIO;
	terrenos->iniciarCursor();
	mostrarSeleccionarTerreno();
	while(terrenos->avanzarCursor() && !vender){

		opcion = elegirTerreno(terrenos->obtenerCursor(),mostrarValorTerreno);

		switch(opcion){

			case 1: vender=true;
					posicion++;

					break;

			case 2: posicion++;
					break;

			default:mostrarPosicionInvalida();
		}
	}
	return posicion;
}

void Estanciero::sembrar(){

	mostrarCredito(credito);

	Cultivo * cultivoElegido=elegirCultivo();

	if(credito<=cultivoElegido->obtenerCostoSemilla()){
		mostrarCreditoInsuficiente();

	}else{

		ui posX=VACIO,posY=VACIO;
		ui posicion=designarPosicion();

		mostrarPreguntarLugarDeSiembra(cultivoElegido);
		elegirParcela(posX,posY,posicion);

		if((terrenos->obtener(posicion)->obtenerParcela(posX,posY))->esSembrable()){
			terrenos->obtener(posicion)->obtenerParcela(posX,posY)->sembrarCultivo(cultivoElegido);
			credito-=cultivoElegido->obtenerCostoSemilla();
			mostrarSiembraCorrecta(cultivoElegido,posX,posY);
		}
	}
}

ui Estanciero::designarPosicion(){
	ui posicion=VACIO;
	bool vender=false,mostrarValorTerreno=false;
	if(terrenos->contarElementos()>1){
		posicion=seleccionarTerreno(vender,mostrarValorTerreno);
	}else{
		posicion=1;
		imprimirTerreno(terrenos,1);
	}
	return posicion;
}

Cultivo * Estanciero::elegirCultivo(){

	Cultivo * result=NULL;
	ui opcion;
	bool eligioCorrectamente=false;
	while(!eligioCorrectamente){
		mostrarCultivosDisponibles(cultivosLeidos);
		Util::pedirEntero(opcion,-1);

		if(opcionCultivoExistente(opcion)){
			result=cultivosLeidos->obtenerDato(opcion-1);
			eligioCorrectamente=true;
		}else{
			mostrarPosicionInvalida();
		}
	}
	return result;
}


void Estanciero::regar(){
	if(tanqueAgua<=0){
		mostrarSinUnidadesDeRiego();

	}else{
		ui posX,posY;
		ui posicion=designarPosicion();
		mostrarPreguntarParcelaDeRiego();
		elegirParcela(posX,posY,posicion);
		if((terrenos->obtener(posicion)->obtenerParcela(posX,posY))->esRegable()){
			terrenos->obtener(posicion)->obtenerParcela(posX,posY)->regar();
			mostrarExitoDeRiego(posX,posY);
			tanqueAgua--;
		}
	}
}

void Estanciero::cosechar(){
	ui posX,posY;

	ui posicion=designarPosicion();

	mostrarPreguntarPosicionDeCosechado();

	elegirParcela(posX,posY,posicion);

	Cultivo * cultivoCosechado =(terrenos->obtener(posicion)->obtenerParcela(posX,posY))->
			cosechar();

	if(cultivoCosechado!=NULL){

		mostrarExitoCosechado(cultivoCosechado);

		credito+=cultivoCosechado->obtenerRentabilidad();
	}
}

void Estanciero::comprarUnTerreno(){

	bool compro=false;

	ui filas=VACIO,columnas=VACIO;

	ui precioTerreno=VACIO;

	if(credito>0 && precioTerreno<credito){

		while(!compro){

			mostrarCredito(credito);

			pedirDimensionesNuevo(filas,columnas);

			precioTerreno=(filas*columnas)+IVATerreno;

			if(precioTerreno<=credito){

				//crea el terreno y lo guarda
				agregarTerreno(filas,columnas);
				compro=true;
				credito-=precioTerreno;

				//aumenta el precio para el siguiente terreno
				IVATerreno+=5;
				mostrarExitoCompraTerreno();

			}else{
				mostrarCreditoInsuficiente();
				compro=true;
			}
		}
	}else{
		mostrarCreditoInsuficiente();
	}
}

void Estanciero::venderUnTerreno(){

	ui posicion=VACIO;

	bool vender=false, mostrarValorTerreno=true;

	if(terrenos->contarElementos()>1){

			posicion = seleccionarTerreno(vender,mostrarValorTerreno);

			if(vender){

				credito+=terrenos->obtener(posicion)->obtenerPrecioVenta();
			    //borra el terreno
			    delete terrenos->obtener(posicion);
			    //reenlaza la lista
			    terrenos->remover(posicion);

			    mostrarExitoVentaTerreno();
			}else{
				mostrarNoVentaTerreno();
			}
	}else{

		mostrarImposibilidadVentaPorUnicoTerreno();
	}
}

void Estanciero::pasarTurno(){

	turnosTranscurridos++;

	if(estaActivo()){
		terrenos->iniciarCursor();
		while(terrenos->avanzarCursor()){
			terrenos->obtenerCursor()->pasarTurno();
		}
	}else{
		imprimirResultadoFinal(this->credito);
		modificarEstado(FINALIZADO);
	}
}

void Estanciero::mostrarEstadoEstanciero(){
	mostrarTurnosTranscurridos(turnosTranscurridos,turnosTotalesGranjero);
	mostrarCredito(credito);
	calcularMultiplicadorAgua();
}

bool Estanciero::opcionCultivoExistente(ui opcion){
	return (opcion>0 && opcion<=cultivosLeidos->obtenerTamanio());
}

bool Estanciero::estaActivo(){
	return turnosTranscurridos<=turnosTotalesGranjero;
}

void Estanciero::elegirParcela(ui &posX,ui &posY,ui posicion){
	bool eleccionValida=false;
	while(!eleccionValida){

		mostrarIngresarPosicionParcela(posX,posY);

		if(terrenos->obtener(posicion)->dentroDelRango(posX-1,posY-1)){
			posX--;
			posY--;
			eleccionValida=true;
		}else{
			mostrarPosicionInvalida();
		}
	}
}


void Estanciero::calcularMultiplicadorAgua(){
	int multiplicador=(rand()%6)+1;
	int aguaObtenida= multiplicador * UNIDADES_RIEGO_POR_TURNO;
	tanqueAgua+=aguaObtenida;
	if(tanqueAgua>TANQUE_CAPACIDAD_MAXIMA){
		tanqueAgua=TANQUE_CAPACIDAD_MAXIMA;
	}
	mostrarEstadoTiradaDado(multiplicador,aguaObtenida,tanqueAgua);
}

Estanciero::~Estanciero(){

	terrenos->iniciarCursor();
	while(terrenos->avanzarCursor()){
		delete terrenos->obtenerCursor();
	}
	delete terrenos;
}
