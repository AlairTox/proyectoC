#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "colas.h"

//Funciones Cola de pedidos
Pedidos* crearColaPedidos(){
    Pedidos* p;
    p = malloc(sizeof(Pedidos));
    p->inicio = p->fin = NULL;
    p->numeroPedidos = 0;
    return p;
}

void pushPedido(Pedidos *colaPedidos, ListaCarrito *carritoCliente){
    //Añade el nuevo pedido al inicio de la cola
    if(colaPedidos->inicio == NULL){
        colaPedidos->inicio = colaPedidos->fin = carritoCliente;
        imprimirCarrito(colaPedidos->inicio);
        printf("\n\n\n");
        return;
    }
    imprimirCarrito(carritoCliente);
    carritoCliente->sig = colaPedidos->inicio;
    colaPedidos->inicio->ant = carritoCliente;
    colaPedidos->inicio = carritoCliente;
    colaPedidos->numeroPedidos++;
}

ListaCarrito* popPedido(Pedidos *colaPedidos){
    //Elimina el pedido más antiguo una vez el pedido se asigna a un repartidor
    ListaCarrito *pedidoAsignado;
    if(colaPedidos->inicio == NULL){
        printf("La cola de pedidos está vacía\n");
        return NULL;
    }
    if(colaPedidos->inicio == colaPedidos->fin){
        pedidoAsignado = colaPedidos->inicio;
        colaPedidos->numeroPedidos--;
        colaPedidos->inicio = colaPedidos->fin = NULL;
    }
    pedidoAsignado = colaPedidos->fin;
    colaPedidos->fin->ant->sig = NULL;
    colaPedidos->fin = colaPedidos->fin->ant;
    pedidoAsignado->ant = NULL;
    return pedidoAsignado;
}

void imprimirColaPedidos(Pedidos *colaPedidos){
    printf("Entrada a imprimirColaPedidos");
    ListaCarrito *c = colaPedidos->fin;
    while(c->ant != NULL){
        imprimirCarrito(c);
        c = c->ant;
    }
    printf("Salida de imprimirColaPedidos\n");
    return;
}

//Funciones Cola de Repartidores en Espera

RepartidoresEspera *crearColaRepartidores(){
    RepartidoresEspera *p;
    p = malloc(sizeof(RepartidoresEspera));
    p->numeroRepartidoresEspera = 0;
    p->inicio = p->fin = NULL;
    return p;
}


void pushRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorLibre){
    if(colaRepartidores->inicio == NULL){
    colaRepartidores->inicio = colaRepartidores->fin = repartidorLibre;
    }
    repartidorLibre->sig = colaRepartidores->inicio;
    colaRepartidores->inicio->ant = repartidorLibre;
    colaRepartidores->inicio = repartidorLibre;
    colaRepartidores->numeroRepartidoresEspera++;
}

Repartidor* popRepartidor(RepartidoresEspera *colaRepartidores){
    Repartidor *repartidorOcupado;
    if(colaRepartidores->inicio ==  NULL){
        printf("La cola de repartidores en espera ya está vacía");
        return NULL;
    }
    repartidorOcupado = colaRepartidores->fin;
    colaRepartidores->fin->ant->sig = NULL;
    colaRepartidores->fin = colaRepartidores->fin->ant;
    repartidorOcupado->ant = NULL;
    return repartidorOcupado;
}

void imprimirRepartidoresEspera(RepartidoresEspera *colaRepartidores){
    Repartidor *r = colaRepartidores->fin;
    while(r->ant != NULL){
        imprimirRepartidor(r);
        r = r->ant;
    }
    return;
}
