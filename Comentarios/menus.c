#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include "listas.h"
#include "funciones.h"

//Impresi�n y selecci�n del submenu
int menuInicial(int opcion){
    setlocale(LC_CTYPE, "SPANISH");
    char ingresado[2];
    printf("----------------------(^._.^)----------------------\n");
    printf("           Bienvenidx a El Huarache Veloz\n\n\n");
    printf("---------------------------------------------------\n");
    printf("                   MEN� PRINCIPAL\n");
    printf("---------------------------------------------------\n");
    printf("Presione [1]: Cliente\n");
    printf("Presione [2]: Gerente\n");
    printf("Presione [3]: Repartidor\n");
    printf("Presione [4]: Almacenista\n");
    printf("Presione [5]: Salir del Programa\n");
    printf("---------------------------------------------------\n");
    fflush(stdin);
    gets(ingresado);
    opcion = atoi(ingresado);

    if(opcion == 0)
        printf("�Error! Ingrese un valor dentro del rango\n");

    return opcion;
}

//Impresi�n de opciones iniciales para el cliente
int menuCliente(int opcionCliente, ListaProductos *lista, ListaCarrito *carrito, Pedidos *colaPedidos){
    int check = 0;
    char ingresado[2];
    printf("-------------------(^._.^)------------------\n");
    printf("              El Huarache Veloz\n\n\n");
    printf("--------------------------------------------\n");
    printf("                   CLIENTE\n");
    printf("--------------------------------------------\n");
    printf("Presione [1]: Seleccionar Productos\n");
    printf("Presione [2]: Revisar el carrito de Compras\n");
    printf("Presione [3]: Realizar Pedido\n");
    printf("Presione [4]: Salir de este men�\n");
    printf("--------------------------------------------\n");
    fflush(stdin);
    gets(ingresado);
    opcionCliente = atoi(ingresado);

    if(opcionCliente == 0)
        printf("�Error! Ingrese un valor dentro del rango\n");

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
                printf("------------------------------------------------\n");
                printf("                RESUMEN DEL PEDIDO\n");
                printf("------------------------------------------------\n");
                printf("No hay ning�n art�culo en su carrito.\n");
                system("Pause");
                system("cls");
            }else{
                do{
                    check = realizarPedido(lista, carrito, colaPedidos, check);
                    printf("Se te regresar� al men� inicial\n");
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

//Impresi�n y selecci�n de las opciones para el gerente
int menuGerente(int opcionGerente, Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores){
    int check;
    char ingresado[2];
    printf("-------------------------(^._.^)-------------------------\n");
    printf("                    El Huarache Veloz\n\n\n");
    printf("---------------------------------------------------------\n");
    printf("                         GERENTE\n");
    printf("---------------------------------------------------------\n");
    printf("Presione [1]: Ver la cola de Pedidos\n");
    printf("Presione [2]: Ver la cola de repartidores en espera\n");
    printf("Presione [3]: Ver la lista de repartidores en tr�nsito\n");
    printf("Presione [4]: Asignar un pedido\n");
    printf("Presione [5]: Salir de este men�\n");
    printf("---------------------------------------------------------\n");
    fflush(stdin);
    gets(ingresado);
    opcionGerente = atoi(ingresado);

    if(opcionGerente == 0)
        printf("�Error! Ingrese un valor dentro del rango\n");

    switch(opcionGerente){
        case 1:
            printf("------------------------------------------------\n");
            printf("                    PEDIDOS\n");
            printf("------------------------------------------------\n");
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
                check = asignarPedido(listaRepartidores, colaRepartidores, colaPedidos, check);
                system("Pause");
                system("cls");
            }while(!check);
        break;
        case 5:
            return opcionGerente;
        break;
    }
    return opcionGerente;
}

//Impresi�n y selecci�n de las opciones para el repartidor
int menuRepartidor(int opcionRepartidor, ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Repartidor *repartidor){
    int check = 0;
    char ingresado[2];
    printf("-----------------------------------------------\n");
    printf("                   REPARTIDOR\n");
    printf("-----------------------------------------------\n");
    printf("Presione [1]: Ver Pedido Asignado\n");
    printf("Presione [2]: Notificar una entrega de pedido\n");
    printf("Presione [3]: Salir de este men�\n");
    printf("-----------------------------------------------\n");
    fflush(stdin);
    gets(ingresado);
    opcionRepartidor = atoi(ingresado);

    if(opcionRepartidor == 0)
        printf("�Error! Ingrese un valor dentro del rango\n");

    switch(opcionRepartidor){
        case 1:
            pedidoAsignado(repartidor);
            system("pause");
            system("cls");
        break;
        case 2:
            if(repartidor->pedidoAsignado == NULL){
                printf("No tienes un pedido asignado que entregar, se te regresar� al men� inicial\n");
                system("pause");
                system("cls");
                return 3;
            }
            do{
                check = entregaPedido(repartidor, listaRepartidores, colaRepartidores, check);
                system("Pause");
                system("cls");
            }while(!check);
        break;
        case 3:
            return opcionRepartidor;
        break;
    }
    return opcionRepartidor;
}

//Impresi�n y selecci�n de las opciones para el almacenista
int menuAlmacenista(int opcionAlmacenista, ListaProductos *lista){

    int check = 0;
    char ingresado[2];
    printf("-----------------------(^._.^)-----------------------\n");
    printf("                  El Huarache Veloz\n\n\n");
    printf("-----------------------------------------------------\n");
    printf("                     ALMACENISTA\n");
    printf("-----------------------------------------------------\n");
    printf("Presione [1]: Mostrar la lista de Productos\n");
    printf("Presione [2]: Registrar la llegada de un producto\n");
    printf("Presione [3]: Salir de este men�\n");
    printf("-----------------------------------------------------\n");

    fflush(stdin);
    gets(ingresado);
    opcionAlmacenista = atoi(ingresado);

    if(opcionAlmacenista == 0)
        printf("�Error! Ingrese un valor dentro del rango\n");

    switch(opcionAlmacenista){
        case 1:
            check = verificarListaProductos(lista, check);
        break;
        case 2:
            agregarProductos(lista);
            system("cls");
        break;
        case 3:
            return opcionAlmacenista;
        break;
    }
    return opcionAlmacenista;
}
