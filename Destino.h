/*
 * Destino.h
 *
 *  Created on: 6 may. 2018
 *      Author: jonathan
 */

#ifndef DESTINO_H_
#define DESTINO_H_
typedef unsigned ui;
#include "Util.h"
#include  <string>
#include <cstdlib>

class Destino{

	private:

		std::string destino;
		ui distanciaEnKMDesdeGranja;
		ui costoDeEnvio;
		char cultivoAEnviar;

	public:

		//pre:
		//post:inicializa las variables en 'VACIO';
		Destino();

		//pre:el nombre del destino sin acentos ni 'ñ' y en mayuscula
		//post:asigna el nombre al destino actual
		void asignarNombreDestino(std::string nombreDelDestino);

		//pre:
		//post:Devuelve nombre del destino
		std::string obtenerNombreDestino();

		//pre:
		//post:Devuelve el costo de enviar el cultivo
		ui obtenerCostoDeEnvio();

		//pre:costoEnvio>'VACIO'
		//post:asigna el costo de enviar el cultivo
		void asignarCostoDeEnvio(ui costoEnvio);

		//pre:la distancia>'VACIO'
		//post:asigna la distancia en km (al destino) desde la granja
		void asignarDistanciaDesdeGranja(ui distancia);

		//pre:
		//post:Devuelve la distancia en km desde la granja hasta el destino actual
		ui obtenerDistanciaHastaGranja();

		//pre:el cultivo es un nombre de cultivo valido
		//post:asigna el nombre al destino actual
		void asignarCultivoAEnviar(char cultivo);

		//pre:
		//post:Devuelve el nombre del cultivo a enviar
		char obtenerCultivoAEnviar();

};


#endif /* DESTINO_H_ */
