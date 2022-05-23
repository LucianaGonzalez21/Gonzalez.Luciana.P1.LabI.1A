/*
 * destino.c
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "destino.h"
#include <string.h>

int listarDestinos(eDestino* destinos, int tam)
{
	int todoOk=0;

	if(destinos!=NULL && tam>0)
	{
		printf("   ****Lista de Destinos ***\n");
		printf("-------------------------------\n");
		printf("Id         Destino     Precio\n");
		printf("------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf("%5d   %10s    $%.2f\n", destinos[i].id, destinos[i].descripcion,  destinos[i].precio);
		}
		todoOk=1;
		printf("\n\n");
	}

	return todoOk;
}

int buscarDestino(eDestino* destinos, int tam, int id, int* pIndice)
{
	int todoOk=0;

	if(destinos!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice=-1;

		for(int i=0; i<tam; i++)
		{
			if(destinos[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int validarDestino(eDestino* destinos, int tam, int id)
{
	int esValido=0;
	int indice;

	buscarDestino(destinos, tam, id, &indice);
	if(indice!=-1)
	{
		esValido=1;
	}

	return esValido;
}

int cargarDescripcionDestino(eDestino* destinos, int tam, int id, char* descripcion)
{
	int todoOk=0;
	int indice;

	if(destinos!=NULL && tam>0 && descripcion!=NULL && validarDestino(destinos, tam, id))
	{
		if(buscarDestino(destinos, tam, id, &indice) && indice!=-1)
		{
			strcpy(descripcion, destinos[indice].descripcion);
		}
		todoOk=1;
	}
	return todoOk;
}
