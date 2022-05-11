/*
 ============================================================================
 Name        : examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "destino.h"
#include "empresa.h"
#include "micro.h"
#include "fecha.h"
#include "tipo.h"
#include "viaje.h"

#define TAM_EMPRESA 4
#define TAM_TIPOS 4
#define TAM_DESTINOS 4
#define TAM_MICRO 100
#define TAM_VIAJES 100

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int index=100;	//id automatico
	int indexViaje=500;
	int flag=0;
	int flagV=0;

	eMicro micros [TAM_MICRO];
	eViaje viajes [TAM_VIAJES];

	eEmpresa empresas[TAM_EMPRESA] = {
			{1000, "Plusmar"},
			{1001, "Flecha Bus"},
			{1002, "Tas"},
			{1003, "El Rapido"}
	};

	eTipo tipos[TAM_TIPOS] = {
			{2000, "Comun"},
			{2001, "Coche Cama"},
			{2002, "Doble"},
			{2003, "Vip"},
	};

	eDestino destinos[TAM_DESTINOS] = {
			{20000, "Calafate", 22250},
			{20001, "Bariloche", 103000},
			{20002, "Iguazu", 84400},
			{20003, "Mendoza", 95600},
	};

	inicializarMicros(micros, TAM_MICRO);
	inicializarViajes(viajes, TAM_VIAJES);

		do {
			if (!menuPrincipal(&opcion)) {

				switch (opcion) {
				case 1:
					printf("opcion 1 ALTA\n");
					if(cargarMicro(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA, &index))
					{
						printf("Micro cargado con exito.\n\n");
						flag=1;
					}
					else
					{
						printf("Error \n\n");
					}
					break;
				case 2:
					printf("opcion 2 MODIFICAR\n");
					if(flag && modificarMicro(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA))
					{
						printf("Modificacion exitosa.\n\n");
					}
					else
					{
						printf("Error. Primero debe cargar al menosun micro\n\n");
					}
					break;
				case 3:
					printf("opcion 3 BAJA\n");
					if(flag && darBajaMicro(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA))
					{
						printf("Micro dado de baja con exito.\n\n");
					}
					else if(!flag)
					{
						printf("Error. Primero debe cargar al menos un micro.\n\n");
					}
					else
					{
						printf("Error al dar de baja.\n\n");
					}
					break;
				case 4:
					printf("opcion 4 LISTAR MICROS\n");
					if(flag)
					{
						if(!ordenarMicros(micros, TAM_MICRO, empresas, TAM_EMPRESA, 1))
						{
							if(mostrarMicros(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA) == -1)
							{
								printf("Error al mostrar\n\n");
							}
						}
					}
					else
					{
						printf("Error. Primero debe cargar al menos un micro\n\n");
					}
					break;
				case 5:
					printf("Opcion 5 LISTAR EMPRESAS\n");
					if(!listarEmpresas(empresas, TAM_EMPRESA))
					{
						printf("Error al listar empresas\n\n");
					}
					break;
				case 6:
					printf("OPCION 6 LISTAR TIPOS\n");
					if(!listarTipos(tipos, TAM_TIPOS))
					{
						printf("Error al listar tipos\n\n");
					}
					break;
				case 7:
					printf("OPCION 7 LISTAR DESTINOS\n");
					if(!listarDestinos(destinos, TAM_DESTINOS))
					{
						printf("Error al listar destinos\n\n");
					}
					break;
				case 8:
					printf("opcion 8 Alta viaje\n");
					if(!cargarViaje(viajes, TAM_VIAJES, micros, TAM_MICRO, destinos, TAM_DESTINOS, tipos, TAM_TIPOS, empresas, TAM_EMPRESA, &indexViaje))
					{

						printf("Error al cargar viaje\n\n");
					}
					else
					{
						flagV=1;
						printf("Viaje cargado con exitos\n\n");
					}
					break;
				case 9:
					printf("opcion 9 listar viajes\n");
					if(flagV)
					{
						if(mostrarViajes(viajes, TAM_VIAJES, micros, TAM_MICRO, destinos, TAM_DESTINOS) == -1)
						{
							printf("Error al intentar listar\n\n");
						}
					}
					break;
				case 10:
					printf("Usted ha salido\n");
					break;
				}
			}
			else
			{
				printf("ERROR. Cantidad de reintentos agotada. \nPrograma finalizado\n");
				break;
			}
		} while (opcion != 10);

		return EXIT_SUCCESS;


}
