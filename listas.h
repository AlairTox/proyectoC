#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "elemento.h"

typedef struct ListaProductos{
    //productos que se mostraran al almacenista
    Producto *inicio, *fin;
    int n;
}ListaProductos;

typedef struct ListaRepartidoresTransito{
    //La lista de repartidores que estan en camino
    Repartidor  *inicio, *fin;
    int n;
}ListaRepartidoresTransito;

typedef struct ListaCarrito{
    struct ListaCarrito *ant, *sig;
    Producto *inicio, *fin;
    int n;
    Cliente* cliente;
}ListaCarrito;


//Funciones ListaProductos
ListaProductos *nuevaListaProductos(void);
void imprimirListaProductos(ListaProductos *lista);
int vaciaListaProductos(ListaProductos *lista);
void agregarProducto(ListaProductos *lista, char *nombre, int precio, int existencias);

//Funciones ListaRepartidores
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void);
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void agregarRepartidor(ListaRepartidoresTransito *lista, char *nombre, int id);

//Funciones Carrito
ListaCarrito* nuevoCarrito(void);
void imprimirCarrito(ListaCarrito* carrito);
int vacioCarrito(ListaCarrito *carrito);
void agregarPedido(ListaCarrito *carrito, char *nombre, int precio, int existencias);
void agregarCliente(ListaCarrito *carrito, char *nombre, char *direccion, double telefono, int costo);

#endif // LISTAS_H_INCLUDED
