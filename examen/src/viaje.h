/*
 * viaje.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include "fecha.h"

#ifndef VIAJE_H_
#define VIAJE_H_

typedef struct{
	int id;
	int idMicro;
	int idDestino;
	eFecha fecha;
	int isEmpty;
}eViaje;

#endif /* VIAJE_H_ */

/// @brief Pone todas las banderas isEmpty en 1 indicando que las posiciones en el vector Viajes estan libres
///
/// @param viajes Es el vector de viajes
/// @param tam Tamanio del vector viajes
/// @return Devuelve 0 si hay error de parametros, 1 si no
int inicializarViajes(eViaje* viajes, int tam);


/// @brief Busca en el vector de viajes un lugar libre, donde isEmpty valga 1
///
/// @param viajes Es el vector de viajes
/// @param tam Es el tamanio del vector viajes
/// @param pIndice Es el puntero al espacio de memoria donde se alojara la posicion libre o bien -1 si no encontro lugar
/// @return Retorna 0 si hay algun error de parametros, 1 si estan bien
int buscarViajeLibre(eViaje* viajes, int tam, int* pIndice);


/// @brief Agrega en una lista de viajes, los valores recibidos por parametro
///
/// @param viajes Es el vector de viajes
/// @param tamV Es el tamanio del vector de viajes
/// @param micros Es el vector de micros
/// @param tamM Es el tamanio del vector de micros
/// @param destinos Es el vector de destinos
/// @param tamD Es el tamanio del vector de destinos
/// @param id
/// @param idMicro
/// @param idDestino
/// @param dia
/// @param mes
/// @param anio
/// @return Devuelve -1 si hay error de parametros y 0 si pudo agregar el viaje al vector
int agregarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos,int tamD, int id, int idMicro,int idDestino, int dia, int mes, int anio);


/// @brief Pide al usuario y carga todos los campos del tipo eViaje, excepto por el campo id que es autoincremental
///
/// @param viajes
/// @param tamV
/// @param micros
/// @param tamM
/// @param destinos
/// @param tamD
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @param pIndex Es el puntero al espacio de memoria, que tiene guardado el valor del id, y al cual se le incrementa +1 cuando se ejecuta esta funcion
/// @return Retorna 0 si hubo error de parametros, 1 si pudo cargar los datos correctamente
int cargarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD,  eTipo* tipos, int tamT, eEmpresa* empresas, int tamE,int* pIndex);

/// @brief Muestra en pantalla todos los datos de un viaje
///
/// @param unViaje
/// @param micros
/// @param tamM
/// @param destinos
/// @param tamD
/// @return Retorna 0 si hubo error de parametros, 1 si lo pudo imprimir correctamente
int mostrarViaje(eViaje unViaje, eMicro* micros, int tamM, eDestino* destinos, int tamD);


/// @brief Imprime el contenido del vector viajes
///
/// @param viajes
/// @param tamV
/// @param micros
/// @param tamM
/// @param destinos
/// @param tamD
/// @return Devuelve -1 si hubo error de parametros,0 si no
int mostrarViajes(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD);


/// @brief Se le pide al usuario el id de un micro y se muestran los viajes que el mismo realizo
///
/// @param viajes
/// @param tamV
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @param tipos
/// @param tamT
/// @param destinos
/// @param tamD
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int mostrarViajesSegunMicro(eViaje* viajes, int tamV, eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, eDestino* destinos, int tamD);


/// @brief Pide al usuario un micro y calcula e informa el precio total de los viajes que ese micro realizo
///
/// @param viajes
/// @param tamV
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @param tipos
/// @param tamT
/// @param destinos
/// @param tamD
/// @return
int informarPrecioTotalDeViajeSegunMicro(eViaje* viajes, int tamV, eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, eDestino* destinos, int tamD);



int hardcodearViajes(eViaje* viajes , int tam, int cant, int* pIndex);


/// @brief Pide al usuario el id de un destino e informa los viajes realizados a ese destino en su correspondiente fecha
///
/// @param viajes
/// @param tamV
/// @param micros
/// @param tamM
/// @param destinos
/// @param tamD
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Devuelve 0 si hubo erorr de parametros, 1 si no
int informarViajesADestino(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD, eTipo*  tipos, int tamT, eEmpresa* empresas, int tamE);


/// @brief Pide al usuario una fecha y muestra todos los viajes que se realizaron en la misma
///
/// @param viajes
/// @param tamV
/// @param micros
/// @param tamM
/// @param destinos
/// @param tamD
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int mostrarViajesSegunFecha(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD);
