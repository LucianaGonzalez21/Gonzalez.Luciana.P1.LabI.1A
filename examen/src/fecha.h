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

/// @brief Valida que una fecha sea valida, segun dia, mes y anio
///
/// @param dia
/// @param mes
/// @param anio
/// @return Devuelve 1 si la fecha es valida, 0 si no
int validarFecha(int dia, int mes, int anio);
