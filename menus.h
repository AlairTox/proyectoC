#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "listas.h"
#include "colas.h"

int menuInicial(char opc);
int menuCliente(int opcionCliente, ListaProductos *lista, Pedidos *colaPedidos);
int menuGerente(int opcionGerente, Pedidos *colaPedidos, RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores);
int menuRepartidor(int opcionRepartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores);
int menuAlmacenista(int opcionAlmacenista, ListaProductos *lista);

#endif // MENUS_H_INCLUDED
