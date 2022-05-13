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
void agregarProducto(ListaProductos *lista, char *nombre, float precio, int existencias);

//Funciones ListaRepartidores
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void);
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void agregarRepartidor(ListaRepartidoresTransito *lista, char *nombre, int id);
void eliminarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor);

//Funciones Carrito
ListaCarrito* nuevoCarrito(void);
void imprimirCarrito(ListaCarrito* carrito);
int vacioCarrito(ListaCarrito *carrito);
void agregarProductoCarrito(ListaCarrito *carrito, char *nombre, float precio, int existencias);
void agregarCliente(ListaCarrito *carrito, char *nombre, char *direccion, double telefono, float costo);

#endif // LISTAS_H_INCLUDED
