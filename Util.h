#ifndef UTIL_H_

#define UTIL_H_

const unsigned VACIO=0;

typedef unsigned ui;

namespace Util{

	/*Funcion que pide y valida un entero al usuario.

	 Recibe como parametros, una variable entera por referencia donde se alojara el resultado obtenido

	 y una variable entera como valor por defecto en caso de no poder validar la entrada del usuario*/

	void pedirEntero(ui &destino,ui valorDefault=-1);

}



#endif

