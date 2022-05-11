/*
 * viaje.c
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "micro.h"
#include "destino.h"
#include "fecha.h"
#include "viaje.h"


int inicializarViajes(eViaje* viajes, int tam) {
	int todoOk = 0;

	if (viajes != NULL && tam > 0) {
		todoOk = 1;

		for(int i=0; i<tam; i++)
		{
			viajes[i].isEmpty = 1;
		}
	}

	return todoOk;
}

int buscarViajeLibre(eViaje* viajes, int tam, int* pIndice)
{
	int todoOk=0;

	if(viajes != NULL && tam>0 && pIndice!=NULL)
	{
		todoOk=1;
		*pIndice = -1;

		for(int i=0; i<tam; i++)
		{
			if(viajes[i].isEmpty)
			{
				*pIndice = i;
				break;
			}
		}
	}

	return todoOk;
}

int agregarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos,int tamD, int id, int idMicro,int idDestino, int dia, int mes, int anio)
{
	int todoOk=-1;
	int i;

	if(viajes!=NULL && tamV>0 && id>=500 && validarMicro(micros, tamM, idMicro) && validarDestino(destinos, tamD, idDestino))
	{
		if(buscarViajeLibre(viajes, tamV, &i) && i>=0)
		{
			viajes[i].id = id;
			viajes[i].idMicro = idMicro;
			viajes[i].idDestino = idDestino;
			viajes[i].fecha.dia = dia;
			viajes[i].fecha.mes = mes;
			viajes[i].fecha.anio = anio;
			viajes[i].isEmpty=0;
			todoOk=0;
		}
	}

	return todoOk;
}

int cargarViaje(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD,  eTipo* tipos, int tamT, eEmpresa* empresas, int tamE,int* pIndex)	//este pIndex es el que declaro en main
{
	int todoOk=0;
	eViaje nuevoViaje;
	int idM;
	int idD;
	int d;
	int m;
	int a;

	if(viajes!=NULL && tamV>0 && micros!=NULL &&  tamM>0 && destinos!=NULL && tamD>0 && pIndex!=NULL)
	{
		if(
			!mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE) &&
			!utn_getNumero(&idM, "Ingrese el id de un micro: ", "Error, no valido\n", 100, 10000, 3) &&
			validarMicro(micros, tamM, idM) &&
			listarDestinos(destinos, tamD) &&
			!utn_getNumero(&idD, "Ingrese el id del destino: ", "Error, no valido.\n", 20000, 20003, 3) &&
			!utn_getNumero(&d, "Fecha\nIngrese el dia: ", "Error", 1, 31, 3) &&
			!utn_getNumero(&m, "Fecha\nIngrese el mes: ", "Error", 1, 12, 3) &&
			!utn_getNumero(&a, "Fecha\nIngrese el anio: ", "Error", 0, 2023, 3))
		{

			nuevoViaje.idMicro = idM;
			nuevoViaje.idDestino = idD;
			nuevoViaje.fecha.dia = d;
			nuevoViaje.fecha.mes = m;
			nuevoViaje.fecha.anio = a;
			nuevoViaje.id = *pIndex;
			*pIndex = *pIndex + 1;
			agregarViaje(viajes, tamV, micros, tamM, destinos, tamD, nuevoViaje.id, nuevoViaje.idMicro, nuevoViaje.idDestino, nuevoViaje.fecha.dia, nuevoViaje.fecha.mes, nuevoViaje.fecha.anio);
			todoOk=1;
		}
	}

	return todoOk;
}

//-----------------
int mostrarViaje(eViaje unViaje, eMicro* micros, int tamM, eDestino* destinos, int tamD)
{
	int todoOk=0;
	char descripcionDestino[20];

	if(micros!=NULL && tamM>0 && destinos!=NULL && tamD>0)
	{
		if(!unViaje.isEmpty)
		{
			cargarDescripcionDestino(destinos, tamD, unViaje.idDestino,descripcionDestino);

			printf("%5d    %5d    %10s   %d/%d/%d\n",

					unViaje.id,
					unViaje.idMicro,
					descripcionDestino,
					unViaje.fecha.dia,
					unViaje.fecha.mes,
					unViaje.fecha.anio);
			todoOk=1;
		}
	}
	return todoOk;
}

int mostrarViajes(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD)
{
	int todoOk=-1;

	if(viajes!=NULL && tamV>0 && micros!=NULL && tamM>0 && destinos!=NULL && tamD>0)
	{
		todoOk=0;

		printf("      ***Lista de Viajes***\n");
		printf("Id        IdMicro          Destino        Fecha\n");
		printf("-----------------------------------------------\n");

		for(int i=0; i<tamV; i++)
		{
			if(!viajes[i].isEmpty)
			{
				mostrarViaje(viajes[i], micros, tamM, destinos, tamD);
			}
		}
		printf("\n\n");
	}

	return todoOk;
}
