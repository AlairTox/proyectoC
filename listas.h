#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "elemento.h"

//LISTA DE PRODUCTOS
typedef struct ListaProductos{
    Producto *inicio, *fin;
    int n;
}ListaProductos;

//lISTA DE REPARTIDORES
typedef struct ListaRepartidoresTransito{
    Repartidor  *inicio, *fin;
    int n;
}ListaRepartidoresTransito;

//LISTA CARRITO
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
void eliminarProductoCarrito(Producto *p, ListaCarrito *carrito);

//Funciones ListaRepartidores
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void);
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void agregarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor);
void eliminarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor);

//Funciones Carrito
ListaCarrito* nuevoCarrito(void);
void imprimirCarrito(ListaCarrito* carrito);
int vacioCarrito(ListaCarrito *carrito);
void agregarProductoCarrito(ListaCarrito *carrito, char *nombre, float precio, int existencias);
void agregarCliente(ListaCarrito *carrito, char *nombre, char *direccion, double telefono, float costo);

#endif // LISTAS_H_INCLUDED
