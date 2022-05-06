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
void listaProductos(); //siguiente (tal vez ya la hizo alair)
void agregarProductos();

#endif // FUNCIONES_H_INCLUDED