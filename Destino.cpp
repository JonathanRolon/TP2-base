/*
 * Destino.cpp
 *
 *  Created on: 6 may. 2018
 *      Author: jonathan
 */
#include "Destino.h"

Destino::Destino(){
	destino="";
	distanciaEnKMDesdeGranja=VACIO;
	costoDeEnvio=VACIO;
	cultivoAEnviar=VACIO;
}

void Destino::asignarNombreDestino(std::string nombreDelDestino){
	this->destino=nombreDelDestino;
}

std::string Destino::obtenerNombreDestino(){
	return destino;
}

ui Destino::obtenerCostoDeEnvio(){
	return costoDeEnvio;
}

void Destino::asignarCostoDeEnvio(ui costoEnvio){
	this->costoDeEnvio=costoEnvio;
}

void Destino::asignarDistanciaDesdeGranja(ui distancia){
	this->distanciaEnKMDesdeGranja=distancia;
}

ui Destino::obtenerDistanciaHastaGranja(){
	return distanciaEnKMDesdeGranja;
}

void Destino::asignarCultivoAEnviar(char cultivo){
	this->cultivoAEnviar=cultivo;
}

char Destino::obtenerCultivoAEnviar(){
	return cultivoAEnviar;
}

