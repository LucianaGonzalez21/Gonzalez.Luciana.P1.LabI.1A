/*
 * fecha.c
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include "fecha.h"

int validarFecha(int dia, int mes, int anio)
{
	int esValido=0;

	if(dia>0 && dia<=31 && mes>0 && mes<=12 && anio>0)
	{
		esValido=1;
	}
	return esValido;
}
