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
    if(colaRepartidores->inicio == NULL){//Si la cola de repartidores está vacía
    colaRepartidores->inicio = colaRepartidores->fin = repartidorLibre;//El repartidor se agrega al inicio y al final de la cola
    }
    //Si la cola de repartidores no está vacía
    repartidorLibre->sig = colaRepartidores->inicio;//El nuevo repartidor en su campo siguiente tendrá al primer repartidor de la cola
    colaRepartidores->inicio->ant = repartidorLibre;//El repartidor al inicio de la cola en su campo anterior tendra al nuevo repartidor
    colaRepartidores->inicio = repartidorLibre;//El nuevo inicio de la cola tendrá la dirección del repartidor agregado
    colaRepartidores->numeroRepartidoresEspera++;//Se suma en uno el numero de repartidores en la cola
    return;
}

//Elimina el �ltimo repartidor al final de la cola de repartidores//Regresando su direcci�n
Repartidor* popRepartidor(RepartidoresEspera *colaRepartidores){
    Repartidor *repartidorOcupado;//Declaracion de un apuntador a repartidor

    if(colaRepartidores->inicio ==  NULL){//Si la cola de repartidores está vacía
        printf("La cola de repartidores en espera ya esta vacia\n");//Se imprime mensaje
        return NULL;//Se regresa una dirección nula
    }

    if(colaRepartidores->inicio == colaRepartidores->fin){//Si la cola de repartidores solo tiene un repartidor
        repartidorOcupado = colaRepartidores->inicio;//El repartidor a eliminar es el único repartidor en la cola
        colaRepartidores->numeroRepartidoresEspera--;//Se resta en 1 el número de repartidores en la cola
        colaRepartidores->inicio = colaRepartidores->fin = NULL;//El inicio y fin de la cola apuntan a tierra
        return repartidorOcupado;//Se regresa la dirección del repartidor eliminado
    }
    //Si hay mas de un repartidor en la cola
    repartidorOcupado = colaRepartidores->fin;//El repartidor a eliminar es el último en la cola
    colaRepartidores->fin->ant->sig = NULL;//El penultimo repartidor de la cola en su campo siguiente apunta a NULL
    colaRepartidores->fin = colaRepartidores->fin->ant;//El nuevo fin de la cola es el penultimo repartidor en esta
    repartidorOcupado->ant = NULL;//El repartidor eliminado en su campo anterior ahora apunta a NULL
    return repartidorOcupado;//Se regresa la dirección del repartidor eliminado
}

//Imprime la cola de repartidores
void imprimirRepartidoresEspera(RepartidoresEspera *colaRepartidores){
    Repartidor *r = colaRepartidores->fin;//Apuntador a repartidor tiene la dirección del último repartidor de la cola
    printf("------------------------------------------------\n");
    printf("             REPARTIDORES EN ESPERA\n");
    printf("------------------------------------------------\n");
    if(r == NULL){//Si la cola está vacía
        printf("La cola de repartidores esta vacia\n");
        return;
    }

    if(r == colaRepartidores->inicio){//Si la cola solo tiene un repartidor

        imprimirRepartidor(r);//Se imprime el repartidor
        return;
    }else{//Si la cola tiene más de un repartidor
        while(r != NULL){//Mientras el apuntador no apunte a tierra
            imprimirRepartidor(r);//Se imprime el repartidor
            r = r->ant;//El apuntador ahora apunta al repartidor que tiene en su campo anterior
            printf("------------------------------------------------\n");
        }
    }
    return;
}

//Inicialización de la cola de Repartidores
void inicializarColaRepartidores(RepartidoresEspera *colaRepartidores){
    pushRepartidor(colaRepartidores, crearRepartidor("Ju�n P�rez", 2504));//Se agregan 5 repartidores a la cola
    pushRepartidor(colaRepartidores, crearRepartidor("Pancracio Dom�nguez", 1302));//Con nombre y id
    pushRepartidor(colaRepartidores, crearRepartidor("Mar�a Aguilar", 1857));//Usando la función crearRepartidor
    pushRepartidor(colaRepartidores, crearRepartidor("Garry Flores", 2491));//en donde primer parametro es nombre
    pushRepartidor(colaRepartidores, crearRepartidor("Daniela Hern�ndez", 1504));//y el segundo es el id
    return;
}
