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
	int index=100;
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
					if(flag && modificarMicro(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA))
					{
						printf("Modificacion exitosa.\n\n");
					}
					else if(!flag)
					{
						printf("Error. Primero debe cargar al menosun micro\n\n");
					}
					else
					{
						printf("Error al modificar.\n\n");
					}
					break;
				case 3:
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
					if(!listarEmpresas(empresas, TAM_EMPRESA))
					{
						printf("Error al listar empresas\n\n");
					}
					break;
				case 6:
					if(!listarTipos(tipos, TAM_TIPOS))
					{
						printf("Error al listar tipos\n\n");
					}
					break;
				case 7:
					if(!listarDestinos(destinos, TAM_DESTINOS))
					{
						printf("Error al listar destinos\n\n");
					}
					break;
				case 8:
					if(!cargarViaje(viajes, TAM_VIAJES, micros, TAM_MICRO, destinos, TAM_DESTINOS, tipos, TAM_TIPOS, empresas, TAM_EMPRESA, &indexViaje))
					{

						printf("Error al cargar viaje\n\n");
					}
					else
					{
						flagV=1;
						printf("Viaje cargado con exito\n\n");
					}
					break;
				case 9:
					if(flagV)
					{
						if(mostrarViajes(viajes, TAM_VIAJES, micros, TAM_MICRO, destinos, TAM_DESTINOS) == -1)
						{
							printf("Error al intentar listar\n\n");
						}
					}
					else
					{
						printf("Primero debe cargar un viaje.\n\n");
					}
					break;
				case 10:
					if(flag)
					{
						if(!mostrarMicrosEmpresa(micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPOS))
						{
							printf("Error al mostrar\n");
						}
					}
					break;
				case 11:
					if(flag)
					{
						if(!mostrarMicrosTipo(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA))
						{
							printf("Error al mostrar.\n\n");
						}
					}
					break;
				case 12:
					if(flag)
					{
						if(!informarPromedioDeMicrosVip(micros, TAM_MICRO, empresas, TAM_EMPRESA))
						{
							printf("Error al mostrar.\n\n");
						}
					}
					break;
				case 13:
					if(flag)
					{
						if(!mostrarMicrosPorEmpresa(micros, TAM_MICRO, tipos, TAM_TIPOS, empresas, TAM_EMPRESA))
						{
							printf("Error al mostrar.\n\n");
						}
					}
					break;
				case 14:
					if(flag)
					{
						if(!informarEmpresaMayorCapacidad(micros, TAM_MICRO, empresas, TAM_EMPRESA))
						{
							printf("Error al mostrar.\n\n");
						}
					}
					break;
				case 15:
					if(flag)
					{
						if(!informarEmpresaMenorCantidadMicros(micros, TAM_MICRO, empresas, TAM_EMPRESA))
						{
							printf("Error al informar.\n\n");
						}
					}
					break;
				case 16:
					if(flag)
					{
						if(!mostrarViajesSegunMicro(viajes, TAM_VIAJES, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPOS, destinos, TAM_DESTINOS))
						{
							printf("Error al informar.\n\n");
						}
					}
					break;
				case 17:
					if(flag)
					{
						if(!informarPrecioTotalDeViajeSegunMicro(viajes, TAM_VIAJES, micros, TAM_MICRO, empresas, TAM_EMPRESA, tipos, TAM_TIPOS, destinos, TAM_DESTINOS))
						{
							printf("Error al informar.\n\n");
						}
					}
					break;
				case 18:
					if(flag)
					{
						if(!informarViajesADestino(viajes, TAM_VIAJES, micros, TAM_MICRO, destinos, TAM_DESTINOS, tipos, TAM_TIPOS, empresas, TAM_EMPRESA))
						{
							printf("Error al informar.\n\n");
						}
					}
					break;
				case 19:
					if(flag)
					{
						if(!mostrarViajesSegunFecha(viajes, TAM_VIAJES, micros, TAM_MICRO, destinos, TAM_DESTINOS))
						{
							printf("Error al informar.\n\n");
						}
					}
					break;
				case 20:
					printf("Usted ha salido\n");
					break;
				}
			}
			else
			{
				printf("ERROR. Cantidad de reintentos agotada. \nPrograma finalizado\n");
				break;
			}
		} while (opcion != 20);

		return EXIT_SUCCESS;


}
