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

int menuPrincipal(int *opcion) {

	int rta;

	if (opcion != NULL) {
		printf("**MENU DE OPCIONES**\n");
		printf("1.ALTA micro\n");
		printf("2.MODIFICAR micro\n");
		printf("3.BAJA micro\n");
		printf("4.LISTAR micros\n");
		printf("5.LISTAR empresas\n");
		printf("6.LISTAR tipos\n");
		printf("7.LISTAR destinos\n");
		printf("8.ALTA viaje\n");
		printf("9.LISTAR viajes\n");
		printf("10. Mostrar lista de micros de una Empresa.\n");
		printf("11. Mostrar lista de micros de un Tipo.\n");
		printf("12. Mostrar promedio de micros vip sobre el total de micros de una empresa\n");
		printf("13. Mostrar micros separados por empresa .\n");
		printf("14. Mostrar empresa/s con mayor capacidad\n");
		printf("15. Mostrar la empresa con menor cantidad de micros\n");
		printf("16. Mostrar viajes de un micro\n");
		printf("17. Mostrar suma de precios de viajes que realizo un micro\n");
		printf("18. Mostrar los micros que viajaron a und destino con su fecha\n");
		printf("19. Mostrar viajes realizados en una fecha\n");
		printf("20.SALIR\n\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 20, 3);
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

int verificarDisponibilidadVectorMicros(eMicro* micros, int tam)
{
	int estaVacio=1;

	for(int i=0; i<tam; i++)
	{
		if(!micros[i].isEmpty)
		{
			estaVacio=0;
			break;
		}
	}
	return estaVacio;
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
			!utn_getNumero(&nuevoMicro.idEmpresa, "Ingrese el Id de la empresa: ", "Error, no valido.\n", 0, 2000, 3) &&	//1000-1003
			validarEmpresa(empresas, tamE, nuevoMicro.idEmpresa) &&
			listarTipos(tipos, tamT) &&
			!utn_getNumero(&nuevoMicro.idTipo, "Ingrese el Id del tipo: ", "Error, no valido.\n", 0, 3000, 3) &&	///2000-2003
			validarTipo(tipos, tamT, nuevoMicro.idTipo) &&
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
		if(!unMicro.isEmpty)	// for(int i=0; i<tamCliente; i++)
								//{if(clientes[i].id == unMicro.idCliente) ---> printf }
		{
			cargarDescripcionTipo(tipos, tamT, unMicro.idTipo, descripcionTipo);
			cargarDescripcionEmpresa(empresas, tamE, unMicro.idEmpresa, descripcionEmpresa);

			printf("%4d    %10s   %10s           %d\n",
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
	int flag=0;

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
				flag=1;
			}
		}

		if(!flag)
		{
			printf("No hay micros cargados en el sistema.\n\n");
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

			if(!verificarDisponibilidadVectorMicros(micros, tamM))
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
					todoOk=1;

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
			else
			{
				printf("No hay micros cargados.\n");
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

		if(!verificarDisponibilidadVectorMicros(micros, tamM))
		{
			mostrarMicros(micros, tamM, tipos, tamT, empresas, tamE);

			if(!utn_getNumero(&id, "Ingrese el id del micro al que desea dar de baja: ", "Error, id no valido.\n", 100, 10000,3)
				&& !eliminarMicro(micros, tamM, id))
			{
				todoOk=1;
			}
		}
		else
		{
			printf("No hay micros cargados.\n");
		}
	}

	return todoOk;
}

//REVISAR ESTA AL PEDO
/*
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
} */


int validarMicro(eMicro* micros, int tam, int id)
{
	int esValido=0;
	int indice;

	indice = buscarMicroPorId(micros, tam, id);
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

//NUEVO
//mostrar micros de una empresa que elija el usuario

int mostrarMicrosEmpresa(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT)
{
	int todoOk=0;
	int id;
	int flag=0;
	char descripcion[20];

	if(micros!=NULL && empresas!=NULL && tipos!=NULL && tamM>0 && tamE>0 && tamT>0)
	{
		todoOk=1;

		if(listarEmpresas(empresas, tamT) &&
			!utn_getNumero(&id, "Ingrese el Id de la Empresa: ", "Error, no valido\n", 0, 4000, 3)
		)
		{
			if(!validarEmpresa(empresas, tamE, id))
			{
				printf("Id no encontrado.\n");
			}
			else
			{
				printf("      ***Lista de micros***\n");
				printf("Id         Empresa        Tipo          Capacidad\n");
				printf("------------------------------------------------------\n");
				for(int i=0; i<tamM; i++)
				{
					if(micros[i].idEmpresa == id)
					{
						mostrarMicro(micros[i], tipos, tamT, empresas, tamE);
						flag=1;
					}
				}

				if(!flag)
				{
					cargarDescripcionEmpresa(empresas, tamE, id, descripcion);
					printf("No hay micros de la empresa %s.\n\n", descripcion);
				}
				printf("\n\n");
			}
		}
	}

	return todoOk;
}


//mostrar micros de un tipo que elija el usuario
int mostrarMicrosTipo(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	int id;
	int flag=0;
	char descripcion[20];

	if(micros!=NULL && tipos!= NULL && empresas!=NULL && tamM>0 && tamT>0 && tamE)
	{
		todoOk=1;

		if(listarTipos(tipos, tamT) &&
			!utn_getNumero(&id, "Ingrese el Id del tipo: ", "Error, no valido.\n", 0, 3000, 3))
		{
			if(!validarTipo(tipos, tamT, id))
			{
				printf("Id no encontrado.\n");
			}
			else
			{
				printf("      ***Lista de micros***\n");
				printf("Id         Empresa        Tipo          Capacidad\n");
				printf("------------------------------------------------------\n");
				for(int i=0; i<tamM; i++)
				{
					if(micros[i].idTipo == id)
					{
						mostrarMicro(micros[i], tipos, tamT, empresas, tamE);
						flag=1;
					}
				}

				if(!flag)
				{
					cargarDescripcionTipo(tipos, tamT, id, descripcion);
					printf("No hay micros del Tipo %s\n", descripcion);
				}
			}
		}
	}

	return todoOk;
}


//Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa
int informarPromedioDeMicrosVip(eMicro* micros, int tamM, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	int contador[4]= {0,0,0,0};
	int contadorMicros[4] = {0,0,0,0};
	float promedios[4]= {0,0,0,0};
	char descripcion1[20];

	if(micros!=NULL && tamM>0 && empresas!=NULL && tamE>0)
	{
		todoOk=1;


		for(int i=0; i<tamE;i++)
		{
			for(int j=0; j<tamM; j++)
			{
				if(!micros[j].isEmpty && empresas[i].id == micros[j].idEmpresa)
				{
					contadorMicros[i]++;
					if(micros[j].idTipo == 2003 && empresas[i].id == micros[j].idEmpresa) //vip 2003
					{
						contador[i]++;
					}
				}
			}
		}


		for(int i=0; i<tamE; i++)
		{
			if(contadorMicros[i]>0)
			{
				promedios[i] = (float)contador[i] / contadorMicros[i];
			}
		}


		printf("Promedio de micros de tipo Vip sobre el total de micros de una empresa.\n");
		for(int i=0; i<tamE; i++)
		{
			cargarDescripcionEmpresa(empresas, tamM, empresas[i].id, descripcion1);
			printf("Empresa %s Promedio: %.2f \n", descripcion1, promedios[i]);
		}

	}

	return todoOk;
}


//mostrar micros por empresa
int mostrarMicrosPorEmpresa(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	int flag;

	if(micros!=NULL && tamM>0 && tipos!=NULL && tamT>0 && empresas!=NULL && tamE>0)
	{
		todoOk=1;

		for(int i=0; i<tamE; i++)	//recorro empresas
		{
			flag=0;
			printf("Empresa: %s\n\n", empresas[i].descripcion);
			printf("Id         Empresa        Tipo          Capacidad\n");
			printf("------------------------------------------------------\n");

			for(int j=0; j<tamM; j++)	//recorro micros
			{
				if(empresas[i].id == micros[j].idEmpresa)
				{
					mostrarMicro(micros[j], tipos, tamT, empresas, tamE);
					flag=1;
				}
			}

			if(!flag)
			{
				printf("No hay micros.\n\n");
			}
			printf("\n\n");
		}
	}


	return todoOk;
}


//Informar la o las empresas que pueden transportar más pasajeros (mayor acumulador de capacidades de sus micros)
int informarEmpresaMayorCapacidad(eMicro* micros, int tamM, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
	int capacidad[4] = {0,0,0,0};
	int flag=0;
	int mayor;

	if(micros!=NULL && tamM>0 && empresas!=NULL && tamE>0)
	{
		todoOk=1;


		for(int i=0; i<tamE; i++)
		{
			for(int j=0; j<tamM; j++)
			{
				if(!micros[j].isEmpty && empresas[i].id == micros[j].idEmpresa)
				{
					capacidad[i] += micros[j].capacidad;
				}
			}
		}


		for(int i=0; i<4; i++)
		{
			if(!flag || capacidad[i] > mayor)
			{
				mayor = capacidad[i];
				flag=1;
			}
		}


		printf("Empresa/s con mayor capacidad: \n");
		for(int i=0; i<tamE; i++)
		{
			if(capacidad[i] == mayor)
			{
				printf("%s\n", empresas[i].descripcion);
			}
		}
	}

	return todoOk;
}

//Mostrar la empresa con menor cantidad de MICROS
int informarEmpresaMenorCantidadMicros(eMicro* micros, int tamM, eEmpresa* empresas, int tamE)
{
	int todoOk=0;
		int contadores[4] = {0,0,0,0};
		int flag=0;
		int menor;

		if(micros!=NULL && tamM>0 && empresas!=NULL && tamE>0)
		{
			todoOk=1;


			for(int i=0; i<tamE; i++)
			{
				for(int j=0; j<tamM; j++)
				{
					if(!micros[j].isEmpty && empresas[i].id == micros[j].idEmpresa)
					{
						contadores[i]++;
					}
				}
			}


			for(int i=0; i<4; i++)
			{
				if(!flag || contadores[i] < menor)
				{
					menor = contadores[i];
					flag=1;
				}
			}


			printf("Empresa/s con menor cantidad de micros: \n");
			for(int i=0; i<tamE; i++)
			{
				if(contadores[i] == menor)
				{
					printf("%s\n", empresas[i].descripcion);
				}
			}
		}

		return todoOk;
}
