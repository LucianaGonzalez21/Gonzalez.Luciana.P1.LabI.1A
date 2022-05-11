/*
 * empresa.c
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "tipo.h"
#include "empresa.h"
#include <string.h>

int listarEmpresas(eEmpresa* empresas, int tam)
{
	int todoOk=0;

	if(empresas!=NULL && tam>0)
	{
		printf("        ****Lista de Empresas ***\n");
		printf("-------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf("%5d      %20s\n", empresas[i].id, empresas[i].descripcion);
		}
		todoOk=1;
		printf("\n\n");
	}

	return todoOk;
}

int buscarEmpresa(eEmpresa* empresas, int tam, int id, int* pIndice)
{
	int todoOk=0;

	if(empresas!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice=-1;

		for(int i=0; i<tam; i++)
		{
			if(empresas[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int validarEmpresa(eEmpresa* empresas, int tam, int id)
{
	int esValido=0;
	int indice;

	buscarEmpresa(empresas, tam, id, &indice);
	if(indice!=-1)	// si es >=0 significa que encontro un id valiido y me devuelve el  indice
	{
		esValido=1;
	}

	return esValido;
}

int cargarDescripcionEmpresa(eEmpresa* empresas, int tam, int id, char* descripcion)
{
	int todoOk=0;
	int indice;

	if(empresas!=NULL && tam>0 && descripcion!=NULL && validarEmpresa(empresas, tam, id))
	{
		if(buscarEmpresa(empresas, tam, id, &indice) && indice!=-1)
		{
			strcpy(descripcion, empresas[indice].descripcion);
		}
		todoOk=1;
	}
	return todoOk;
}
