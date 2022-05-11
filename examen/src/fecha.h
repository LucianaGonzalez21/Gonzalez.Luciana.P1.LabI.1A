/*
 * fecha.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#ifndef FECHA_H_
#define FECHA_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

#endif /* FECHA_H_ */

int validarFecha(int dia, int mes, int anio);
