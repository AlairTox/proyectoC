#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include "elemento.h"
#include "listas.h"

typedef struct Pedidos{//Pedidos hechos que el gerente asigna a los repartidores
    int numeroPedidos;
    ListaCarrito* Pedidos;
    int tope;

}Pedidos;

typedef struct RepartidoresEspera{//Repartidores que están esperando que se les asigne un pedido
    Repartidor* RepartidoresEnEspera;
    int numeroRepartidoresEspera;
    int tope;
}RepartidoresEspera;

//Funciones Cola de Pedidos
Pedidos* crearColaPedidos(int numeroPedidos);
void pushPedido(Pedidos *colaPedidos, ListaCarrito *carritoCliente);
void popPedido(Pedidos *colaPedidos, ListaCarrito *pedidoAsignado);
int vacioPedido(Pedidos *colaPedidos);
void imprimirColaPedidos(Pedidos *colaPedidos);

//Funciones Cola de Repartidores en Espera
RepartidoresEspera *crearColaRepartidores(int numeroRepartidoresEspera);
int vacioRepartidor(RepartidoresEspera *colaRepartidores);
void pushRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorOcupado);
void popRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorLibre);
void imprimirRepartidoresEspera(RepartidoresEspera *colaRepartidores);

#endif // PILAS_H_INCLUDED