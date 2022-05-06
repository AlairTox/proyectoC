#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "colas.h"

//Funciones Cola de pedidos
int vacioPedido(Pedidos *colaPedidos){
    //verificar que este vacio
    if(colaPedidos->tope == 1)
        return 1;
    return 0;
}

Pedidos* crearColaPedidos(int numeroPedidos){
    Pedidos* p;
    p = malloc(sizeof(Pedidos));
    p->tope = -1;
    p->numeroPedidos = numeroPedidos;
    p->Pedidos = malloc(sizeof(ListaProductos)*numeroPedidos);
}

void pushPedido(Pedidos *colaPedidos, ListaProductos *carritoCliente){
    //Añade el nuevo pedido al inicio de la cola
    if(colaPedidos->tope == (colaPedidos->numeroPedidos -1)){
        colaPedidos->numeroPedidos = colaPedidos->numeroPedidos + 5;
        colaPedidos->Pedidos = realloc(colaPedidos->Pedidos,colaPedidos->numeroPedidos*sizeof(Pedidos));
    }
    colaPedidos->tope++;
    for(int j = colaPedidos->numeroPedidos;j == 0;j--){//Verificar el funcionamiento de esta porqueria
        colaPedidos->Pedidos[j+1] = colaPedidos->Pedidos[j];
    }
    colaPedidos->Pedidos[0]  = *carritoCliente;
}

void popPedido(Pedidos *colaPedidos, ListaProductos* pedidoAsignado){
    //Elimina el pedido más antiguo una vez el pedido se asigna a un repartidor
    if(vacioPedido(colaPedidos)){
        printf("La cola de pedidos está vacía\n");
        return;
    } else {
        *pedidoAsignado = colaPedidos->Pedidos[colaPedidos->tope];
        colaPedidos->tope--;
    }
}

//Funciones Cola de Repartidores en Espera
int vacioRepartidor(RepartidoresEspera *colaRepartidores){
    if(colaRepartidores->tope == 1)
        return 1;
    return 0;
}

RepartidoresEspera *crearColaRepartidores(int numeroRepartidoresEspera){
    RepartidoresEspera *p;
    p = malloc(sizeof(RepartidoresEspera));
    p->tope = -1;
    p->numeroRepartidoresEspera = numeroRepartidoresEspera;
    p->RepartidoresEnEspera = malloc(sizeof(Repartidor)*numeroRepartidoresEspera);
    return p;
}


void pushRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorOcupado){
    if(colaRepartidores->tope == (colaRepartidores->numeroRepartidoresEspera - 1)){
        colaRepartidores->numeroRepartidoresEspera += 5;
        colaRepartidores->RepartidoresEnEspera = realloc(colaRepartidores->RepartidoresEnEspera, colaRepartidores->numeroRepartidoresEspera * sizeof(Repartidor));
    }
    colaRepartidores->tope++;
    for(int j = colaRepartidores->numeroRepartidoresEspera;j == 0;j--){
        colaRepartidores->RepartidoresEnEspera[j+1] = colaRepartidores->RepartidoresEnEspera[j];
    }
    colaRepartidores->RepartidoresEnEspera[0] = *repartidorOcupado;
}

void popRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorLibre){
    if(vacioRepartidor(colaRepartidores)){
        printf("La cola de reaprtidores en espera está vacía");
        return;
    } else {
        *repartidorLibre = colaRepartidores->RepartidoresEnEspera[colaRepartidores->tope];
        colaRepartidores->tope--;
        return;
    }
}
