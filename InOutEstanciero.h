/*
 * InOutEstanciero.h
 *
 *  Created on: 10 may. 2018
 *      Author: jonathan
 */

#ifndef INOUTESTANCIERO_H_
#define INOUTESTANCIERO_H_

#include "Cultivo.h"
#include "Lista.h"
#include "Vector.h"
#include "Terreno.h"
#include "Util.h"

const int CREDITO_INICIAL=50;
const int TANQUE_CAPACIDAD_MAXIMA=25;
const int UNIDADES_RIEGO_POR_TURNO=5;

typedef unsigned ui;

/*Pre: 'transcurridos'>=1,'totales'>0
 * Post:imprime los turnos transcurridos por pantalla
 */
void mostrarTurnosTranscurridos(ui transcurridos,ui totales);

/*Pre:cultivoCosechado es un puntero al cultivo cosechado (que es distinto de NULL)
 * Post:imprime los creditos conseguidos por cosechar el cultivo
 */
void mostrarExitoCosechado(Cultivo * cultivoCosechado);

/*Pre:~
 * Post:Muestra la leyenda para que el usuario ingrese la cantidad de jugadores
 */
void mostrarIngresarJugadores();

/*Pre:~
 * Post:muestra el fracaso de vender algun terreno
 */
void mostrarNoVentaTerreno();

/*Pre:~
 * Post:Muestra la leyenda al usuario para que ingrese los turnos
 */
void mostrarIngresarTurnos();

/*Pre:~
 * Post:Muestra la leyenda de falta de agua para riego
 */
void mostrarSinUnidadesDeRiego();

/*Pre:~
 * Post:Muestra la leyenda inicial para elegir un terreno.
 */
void mostrarSeleccionarTerreno();

/*Pre:~
 * Post:Muestra la pregunta de que parcela se desea regar.
 */
void mostrarPreguntarParcelaDeRiego();

/*Pre:~
 * Post:Muestra la leyenda de opcion ingresada no valida.
 */
void mostrarOpcionIncorrecta();

/*Pre:~
 * Post:Muestra la leyenda de la incapacidad de comprar un terreno, semilla, etc.
 */
void mostrarCreditoInsuficiente();

/*Pre:~
 * Post:Pregunta la fila y columna. Guarda la filas y columna en las respectivas variables.
 */
void pedirDimensionesNuevo(ui &filas,ui &columnas);

/*Pre:'VACIO'<=posX<'largo del terreno actual', 'VACIO'<=posY<'ancho del terreno actual'
 * Post: Muestra la leyenda de parcela regada exitosamente.
 */
void mostrarExitoDeRiego(ui posX,ui posY);

/*Pre:'cultivosLeidos' fue inicializado desde el archivo
 * Post:Muestra los cultivos disponibles, ademas muestra la leyenda para ingresar el cultivo.
 */
void mostrarCultivosDisponibles(Vector <Cultivo> * cultivosLeidos);

/*Pre:N y M son las medidas del terreno y preferentemente inicializadas en 'VACIO'
 * Post:Se modifican las variables de acuerdo a las dimensiones ingresadas por pantalla
 */
void mostrarPedirTerrenoInicial(ui &N, ui &M);

/*Pre:~
 * Post:Muestra el exito de haber vendido un terreno.
 */
void mostrarExitoVentaTerreno();

/*Pre: 'cultivoElegido' apunta al cultivo elegido(que yace en el vector de cultivos),
 *     'VACIO'<=posX<'largo del terreno actual', 'VACIO'<=posY<'ancho del terreno actual'
 * Post: Leyenda de siembra exitosa.
 */
void mostrarSiembraCorrecta(Cultivo *cultivoElegido, ui posX, ui posY);

/*Pre: 'cultivoElegido' apunta al cultivo elegido(que yace en el vector de cultivos),
 * Post: Pregunta posicion de sembrado del '*cultivoElegido'
 */
void mostrarPreguntarLugarDeSiembra(Cultivo * cultivoElegido);

/*Pre:~
 * Post:Muestra leyenda de compra de terreno exitosa
 */
void mostrarExitoCompraTerreno();

/*Pre:Si las posiciones ingresadas son enteros validos
 * Post:Los almacena en posX, y posY respectivamente, de lo contrario almacena un '-1' por default.
 */
void mostrarIngresarPosicionParcela(ui &posX,ui &posY);

/*Pre:terrenos tiene al menos un terreno, 0<posicion<(terrenos->contarElementos())
 * Post:imprime el terreno de la lista en la posicion indicada
 */
void imprimirTerreno(Lista <Terreno*>*terrenos, ui posicion);

/*Pre:obtiene una copia del atributo credito
 * Post:lo muestra por pantalla
 */
void mostrarCredito(ui credito);

/*Pre:~
 * Post:Muestra la leyenda de posicion fuera de rango
 */
void mostrarPosicionInvalida();

/*Pre:~
 * Post: Pregunta la posicion de la parcela a cosechar.
 */
void mostrarPreguntarPosicionDeCosechado();

/*Pre:'VACIO'< multiplicador <= 6,'VACIO' < tanqueAgua <= TANQUE_CAPACIDAD_MAXIMA,
 *    'VACIO'< 'aguaObtenida' <multiplicador * UNIDADES_RIEGO_POR_TURNO
 * Post:Muestra con una leyenda las tres cantidades al usuario
 */
void mostrarEstadoTiradaDado(ui multiplicador,ui aguaObtenida,ui tanqueAgua);

/*Pre:la lista debe tener al menos un terreno
 * Post:Permite seleccionar el terreno y devolver la opcion de si elegi un terreno
 */
int mostrarElegirTerreno(Lista <Terreno*> *terrenos);

/*Pre:~
 * Post:muestra la imposibilidad de venta del unico terreno
 */
void mostrarImposibilidadVentaPorUnicoTerreno();

/*Pre:~
 * Post:imprime un resumen final con los datos de la partida
 */
void imprimirResultadoFinal(ui credito);

#endif /* INOUTESTANCIERO_H_ */
