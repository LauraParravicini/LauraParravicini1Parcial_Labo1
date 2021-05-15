#include "categoria.h"

int cargarDescripcionCateg(int id , eCategoria categorias[], int tam, char descripcion[]){
	int retorno = -1;
	if(id >= 100 && id <= 500 && categorias != NULL && tam > 0 && descripcion != NULL){
		for(int i = 0; i < tam; i++){
			if(categorias[i].id== id){
				strcpy(descripcion, categorias[i].descripcion);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


