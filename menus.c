#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "listas.h"
#include "funciones.h"

//Impresión y selección del submenu
int menuInicial(int opcion){
    char ingresado[2];
    printf("Te encuentras en el menú inicial\n");
    printf("Ingresa [1]: Cliente\n");
    printf("ingresa [2]: Gerente\n");
    printf("Ingresa [3]: Repartidor\n");
    printf("Ingresa [4]: Almacenista\n");
    printf("ingresa [5]: Salir del Programa\n");
    fflush(stdin);
    gets(ingresado);
    opcion = atoi(ingresado);
    if(opcion == 0)
        printf("Ingrese un valor numerico\n");
    return opcion;
}

//Impresión de opciones iniciales para el cliente
int menuCliente(int opcionCliente, ListaProductos *lista, ListaCarrito *carrito, Pedidos *colaPedidos){
    int check = 0;
    char ingresado[2];
    printf("Este es el menu para Clientes\n");
    printf("Ingresa [1]: Seleccionar Productos\n");
    printf("Ingresa [2]: Revisar el carrito de Compras\n");
    printf("ingresa [3]: Realizar Pedido\n");
    printf("Ingresa [4]: Salir de este menu\n");
    fflush(stdin);
    gets(ingresado);
    opcionCliente = atoi(ingresado);
    if(opcionCliente == 0)
        printf("Ingrese un valor numerico\n");
    switch(opcionCliente){
        case 1:
            do{
                system("cls");
                check = navegacionProductos(lista, carrito, check);
            }while(!check);
        break;
        case 2:
            do{
                system("cls");
                check = revisarCarrito(carrito, check);
            }while(!check);
        break;
        case 3:
            system("cls");
            if(vacioCarrito(carrito)){
                printf("No hay ningun articulo en su carrito.\n");
                system("Pause");
                system("cls");
            }else{
                do{
                    check = realizarPedido(lista, carrito, colaPedidos, check);
                    printf("Se te regresara al menu inicial\n");
                    system("Pause");
                    system("cls");
                    return 4;
                }while(!check);
            }
        break;
        case 4:
            return opcionCliente;
        break;
    }
    return opcionCliente;
}

//Impresión y selección de las opciones para el gerente
int menuGerente(int opcionGerente, Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores){
    int check;
    char ingresado[2];
    printf("Este es el menu del Gerente\n");
    printf("Ingresa [1]: Ver la cola de Pedidos\n");
    printf("Ingresa [2]: Ver la cola de repartidores en espera\n");
    printf("Ingresa [3]: Ver la lista de repartidores en transito\n");
    printf("Ingresa [4]: Asignar un pedido\n");
    printf("Ingresa [5]: Salir de este menu\n");
    fflush(stdin);
    gets(ingresado);
    opcionGerente = atoi(ingresado);
    if(opcionGerente == 0)
        printf("Ingrese un valor numerico\n");
    switch(opcionGerente){
        case 1:
            imprimirColaPedidos(colaPedidos);
            system("Pause");
            system("cls");
        break;
        case 2:
            imprimirRepartidoresEspera(colaRepartidores);
            system("Pause");
            system("cls");

        break;
        case 3:
            imprimirListaRepartidoresTransito(listaRepartidores);
            system("Pause");
            system("cls");
        break;
        case 4:
            do{
                system("cls");
                check = asignarPedido(listaRepartidores, colaRepartidores, colaPedidos, check);
                system("Pause");
            }while(!check);
        break;
        case 5:
            return opcionGerente;
        break;
    }
    return opcionGerente;
}

//Impresión y selección de las opciones para el repartidor
int menuRepartidor(int opcionRepartidor, ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Repartidor *repartidor){
    int check = 0;
    char ingresado[2];
    printf("Este es el menu del Repartidor\n");
    printf("Ingresa [1]: Ver Pedido Asignado\n");
    printf("Ingresa [2]: Notificar una entrega de pedido\n");
    printf("Ingresa [3]: Salir de este menu\n");
    fflush(stdin);
    gets(ingresado);
    opcionRepartidor = atoi(ingresado);
    if(opcionRepartidor == 0)
        printf("Ingrese un valor numerico\n");

    switch(opcionRepartidor){
        case 1:
            pedidoAsignado(repartidor);
        break;
        case 2:
            if(repartidor->pedidoAsignado == NULL){
                printf("No tienes un pedido asignado que entregar, se te regresara al menu inicial\n");
                system("pause");
                return 3;
            }
            do{
                system("cls");
                check = entregaPedido(repartidor, listaRepartidores, colaRepartidores, check);
                system("Pause");
            }while(!check);
        break;
        case 3:
            return opcionRepartidor;
        break;
    }
    return opcionRepartidor;
}

//Impresión y selección de las opciones para el almacenista
int menuAlmacenista(int opcionAlmacenista, ListaProductos *lista){

    int check = 0;
    char ingresado[2];

    printf("Este es el menu del Almacenista\n");
    printf("Ingresa [1]: Mostrar la lista de Productos\n");
    printf("Ingresa [2]: Registrar la llegada de un producto\n");
    printf("Ingresa [3]: Salir de este menu\n");

    fflush(stdin);
    gets(ingresado);
    opcionAlmacenista = atoi(ingresado);
    if(opcionAlmacenista == 0)
        printf("Ingrese un valor numerico\n");

    switch(opcionAlmacenista){
        case 1:
            check = verificarListaProductos(lista, check);
        break;
        case 2:
            agregarProductos(lista);
        break;
        case 3:
            return opcionAlmacenista;
        break;
    }
    return opcionAlmacenista;
}
