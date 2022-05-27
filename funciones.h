#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "listas.h"
#include "colas.h"

//funciones Cliente
char convertirMayus(char caracter);
void impresionNavegacion(void);
void seleccionProducto(Producto *p, ListaCarrito *carrito);
int navegacionProductos(ListaProductos *lista, ListaCarrito *carrito, int check);
int revisarCarrito(ListaCarrito *carrito, int check);
int realizarPedido(ListaProductos *lista, ListaCarrito *carrito, Pedidos *colaPedidos, int check);

//funciones Gerente
int asignarPedido(ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Pedidos *colaPedidos, int check);

//funciones Repartidor
void pedidoAsignado(Repartidor *repartidor);
int entregaPedido(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, int check);
Repartidor *pedirUsuario(RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores);

//funciones Almacenista
//void navegacionMenu-Usamos la misma funci�n del cliente, solo queremos navegar en la lista
void agregarProductos(ListaProductos *lista);
int verificarListaProductos(ListaProductos *lista, int check);

//funciones Producto
void grabarProducto(char *nombre, struct Producto p[]);
void recuperarProducto(char *archivo, struct Producto v[]);

#endif // FUNCIONES_H_INCLUDED

