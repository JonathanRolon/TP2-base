/*
 * cultivoObj.h
 *
 *  Created on: 23 abr. 2018
 *      Author: jonathan
 */

#ifndef CULTIVO_H_

#define CULTIVO_H_

#include "Util.h"

typedef unsigned short int usi;

class Cultivo{

	private:

		char nombreCultivo;

		usi costoSemilla;

		usi tiempoCrecimiento;

		usi rentabilidad;

		usi tiempoRecuperacion;

		usi consumoDeAgua;

	public:

		/*Pre:una vez creado el objeto
	      Post:inicializa las variables en cero.*/
		Cultivo();

		/*Pre:'nombreAsignarCultivo' es un caracter valido.
		  Post:asigna el nombre al cultivo*/
		void asignarNombreCultivo(char nombreAsignarACultivo);

		/*Pre:~
		  Post:Devuelve el nombre del cultivo */
		char obtenerNombreCultivo();

		/*Pre:~
		  Post:Devuelve el valor de compra de la semilla del cultivo*/
		usi obtenerCostoSemilla();

		/*Pre:'costoAsignado'>'VACIO'
		  Post:el 'costoAsignado' se asigna al cultivo */
		void asignarCostoSemilla(usi costoAsignado);

		/*Pre:~
		  Post:Devuelve el tiempo de Recuperacion del cultivo en
		       la parcela una vez cultivado, secado o podrido.*/
	    usi obtenerTiempoRecuperacion();

	    /*Pre:'tiempoAsignado'>='VACIO'.
	      Post:Se asigna el 'tiempoAsignado' al tiempoCrecimiento*/
	    void asignarTiempoRecuperacion(usi tiempoAsignado);

	    /*Pre:'rentabilidad'>'VACIO'
	      Post:asigna el monto a rentabilidad*/
	    void asignarRentabilidad(usi ganancia);

	    /*Pre:~
	      Post:Devuelve la rentabilidad del cultivo*/
	    usi obtenerRentabilidad();

	    /*Pre:el 'tiempoCrecimientoAsignado'>'VACIO'
	  	  Post:se asigna el 'tiempoCrecimientoAsignado' al cultivo*/
	  	void asignarTiempoCrecimiento(usi tiempoCrecimientoAsignado);

	    /*Pre:~
	  	  Post:Devuelve el tiempo de maduracion del cultivo*/
	  	usi obtenerTiempoCrecimiento();

	    /*Pre:~
	      Post:Devuelve el consumo de unidades de riego (del cultivo) por parcela*/
	    usi obtenerConsumoDeAgua();

	    /*Pre:el 'consumoDeAguaAsignado'>'VACIO'
	      Post:asigna 'consumoDeAguaAsignado' al 'consumoDeAgua' del cultivo*/
	    void asignarConsumoDeAgua(usi consumoDeAguaAsignado);

};

#endif /* CULTIVO_H_ */
