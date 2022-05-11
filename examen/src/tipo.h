/*
 * tipo.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

#endif /* TIPO_H_ */

int listarTipos(eTipo* tipos, int tam);
int buscarTipo(eTipo* tipos, int tam, int id, int* pIndice);
int validarTipo(eTipo* tipos, int tam, int id);
int cargarDescripcionTipo(eTipo* tipos, int tam, int id, char* descripcion);
