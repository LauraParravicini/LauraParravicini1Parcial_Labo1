#include "juego.h"

int mostrarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamC){
    char descripcion[21];
    int retorno = -1;
    if(juegos != NULL && tam > 0){
        printf("\n\n------ Juegos Disponibles -----\n");
            printf("Codigo    Descripcion                  Importe  Categoria \n");
        for(int i = 0; i < tam ; i++){
            cargarDescripcionCateg(juegos[i].idCategoria,categorias,tamC,descripcion);
            printf(" %4d      %15s               %5.2f      %5s \n", juegos[i].codigo, juegos[i].descripcion,juegos[i].importe,descripcion);
            retorno = 1;
        }
    }
    return retorno;
}

int validarJuego(int id, eJuego juegos[], int tam){
    int retorno = 0;
    if(juegos != NULL && tam > 0){
        for(int i = 0; i < tam ; i++){
            if(juegos[i].codigo == id){
                retorno = 1;
            }
        }
    }
    return retorno;
}


int cargarDescripcionJuego(int id , eJuego juegos[], int tam, char descripcion[]){
	int retorno = -1;
	if(id >= 1 && id <= 5 && juegos != NULL && tam > 0 && descripcion != NULL){
		for(int i = 0; i < tam; i++){
			if(juegos[i].codigo == id){
				strcpy(descripcion, juegos[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
