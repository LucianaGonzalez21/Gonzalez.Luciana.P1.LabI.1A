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

int listarEmpresas(eEmpresa* empresas, int tam);
int buscarEmpresa(eEmpresa* empresas, int tam, int id, int* pIndice);
int validarEmpresa(eEmpresa* empresas, int tam, int id);
int cargarDescripcionEmpresa(eEmpresa* empresas, int tam, int id, char* descripcion);
