#include <stdlib.h>
#include <stdio.h>

#include "listas.h"
//FUNCIONES DE LA LISTA DE PRODUCTOS------------------------------
//CREAR LISTA DE PRODUCTOS
ListaProductos *nuevaListaProductos(void){
    ListaProductos *p;
    p = malloc(sizeof(ListaProductos));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

//VERIFICAR QUE LA LISTA DE PRODUCTOS ESTÁ VACÍA
int vaciaListaProductos(ListaProductos *lista){
    return lista->inicio == NULL;    
}

//IMPRIMIR LA LISTA DE PRODUCTOS
void imprimirListaProductos(ListaProductos * lista){
    Producto *p;
    if(vaciaListaProductos(lista)){
        printf("Lista vacia\n");
        return;
    }
    p = lista->inicio;
    while(p!=NULL){
        imprimirProducto(p);
        p = p->sig;
    }
    printf("-------------------------\n");
    return;
}

//AGREGAR UN PRODUCTO A LA LISTA DE PRODUCTOS
void agregarProducto(ListaProductos *lista, char *nombre, int precio, int existencias){
    Producto *e =crearProducto(nombre, precio, existencias);
    if(listaVacia(lista)){
        lista->inicio = e;
        lista->fin = e;
        return;
    }
    e->ant = lista->fin;
    lista->fin->sig = e;
    lista->fin = e;
}

//FUNCIONES DE LA LISTA DE REPARTIDORES---------------------------------------------------------
//CREAR LISTA DE REPARTIDORES
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void){
    ListaRepartidoresTransito  *p;
    p = malloc(sizeof(ListaRepartidoresTransito));
    p->inicio = p->fin = NULL;
    p->n=0;
    return p;
}

//VERIFICAR SI LA LISTA DE REPARTIDORES ESTÁ VACÍA
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista){
    return lista->inicio == NULL;    
}

//IMPRIME LISTA DE REPARTIDORES
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito * lista){
    Repartidor *p;
    if(vaciaListaRepartidoresTransito(lista)){
        printf("No hay repartidores en tránsito\n");
        return;
    }
    p = lista->inicio;
    while(p!=NULL){
        printf("Nombre: %s\n", p->nombre);
        printf("ID: %d\n", p->id);
        p = p->sig;
    }
    printf("\n");
    return;
}

//Funciones Carrito
Carrito* nuevoCarrito(void){
    Carrito *c;
    c = malloc(sizeof(Carrito));
    c->Carrito = c->cliente = NULL;
}

void imprimirCarrito(Carrito *carrito){
    imprimirListaProductos(carrito);
    imprimirCliente(carrito->cliente);  
}