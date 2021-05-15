#include "cliente.h"
#include "alquiler.h"
int initClientes(eCliente clientes[], int tam){
    if(clientes != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			clientes[i].isEmpty = 1;
		}
	}
	return 0;
}

int altaCliente(eCliente clientes[], int tam, int* id){
    int retorno = -1;

	eCliente nuevo;
	if(clientes != NULL && tam > 0){
		int lugar = buscarLibreCliente(clientes, tam);
		if(lugar >= 0){
                char sexo;
                nuevo.codigo = *id;

                utn_getName("\n-- Ingrese nombre : ", "\n-!- Invalido -!-", 1, 51, 10, nuevo.nombre);
                utn_getName("\n-- Ingrese apellido : ", "\n-!- Invalido -!-", 1, 51, 10, nuevo.apellido);

                printf("\n-- Ingrese sexo: ");
                fflush(stdin);
                scanf(" %c",&sexo);
                while(sexo != 'f' && sexo != 'm') {
                    printf("\n-!- Error -!- - Reingrese sexo: ");
                    fflush(stdin);
                    scanf(" %c",&sexo);
                }
                nuevo.sexo = sexo;

                utn_getTelefono("\n-- Ingrese telefono (sin signos): ","-!- Invalido -!-",1,21,0,99,10,nuevo.telefono);

                nuevo.isEmpty = 0;
				clientes[lugar] = nuevo;
				(*id)++;
				retorno = 1;
		}else{
			printf("- No hay lugar para mas clientes -");
			retorno = -1;
		}
	}
	return retorno;
}

int buscarLibreCliente(eCliente clientes[], int tam){
    int indice = -1;
    if(clientes != NULL && tam > 0){
        for(int i = 0; i < tam ; i++){
            if(clientes[i].isEmpty){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarClientes(eCliente clientes[], int tam){
    int retorno = -1;
    int flagHay = 0;
    if(clientes != NULL && tam > 0){
        printf("\n------ Clientes cargados -------\n");
        printf("\n-- Codigo  Nombre Apellido  Sexo  Telefono -------\n");
        eCliente aux;
        for(int i = 0; i < tam -1; i++){
                for(int j = i+1; j < tam; j++){
                    if( strcmp(clientes[i].apellido,clientes[j].apellido) > 0 ||
                        (   strcmp(clientes[i].apellido, clientes[j].apellido) == 0  &&  strcmp(clientes[i].nombre, clientes[j].nombre) > 0 ) ){
                        aux = clientes[i];
                        clientes[i] = clientes[j];
                        clientes[j] = aux;
                    }
                }
        }


        for(int i = 0; i < tam ; i++){
           if(clientes[i].isEmpty == 0){
            flagHay = 1;
            printf(" %4d    %5s    %5s   %4c    %7s \n", clientes[i].codigo, clientes[i].nombre, clientes[i].apellido, clientes[i].sexo,clientes[i].telefono);
            retorno = 1;
           }
        }
        if(!flagHay){
            printf("-!- No hay clientes cargados -!-");
            retorno = 1;
        }
    }
    return retorno;
}

int modifCliente(eCliente clientes[], int tam){
    int idIngresado;
	int indiceExiste = 0;
	int opcion;
	int retorno = -1;
	char nombre[51];
    char apellido[51];
    char telefono[21];
	if(clientes != NULL && tam > 0){
		utn_getNumero(&idIngresado,"\nIngrese id de Cliente a modificar: ","-!- Invalido -!-",0, 10000,10);
		indiceExiste = buscarCliente(clientes,tam,idIngresado);
		if(indiceExiste >= 0){
			printf("\n----*- Editando-*---\n");
            printf("\n\n-- Codigo  Nombre Apellido  Sexo Telefono -------\n");
			printf(" %4d    %5s    %5s   %4c    %7s \n", clientes[indiceExiste].codigo, clientes[indiceExiste].nombre, clientes[indiceExiste].apellido, clientes[indiceExiste].sexo,clientes[indiceExiste].telefono);
			printf("\t\n 1) Nombre \t\n 2) Apellido  \t\n 3) Telefono \t\n 4) Volver ");
			utn_getNumero(&opcion,"\nIngrese opcion 1-4: ","-!- Opcion invalida -!-",1,4,10);
				switch(opcion){
					case 1:
					    utn_getName("\n-- Ingrese nuevo nombre : ", "\n-!- Invalido -!-", 1, 51, 10, nombre);
                        strcpy(clientes[indiceExiste].nombre, nombre);
						break;
                    case 2:
                        utn_getName("\n-- Ingrese nuevo apellido : ", "\n-!- Invalido -!-", 1, 51, 10, apellido);
                        strcpy(clientes[indiceExiste].apellido, apellido);
                        break;
					case 3:
						utn_getTelefono("\n-- Ingrese telefono (sin signos): ","-!- Invalido -!-",1,21,0,99,10,telefono);
                        strcpy(clientes[indiceExiste].telefono,telefono);
						break;
					case 4:
						break;
				}
				retorno = 1;
		}else{
			printf("--- No existe el user ---\n");
			retorno = -1;
		}
	}
	return retorno;

}


int buscarCliente(eCliente clientes[], int tam, int id){
    int retorno = -1;
    if(clientes != NULL && tam > 0 && id > 0){
        for(int i = 0; i < tam; i++){
            if(clientes[i].isEmpty == 0 && clientes[i].codigo == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


