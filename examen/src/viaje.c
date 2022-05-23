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

		if(!verificarDisponibilidadVectorMicros(micros, tamM) )
		{
			if(	!mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE) &&
				!utn_getNumero(&idM, "Ingrese el id de un micro: ", "Error, no valido\n", 100, 10000, 3) &&
				validarMicro(micros, tamM, idM) &&
				listarDestinos(destinos, tamD) &&
				!utn_getNumero(&idD, "Ingrese el id del destino: ", "Error, no valido.\n", 0, 20100, 3) &&	///20000-20003
				validarDestino(destinos, tamD, idD) &&
				!utn_getNumero(&d, "Fecha\nIngrese el dia: ", "Error", 1, 31, 3) &&
				!utn_getNumero(&m, "Ingrese el mes: ", "Error", 1, 12, 3) &&
				!utn_getNumero(&a, "Ingrese el anio: ", "Error", 0, 2030, 3) &&
				validarFecha(d, m, a))
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
		else
		{
			printf("Primero debe cargar un micro\n");
		}

	}

	return todoOk;
}

int mostrarViaje(eViaje unViaje, eMicro* micros, int tamM, eDestino* destinos, int tamD)
{
	int todoOk=0;
	char descripcionDestino[20];

	if(micros!=NULL && tamM>0 && destinos!=NULL && tamD>0)
	{
		if(!unViaje.isEmpty)
		{
			cargarDescripcionDestino(destinos, tamD, unViaje.idDestino,descripcionDestino);

			printf("%5d           %5d        %15s      %02d/%02d/%d\n",

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
	int flag=0;

	if(viajes!=NULL && tamV>0 && micros!=NULL && tamM>0 && destinos!=NULL && tamD>0)
	{
		todoOk=0;

		printf("      ***Lista de Viajes***\n");
		printf("  Id Viaje        Id Micro          Destino        Fecha\n");
		printf("------------------------------------------------------------\n");

		for(int i=0; i<tamV; i++)
		{
			if(!viajes[i].isEmpty)
			{
				mostrarViaje(viajes[i], micros, tamM, destinos, tamD);
				flag=1;
			}
		}

		if(!flag)
		{
			printf("No hay viajes cargados en el sistema.\n\n");
		}
		printf("\n\n");
	}

	return todoOk;
}


int hardcodearViajes(eViaje* viajes , int tam, int cant, int* pIndex)
{

    int todoOk = 0;
    eViaje lista[] =
    {
		{0, 100, 20000, {12, 5,2022}, 0},
		{0, 100, 20003, {14, 8, 2023}, 0},
		{0, 102, 20002, {20, 10, 2020}, 0},
		{0, 103, 20001, {11, 11, 2024}, 0},
		{0, 100, 20002, {30, 12, 2022}, 0},
		{0, 104, 20000, {2, 2, 2022}, 0},
		{0, 105, 20001, {27, 10, 2023}, 0},
		{0, 102, 20002, {4, 7, 2023}, 0},
		{0, 103, 20000, {19, 8, 2024}, 0},
		{0, 101, 20001, {7, 3, 2024}, 0}
    };

    if(viajes != NULL && tam > 0 && pIndex != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
        	if(viajes[i].isEmpty)
        	{
				viajes[i] = lista[i];
				viajes[i].id = *pIndex;
				*pIndex = *pIndex +1;
        	}

        }
        todoOk = 1;
    }
    return todoOk;

}

//el usuario elige el micro y se muestran los viajes
int mostrarViajesSegunMicro(eViaje* viajes, int tamV, eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, eDestino* destinos, int tamD)
{
	int todoOk=0;
	int id;
	int flag=0;

	if(viajes!=NULL && tamV>0 && micros!=NULL && tamM>0 && empresas!=NULL && tamE>0 && tipos!=NULL && tamT>0)
	{
		todoOk=1;

		if(!mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE)
			&& !verificarDisponibilidadVectorMicros(micros, tamM)
			&& !utn_getNumero(&id, "Ingrese el Id del micro: ", "Error, no valido\n", 100, 10000, 3)
			&& validarMicro(micros, tamM, id))
		{
			printf("  Id Viaje        Id Micro          Destino        Fecha\n");
			printf("------------------------------------------------------------\n");
			for(int i=0; i<tamV; i++)
			{
				if(viajes[i].idMicro == id)
				{
					mostrarViaje(viajes[i], micros, tamM, destinos, tamD);
					flag=1;
				}
			}
			if(!flag)
			{
				printf("No hay viajes con ese micro\n\n");
			}
		}
	}

	return todoOk;
}

//pedir un micro e informar la suma de los precios de todos los viajes que realizo
int informarPrecioTotalDeViajeSegunMicro(eViaje* viajes, int tamV, eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, eDestino* destinos, int tamD)
{
	int todoOk=0;
	float acumulador=0;
	int id;

	if(micros!=NULL && tamM>0 && viajes!=NULL && tamV>0 && empresas!=NULL && tamE>0 && tipos!=NULL && tamT>0 && destinos!=NULL && tamD>0)
	{
		todoOk=1;

		if(!mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE)
			&& !verificarDisponibilidadVectorMicros(micros, tamM)
			&& !utn_getNumero(&id, "Ingrese el Id del micro: ", "Error, no valido\n", 100, 10000, 3)
			&& validarMicro(micros, tamM, id))
		{

			for(int i=0; i<tamV; i++)	//recorro viajes
			{
				for(int j=0; j<tamD; j++)	//recorro destinos
				{
					if(!viajes[i].isEmpty && viajes[i].idMicro == id && viajes[i].idDestino == destinos[j].id)
					{
						acumulador += destinos[j].precio;
					}
				}
			}

			printf("Suma de precios: $ %.2f\n", acumulador);
		}
	}

	return todoOk;
}

//pedir un destino y mostrar los micros que viajaron a ese destino y en que fecha
int informarViajesADestino(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD, eTipo*  tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	int idD;
	char descripcionEmpresa[20];
	char descripcionTipo[20];
	int flag=0;

	if(micros!=NULL && tamM>0 && viajes!=NULL && tamV>0 && empresas!=NULL && tamE>0 && tipos!=NULL && tamT>0 && destinos!=NULL && tamD>0)
	{
		todoOk=1;
		if(listarDestinos(destinos, tamD) &&
				!utn_getNumero(&idD, "Ingrese id destino: ", "Error, no valido\n", 0, 20100, 3) &&
				validarDestino(destinos, tamD, idD))
		{
			printf("Id         Empresa        Tipo          Capacidad      Fecha\n");
			printf("-------------------------------------------------------------\n");
			for(int i=0; i<tamV; i++)
			{
				for(int j=0; j<tamM; j++)
				{
					if(!viajes[i].isEmpty && viajes[i].idDestino == idD && viajes[i].idMicro == micros[j].id)
					{
						cargarDescripcionTipo(tipos, tamT, micros[j].idTipo, descripcionTipo);
						cargarDescripcionEmpresa(empresas, tamE, micros[j].idEmpresa, descripcionEmpresa);

						printf("%4d    %10s   %10s           %d      %02d/%02d/%d\n",
								micros[j].id,
								descripcionEmpresa,
								descripcionTipo,
								micros[j].capacidad,
								viajes[i].fecha.dia,
								viajes[i].fecha.mes,
								viajes[i].fecha.anio
								);
						flag=1;
					}
				}
			}

			if(!flag)
			{
				printf("No hay micros a ese destino\n\n");
			}
		}
	}


	return todoOk;
}


//Pedir una fecha y mostrar todos los viajes realizados en la misma
int mostrarViajesSegunFecha(eViaje* viajes, int tamV, eMicro* micros, int tamM, eDestino* destinos, int tamD)
{
	int todoOk=0;
	int dia;
	int mes;
	int anio;
	int flag=0;

	if(viajes!=NULL && tamV>0 && micros!=NULL && tamM>0 && destinos!=NULL && tamD>0)
	{
		todoOk=1;
		if(!utn_getNumero(&dia, "Fecha\nIngrese dia: ", "Error, no valido.\n", 1, 31, 3) &&
			!utn_getNumero(&mes, "Ingrese mes: ", "Error, no valido.\n", 1, 12, 3) &&
			!utn_getNumero(&anio, "Ingrese anio: ", "Error, no valido.\n", 0, 2030, 3) &&
			validarFecha(dia, mes, anio)
		)
		{
			printf("      ***Lista de Viajes***\n");
			printf("  Id Viaje        Id Micro          Destino        Fecha\n");
			printf("------------------------------------------------------------\n");
			for(int i=0; i<tamV; i++)
			{
				if(!viajes[i].isEmpty && viajes[i].fecha.dia == dia && viajes[i].fecha.mes == mes && viajes[i].fecha.anio == anio)
				{
					mostrarViaje(viajes[i], micros, tamM, destinos, tamD);
					flag=1;
				}
			}

			if(!flag)
			{
				printf("No hay viajes en tal fecha.\n\n");
			}
		}
	}


	return todoOk;
}
