/*
 * inicializar.h
 *
 *  Created on: 10 may. 2018
 *      Author: jonathan
 */

#ifndef INICIALIZAR_H_
#define INICIALIZAR_H_

typedef unsigned ui;

#include "Util.h"
#include "Vector.h"
#include "Cultivo.h"
#include "Destino.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>



/*Pre:cantidadL>0
* Post:inicializa la variable de cantidad de jugadores
*/
ui asignarCantidadJugadores();

/*Pre:turnos>0
* Post:inicializa la variable de cantidad de turnos
*/
ui asignarCantidadDeTurnosTotal();

/*Pre:archivo es la ruta del archivo en la carpeta donde reside el codigo
* Post:Si no cargo muestra un mensaje de error y sale de ejecucion
*/
void errorDeCarga(std::string archivo);

/*Pre: la cadena esta vacia, aux esta cargado con una linea del archivo destinos, pos==0.
* Post:Modifica el tamanio del nuevo string, concatena caracteres  desde aux a la cadena solo si
*      no son ni ','  ni ' '
*/
void asignarCadena(std::string &cadena,std::string aux,ui &pos);

/*Pre:entrada es la ruta del archivo en la carpeta del codigo, el vector de cultivos inicializado en NULL
* Post: El vector queda inicializado.
*/
void inicializarCultivos(std::string entrada,Vector <Cultivo> *cultivos);

/*Pre:rutaArchivo es la ruta del archivo en la carpeta del codigo, el vector de destinos inicializado en NULL
* Post: el vector de destinos queda inicializado
*/
void inicializarDestinos(std::string rutaArchivo,Vector <Destino> * vectorDestinos);


#endif /* INICIALIZAR_H_ */
