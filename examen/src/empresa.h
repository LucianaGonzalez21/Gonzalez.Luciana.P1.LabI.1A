/*
 * empresa.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

typedef struct{
	int id;
	char descripcion[20];
}eEmpresa;

#endif /* EMPRESA_H_ */

/// @brief Imprime los datos del vector de Empresas
///
/// @param empresas Es el vector de empresas
/// @param tam Es el tamanio del vector
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int listarEmpresas(eEmpresa* empresas, int tam);


/// @brief  Busca una empresa a traves de un id, y devuelve la posicion donde se encuentra por medio de un puntero
///
/// @param empresas
/// @param tam
/// @param id
/// @param pIndice Es el puntero al espacio de memoria donde se alojara el indice encontrado o -1 si no lo encontro
/// @return Retorna 0 si hubo algun error de parametros, o 1 si no
int buscarEmpresa(eEmpresa* empresas, int tam, int id, int* pIndice);


/// @brief Valida que una empresa exista en el vector a traves del id que se le pasa por parametro
///
/// @param empresas
/// @param tam
/// @param id
/// @return Devuelve 1 si existe en el vector, 0 si no
int validarEmpresa(eEmpresa* empresas, int tam, int id);


/// @brief Busca a traves de un id una empresa que exista y guarda en el puntero la descripcion de esa empresa
///
/// @param empresas
/// @param tam
/// @param id
/// @param descripcion
/// @return  Devuelve 0 si hubo error de parametros, 1 si no
int cargarDescripcionEmpresa(eEmpresa* empresas, int tam, int id, char* descripcion);
