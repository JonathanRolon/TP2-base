/*
 * inicializar.cpp
 *
 *  Created on: 10 may. 2018
 *      Author: jonathan
 */

#include "Inicializar.h"

ui asignarCantidadJugadores(){
	ui ingreso=VACIO;
	std::cout<<"Ingrese la cantidad de Jugadores"<<std::endl;
	Util::pedirEntero(ingreso,1);
	return ingreso;
}

ui asignarCantidadDeTurnosTotal(){
	ui ingreso=VACIO;
	std::cout<<"Ingrese los turnos del juego"<<std::endl;
	Util::pedirEntero(ingreso,1);
	return ingreso;
}

void errorDeCarga(std::string archivo){

		std::cerr << "Error al intentar cargar "<<archivo;

		exit(1);
}

void asignarCadena(std::string &cadena,std::string aux,ui &pos){
	pos+=2;
	while(aux[pos]!=',' && aux[pos]!=' '){
		cadena+=aux[pos];
		pos++;
	}
}

void inicializarCultivos(std::string entrada,Vector <Cultivo> *vectorCultivos)
{
	std::ifstream archivoCultivos(entrada.c_str(), std::ios::in);

	char nombreCultivo,coma;
	usi costoSemilla=VACIO, tiempoCrecimiento=VACIO, rentabilidad=VACIO,
	    tiempoRecuperacion=VACIO, consumoDeAgua=VACIO;

	if (!archivoCultivos)
	{
		errorDeCarga(entrada);
	}
	Cultivo cultivoLeido;

	ui j=0;
	while(!archivoCultivos.eof())
	{

		archivoCultivos>>nombreCultivo>>coma>>costoSemilla>>coma>>tiempoCrecimiento
					   >>coma>>rentabilidad>>coma>>tiempoRecuperacion>>coma>>consumoDeAgua;
		if(!archivoCultivos.eof()){
			cultivoLeido.asignarNombreCultivo(nombreCultivo);
			cultivoLeido.asignarCostoSemilla(costoSemilla);
			cultivoLeido.asignarTiempoRecuperacion(tiempoRecuperacion);
			cultivoLeido.asignarRentabilidad(rentabilidad);
			cultivoLeido.asignarTiempoCrecimiento(tiempoCrecimiento);
			cultivoLeido.asignarConsumoDeAgua(consumoDeAgua);

			vectorCultivos->asignarTamanio(j+1);
			vectorCultivos->asignarValor(&cultivoLeido,j);
			j++;
		}

	}
}

void inicializarDestinos(std::string rutaArchivo,Vector <Destino> *vectorDestinos)
{
	std::ifstream archivoDestinos(rutaArchivo.c_str(), std::ios::in);
	std::string destino;
	char cultivoAEnviar;
	std::string costoEnvio;
	std::string distanciaEnKM;

	Destino destinoLeido;
	std::string aux;
	if (!archivoDestinos){

			errorDeCarga(rutaArchivo);
	}
	ui j=0,i;

	while(getline(archivoDestinos,aux) && !archivoDestinos.eof()){
		destino="",cultivoAEnviar='.',costoEnvio="",distanciaEnKM="";

		i=0;

		while(aux[i]!=','){

			destino+=aux[i];

			i++;
		}
		asignarCadena(distanciaEnKM,aux,i);
		asignarCadena(costoEnvio,aux,i);

		i+=2;
		cultivoAEnviar=aux[i];

		destinoLeido.asignarNombreDestino((std::string)destino);
		destinoLeido.asignarDistanciaDesdeGranja((ui)atoi(distanciaEnKM.c_str()));
		destinoLeido.asignarCostoDeEnvio((ui)atoi(costoEnvio.c_str()));
		destinoLeido.asignarCultivoAEnviar(cultivoAEnviar);

		vectorDestinos->asignarTamanio(j+1);
		vectorDestinos->asignarValor(&destinoLeido,j);
		j++;
	}
}


