#include <string>
#include "Cultivo.h"

#ifndef PARCELA_H_

#define PARCELA_H_

typedef unsigned ui;


class Parcela{

	private :
		/*Informacion de la parcela*/

		ui danio;

		int edad;

		bool estaHidratada;

		Cultivo * cultivoActual;

		ui coordenadaX,coordenadaY;

		Cultivo * retirarCultivo();

	public:

		/*Inicializa la parcela*/

		Parcela();


		/*Metodo que devuelve la representacion grafica de la parcela*/

		std::string toString();


		/*Post: devuelve si esta vacia*/

		bool estaVacia();


		/* pre:
		 * Post:devuelve si la parcela tiene un cultivo en edad cosechable*/

		bool esCosechable();

		/* pre:
		 * Post:devuelve si la parcela esta apta para siembra*/
		bool esSembrable();

		/* pre:
		 * Post:devuelve si la parcela esta apta para riego*/
		bool esRegable();

		/*Pre:Metodo que recibe un puntero hacia la informacion de un cultivo.

		 	  Hace los chequeos pertinentes para sembrarlo en la parcela

		 Post:Siembra el cultivo*/

		void sembrarCultivo( Cultivo*);


		/*Metodo que hace los controles pertinentes para regar una parcela

		 Post:: Riega la parcela*/

		void regar();


		/*Metodo que cosecha al cultivo actual, en caso de poderse

		 Post:Devuelve un puntero hacia la informacion del cultivo que se acaba de cosechar

		 Devuelve NULL en caso de no haber cosechado ningun cultivo*/

		Cultivo * cosechar();


		/*Metodo donde reside la logica necesaria para incrementar un turno*/

		void pasarTurno();


};


#endif

