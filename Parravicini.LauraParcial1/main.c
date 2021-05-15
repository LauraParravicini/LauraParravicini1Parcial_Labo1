#include "utn.h"
#include "categoria.h"
#include "juego.h"
#include "cliente.h"
#include "alquiler.h"
#include <stdio.h>
#include <stdlib.h>

#define SALIR 7
#define TAMC 10
#define TAMA 20
#define TAMJ 5
#define TAMCAT 5

//Estas funciones se encuentran en main debido al error de bibiotecas referido en la cursada
int bajaCliente(eCliente clientes[], int tam, eAlquiler alquileres[], int tamA);
int bajaAlquileresCliente(int idCliente,eAlquiler alquileres[], int tamA);

int main()
{
    eJuego juegos[TAMJ] = {  {1, "Tateti" , 50, 100} , {2, "Starcraft" , 400, 300} , {3, "Conejo Galera" , 700, 500} , {4, "Poker" , 200, 200} , {5, "Ruleta" , 2000, 400} };
    eCategoria categorias[TAMCAT] = { {100, "Mesa"},{200, "Azar"} , {300, "Estrategia"} , {400, "Salon" } , {500, "Magia"} };

    eCliente clientes[TAMC];
    eAlquiler alquileres[TAMA];

    initClientes(clientes,TAMC);
    initAlquileres(alquileres,TAMA);

    int nextId = 1;
    int nextIdAlquiler = 1;
    int opcion;
    int status;
    int flagAlta = 0;
    do{
            printf("-----------*-*-*--- Alquiler de Juegos ---*-*-*---------------\n\n");
            printf("--- Menu ---\n 1) Alta cliente \n ");
            if(flagAlta){
                printf("2) Modificar cliente \n 3) Baja cliente \n 4) Listar Cliente \n 5) Alta alquiler \n 6) Listar alquileres\n");
            }
            printf("\n 7) Salir del sistema \n");
            utn_getNumero(&opcion,"\n--- Ingrese opcion: ", "\n-!- Dato Invalido -!-\n",1,10,10);
            switch(opcion){
                case 1:
                    status = altaCliente(clientes,TAMC,&nextId);
                    status != -1 ? printf("\n--- Cliente Agregado ---\n\n") : printf("\n-!- Hubo error al cargar Cliente -!-\n") ;
                    flagAlta++;
                    break;
                case 2:
                    status = modifCliente(clientes,TAMC);
                    status != -1 ? printf("\n--- Operacion exitosa ---\n\n") : printf("\n-!- Hubo error al modificar Cliente -!-\n") ;
                    break;
                case 3:
                    status = bajaCliente(clientes,TAMC,alquileres,TAMA);
                    status != -1 ? printf("\n--- Operacion exitosa ---\n\n") : printf("\n-!- Hubo error al borrar Cliente -!-\n") ;
                    break;
                case 4:
                    status = mostrarClientes(clientes,TAMC);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n\n") ;
                    break;
                case 5:
                    status = altaAlquiler(alquileres,TAMA,&nextIdAlquiler,clientes,TAMC,juegos,TAMJ,categorias,TAMCAT);
                    status != -1 ? printf("\n ---- Alquiler cargado -----\n\n") : printf("\n-!- Hubo error al cargar -!-\n") ;
                    break;
                case 6:
                    status = mostrarAlquileres(alquileres,TAMA,juegos,TAMJ);
                    status != -1 ? printf("\n\n") : printf("\n-!- Hubo error al mostrar -!-\n") ;
                    break;
                case 7:
                    break;
            }

    }while(opcion != SALIR);


    return EXIT_SUCCESS;
}

int bajaCliente(eCliente clientes[], int tam, eAlquiler alquileres[], int tamA){
    int retorno = -1;
	int idBorrar;
	char confirmacion;
	if(clientes != NULL && tam > 0){
		printf("\n--- Lista Clientes - Baja --- ");

		mostrarClientes(clientes,tam);

		utn_getNumero(&idBorrar, "\n- Ingrese id de Cliente a borrar: ","-!- Invalido -!-",1,tam,10);
		int indiceBorrar = buscarCliente(clientes,tam,idBorrar);
		if(indiceBorrar >= 0){
            printf("\n-- Codigo  Nombre Apellido  Sexo  Telefono -------\n");
            printf(" %4d    %5s    %5s   %4c    %7s \n", clientes[indiceBorrar].codigo, clientes[indiceBorrar].nombre, clientes[indiceBorrar].apellido, clientes[indiceBorrar].sexo,clientes[indiceBorrar].telefono);

			printf("\n¿Quiere borrarlo? s/n: ");
            fflush(stdin);
			scanf(" %c",&confirmacion);
			if(confirmacion == 's'){
				clientes[indiceBorrar].isEmpty = 1;

				bajaAlquileresCliente(idBorrar,alquileres,tamA);

				retorno = 1;
			}else{
				printf("-- No se borro --\n");
				retorno = -1;
			}
		}else{
			printf("--No existe--");
			retorno = -1;
		}
	}
	return retorno;
}

int bajaAlquileresCliente(int idCliente,eAlquiler alquileres[], int tamA){
    int cant = 0;
    if(alquileres != NULL && tamA > 0){
        for(int i = 0; i < tamA; i++){
            if(alquileres[i].isEmpty == 0 && alquileres[i].codCliente == idCliente){
                alquileres[i].isEmpty = 1;
                cant++;
            }
        }
    }
    return cant;
}
