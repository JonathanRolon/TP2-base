#include <string>
#include "Parcela.h"


#ifndef TERRENO_H_

#define TERRENO_H_

typedef unsigned ui;

class Terreno{

	private:

		ui largoN, anchoM;
		float precioActualVenta;
		Parcela **terreno;

	public:

		/*Pre:
		 * Post: los atributos quedan inicializados en 'VACIO'*/
		Terreno();

		/*Pre:
	     * Post: el terreno de parcelas se crea y queda inicializado con largo N y ancho M*/
		void inicializarParcelas();

		/*Pre: las cantidades pasadas son superiores a cero
		 * Post: los atributos de tamanio quedan inicializados*/
	    void modificarTamanio(ui largo, ui ancho);

		/*Pre:
		 *Post:Devuelve la ganancia en monedas que dara al vender el terreno
		 */
		ui obtenerPrecioVenta();

		/*Pre:largo>0 ancho>0
		 *Post:asigna el largo y el ancho a la instancia
		 */
		void asignarMedidas(ui largo,ui ancho);

		/*Pre:
		 *Post:Devuelve el largo N del terreno
		 */
		ui obtenerLargo();

		/*Pre:
		 *Post:Devuelve el ancho M del terreno
		 */
	    ui obtenerAncho();

		/* Pre:~
		 * Post:devuelve la representacion grafica del terreno*/
		std::string toString();

		/*Pre:Las coordenadas son mayores a cero.
		Post: Devuelve un puntero hacia la parcela si las coordenadas
		      estan entre los limites del terreno,*/

		Parcela* obtenerParcela(ui fila,ui columna);

		/*Post:Devuelve si la fila y columna estan dentro
		       de los limites del terreno*/
		bool dentroDelRango(ui fila,ui columna);

		/* Pre:~
		 * Post:recorre las parcelas e incrementa un turno a cada una*/

		void pasarTurno();

		/* Pre:~
		 * Post:libera memoria dinamica*/
		~Terreno();

};


#endif

