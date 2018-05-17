#include "Parcela.h"

#include <cctype>
#include <iostream>

#include "Util.h"



using namespace std;

Parcela::Parcela(){

	danio=0;

	edad=0;

	cultivoActual=NULL;

	estaHidratada=false;

	coordenadaX=0;

	coordenadaY=0;

}


string Parcela::toString(){

	string valor=" ";

	if(!estaVacia() && danio==0){

		valor+=tolower((*cultivoActual).obtenerNombreCultivo());

		if(cultivoActual->obtenerTiempoCrecimiento()==edad){

			valor=toupper((*cultivoActual).obtenerNombreCultivo());
		}
		else
			if(estaHidratada){

				valor+='!';
			}
			else{
				valor+=' ';
			}

	}else if(danio>0){

		valor=" ~ ";

	}

	return valor;

}



bool Parcela::estaVacia(){

	return cultivoActual==NULL;

}


bool Parcela::esCosechable(){
	bool cosechable=false;
	if(estaVacia()){
		cout<<"No se puede cosechar una parcela vacia"<<endl;
	}else
		if(cultivoActual->obtenerTiempoCrecimiento()!=edad && !estaVacia()){
		cout << "No se puede cosechar la parcela porque el cultivo"
			 << (*cultivoActual).obtenerNombreCultivo()
			 << " aun no ha alcanzado su maximo nivel de crecimiento"<<endl;
		}else{
			cosechable=true;
		}
	return cosechable;
}

bool Parcela::esSembrable(){
	bool sembrable=false;
	if(!estaVacia() && danio==VACIO){

			cout<<"La parcela se encuentra ocupada"<<endl;

		}else
			if(danio>VACIO && estaVacia()){

			cout<<"La parcela se encuentra en proceso de recuperacion"<<endl;

			}else
				if(estaVacia() && danio==VACIO){
					sembrable=true;
				}
	return sembrable;
}

bool Parcela::esRegable(){

	bool regable=false;

	if(estaVacia()){

			cout<<"No se puede regar una parcela vacia"<<endl;

		}else
			if(cultivoActual->obtenerTiempoCrecimiento()==edad){

				cout << "No se puede regar la parcela porque el cultivo"
					 << (*cultivoActual).obtenerNombreCultivo()
					 << " ya se encuentra en su maximo nivel de crecimiento"
					 << endl;

		}else
			if(estaHidratada){

				cout<<"La parcela ya se encuentra hidratada"<<endl;

		}else{
			regable=true;
		}
	return regable;
}

void Parcela::sembrarCultivo( Cultivo* cultivo){

		cultivoActual=cultivo;
}


void Parcela::regar(){

		estaHidratada=true;

}


Cultivo * Parcela::cosechar(){

	Cultivo * cultivoCosechado=NULL;

	if(esCosechable()){
		cultivoCosechado=retirarCultivo();
	}

	return cultivoCosechado;

}

void Parcela::pasarTurno(){

	if(!estaVacia()){

		if(estaHidratada){

			edad++;

			estaHidratada=false;

		}else{

			retirarCultivo();

		}

	}else
		if(danio>0){

		danio--;

		}

}


Cultivo * Parcela::retirarCultivo(){

	Cultivo * cultivoRetirado=cultivoActual;

	danio=cultivoActual->obtenerTiempoRecuperacion();

	if(edad<cultivoActual->obtenerTiempoCrecimiento())

		danio/=2;

	cultivoActual=NULL;

	return cultivoRetirado;

}

