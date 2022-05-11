/*
 * micro.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include "tipo.h"
#include "empresa.h"

#ifndef MICRO_H_
#define MICRO_H_

typedef struct{
	int id;
	int idEmpresa;
	int idTipo;
	int capacidad;
	int isEmpty;
}eMicro;

#endif /* MICRO_H_ */

int menuPrincipal(int *opcion);
int inicializarMicros(eMicro* micros, int tam);
int buscarPosicionLibre(eMicro* micros, int tam, int* pIndice);
int cargarMicro(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE, int* pIndex);
int agregarMicro(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, int id, int idEmpresa, int idTipo,int capacidad);
int mostrarMicro(eMicro unMicro, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);
int mostrarMicros(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);
int buscarMicroPorId(eMicro* micros, int tam,int id);
int menuModificarMicro(int* opcionModificar);
int modificarMicro(eMicro *micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);
int eliminarMicro(eMicro* micros, int tam, int id);
int darBajaMicro(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);
int buscarMicro(eMicro* micros, int tam, int id, int* pIndice);
int validarMicro(eMicro* micros, int tam, int id);
int ordenarMicros(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, int order);
