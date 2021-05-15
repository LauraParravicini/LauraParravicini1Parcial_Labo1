#include "fecha.h"
#include "cliente.h"
#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct{
    int codAlquiler;//Auto incre
    int codJuego;//Validar
    int codCliente;//Validar
    eFecha fecha;
    int isEmpty;
}eAlquiler;

/** \brief  Inicializa el vector alquileres con isEmpty en 1
 *
 * \param eAlquiler alquileres[]
 * \param int tam
 * \return int
 *
 */
int initAlquileres(eAlquiler alquileres[], int tam);

/** \brief  Ingresa los datos, valida y da de alta un alquiler actualizando el proximo ID
 *
 * \param eAlquiler alquileres[]
 * \param int tam
 * \param int* id
 * \param eCliente clientes[]
 * \param int tamC
 * \param eJuego juegos[]
 * \param int tamJ
 * \param eCategorias categorias[]
 * \param int tamCat
 * \return int
 *
 */
int altaAlquiler(eAlquiler alquileres[], int tam, int* id, eCliente clientes[], int tamC, eJuego juegos[], int tamJ,eCategoria categorias[], int tamCat);

/** \brief  Devuelve la primera posicion libre del vector de alquileres
 *
 * \param eAlquiler alquileres[]
 * \param int tam
 * \return int
 *
 */
int buscarLibreAlquiler(eAlquiler alquileres[], int tam);

/** \brief  Muestra por pantalla los alquileres cargados
 *
 * \param eAlquiler alquileres[]
 * \param int tam
 * \return int
 *
 */
int mostrarAlquileres(eAlquiler alquileres[], int tam,eJuego juegos[], int tamJ);

#endif // ALQUILER_H_INCLUDED
