#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "listas.h"
#include "colas.h"

int menuInicial(void);
int menuCliente(ListaProductos *lista, ListaCarrito *carrito, int opcionCliente, Pedidos *colaPedidos);
int menuGerente(Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores, int opcionGerente);
int menuRepartidor(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, int opcionRepartidor);
void menuAlmacenista(void);

#endif // MENUS_H_INCLUDED
