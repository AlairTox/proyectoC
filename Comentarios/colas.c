#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "colas.h"

//FUNCIONES COLA DE PEDIDOS
//Creacion de la cola de pedidos
Pedidos* crearColaPedidos(void){//Función que regresa la direccion a una cola de pedidos, no recibe parametros
    Pedidos* p;//Declaración de existencia de apuntador a una cola de pedidos
    p = malloc(sizeof(Pedidos));//Reserva de espacio en memoria para una cola de pedidos
    p->numeroPedidos = 0;//Se asigna un 0 al numero de pedidos al iniciarla
    p->inicio = p->fin = NULL;//El inicio y el fin de la cola apuntan a NULL
    return p;//retorno de la dirección de la cola de pedidos
}

//Añade un pedido al inicio de la cola de pedidos
void pushPedido(Pedidos *colaPedidos, ListaCarrito *carritoCliente){//Agrega un pedido(Carrito) a la cola de pedidos(inicio), recibe la direccion del carrito y de la cola
    if(colaPedidos->inicio == NULL){//Si la cola de pedidos en su campo inicio apunta a NULL, la dirección del carrito se asigna al inicio y fin de la cola
        colaPedidos->inicio = colaPedidos->fin = carritoCliente;//Ligado del carrito a la cola(inicio y fin)
        return;
    }

    imprimirCarrito(carritoCliente);//Impresion del carrito agregado a la cola
    carritoCliente->sig = colaPedidos->inicio;//Ligado del carrito(campo sig) al inicio de la cola de pedidos
    colaPedidos->inicio->ant = carritoCliente;//ligado de la cola(campo inicio que es un carrito, en su campo ant) al carrito inicio
    colaPedidos->inicio = carritoCliente;//El nuevo inicio de la cola es el carrito
    colaPedidos->numeroPedidos++;//Se incrementa el numero de pedidos
    return;
}

//Elimina el pedido al final de la cola de pedidos, regresando su direccion
ListaCarrito* popPedido(Pedidos *colaPedidos){//Devuelve la direccion de un carrito eliminado de la cola de pedidos, la cual recibe por parametro
    ListaCarrito *pedidoAsignado;//Declaración de apuntador a carrito(se usara para retornar la dirección del pedido eliminado)

    if(colaPedidos->inicio == NULL){//Si la cola de pedidos esta vacia no hay nada que eliminar
        printf("La cola de pedidos esta vacia\n");
        return NULL;
    }

    if(colaPedidos->inicio == colaPedidos->fin){//Si solo hay un pedido en la cola
        pedidoAsignado = colaPedidos->inicio;//Se asigna la direccion del carrito al inicio de la cola al apuntador declarado anteriormente
        colaPedidos->numeroPedidos--;//Se resta uno al numero de pedidos
        colaPedidos->inicio = colaPedidos->fin = NULL;//El inicio y fin de la cola apuntan a NULL
        return pedidoAsignado;
    }
    //Si hay mas de un pedido en la cola
    pedidoAsignado = colaPedidos->fin;//Se asigna la direccion del carrito al final de la cola al apuntador declarado anteriormente
    colaPedidos->fin->ant->sig = NULL;//El penultimo pedido de la cola en su campo siguiente apunta a NULL, ahora sera ek fin de la cola
    colaPedidos->fin = colaPedidos->fin->ant;//El penultimo pedido de la cola ahora es el fin
    pedidoAsignado->ant = NULL;//Se desliga el pedido retirado de la cola
    return pedidoAsignado;//Retorno de la direccion del pedido que fue eliminado de la cola
}

//Imprime la cola de Pedidos
void imprimirColaPedidos(Pedidos *colaPedidos){//Impresion de la cola de pedidos
    ListaCarrito *c = colaPedidos->fin;//Declaracion de un carrito, se le asigna la direccion del fin de la cola de pedidos

    if(c == NULL){//Si la cola de pedidos esta vacia
        printf("La cola de pedidos esta vacia\n");
        return;
    }

    if(c == colaPedidos->inicio){//Si la cola de pedidos solo tiene un pedidos
        imprimirCarrito(c);
        return;
    }

    for(int k = 0; k <= colaPedidos->numeroPedidos; k++){//Si la cola de pedidos tiene mas de un pedido, se repite hasta que ya no haya pedidos
        printf("\n");
        imprimirCarrito(c);//Impresion del carrito//La primera impresion es el pedido con mas tiempo en la cola
        printf("------------------------------------------------\n");
        printf("------------------------------------------------\n");
        c = c->ant;//Se avanza en la cola de pedidos
    }
    return;
}

//FUNCIONES COLA DE REPARTIDORES
//Creaci�n de la cola de repartidores
RepartidoresEspera *crearColaRepartidores(void){//Retorna una direccion de cola de repartidores en espera, no recibe parametros
    RepartidoresEspera *p;//Apuntador a cola de repartidores
    p = malloc(sizeof(RepartidoresEspera));//Reserva de espacio en memoria para una cola de repartidores
    p->numeroRepartidoresEspera = 0;//Se inicia con un numerdo de repartidores en 0
    p->inicio = p->fin = NULL;//Los apuntadores inicio y fin originalmente apuntan a NULL
    return p;//Se retorna la direccion de la cola de repartidores
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
