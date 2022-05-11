/*
 * tipo.c
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tipo.h"
#include <string.h>

int listarTipos(eTipo* tipos, int tam)
{
	int todoOk=0;

	if(tipos!=NULL && tam>0)
	{
		printf("        ****Lista de Tipos ***\n");
		printf("-------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf("%4d      %20s\n", tipos[i].id, tipos[i].descripcion);
		}
		todoOk=1;
		printf("\n\n");
	}

	return todoOk;
}

int buscarTipo(eTipo* tipos, int tam, int id, int* pIndice)
{
	int todoOk=0;

	if(tipos!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice=-1;

		for(int i=0; i<tam; i++)
		{
			if(tipos[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int validarTipo(eTipo* tipos, int tam, int id)
{
	int esValido=0;
	int indice;

	buscarTipo(tipos, tam, id, &indice);//ya valido parametros en esa funcion
	if(indice!=-1)	// si es >=0 significa que encontro un id valiido y me devuelve el  indice
	{
		esValido=1;
	}

	return esValido;
}

int cargarDescripcionTipo(eTipo* tipos, int tam, int id, char* descripcion)
{
	int todoOk=0;
	int indice;

	if(tipos!=NULL && tam>0 && descripcion!=NULL && validarTipo(tipos, tam, id))
	{
		if(buscarTipo(tipos, tam, id, &indice) && indice!=-1)
		{
			strcpy(descripcion, tipos[indice].descripcion);
		}
		todoOk=1;
	}
	return todoOk;
}
