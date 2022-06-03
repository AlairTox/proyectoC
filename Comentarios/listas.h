#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "elemento.h"

//LISTA DE PRODUCTOS
typedef struct ListaProductos{
    Producto *inicio, *fin;//Contiene dos apuntadores a estructura Producto
    int n;//Contiene un entero para indicar la cantidad de productos en la lista
}ListaProductos;

//lISTA DE REPARTIDORES
typedef struct ListaRepartidoresTransito{
    Repartidor  *inicio, *fin;//Contiene dos apuntadores a estructura Repartidor
    int n;//Contiene un entero para indicar la cantidad de repartidores en la lista
}ListaRepartidoresTransito;

//LISTA CARRITO
typedef struct ListaCarrito{
    struct ListaCarrito *ant, *sig;//Contiene dos apuntadores a estructura ListaCarrito(para viajar en la cola de pedidos)
    Producto *inicio, *fin;//Contiene dos apuntadores a estructura Producto
    int n;//Esto es lo mismo que los otros
    Cliente* cliente;//Contiene apuntador a estructura Cliente para guardar su información correspondiente
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
