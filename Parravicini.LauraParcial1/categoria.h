#include <stdio.h>
#include <stdlib.h>

#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[51];
}eCategoria;

/** \brief  Carga en el parametro descripcion la descripcion de la categoria pasada como ID
 *
 * \param int id
 * \param eCategoria categorias[]
 * \param int tam
 * \param char descripcion[]
 * \return int
 *
 */
int cargarDescripcionCateg(int id , eCategoria categorias[], int tam, char descripcion[]);
#endif // CATEGORIA_H_INCLUDED
