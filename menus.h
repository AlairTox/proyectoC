#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "listas.h"
#include "colas.h"
int menuInicial(void);
int menuCliente(ListaProductos *lista, ListaCarrito *carrito, int opcionCliente, Pedidos *colaPedidos);
void menuGerente(Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores);
void menuRepartidor(ListaRepartidoresTransito *listaRepartidores,RepartidoresEspera *colaRepartidores,Repartidor *repartidor);
void menuAlmacenista(ListaProductos *lista);

#endif // MENUS_H_INCLUDED
