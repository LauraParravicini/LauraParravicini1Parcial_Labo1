#include <stdio.h>
#include "utn.h"
#include <string.h>

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];//Validar
    char apellido[51];//Validar
    char sexo;//Validar
    char telefono[21];//Validar
    int isEmpty;
}eCliente;

/** \brief  Ingresa los datos, valida y da de alta un cliente actualizando el proximo ID
 *
 * \param eCliente clientes[]
 * \param int tam
 * \param int* id
 * \return int
 *
 */
int altaCliente(eCliente clientes[], int tam, int* id);

/** \brief  Inicializa el vector clientes poniendo isEmpty en verdadero (1)
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int initClientes(eCliente clientes[], int tam);

/** \brief  Devuelve la primera posicion libre (isEmpty en verdadero) de clientes
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int buscarLibreCliente(eCliente clientes[], int tam);

/** \brief  Muestra los clientes activos por pantalla
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int mostrarClientes(eCliente clientes[], int tam);

/** \brief Modifica el cliente mostrando las opciones para modificar, validando y actualizando el cliente
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int modifCliente(eCliente clientes[], int tam);

/** \brief  Devuelve la posicion en el vector de un cliente usando su ID
 *
 * \param eCliente clientes[]
 * \param int tam
 * \return int
 *
 */
int buscarCliente(eCliente clientes[], int tam, int id);

#endif // CLIENTE_H_INCLUDED
