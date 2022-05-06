#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "listas.h"
#include "colas.h"

//FUNCIONES CLIENTE

void impresionNavegacion(ListaProductos *lista){
    printf("Para ver el siguiente producto, pulse D");
    printf("Para ver el producto anterior, pulse A");
    printf("Para ver el primer producto, pulse W");
    printf("Para ver el ultimo producto, pulse S");
}

//pendiente: como leer tanto mayus como minus
//volver a unir la mamada esta en 3 funciones navegacion productos cliente, navegacion cl

Producto *siguienteProducto(ListaProductos *lista, Producto *p){
    if(p == lista->fin){
        p = lista->inicio;
        imprimirProducto(p);
        return p;
    }
    p = p->sig;
    imprimirProducto(p);
    return p;
}

Producto *productoAnterior(ListaProductos *lista, Producto *p){
    if(p == lista->inicio){
        p = lista->fin;
        imprimirProducto(p);
        return p;
    }
    p = p->ant;
    imprimirProducto(p);
    return p;
}

Producto *primerProducto(ListaProductos *lista, Producto *p){
    if(p == lista->inicio){
        printf("\nYa se encuentra en el primer elemento de la lista\n");
        return p;
    }
    p = lista->inicio;
    imprimirProducto(p);
    return p;
}

Producto *ultimoProducto(ListaProductos *lista, Producto *p){
    if(p == lista->fin){
        printf("\nYa se encuentra en el ultimo elemento de la lista\n");
        return p;
    }
    p = lista->fin;
    imprimirProducto(p);
    return p;
}

void navegacionProductos(ListaProductos *lista, char opc){
    //Permite moverse a lo largo de cualquier menu de productos
    Producto *p;
    int check=0;

    if(vaciaListaProductos(lista)){
        printf("No hay ningun articulo disponible.\n");
        return;
    }else{
        p = lista->inicio;
        imprimirProducto(p);
        do{
            opc = getchar();
            switch(opc){
                case 'D': //ir al siguiente
                    p = siguienteProducto(lista, p);
                    break;

                case 'A': //ir al anterior
                    p = productoAnterior(lista, p);
                    break;

                case 'W': //ir al inicio
                    p = primerProducto(lista, p);
                    break;

                case 'S': //ir al final
                    p = ultimoProducto(lista, p);
                    break;

                case 'M': //salir de este menu
                    check = 1;
                    break;

                default:
                    printf("Opcion incorrecta. Intente de nuevo.\n");
                    break;
                }
            }while(!check);
        }
    }

    
void seleccionProducto(ListaProductos *lista, Carrito *carrito){
	//a�adir al carrito a la lista: (resta n a existencias)
}

void revisarCarrito(Carrito * carrito){
    char opc;
    printf("Este es su carrito: \n");
    printf("***************************\n");
    opc = getchar();
    navegacionMenu(carrito, opc);
}

void realizarPedido(ListaProductos * lista){
    char opc;
    printf("Este es su pedido final: \n");
    printf("***************************\n");
    imprimirListaProductos(lista);
    printf("Desea finalizar su pedido? [Y/N] \n");

    if(opc == 'Y' || opc == 'y'){

        //crea nuevo cliente en la lista de clientes
        //imprime para que pida los datos
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


//Funciones Gerente------------------------------------------------------------------------------------------------------------------
void verPedidos(Pedidos *colaPedidos){
    while(vacioPedido(colaPedidos)){
        imprimirListaProductos(colaPedidos->Pedidos);
    }
}

void repartidoresEspera(RepartidoresEspera *colaRepartidores){
    Repartidor *p = colaRepartidores->RepartidoresEnEspera;
    for(int j = 0;j < colaRepartidores->numeroRepartidoresEspera; j++){
        imprimirRepartidor(p);
    }
}

//Funciones Almacenista--------------------------------------------------------------------------------------------------------------
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
//
void pedidoAsignado(){
    
}