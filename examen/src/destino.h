/*
 * destino.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct{
	int id;
	char descripcion[20];
	float precio;
}eDestino;

#endif /* DESTINO_H_ */

int listarDestinos(eDestino* destinos, int tam);
int buscarDestino(eDestino* destinos, int tam, int id, int* pIndice);
int validarDestino(eDestino* destinos, int tam, int id);
int cargarDescripcionDestino(eDestino* destinos, int tam, int id, char* descripcion);
