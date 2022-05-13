#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "colas.h"

//FUNCIONES COLA DE PEDIDOS
//Creación de la cola de pedidos
Pedidos* crearColaPedidos(void){
    Pedidos* p;
    p = malloc(sizeof(Pedidos));
    p->numeroPedidos = 0;
    p->inicio = p->fin = NULL;
    return p;
}

//Añade un pedido al inicio de la cola de pedidos
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
}

//Elimina el pedido al final de la cola de pedidos, regresando su dirección
ListaCarrito* popPedido(Pedidos *colaPedidos){
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

//Imprime la cola de Pedidos
void imprimirColaPedidos(Pedidos *colaPedidos){
    ListaCarrito *c = colaPedidos->fin;
    if(c == NULL){
        printf("No hay ningun pedido\n");
        return;
    }
    while(c != NULL){
        printf("dentro del while\n");
        printf("************************\n");
        imprimirCarrito(c);
        if(c->ant == NULL){
                printf("anterior es nulo");
            return;
        }else{
            c = c->ant;
        }
    }
    printf("ya salimos\n");
}

//FUNCIONES COLA DE REPARTIDORES
//Creación de la cola de repartidores
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
}

//Elimina el último repartidor al final de la cola de repartidores//Regresando su dirección
Repartidor* popRepartidor(RepartidoresEspera *colaRepartidores){
    Repartidor *repartidorOcupado;
    if(colaRepartidores->inicio ==  NULL){
        printf("La cola de reaprtidores en espera ya esta vacia\n");
        return NULL;
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
    if(r == colaRepartidores->inicio)
        imprimirRepartidor(r);
    else{
        while(r != NULL){
            imprimirRepartidor(r);
            r = r->ant;
        }
    }
    return;
}
