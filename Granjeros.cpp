/*
 * Juego.cpp
 *
 *  Created on: 10 may. 2018
 *      Author: jonathan
 */

#include "Granjeros.h"

#include <iostream>

#include "Inicializar.h"

#include "Util.h"

Granjeros::Granjeros() {

	this->turnoTranscurrido = VACIO;

	asignarCantidadGranjeros();

	asignarTurnosTotales();

	this->cultivosLeidos = new Vector<Cultivo>;

	this->destinosLeidos = new Vector<Destino>;

	inicializarCultivos("cultivos.dat", cultivosLeidos);

	inicializarDestinos("destinos.dat", destinosLeidos);

	asignarGranjeros();

	ganadorDelJuego=VACIO;

	perdedorDelJuego=VACIO;

}

void Granjeros::asignarCantidadGranjeros() {

	this->cantidadDeGranjeros = asignarCantidadJugadores();
}

void Granjeros::asignarTurnosTotales() {

	this->cantidadDeTurnosTotal = asignarCantidadDeTurnosTotal();
}

void Granjeros::asignarGranjeros() {

	this->jugadores = new Lista<Estanciero*>;

	Estanciero * granjero=NULL;

	for (ui i = 1; i <= cantidadDeGranjeros; i++) {

			granjero=new Estanciero;

			granjero->asignarNumeroEstanciero(i);

			granjero->asignarCultivos(cultivosLeidos);

			granjero->asignarDestinos(destinosLeidos);

			granjero->asignarTotalDeTurnos(cantidadDeTurnosTotal);

			jugadores->agregar(granjero,i);

			granjero=NULL;
	}
}

ui Granjeros::opcionesDelJuego() {

	ui opcion;

	std::cout << std::endl;

	std::cout << "1. Sembrar semillas en una parcela" << std::endl;

	std::cout << "2. Regar una parcela" << std::endl;

	std::cout << "3. Cosechar una parcela" << std::endl;

	std::cout << "4. Comprar terreno" << std::endl;

	std::cout << "5. Vender terreno" << std::endl;

	std::cout << "6. Pasar al siguente turno" << std::endl;

	std::cout << "Ingrese el numero de la accion que desea realizar: ";

	std::cout << std::endl;

	Util::pedirEntero(opcion, -1);

	return opcion;
}

void Granjeros::desarrolloDelJuego() {

	bool pasoElTurno;

	while(turnoTranscurrido<cantidadDeTurnosTotal){

		jugadores->iniciarCursor();

		while(jugadores->avanzarCursor()) {

			std::cout<<std::endl
			         << "GRANJERO: " << jugadores->obtenerCursor()->obtenerNumeroEstanciero()
					 << std::endl    << std::endl;

			if (jugadores->obtenerCursor()->obtenerEstado() == NO_COMENZADO) {

				jugadores->obtenerCursor()->pedirTerrenoInicial();

				jugadores->obtenerCursor()->modificarEstado(JUGANDO);

				jugadores->obtenerCursor()->pasarTurno();
			}

			jugadores->obtenerCursor()->mostrarEstadoEstanciero();

			pasoElTurno = false;

			while (jugadores->obtenerCursor()->obtenerEstado() == JUGANDO && !pasoElTurno) {

				ui opcion = opcionesDelJuego();

				switch (opcion) {

				case 1:
					jugadores->obtenerCursor()->sembrar();
					break;

				case 2:
					jugadores->obtenerCursor()->regar();
					break;

				case 3:
					jugadores->obtenerCursor()->cosechar();
					break;

				case 4:
					jugadores->obtenerCursor()->comprarUnTerreno();
					break;

				case 5:
					jugadores->obtenerCursor()->venderUnTerreno();

					break;

				case 6:
					jugadores->obtenerCursor()->pasarTurno();

					pasoElTurno = true;

					break;

				default:
					std::cout << "Opcion no valida" << std::endl;

				}

			}

		}
		turnoTranscurrido++;
	}
}

//destructor
Granjeros::~Granjeros() {
	jugadores->iniciarCursor();
		while(jugadores->avanzarCursor()){
			delete jugadores->obtenerCursor();
		}
		delete jugadores;
	delete cultivosLeidos;
	delete destinosLeidos;

}
