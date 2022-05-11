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

int inicializarViajes(eViaje* viajes, int tam);
int buscarViajeLibre(eViaje* viajes, int tam, int* pIndice);
int agregarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos,int tamD, int id, int idMicro,int idDestino, int dia, int mes, int anio);
//int cargarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD, int* pIndex);
int cargarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD,  eTipo* tipos, int tamT, eEmpresa* empresas, int tamE,int* pIndex);
int mostrarViaje(eViaje unViaje, eMicro* micros, int tamM, eDestino* destinos, int tamD);
int mostrarViajes(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD);
