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

/// @brief Imprime los datos del vector de Tipos
///
/// @param tipos Es el vector de tipos
/// @param tam Es el tamanio del vector
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int listarTipos(eTipo* tipos, int tam);


/// @brief  Busca un Tipo a traves de un id, y devuelve la posicion donde se encuentra por medio de un puntero
///
/// @param tipos
/// @param tam
/// @param id
/// @param pIndice Es el puntero al espacio de memoria donde se alojara el indice encontrado o -1 si no lo encontro
/// @return Retorna 0 si hubo algun error de parametros, o 1 si no
int buscarTipo(eTipo* tipos, int tam, int id, int* pIndice);


/// @brief Valida que un Tipo exista en el vector a traves del id que se le pasa por parametro
///
/// @param tipos
/// @param tam
/// @param id
/// @return Devuelve 1 si existe en el vector, 0 si no
int validarTipo(eTipo* tipos, int tam, int id);


/// @brief Busca a traves de un id un Tipo que exista y guarda en el puntero la descripcion de ese Tipo
///
/// @param tipos
/// @param tam
/// @param id
/// @param descripcion
/// @return  Devuelve 0 si hubo error de parametros, 1 si no
int cargarDescripcionTipo(eTipo* tipos, int tam, int id, char* descripcion);
