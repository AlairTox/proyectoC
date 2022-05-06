#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "listas.h"

//FUNCIONES CLIENTE

void impresionNavegacion(ListaProductos *lista){
    //aca seria uh. imprimir las opciones wasdm+.
    //si desean cambiar las letras dense. la que no me convence es m, la puse a lo pendejo.
    //no tengo ganas de hacerlo ahorita hope this helps <3 son puros printfs tho
}

//pendiente: como leer tanto mayus como minus
//pendiente: ver como integrar la funcion de añadir y eliminar producto en el switch. Ponerlos dentro de navegacion?
//separar cada una de las funciones?

void navegacionMenu(ListaProductos *lista, char opc){
    //Permite moverse a lo largo de cualquier menu de productos
    Producto *p;
    int check=0;
    //Impresion del menu aca

    if(vaciaListaProductos(lista)){
        printf("No hay ningun articulo disponible.\n");
        return;
    }
    p = lista->inicio;
    imprimirProducto(p);

    do{
        opc = getchar();
        switch(opc){
            case 'D': //ir al siguiente
                if(p == lista->fin){
                    p = lista->inicio;
                    imprimirProducto(p);
                    break;
                }
                p = p->sig;
                imprimirProducto(p);
                break;

            case 'A': //ir al anterior
                if(p == lista->inicio){
                    p = lista->fin;
                    imprimirProducto(p);
                    break;
                }
                p = p->ant;
                imprimirProducto(p);
                break;

            case 'W': //ir al inicio
                if(p == lista->inicio){
                    printf("\nYa se encuentra en el primer elemento de la lista\n");
                    break;
                }
                p = lista->inicio;
                imprimirProducto(p);
                break;

            case 'S': //ir al final
                if(p == lista->fin){
                    printf("\nYa se encuentra en el ultimo elemento de la lista\n");
                    break;
                }
                p = lista->fin;
                imprimirProducto(p);
                break;

            case 'M': //salir de este menu
               check = 1;
               break;

            default:
                printf("");
            }
        }while(!check);
    }

void seleccionProducto(ListaProductos *lista){
	//a�adir al carrito a la lista: (resta n a existencias)
}

void revisarCarrito(ListaProductos * lista){
    printf("Este es su carrito: \n");
    printf("***************************\n");
    navegacionMenu(lista);
}

void realizarPedido(ListaProductos * lista){
    char opc;
    printf("Este es su pedido final: \n");
    printf("***************************\n");
    imprimirListaProductos(lista);
    printf("Desea finalizar su pedido? [Y/N] \n");

    if(opc == 'Y' || opc == 'y'){
        //imprime para que pida los datos
        //crea nuevo cliente
        //
        //se da el anuncio de que el pedido ya est� en camino
    }
    else if(opc == 'N' || opc == 'n'){
        printf("Se le regresar� al menu principal para clientes.\n");
        menuCliente();
    }
}

void eliminarProducto(){
    //elimina un producto del carrito y suma n a existencias
}


//Funciones Almacenista
void agregarProductos(ListaProductos * lista){
    char *nombre;
    int cantidad;
    int precio;
    Producto *p = lista->inicio;
    printf("Ingrese el nombre del producto:     ");
    fflush(stdin);
    gets(nombre);
    fflush(stdin);
    printf("Ingrese la cantidad a almacenar:    ");
    scanf("%d", cantidad);
    printf("Ingrese el precio del producto:     ");
    scanf("%d", precio);
    while(vaciaListaProductos(lista)){
        if(nombre = p->nombre){
            p->precio = precio;
            p->existencias += cantidad;
            return;
        }
        p = p->sig;
    }
    agregarProducto(lista, nombre, precio, cantidad);
    return;
}