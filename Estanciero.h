#include "Cultivo.h"
#include "Destino.h"
#include "Lista.h"
#include "Terreno.h"
#include "Vector.h"

#ifndef ESTANCIERO_H_
#define ESTANCIERO_H_

enum Estado{

	NO_COMENZADO,
	JUGANDO,
	FINALIZADO

};

class Estanciero{

	private:

		//indica si el juego comenzo para el granjero actual
		Estado estado;

		/*Configuracion del juego*/
		Lista <Terreno*> *terrenos;
		ui nroEstanciero;
		ui IVATerreno;
		ui credito;
		int tanqueAgua;
		ui turnosTotalesGranjero;
		Vector <Cultivo>* cultivosLeidos;
		Vector <Destino>* destinosLeidos;
		ui turnosTranscurridos;

		/*Pre: ~
		 * Post:Devuelve un puntero al cultivo elegido*/
		Cultivo * elegirCultivo();

		/*Pre: 0<posicion<terrenos(posicion)->contarElementos()
		 * Post:Pide al usuario y valida un par de coordenadas del terreno
		  	    Guarda la informacion solicitada en un par de variables enteras recibidas por referencia*/
		void elegirParcela(ui & fila,ui & columna,ui posicion);

		/*Pre:~
		 * Post:calculacuanta agua se le asigna al jugador por su nuevo turno
		 * Muestra el resultado de tirar el dado */
		void calcularMultiplicadorAgua();

		/*Pre:~
		 * Post:Devuelve si el cultivo elegido existe en el vector de cultivos leido desde el archivo
		 */
		bool opcionCultivoExistente(ui opcion);

		/*Pre:~
		 * Post:Devuelve la posicion del terreno en la lista.
		 */
		ui designarPosicion();

		/*Pre:N>0, M>0
		 * Post:agrega el terreno a la lista
		 */
		void agregarTerreno(ui N,ui M);

		/*Pre:pide las condiciones iniciales del juego
		 * Post:inicializa segun lo indicado por consola
		 */
		ui seleccionarTerreno(bool & vender,bool mostrarValorTerreno);

	public:
			/*Pre:~
			 * Post:Devuelve la cantidad de turnos transcurridos
			 */
			ui obtenerTurnosTranscurridos();

			/*Pre:~
			 * Post:Muestra el estado del juego para el granjero actual
			 */
			void mostrarEstadoEstanciero();

			/*Pre:~
			 *Post:Devuelve la posicion del granjero en la lista de granjeros
			 */
			ui obtenerNumeroEstanciero();

			/*Pre:0<numeroEstanciero='nroEstanciero anterior'+1
			 * Post:el 'nroEstanciero' queda asignado.
			 */
			void asignarNumeroEstanciero(ui numeroEstanciero);

			/*Pre:'terrenoActual'!=NULL, mostrarValorTerreno es true o false;
			 * Post:Muestra el terrenoActual,
			 * 		si 'mostrarValorTerreno' muestra el valor actual de venta del terreno
			 * 		Ademas pregunta si quiere elegir ese terreno y devuelve el 1 o 0
			 */
			ui elegirTerreno(Terreno * terrenoActual,bool mostrarValorTerreno);

			/*Pre:~
			 * Post:Inicializa los atributos del granjero, estado del juego del granjero, turnos y punteros a
			 *		vector de cultivos y destinos.
			 */
			Estanciero();

			/*Pre:estadoDelJuego es NO_COMENZADO, JUGANDO o FINALIZADO
			 *Post:inicializa el estado.
			 */
			void modificarEstado(Estado estadoDelJuego);

			/*Pre:estado previamente inicializado.
			 *Post:Devuelve el estado del juego para el granjero actual.
			 */
			Estado obtenerEstado();

			/*Pre:~
			 *Post:pide las dimensiones que tendra el terreno nro. primero. Ademas
			 	   lo guarda en la lista.
			 */
			void pedirTerrenoInicial();

			/*Pre: cultivos es un puntero a un vector de tipo Cultivo* que ademas se ha inicializado previamente
			 *Post: Se copia esa direccion a un Vector del granjero
			 */
			void asignarCultivos(Vector <Cultivo>* cultivos);

			/*Pre:destinos es un puntero a un vector de tipo Destino* que ademas se ha inicializado previamente
			 *Post: Se copia esa direccion a un Vector del granjero
			 */
			void asignarDestinos(Vector <Destino>* destinos);

			/*Pre:turnosTotales>0
			 *Post:Se copian los turnos asignados a la variable de turnos del granjero
			 */
			void asignarTotalDeTurnos(ui turnosTotales);

			/*Pre:
			 *Post:Guia al usuario para sembrar un cultivo en una parcela
			 */
			void sembrar();

			/*Pre:~
			 *Post:guia al usuario para regar una parcela
			 */
			void regar();

			/*Pre:~
			 *Post:guia al usuario para cosechar una parcela
		     */
			void cosechar();

			/*Pre:~
		     *Post:guia al usuario para comprar un terreno
		     */
			void comprarUnTerreno();

			/*Pre:
			 *Post:guia al usuario para vender un terreno
			 */
			void venderUnTerreno();

			/*Pre:
			 *Post:reside la logica para transcurrir un turno en la partida actual
			 */
			void pasarTurno();

			/*Pre:~
			 * Post:devuelve si aun quedan turnos disponibles por jugar
			 */
		    bool estaActivo();

		    /*Pre:~
		     *Post:libera la memoria dinamica pedida.
		     */
			~Estanciero();

};

#endif
