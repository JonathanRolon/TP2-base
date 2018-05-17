/*
 * cultivoObj.cpp
 *
 *  Created on: 24 abr. 2018
 *      Author: jonathan
 */

#include "Cultivo.h"

#include <cstdlib>
#include <iostream>

Cultivo::Cultivo(){

	nombreCultivo='~';

	costoSemilla=VACIO;

    tiempoCrecimiento=VACIO;

    rentabilidad=VACIO;

    tiempoRecuperacion=VACIO;

	consumoDeAgua=VACIO;

}

void Cultivo::asignarNombreCultivo(char nombreAsignarACultivo){
	this->nombreCultivo=nombreAsignarACultivo;
}

char Cultivo::obtenerNombreCultivo(){
	return this->nombreCultivo;
}

usi Cultivo::obtenerCostoSemilla(){
	return this->costoSemilla;
}

void Cultivo::asignarCostoSemilla(usi costoAsignado){
	this->costoSemilla=costoAsignado;
}

usi Cultivo::obtenerTiempoRecuperacion(){
	return tiempoRecuperacion;
}

void Cultivo::asignarTiempoRecuperacion(usi tiempoAsignado){
	this->tiempoRecuperacion=tiempoAsignado;
}

void Cultivo::asignarRentabilidad(usi ganancia){
	this->rentabilidad=ganancia;
}

usi Cultivo::obtenerRentabilidad(){
	return this->rentabilidad;
}

void Cultivo::asignarTiempoCrecimiento(usi tiempoCrecimientoAsignado){
	this->tiempoCrecimiento=tiempoCrecimientoAsignado;
}

usi Cultivo::obtenerTiempoCrecimiento(){
	return this->tiempoCrecimiento;
}

usi Cultivo::obtenerConsumoDeAgua(){
	return this->consumoDeAgua;
}

void Cultivo::asignarConsumoDeAgua(usi consumoDeAguaAsignado){
	this->consumoDeAgua=consumoDeAguaAsignado;
}

