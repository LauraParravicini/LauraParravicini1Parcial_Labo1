#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"
#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
typedef struct{
 int codigo;
 char descripcion[20];
 float importe;
 int idCategoria;
}eJuego;

/** \brief  Muestra los clientes por pantalla
 *
 * \param eJuego juegos[]
 * \param int tam
 * \param eCategoria categorias[]
 * \param int tamC
 * \return int
 *
 */
int mostrarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamC);

/** \brief  Valida que el codigo de juego pasado por parametro exista
 *
 * \param int id
 * \param eJuego juegos
 * \param int tam
 * \return int
 *
 */
int validarJuego(int id, eJuego juegos[], int tam);

/** \brief  Carga en el parametro descripcion la descripcion del id de juego
 *
 * \param int id
 * \param eJuego juegos
 * \param int tam
 * \param char descripcion[]
 * \return int
 *
 */
int cargarDescripcionJuego(int id , eJuego juegos[], int tam, char descripcion[]);
#endif // JUEGO_H_INCLUDED
