#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "colas.h"

//FUNCIONES COLA DE PEDIDOS
//Creaci�n de la cola de pedidos
Pedidos* crearColaPedidos(void){
    Pedidos* p;
    p = malloc(sizeof(Pedidos));
    p->numeroPedidos = 0;
    p->inicio = p->fin = NULL;
    return p;
}

//A�ade un pedido al inicio de la cola de pedidos
void pushPedido(Pedidos *colaPedidos, ListaCarrito *carritoCliente){
    if(colaPedidos->inicio == NULL){
        colaPedidos->inicio = colaPedidos->fin = carritoCliente;
        return;
    }

    imprimirCarrito(carritoCliente);
    carritoCliente->sig = colaPedidos->inicio;
    colaPedidos->inicio->ant = carritoCliente;
    colaPedidos->inicio = carritoCliente;
    colaPedidos->numeroPedidos++;
    return;
}

//Elimina el pedido al final de la cola de pedidos, regresando su direcci�n
ListaCarrito* popPedido(Pedidos *colaPedidos){
    ListaCarrito *pedidoAsignado;

    if(colaPedidos->inicio == NULL){
        printf("La cola de pedidos esta vacia\n");
        return NULL;
    }

    if(colaPedidos->inicio == colaPedidos->fin){
        pedidoAsignado = colaPedidos->inicio;
        colaPedidos->numeroPedidos--;
        colaPedidos->inicio = colaPedidos->fin = NULL;
        return pedidoAsignado;
    }

    pedidoAsignado = colaPedidos->fin;
    colaPedidos->fin->ant->sig = NULL;
    colaPedidos->fin = colaPedidos->fin->ant;
    pedidoAsignado->ant = NULL;
    return pedidoAsignado;
}

//Imprime la cola de Pedidos
void imprimirColaPedidos(Pedidos *colaPedidos){
    ListaCarrito *c = colaPedidos->fin;

    if(c == NULL){
        printf("La cola de pedidos esta vacia\n");
        return;
    }

    if(c == colaPedidos->inicio){
        imprimirCarrito(c);
        return;
    }

    for(int k = 0; k <= colaPedidos->numeroPedidos; k++){
        printf("\n");
        imprimirCarrito(c);
        printf("------------------------------------------------\n");
        printf("------------------------------------------------\n");
        c = c->ant;
    }
    return;
}

//FUNCIONES COLA DE REPARTIDORES
//Creaci�n de la cola de repartidores
RepartidoresEspera *crearColaRepartidores(void){
    RepartidoresEspera *p;
    p = malloc(sizeof(RepartidoresEspera));
    p->numeroRepartidoresEspera = 0;
    p->inicio = p->fin = NULL;
    return p;
}

//Agrega un repartidor al inicio de la cola de repartidores
void pushRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorLibre){
    if(colaRepartidores->inicio == NULL){
    colaRepartidores->inicio = colaRepartidores->fin = repartidorLibre;
    }

    repartidorLibre->sig = colaRepartidores->inicio;
    colaRepartidores->inicio->ant = repartidorLibre;
    colaRepartidores->inicio = repartidorLibre;
    colaRepartidores->numeroRepartidoresEspera++;
    return;
}

//Elimina el �ltimo repartidor al final de la cola de repartidores//Regresando su direcci�n
Repartidor* popRepartidor(RepartidoresEspera *colaRepartidores){
    Repartidor *repartidorOcupado;

    if(colaRepartidores->inicio ==  NULL){
        printf("La cola de repartidores en espera ya esta vacia\n");
        return NULL;
    }

    if(colaRepartidores->inicio == colaRepartidores->fin){
        repartidorOcupado = colaRepartidores->inicio;
        colaRepartidores->numeroRepartidoresEspera--;
        colaRepartidores->inicio = colaRepartidores->fin = NULL;
        return repartidorOcupado;
    }

    repartidorOcupado = colaRepartidores->fin;
    colaRepartidores->fin->ant->sig = NULL;
    colaRepartidores->fin = colaRepartidores->fin->ant;
    repartidorOcupado->ant = NULL;
    return repartidorOcupado;
}

//Imprime la cola de repartidores
void imprimirRepartidoresEspera(RepartidoresEspera *colaRepartidores){
    Repartidor *r = colaRepartidores->fin;
    printf("------------------------------------------------\n");
    printf("             REPARTIDORES EN ESPERA\n");
    printf("------------------------------------------------\n");
    if(r == NULL){
        printf("La cola de repartidores esta vacia\n");
        return;
    }

    if(r == colaRepartidores->inicio){

        imprimirRepartidor(r);
        return;
    }else{
        while(r != NULL){
            imprimirRepartidor(r);
            r = r->ant;
            printf("------------------------------------------------\n");
        }
    }
    return;
}

void inicializarColaRepartidores(RepartidoresEspera *colaRepartidores){
    pushRepartidor(colaRepartidores, crearRepartidor("Ju�n P�rez", 2504));
    pushRepartidor(colaRepartidores, crearRepartidor("Pancracio Dom�nguez", 1302));
    pushRepartidor(colaRepartidores, crearRepartidor("Mar�a Aguilar", 1857));
    pushRepartidor(colaRepartidores, crearRepartidor("Garry Flores", 2491));
    pushRepartidor(colaRepartidores, crearRepartidor("Daniela Hern�ndez", 1504));
    return;
}
