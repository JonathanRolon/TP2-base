#include "Terreno.h"

#include "Util.h"

using namespace std;
/*Parcela
 *
 */

Terreno::Terreno(){
	largoN=VACIO;
	anchoM=VACIO;
	precioActualVenta=VACIO;
	terreno=NULL;
}

void Terreno::inicializarParcelas(){
	terreno=new Parcela*[largoN];
	for(ui i=0;i<largoN;i++){
		terreno[i]=new Parcela [anchoM];
	}
	for(ui i=0;i<largoN;i++){
		for(ui j=0;j<anchoM;j++){
			terreno[i][j]=Parcela();
		}
	}
	precioActualVenta=(largoN*anchoM)/2;
}

ui Terreno::obtenerPrecioVenta(){
	return precioActualVenta;
}

ui Terreno::obtenerLargo(){
	return largoN;
}

ui Terreno::obtenerAncho(){
	return anchoM;
}

void Terreno::asignarMedidas(ui largo,ui ancho){
	this->largoN=largo;
	this->anchoM=ancho;
}

string Terreno::toString(){

	string result ="";

	for(ui i=0;i<largoN;i++){

		for(ui j=0;j<anchoM;j++){

			result+="===";

		}

		result+='\n';

		for(ui j=0;j<anchoM;j++){

			result+="|"+terreno[i][j].toString()+"|";

		}

		result+='\n';

	}

	for(ui j=0;j<anchoM;j++){

		result+= "===";

	}

	result+='\n';

	return result;

}


Parcela* Terreno::obtenerParcela(ui fila,ui columna){
	Parcela * parcelaActual=NULL;
	if(dentroDelRango(fila,columna))
		parcelaActual=&terreno[fila][columna];
	return parcelaActual;
}

bool Terreno::dentroDelRango(ui fila,ui columna){
	return (fila>=0 && fila<largoN && columna>=0 && columna<anchoM);
}

void Terreno::modificarTamanio(ui largo,ui ancho){
	largoN=largo;
	anchoM=ancho;
}

void Terreno::pasarTurno(){

	for(ui i=0;i<largoN;i++){

		for(ui j=0;j<anchoM;j++){

			terreno[i][j].pasarTurno();

		}

	}

}

Terreno::~Terreno(){
		for(ui i=0;i<largoN;i++){
				delete [] terreno[i];
		}
		delete [] terreno;
}

