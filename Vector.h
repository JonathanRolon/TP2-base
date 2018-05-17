/*
 * Vector.h
 *
 *  Created on: 27 abr. 2018
 *      Author: jonathan
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>

#include "Util.h"


typedef unsigned ui;

template < typename TipoDeDato >

class Vector{

	private:

		ui tamanio;

		TipoDeDato *datos;

	public:

		//Declaraciones;

		/*constructor c/ parametros
		*pre: tamanio>0
		*post: crea un vector con tamanio = tam e inicializa en 0
		*/
		Vector (ui tam);

		/*constructor s/ parametros
		*post:inicializa en 0 los atributos
		*/

		Vector();


		/*constructor de copia
		 *copia de un objeto a otro
		 */
		Vector(const Vector &Vec);

		/*pre:T es T valido y 0<=pos<obtenerTamanio()
		 *post:asigna el T en el vector en la posicion pos
		*/
		void asignarValor(TipoDeDato *dato,ui pos);

		/*pre:0<=pos<obtenerTamanio()
		 *post:devuelve el T de la posicion pos
		 */
		TipoDeDato * obtenerDato(ui pos);

		/*pre:
		 *post:devuelve el tamanio
		 */
		ui obtenerTamanio();

		/*pre:tam >0
		 *post:si tam > tamanio se pasan los Ts del vector y se completa con 0
		 */
		void asignarTamanio(ui tam);

		/*
		 *libera recursos
		 */
		~Vector();

	private:

		/*
		 *inicializa el vector Ts en NULL
		 */
		void inicializar();

		/*pre:aux es puntero a un vector nuevo, tam>0
		 *pre:inicializa aux en NULL
		 */
		void inicializar(TipoDeDato* vec,ui tam);

		/*pre:vec es un puntero a vector nuevo , tam>0
		 *post:copia Ts a vec
		 */
		void copiar(TipoDeDato * vec,ui tam);


/*	Definiciones...
 *
 * Vector.cpp
 *
 */
};

template< typename TipoDeDato >
Vector<TipoDeDato>::Vector(){

	this->tamanio=VACIO;
	datos=NULL;

}

template< typename TipoDeDato >
Vector<TipoDeDato>::Vector(ui tam){
		tamanio=tam;
		datos =new TipoDeDato[tam];
		inicializar();
}

template< typename TipoDeDato >
Vector<TipoDeDato>::Vector(const Vector &vec){
	this->tamanio=vec.tamanio;
	if(tamanio>0){
		this->datos=new TipoDeDato[tamanio];
		this->copiar(vec.datos,vec.tamanio);
	}else{
		this->datos=NULL;
	}
}

template< typename TipoDeDato >
void Vector<TipoDeDato>::asignarValor(TipoDeDato* dato,ui pos){
		datos[pos]=*dato;
}

template< typename TipoDeDato >
TipoDeDato* Vector<TipoDeDato>::obtenerDato(ui pos){
		return &datos[pos];
}

template< typename TipoDeDato >
void Vector<TipoDeDato>::asignarTamanio(ui tam){
	TipoDeDato * vec =new TipoDeDato[tam];
	inicializar(vec,tam);
	if(tamanio>0){
		copiar(vec,tam);
		delete [] datos;
	}
	datos=vec;
	tamanio=tam;
}

template< typename TipoDeDato >
ui Vector<TipoDeDato>::obtenerTamanio(){
	return tamanio;
}

template< typename TipoDeDato >
void Vector<TipoDeDato>::inicializar(){
	for(ui i=0;i<tamanio;i++){
		datos[i]=TipoDeDato();
	}
}

template< typename TipoDeDato >
void Vector<TipoDeDato>::inicializar(TipoDeDato* aux,ui tam){
	for(ui i=0;i<tam;i++){
		aux[i]=TipoDeDato();
	}
}

template< typename TipoDeDato >
void Vector<TipoDeDato>::copiar(TipoDeDato * vec,ui tam){
	ui menor=tam;
	if(tamanio<tam){
		menor=tamanio;
	}
	for(ui i=0; i<menor;i++){
		vec[i]=this->datos[i];
	}
}


template< typename TipoDeDato >
Vector<TipoDeDato>::~Vector(){
	delete [] datos;
}

#endif
