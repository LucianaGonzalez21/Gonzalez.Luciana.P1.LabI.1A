/*
 * micro.h
 *
 *  Created on: May 11, 2022
 *      Author: Dell
 */

#include "tipo.h"
#include "empresa.h"

#ifndef MICRO_H_
#define MICRO_H_

typedef struct{
	int id;
	int idEmpresa;
	int idTipo;
	int capacidad;
	int isEmpty;
}eMicro;

#endif /* MICRO_H_ */


/// @brief Muestra el menu de opciones y pide al usuario que ingrese un numero
///
/// @param opcion Puntero al espacio de memoria donde se alojara la opcion que haya ingresado el usuario
/// @return Devuelve 0 si consiguio una opcion valida, -1 si no
int menuPrincipal(int *opcion);


/// @brief Pone todas las banderas isEmpty en 1 indicando que las posiciones en el vector Micros estan libres
///
/// @param micros Es el vector de Micros
/// @param tam Tamanio del vector micros
/// @return Devuelve 0 si hay error de parametros, 1 si no
int inicializarMicros(eMicro* micros, int tam);

/// @brief Busca en el vector de micros un lugar libre, donde isEmpty valga 1
///
/// @param micros Es el vector de micros
/// @param tam Es el tamanio del vector micros
/// @param pIndice Es el puntero al espacio de memoria donde se alojara la posicion libre o bien -1 si no encontro lugar
/// @return Retorna 0 si hay algun error de parametros, 1 si estan bien
int buscarPosicionLibre(eMicro* micros, int tam, int* pIndice);


/// @brief Pide al usuario y carga todos los campos del tipo eMicro, excepto por el campo id que es autoincremental
///
/// @param micros
/// @param tamM
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @param pIndex
/// @return Retorna 0 si hubo error de parametros, 1 si pudo cargar los datos correctamente
int cargarMicro(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE, int* pIndex);

/// @brief  Agrega en una lista de micros, los valores recibidos por parametro
///
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @param tipos
/// @param tamT
/// @param id
/// @param idEmpresa
/// @param idTipo
/// @param capacidad
/// @return Devuelve -1 si hay error de parametros y 0 si pudo agregar el micro al vector
int agregarMicro(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT, int id, int idEmpresa, int idTipo,int capacidad);


/// @brief Muestra en pantalla todos los datos de un micro
///
/// @param unMicro
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Retorna 0 si hubo error de parametros, 1 si lo pudo imprimir correctamente
int mostrarMicro(eMicro unMicro, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);


/// @brief Imprime el contenido del vector micros
///
/// @param micros
/// @param tamM
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Devuelve -1 si hubo error de parametros,0 si no
int mostrarMicros(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);


/// @brief Busca un micro por el id pasado por parametro
///
/// @param micros
/// @param tam
/// @param id
/// @return Devuelve -1 si hubo error de parametros o no encontro el micro, sino devuelve el indice del vector
int buscarMicroPorId(eMicro* micros, int tam,int id);


/// @brief Muestra un menu de opciones y pide al usuario que ingrese un numero
///
/// @param opcionModificar Puntero al espacio de memoria donde se alojara la opcion que haya ingresado el usuario
/// @return Devuelve 0 si consiguio una opcion valida, -1 si no
int menuModificarMicro(int* opcionModificar);


/// @brief Muestra la lista de micros, despliega un menu de opciones para que el usuario elija que dato quiere modificar a traves
/// 		del id del micro y lo modifica
///
/// @param micros
/// @param tamM
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Retorna 0 si hay error de parametros o si no encuentra el id ingresado, y 1 si los parametros estan bien
int modificarMicro(eMicro *micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);


/// @brief Elimina un micro segun el id pasado por parametro, poniendo el isEmpty en 1
///
/// @param micros
/// @param tam
/// @param id
/// @return Retorna -1 si hubo error de parametros,  0 si pudo eliminar el micro
int eliminarMicro(eMicro* micros, int tam, int id);


/// @brief Elimina a un pasajero de la lista pidiendo el id
///
/// @param micros
/// @param tamM
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Retorna -1 si hubo algun error de parametros, 0 si no y 1 si lo pudo eliminar
int darBajaMicro(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);


//int buscarMicro(eMicro* micros, int tam, int id, int* pIndice);

/// @brief Valida que un micro exista en el vector a traves del id que se le pasa por parametro
///
/// @param micros
/// @param tam
/// @param id
/// @return Devuelve 1 si existe, 0 si no
int validarMicro(eMicro* micros, int tam, int id);

/// @brief Ordena el vector de micros por empresa y por capacidad
///
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @param order
/// @return Devuelve -1 si hubo error de parametros, 0 si no
int ordenarMicros(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, int order);


/// @brief Recorre el vector de micros para validar si se encuentra vacio o no
///
/// @param micros
/// @param tam
/// @return Devuelve 1 si esta completamente libre, 0 si no
int verificarDisponibilidadVectorMicros(eMicro* micros, int tam);

/// @brief Pide al usuario el id de una empresa y muestra los micros de esa empresa
///
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @param tipos
/// @param tamT
/// @return Devuelve 0 si hubo error de parametros , 1 si no
int mostrarMicrosEmpresa(eMicro* micros, int tamM, eEmpresa* empresas, int tamE, eTipo* tipos, int tamT);


/// @brief Pide al usuario el id de un Tipo y muestra los micros de ese tipo
///
/// @param micros
/// @param tamM
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int mostrarMicrosTipo(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);


/// @brief Calcula el promedio de micros de tipo vip sobre el total de micros de una empresa, e informa
///
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int informarPromedioDeMicrosVip(eMicro* micros, int tamM, eEmpresa* empresas, int tamE);


/// @brief Muestra la lista de micros separada por las distintas empresas
///
/// @param micros
/// @param tamM
/// @param tipos
/// @param tamT
/// @param empresas
/// @param tamE
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int mostrarMicrosPorEmpresa(eMicro* micros, int tamM, eTipo* tipos, int tamT, eEmpresa* empresas, int tamE);

/// @brief Calcula e informa la/s empresa/s con mayor acumulador de capacidad
///
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int informarEmpresaMayorCapacidad(eMicro* micros, int tamM, eEmpresa* empresas, int tamE);


/// @brief Calcula e informa la/s empresa/s con menor cantidad de micros
///
/// @param micros
/// @param tamM
/// @param empresas
/// @param tamE
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int informarEmpresaMenorCantidadMicros(eMicro* micros, int tamM, eEmpresa* empresas, int tamE);
