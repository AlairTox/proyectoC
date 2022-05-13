#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

#include "elemento.h"
#include "listas.h"

//COLA DE PEDIDOS
typedef struct Pedidos{
    int numeroPedidos;
    ListaCarrito *inicio, *fin;

}Pedidos;

//COLA DE REPARTIDORES
typedef struct RepartidoresEspera{
    Repartidor *inicio, *fin;
    int numeroRepartidoresEspera;
}RepartidoresEspera;

//Funciones Cola de Pedidos
Pedidos* crearColaPedidos(void);
void pushPedido(Pedidos *colaPedidos, ListaCarrito *carritoCliente);
ListaCarrito* popPedido(Pedidos *colaPedidos);
int vacioPedido(Pedidos *colaPedidos);
void imprimirColaPedidos(Pedidos *colaPedidos);

//Funciones Cola de Repartidores en Espera
RepartidoresEspera *crearColaRepartidores(void);
int vacioRepartidor(RepartidoresEspera *colaRepartidores);
void pushRepartidor(RepartidoresEspera *colaRepartidores, Repartidor *repartidorLibre);
Repartidor* popRepartidor(RepartidoresEspera *colaRepartidores);
void imprimirRepartidoresEspera(RepartidoresEspera *colaRepartidores);

#endif // COLAS_H_INCLUDED
