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

	if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
		dia<=31 ) ||
		((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
		dia <=30) ||
		(anio%4 == 0 && mes == 2  && dia <=29) ||
		(anio%4 != 0 && mes ==2 && dia<=28)
	)
	{
		esValido=1;
	}
	return esValido;
}
