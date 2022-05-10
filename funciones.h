#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "listas.h"
#include "colas.h"

//funciones Cliente
char convertirMayus(char caracter);
void impresionNavegacion(void);
void seleccionProducto(Producto *p, ListaCarrito *carrito);
int navegacionProductos(ListaProductos *lista, ListaCarrito *carrito);
void eliminarProductoCarrito(Producto *p, ListaCarrito *carrito);
int revisarCarrito(ListaCarrito *carrito);
void realizarPedido(ListaCarrito *carrito, Pedidos *colaPedidos);

//funciones Gerente
void verPedidos(Pedidos *colaPedidos);
void repartidoresEspera(RepartidoresEspera *colaRepartidores);
void repartidoresTransito();
void asignarPedido();

//funciones Repartidor
void pedidoAsignado();
void entregaPedido();

//funciones Almacenista
//void navegacionMenu-Usamos la misma función del cliente, solo queremos navegar en la lista
void agregarProductos(ListaProductos *lista);
//funciones Producto
void grabarProducto(char *nombre, struct Producto p[]);
void recuperarProducto(char *archivo, struct Producto v[]);
#endif // FUNCIONES_H_INCLUDED