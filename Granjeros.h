/*
 * Juego.h
 *
 *  Created on: 10 may. 2018
 *      Author: jonathan
 */

#ifndef GRANJEROS_H_
#define GRANJEROS_H_

#include "Cultivo.h"
#include "Destino.h"
#include "Estanciero.h"
#include "Lista.h"

class Granjeros{

	private:

		 ui turnoTranscurrido, cantidadDeGranjeros,
		    cantidadDeTurnosTotal;
		 Vector <Cultivo> *cultivosLeidos;
		 Vector <Destino> *destinosLeidos;
		 Lista <Estanciero*> *jugadores;
		 ui ganadorDelJuego;
		 ui perdedorDelJuego;
		 ui opcionesDelJuego();

	public:

		 /*Pre:~
		 * Post:los atributos queda inicializados, ademas los vectores cultivosLeidos y destinosLeidos tienen
		 *      asignada una direccion de memoria dinamica. La lista de jugadores esta creada.
		 */
		 Granjeros();

		 /*Pre: una instancia ha sido creada
		  * Post: Posee las funciones generales del juego. Guia al usuario a traves del menu de opciones
		  */
		 void desarrolloDelJuego();

		 /*Pre:~
		  * Post:Agrega los granjeros a la lista de granjeros
		  */
		 void asignarGranjeros();

		 /*Pre:~
		 * Post:la cantidad de granjeros ha sido asignada.
		 */
		 void asignarCantidadGranjeros();

		 /*Pre:~
		 * Post:la cantidad de turnos totales ha sido asignada.
		 */
		 void asignarTurnosTotales();

		 /*Pre:~
	     * Post: libera los recursos pedidos.
		 */
		 ~Granjeros();

};

#endif /* GRANJEROS_H_ */
