#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "listas.h"
#include "elemento.h"

//funciones Cliente
void impresionNavegacion(ListaProductos *lista);
void navegacionMenu(ListaProductos *lista);
void seleccionProducto(ListaProductos *lista);
void revisarCarrito();
void realizarPedido();
void eliminarProducto();

//funciones Gerente
void verPedidos();
void repartidoresEspera();
void repartidoresTransito();
void asignarPedido();

//funciones Repartidor
void pedidoAsignado();
void entregaPedido();

//funciones Almacenista
//void navegacionMenu-Usamos la misma función del cliente, solo queremos navegar en la lista
void agregarProductos(ListaProductos *lista);

#endif // FUNCIONES_H_INCLUDED