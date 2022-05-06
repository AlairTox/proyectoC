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

//Funciones ListaProductos
ListaProductos *nuevaListaProductos(void);
void imprimirListaProductos(ListaProductos *lista);
int vaciaListaProductos(ListaProductos *lista);
void agregarProducto(ListaProductos *lista, char *nombre, int precio, int existencias);

//Funciones ListaRepartidores
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void);
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista);
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito * lista);

#endif // LISTAS_H_INCLUDED
