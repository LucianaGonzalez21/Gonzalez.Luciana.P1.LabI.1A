/*
 * micro.c
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "micro.h"
#include "tipo.h"
#include "destino.h"
#include "empresa.h"
#include <string.h>


/// @brief Muestra el menu de opciones y pide al usuario que ingrese un numero
///
/// @param opcion Puntero al espacio de memoria donde se alojara la opcion que haya ingresado el usuario
/// @return Devuelve 0 si consiguio una opcion valida, -1 si no
int menuPrincipal(int *opcion) {

	int rta;

	if (opcion != NULL) {
		printf("1.ALTA micro\n");
		printf("2.MODIFICAR micro\n");
		printf("3.BAJA micro\n");
		printf("4.LISTAR micros\n");
		printf("5.LISTAR empresas\n");
		printf("6.LISTAR tipos\n");
		printf("7.LISTAR destinos\n");
		printf("8.ALTA viaje\n");
		printf("9.LISTAR viajes\n");
		printf("10.SALIR\n\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 10, 3);
	}

	return rta;

}


int inicializarMicros(eMicro* micros, int tam) {
	int todoOk = 0;

	if (micros != NULL && tam > 0) {
		todoOk = 1;

		for(int i=0; i<tam; i++)
		{
			micros[i].isEmpty = 1;
		}
	}

	return todoOk;
}

/// @brief Busca en el vector un lugar libre, y si lo encuentra devuelve por referencia la posicion o -1 si no lo encontro
///
/// @param  Es el vector de micros
/// @param Es el largo del vector
/// @param pIndice Puntero al espacio de memoria donde se alojara el indice o -1
/// @return Devuelve 0 si hay error de parametros, 1 si no
int buscarPosicionLibre(eMicro* micros, int tam, int* pIndice)
{
	int todoOk=0;

	if(micros != NULL && tam>0 && pIndice!=NULL)
	{
		todoOk=1;
		*pIndice = -1;

		for(int i=0; i<tam; i++)
		{
			if(micros[i].isEmpty)
			{
				*pIndice = i;
				break;
			}
		}
	}

	return todoOk;
}


int agregarMicro(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, int id, int idEmpresa, int idTipo,int capacidad)
{
	int todoOk=-1;
	int i;

	if(micros!=NULL && tamM>0 && empresas!=NULL && tamE>0 && tipos!=NULL && tamT>0 && validarEmpresa(empresas, tamE, idEmpresa) && validarTipo(tipos, tamT, idTipo) && capacidad>=1 && capacidad<=50)
	{
		if(buscarPosicionLibre(micros, tamM, &i) && i>=0)
		{
			micros[i].id = id;
			micros[i].idEmpresa = idEmpresa;
			micros[i].idTipo = idTipo;
			micros[i].capacidad = capacidad;
			micros[i].isEmpty = 0;
			todoOk=0;
		}

	}

	return todoOk;
}


int cargarMicro(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE, int* pIndex)
{
	int todoOk=0;
	eMicro nuevoMicro;

	if(micros!=NULL && tamM>0 && tipos!=NULL && tamT>0 && empresas!=NULL && tamE>0 && pIndex!=NULL)
	{
		if( listarEmpresas(empresas, tamE) &&
			!utn_getNumero(&nuevoMicro.idEmpresa, "Ingrese el numero de la empresa: ", "Error, no valido.\n", 1000, 1003, 3) &&
			listarTipos(tipos, tamT) &&
			!utn_getNumero(&nuevoMicro.idTipo, "Ingrese el numero del tipo: ", "Error, no valido.\n", 2000, 2003, 3) &&
			!utn_getNumero(&nuevoMicro.capacidad, "Ingrese la capacidad del micro (entre 1 y 50): ", "Error, no valido.\n", 1, 50, 3))
		{

			nuevoMicro.id = *pIndex;
			*pIndex = *pIndex + 1;
			agregarMicro(micros, tamM, empresas, tamE, tipos, tamT, nuevoMicro.id, nuevoMicro.idEmpresa, nuevoMicro.idTipo, nuevoMicro.capacidad);
			todoOk=1;
		}
	}

	return todoOk;
}


int mostrarMicro(eMicro unMicro, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	char descripcionTipo[20];
	char descripcionEmpresa[20];

	if(tipos!=NULL && tamT>0 && empresas!=NULL && tamE>0)
	{
		if(!unMicro.isEmpty)
		{
			cargarDescripcionTipo(tipos, tamT, unMicro.idTipo, descripcionTipo);
			cargarDescripcionEmpresa(empresas, tamE, unMicro.idEmpresa, descripcionEmpresa);

			printf("%4d   %10s   %10s   %d\n",
					unMicro.id,
					descripcionEmpresa,
					descripcionTipo,
					unMicro.capacidad
					);
			todoOk=1;
		}
	}
	return todoOk;
}

int mostrarMicros(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=-1;

	if(micros!=NULL && tamM>0 && tipos!=NULL && tamT>0 && empresas!=NULL && tamE>0)
	{
		todoOk=0;

		printf("      ***Lista de micros***\n");
		printf("Id         Empresa        Tipo          Capacidad\n");
		printf("------------------------------------------------------\n");

		for(int i=0; i<tamM; i++)
		{
			if(!micros[i].isEmpty)
			{
				mostrarMicro(micros[i], tipos, tamT, empresas, tamE);
			}
		}
		printf("\n\n");
	}

	return todoOk;
}


int buscarMicroPorId(eMicro* micros, int tam,int id)
{
	int index=-1;

	if(micros!=NULL && tam>0 && id>=100)
	{
		for(int i=0; i<tam; i++)
		{
			if(!micros[i].isEmpty && micros[i].id == id)
			{
				index=i;
				break;
			}
		}

	}
	return index;
}

int menuModificarMicro(int* opcionModificar)
{
	int rta;

	if(opcionModificar!=NULL)
	{
		printf("Opciones a modificar:\n");
		printf("1.Tipo\n");
		printf("2.Capacidad\n");
		printf("3.Cancelar\n");

		rta = utn_getNumero(opcionModificar, "Ingrese el numero de la opcion que desea modificar: ", "Error, opcion no valida.\n", 1, 3, 3);
	}

	return rta;
}

int modificarMicro(eMicro *micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	int id;
	int opcionModificar;
	int indice;
	int tipo;
	int capacidad;

		if (micros != NULL && tamM>0 && tipos!=NULL && tamT>0 && empresas!=NULL && tamE>0)
		{
			mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE);

			if (!utn_getNumero(&id, "Ingrese el id del micro a modificar\n","Error\n", 100, 10000, 3))
			{
				indice = buscarMicroPorId(micros, tamM, id);
			}
			else
			{
				return todoOk;
			}

			if (indice>=0 && !menuModificarMicro(&opcionModificar))
			{
				todoOk=1;	//REVISAR

				switch (opcionModificar) {
				case 1:
					printf("Modificar tipo\n");
					if(listarTipos(tipos, tamT) &&
						!utn_getNumero(&tipo, "Ingrese el numero del tipo: ", "Error, no valido.\n", 2000, 2003, 3))
					{
						micros[indice].idTipo = tipo;
						printf("Id         Empresa        Tipo          Capacidad\n");
						printf("------------------------------------------------------\n");
						mostrarMicro(micros[indice], tipos, tamT, empresas, tamE);
					}
					break;
				case 2:
					printf("Modificar Capacidad\n");
					if(!utn_getNumero(&capacidad, "Ingrese la capacidad del micro (entre 1 y 50): ", "Error, no valido.\n", 1, 50, 3))
					{
						micros[indice].capacidad = capacidad;
						printf("Id         Empresa        Tipo          Capacidad\n");
						printf("------------------------------------------------------\n");
						mostrarMicro(micros[indice], tipos, tamT, empresas, tamE);
					}
					break;
				default:
					break;
				}
			} else if (indice<0)
			{
				printf("Id no encontrado\n");
			} else
			{
				printf("Opcion no valida\n");
			}
	}

	return todoOk;
}



int eliminarMicro(eMicro* micros, int tam, int id)
{
	int todoOk=-1;
	int index;

	if(micros!=NULL && tam>0 && id>=100)
	{
		index = buscarMicroPorId(micros, tam, id);
		if(index!=-1)
		{
			micros[index].isEmpty = 1;
			todoOk=0;
		}
	}
	return todoOk;
}


int darBajaMicro(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=-1;
	int id;

	if(micros!=NULL && tamM>0 && tipos!=NULL && tamT>0 && empresas!=NULL && tamE>0)
	{
		todoOk=0;
		mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE);

		if(!utn_getNumero(&id, "Ingrese el id del micro al que desea dar de baja: ", "Error, id no valido.\n", 100, 10000,3)
			&& !eliminarMicro(micros, tamM, id))	//compruebo que encontro el id
		{
			todoOk=1;
		}
	}

	return todoOk;
}

//REVISAR
int buscarMicro(eMicro* micros, int tam, int id, int* pIndice)
{
	int todoOk=0;

	if(micros!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice=-1;

		for(int i=0; i<tam; i++)
		{
			if(micros[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int validarMicro(eMicro* micros, int tam, int id)
{
	int esValido=0;
	int indice;

	buscarMicro(micros, tam, id, &indice);
	if(indice!=-1)
	{
		esValido=1;
	}

	return esValido;
}

//***********
int ordenarMicros(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, int order)		//ordenar por empresa y por capacidad
{
	int todoOk=-1;
	eMicro auxiliar;
	char descripcionEmpresa[100];
	char descripcionEmpresa2[100];


	if(micros!=NULL && tamM>0 && empresas!=NULL && tamE>0 && (!order || order ))
	{
		todoOk=0;
		for(int i=0; i<tamM-1; i++)
		{
			for(int j=i+1; j<tamM; j++)
			{
				cargarDescripcionEmpresa(empresas, tamE, micros[i].idEmpresa,descripcionEmpresa);
				cargarDescripcionEmpresa(empresas, tamE, micros[j].idEmpresa,descripcionEmpresa2);

				if((order && stricmp(descripcionEmpresa, descripcionEmpresa2)>0) ||
					(order && stricmp(descripcionEmpresa, descripcionEmpresa2)==0 && micros[i].capacidad > micros[j].capacidad))
				{
					auxiliar = micros[i];
					micros[i] = micros[j];
					micros[j] = auxiliar;
				}
				else if((!order && stricmp(descripcionEmpresa, descripcionEmpresa2)<0) ||
						(!order && stricmp(descripcionEmpresa, descripcionEmpresa2)==0 && micros[i].capacidad < micros[j].capacidad))
				{
					auxiliar = micros[i];
					micros[i] = micros[j];
					micros[j] = auxiliar;
				}
			}
		}
	}

	return todoOk;
}
