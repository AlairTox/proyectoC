#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "listas.h"
#include "colas.h"

//funciones Cliente
void impresionNavegacion(void);
void seleccionProducto(Producto *p, ListaCarrito *carrito);
int navegacionProductos(ListaProductos *lista, ListaCarrito *Carrito);
void eliminarProductoCarrito(Producto *p);
int revisarCarrito(ListaCarrito *carrito);
void realizarPedido(ListaCarrito *carrito);

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

#endif // FUNCIONES_H_INCLUDED
