#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "listas.h"
#include "colas.h"

int menuInicial(int opcion);
int menuCliente(int opcionCliente, ListaProductos *lista, ListaCarrito *carrito, Pedidos *colaPedidos);
int menuGerente(int opcionGerente, Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores);
int menuRepartidor(int opcionRepartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, Repartidor *repartidor);
int menuAlmacenista(int opcionAlmacenista, ListaProductos *lista);

#endif // MENUS_H_INCLUDED
