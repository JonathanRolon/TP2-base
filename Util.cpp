#include "Util.h"

#include <iostream>

#include <limits>


void Util::pedirEntero(ui &destino,ui valorDefault){

	std::cin>>destino;

	if(std::cin.fail()){

		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

		destino=valorDefault;

	}

}

