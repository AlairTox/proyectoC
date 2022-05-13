#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "funciones.h"

//Impresión y selección del submenu
int menuInicial(void){
    int opcion;
    do{
        printf("Te encuentras en el menú inicial\n");
        printf("Ingresa [1]: Cliente\n");
        printf("ingresa [2]: Gerente\n");
        printf("Ingresa [3]: Repartidor\n");
        printf("Ingresa [4]: Almacenista\n");
        printf("ingresa [5]: Salir del Programa\n");
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > 5);
    return opcion;
}

//Impresión de opciones iniciales para el cliente
int menuCliente(ListaProductos *lista, ListaCarrito *carrito, int opcionCliente, Pedidos *colaPedidos){
    int check;
    do{
        printf("Este es el menu para Clientes\n");
        printf("Ingresa [1]: Seleccionar Productos\n");
        printf("Ingresa [2]: Revisar el carrito de Compras\n");
        printf("ingresa [3]: Realizar Pedido\n");
        printf("Ingresa [4]: Salir de este menu\n");
        scanf("%d", &opcionCliente);
    }while(opcionCliente < 1 || opcionCliente > 4);
    switch(opcionCliente){
        case 1:
            do{
                system("cls");
                check = navegacionProductos(lista, carrito);
            }while(!check);
        break;
        case 2:
            do{
                system("cls");
                check = revisarCarrito(carrito);
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
                    check = realizarPedido(carrito, colaPedidos);
                    system("Pause");
                    system("cls");
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
int menuGerente(Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores, int opcionGerente){
    int check;
    do{
        printf("Este es el menu del Gerente\n");
        printf("Ingresa [1]: Ver la cola de Pedidos\n");
        printf("Ingresa [2]: Ver la cola de repartidores en espera\n");
        printf("Ingresa [3]: Ver la lista de repartidores en transito\n");
        printf("Ingresa [4]: Asignar un pedido\n");
        printf("Ingresa [5]: Salir de este menu\n");
        scanf("%d", &opcionGerente);
    }while(opcionGerente < 1 || opcionGerente > 5);
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
                check = asignarPedido(listaRepartidores, colaRepartidores, colaPedidos);
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
int menuRepartidor(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, int opcionRepartidor){
    int check = 0;
    do{
        printf("Este es el menu del Repartidor\n");
        printf("Ingresa [1]: Ver Pedido Asignado\n");
        printf("Ingresa [2]: Notificar una entrega de pedido\n");
        printf("Ingresa [3]: Salir de este menu\n");
        scanf("%d", &opcionRepartidor);
    }while(opcionRepartidor < 1 || opcionRepartidor > 3);
    switch(opcionRepartidor){
        case 1:
            pedidoAsignado(repartidor);
        break;
        case 2:
            do{
                system("cls");
                check = entregaPedido(repartidor, lista, colaRepartidores, check);
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
int menuAlmacenista(ListaProductos *lista, int opcionAlmacenista){
    int check = 0;
    do{
        printf("Este es el menu del Almacenista\n");
        printf("Ingresa [1]: Mostrar la lista de Productos\n");
        printf("Ingresa [2]: Registrar la llegada de un producto\n");
        printf("Ingresa [3]: Salir de este menu\n");
        scanf("%d", &opcionAlmacenista);
    }while(opcionAlmacenista < 1 || opcionAlmacenista > 3);
    switch(opcionAlmacenista){
        case 1:
            check = verificarListaProductos(lista, check);
        break;
        case 2:
            agregarProductos(lista);
        break;
        case 3:
            return;
        break;
    }
}
