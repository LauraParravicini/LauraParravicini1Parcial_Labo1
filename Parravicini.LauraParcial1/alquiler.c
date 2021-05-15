#include "alquiler.h"

int initAlquileres(eAlquiler alquileres[], int tam){
    if(alquileres != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			alquileres[i].isEmpty = 1;
		}
	}
	return 0;
}

int altaAlquiler(eAlquiler alquileres[], int tam, int* id, eCliente clientes[], int tamC, eJuego juegos[], int tamJ,eCategoria categorias[], int tamCat){
    int retorno = -1;
    int codJuego;
    int codCliente;
	eAlquiler nuevo;
	if(alquileres != NULL && tam > 0){
		int lugar = buscarLibreAlquiler(alquileres, tam);
		if(lugar >= 0){
                nuevo.codAlquiler = *id;

                mostrarJuegos(juegos,tamJ,categorias,tamC);

                printf("\n- Ingrese Codigo de Juego: ");
                scanf(" %d", &codJuego);
                while( !validarJuego(codJuego,juegos,tamJ) ){
                    printf("-!- Juego invalido -!- Reingrese codigo de juego: ");
                    scanf(" %d", &codJuego);
                }
                nuevo.codJuego = codJuego;

                mostrarClientes(clientes,tamC);
                printf("\n- Ingrese Codigo de cliente: ");
                scanf(" %d", &codCliente);
                while( buscarCliente(clientes,tamC,codCliente) == -1 ){
                    printf("-!- Cliente invalido -!- Reingrese codigo de cliente: ");
                    scanf(" %d", &codCliente);
                }
                nuevo.codCliente = codCliente;

                utn_getFecha(&nuevo.fecha.dia,&nuevo.fecha.mes,&nuevo.fecha.anio,"\n- Ingrese fecha de alquiler: ","\n-!- Fecha Invalida -!-\n",10);

                nuevo.isEmpty = 0;
				alquileres[lugar] = nuevo;
				(*id)++;
				retorno = 1;
		}else{
			printf("- No hay lugar para mas Alquileres -");
			retorno = -1;
		}
	}
	return retorno;
}

int buscarLibreAlquiler(eAlquiler alquileres[], int tam){
    int indice = -1;
    if(alquileres != NULL && tam > 0){
        for(int i = 0; i < tam ; i++){
            if(alquileres[i].isEmpty){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarAlquileres(eAlquiler alquileres[], int tam,eJuego juegos[], int tamJ){
    char descripcion[21];
    int retorno = -1;
    if(alquileres != NULL && tam > 0){
        printf("\n\n------ Alquileres cargados -------\n");
        printf("\n-- Alquiler       Juego      Cliente   Fecha -------\n");

        for(int i = 0; i < tam ; i++){
           if(alquileres[i].isEmpty == 0){
            cargarDescripcionJuego(alquileres[i].codJuego,juegos,tamJ,descripcion);
            printf("   %4d       %10s     %4d   %2d/%2d/%4d    \n", alquileres[i].codAlquiler, descripcion, alquileres[i].codCliente, alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio);
            retorno = 1;
           }
        }
        if(retorno == -1){
            printf("\n-!- No hay alquileres cargados -!-\n\n");
            retorno = 1;
        }
    }
    return retorno;
}

