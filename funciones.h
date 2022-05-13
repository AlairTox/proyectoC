#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "listas.h"
#include "colas.h"

//funciones Cliente
char convertirMayus(char caracter);
void impresionNavegacion(void);
void seleccionProducto(Producto *p, ListaCarrito *carrito);
int navegacionProductos(ListaProductos *lista, ListaCarrito *carrito);
int revisarCarrito(ListaCarrito *carrito);
int realizarPedido(ListaCarrito *carrito, Pedidos *colaPedidos);

//funciones Gerente
int asignarPedido(ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Pedidos *colaPedidos);

//funciones Repartidor
void pedidoAsignado(Repartidor *repartidor);
int entregaPedido(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, int check);

//funciones Almacenista
//void navegacionMenu-Usamos la misma función del cliente, solo queremos navegar en la lista
void agregarProductos(ListaProductos *lista);
int verificarListaProductos(ListaProductos *lista, int check);

//funciones Producto
void grabarProducto(char *nombre, struct Producto p[]);
void recuperarProducto(char *archivo, struct Producto v[]);

#endif // FUNCIONES_H_INCLUDED
