/*
 * InOutEstanciero.cpp
 *
 *  Created on: 10 may. 2018
 *      Author: jonathan
 */
#include "InOutEstanciero.h"

#include <iostream>

void mostrarIngresarJugadores(){

	std::cout<<"Comience ingresando las condiciones de juego"<<std::endl;

	std::cout<<"Ingrese la cantidad de jugadores"<<std::endl;

}

void mostrarIngresarTurnos(){

	std::cout<<"Ingrese la cantidad de turnos del juego"<<std::endl;

}

void mostrarPosicionInvalida(){
	std::cout<<"Posicion invalida";
}

void mostrarNoVentaTerreno(){
	std::cout<<"No se vendio algun terreno."<<std::endl;
}

void mostrarExitoCosechado(Cultivo * cultivoCosechado){
	std::cout<<"Ha conseguido "<<cultivoCosechado->obtenerRentabilidad()
		<<" creditos por el cultivo "<<cultivoCosechado->obtenerNombreCultivo()<<std::endl;
}

void mostrarPreguntarPosicionDeCosechado(){
	std::cout<<"Que parcela desea cosechar?"<<std::endl;
}

void mostrarSinUnidadesDeRiego(){
	std::cout<<"No dispone de unidades de riego para utilizar"<<std::endl;
}

void mostrarPreguntarParcelaDeRiego(){
	std::cout<<"Que parcela desea regar?"<<std::endl;
}

void mostrarExitoDeRiego(ui posX,ui posY){
	std::cout<<"La parcela ("<<posX+1<<","<<posY+1<<") " "fue regada con exito"<<std::endl;
}

void mostrarCultivosDisponibles(Vector <Cultivo> * cultivosLeidos){

	std::cout<<"Cultivos disponibles:"<<std::endl;

	for(ui i=0;i<cultivosLeidos->obtenerTamanio();i++){

		std::cout<<(i+1)<<". "<<cultivosLeidos->obtenerDato(i)->obtenerNombreCultivo()<<std::endl;
	}

	std::cout<<"Ingrese el numero del cultivo deseado: "<<std::endl;
}

void mostrarSeleccionarTerreno(){
	std::cout<<"Seleccione el terreno."<<std::endl;
}

void mostrarTurnosTranscurridos(ui transcurridos,ui totales){
	std::cout<<"Turno "<<transcurridos<<" de "<<totales<<std::endl;
}

void mostrarPedirTerrenoInicial(ui &N, ui &M){

	std::cout<<"Ingrese las medidas del terreno inicial:"<<std::endl;

	pedirDimensionesNuevo(N,M);

}

void mostrarCredito(ui credito){

	std::cout<<"Credito actual: "<<credito<<std::endl;

}


void pedirDimensionesNuevo(ui &filas,ui &columnas){
	std::cout<<"Ingrese la cantidad de filas que tendra su terreno"<<std::endl;

	Util::pedirEntero(filas,1);

	std::cout<<"Ingrese la cantidad de columnas que tendra su terreno"<<std::endl;

	Util::pedirEntero(columnas,1);
}


void mostrarImposibilidadVentaPorUnicoTerreno(){
	std::cout<<"Usted tiene un solo terreno, compre otro para vender el actual."<<std::endl;
}

void imprimirTerreno(Lista <Terreno*>*terrenos, ui posicion){
	std::cout<<terrenos->obtener(posicion)->toString();
}

void mostrarIngresarPosicionParcela(ui &posX, ui &posY){

	std::cout<<"Ingrese la coordenada X de la parcela: ";
	Util::pedirEntero(posX,-1);
	std::cout<<"Ingrese la coordenada Y de la parcela: ";
	Util::pedirEntero(posY,-1);
}

void mostrarOpcionIncorrecta(){
	std::cout<<"No se ingreso una opcion correcta"<<std::endl;
}

void mostrarCreditoInsuficiente(){
	std::cout<<"No dispone del credito suficiente para comprar esto."<<std::endl;
}

void mostrarEstadoTiradaDado(ui multiplicador,ui aguaObtenida,ui tanqueAgua){
	std::cout<<"Su multiplicador de agua es "<<multiplicador<<std::endl;
	std::cout<<"Ha conseguido "<<aguaObtenida<<" unidades de riego"<<std::endl;
	std::cout<<"Su tanque de agua tiene "<<tanqueAgua<<" de "<<TANQUE_CAPACIDAD_MAXIMA
			 <<" unidades de riegos disponibles"<<std::endl;
}

void mostrarExitoVentaTerreno(){
	std::cout<<"El terreno ha sido vendido."<<std::endl;
}

void mostrarSiembraCorrecta(Cultivo *cultivoElegido, ui posX, ui posY){
	std::cout<<"El "<<cultivoElegido->obtenerNombreCultivo()
			 <<" fue sembrado correctamente en la parcela ("<<posX+1<<","<<posY+1<<")"
			 <<std::endl;
}

void mostrarPreguntarLugarDeSiembra(Cultivo * cultivoElegido){
	std::cout<<"Donde quiere sembrar el cultivo: "<<cultivoElegido->obtenerNombreCultivo()
			 <<"?"<<std::endl;
}

void mostrarExitoCompraTerreno(){
	std::cout<<"Muy bien!! el terreno se agrego a terrenos actuales"<<std::endl<<std::endl;
}

void imprimirResultadoFinal(ui credito){

	std::cout<<"Fin del juego"<<std::endl;
	std::cout<<"Su credito final es de "<<credito<<". Felicitaciones!"<<std::endl;
	std::cout<<"Gracias por jugar"<<std::endl;

}

int mostrarElegirTerreno(Lista <Terreno*> *terrenos){
	ui opcion;
	std::cout<<terrenos->obtenerCursor()->toString()<<std::endl
		     <<"1.Si" << std::endl << "2.No" << std::endl << std::endl;
	Util::pedirEntero(opcion,-1);
	return opcion;
}


