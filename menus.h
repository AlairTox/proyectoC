#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "listas.h"
#include "colas.h"
int menuInicial(void);
int menuCliente(ListaProductos *lista, ListaCarrito *carrito, int opcionCliente, Pedidos *colaPedidos);
void menuGerente(void);
void menuRepartidor(void);
void menuAlmacenista(void);

#endif // MENUS_H_INCLUDED
