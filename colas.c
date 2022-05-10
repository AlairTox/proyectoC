#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "colas.h"

//Funciones Cola de pedidos
int vacioPedido(Pedidos *colaPedidos){
    //verificar que este vacio
    if(colaPedidos->inicio == NULL)
        return 1;
    return 0;
}

Pedidos* crearColaPedidos(int numeroPedidos){
    Pedidos* p;
    p = malloc(sizeof(Pedidos));
    p->inicio = p->fin = NULL;
    p->numeroPedidos = numeroPedidos;
    return p;
}

void pushPedido(Pedidos *colaPedidos, ListaCarrito *carritoCliente){//FUNCION TERMINADA
    //Añade el nuevo pedido al inicio de la cola
    printf("Impresion Entrada(AntesIF)pushPedido\n");
    if(colaPedidos->inicio == NULL){
        printf("Impresion dentro de IF pushPedido\n");
        colaPedidos->inicio = colaPedidos->fin = carritoCliente;
        printf("Impresion de pedido dentro de colaPedidos\n");
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

void popPedido(Pedidos *colaPedidos, ListaCarrito* pedidoAsignado){
    //Elimina el pedido más antiguo una vez el pedido se asigna a un repartidor
    if(vacioPedido(colaPedidos)){
        printf("La cola de pedidos está vacía\n");
        return;
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
}

void imprimirColaPedidos(Pedidos *colaPedidos){
    ListaCarrito *c = colaPedidos->inicio;
    while(c != NULL){
        printf("Impresion de entrada al ciclo imprimirColaPedidos\n");
          imprimirCarrito(c);
          c = c->sig;
          }
    return;
}

//Funciones Cola de Repartidores en Espera
int vacioRepartidor(RepartidoresEspera *colaRepartidores){
    if(colaRepartidores->inicio == NULL)
        return 1;
    return 0;
}

RepartidoresEspera *crearColaRepartidores(int numeroRepartidoresEspera){
    RepartidoresEspera *p;
    p = malloc(sizeof(RepartidoresEspera));
    p->numeroRepartidoresEspera = numeroRepartidoresEspera;
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

void popRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorOcupado){
    if(colaRepartidores->inicio ==  NULL){
        printf("La cola de reaprtidores en espera ya está vacía");
        return;
    }
    repartidorOcupado = colaRepartidores->fin;
    colaRepartidores->fin->ant->sig = NULL;
    colaRepartidores->fin = colaRepartidores->fin->ant;
    repartidorOcupado->ant = NULL;
}

void imprimirRepartidoresEspera(RepartidoresEspera *colaRepartidores){
    Repartidor *r = colaRepartidores->inicio;
    while(r != NULL){
        imprimirRepartidor(r);
        r = r->sig;
    }
}
