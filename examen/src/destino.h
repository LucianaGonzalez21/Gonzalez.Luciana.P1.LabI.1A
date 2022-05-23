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


/// @brief Imprime los datos del vector de destinos
///
/// @param destinos Es el vector de destinos
/// @param tam Es el tamanio del vector
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int listarDestinos(eDestino* destinos, int tam);


/// @brief  Busca un destino a traves de un id, y devuelve la posicion donde se encuentra por medio de un puntero
///
/// @param destinos
/// @param tam
/// @param id
/// @param pIndice Es el puntero al espacio de memoria donde se alojara el indice encontrado o -1 si no lo encontro
/// @return Retorna 0 si hubo algun error de parametros, o 1 si no
int buscarDestino(eDestino* destinos, int tam, int id, int* pIndice);


/// @brief Valida que un destino exista en el vector a traves del id que se le pasa por parametro
///
/// @param destinos
/// @param tam
/// @param id
/// @return Devuelve 1 si existe en el vector, 0 si no
int validarDestino(eDestino* destinos, int tam, int id);


/// @brief Busca a traves de un id un destino que exista y guarda en el puntero la descripcion de ese destino
///
/// @param destinos
/// @param tam
/// @param id
/// @param descripcion
/// @return  Devuelve 0 si hubo error de parametros, 1 si no
int cargarDescripcionDestino(eDestino* destinos, int tam, int id, char* descripcion);
