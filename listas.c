#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
void imprimirListaProductos(ListaProductos *lista){
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
void agregarProducto(ListaProductos *lista, char *nombre, float precio, int existencias){
    Producto *e = crearProducto(nombre, precio, existencias);
    if(vaciaListaProductos(lista)){
        lista->inicio = e;
        lista->fin = e;
        return;
    }
    e->ant = lista->fin;
    lista->fin->sig = e;
    lista->fin = e;
    return;
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
        printf("-----------------\n");
        p = p->sig;
    }
    printf("\n");
    return;
}

//AÑADIR REPARTIDOR A LA LISTA DE REPARTIDORES EN TRANSITO
void agregarRepartidor(ListaRepartidoresTransito *lista, char *nombre, int id){
        Repartidor *r = crearRepartidor (nombre, id);
    if(vaciaListaRepartidoresTransito(lista)){
        lista->inicio = r;
        lista->fin = r;
        return;
    }
    r->ant = lista->fin;
    lista->fin->sig = r;
    lista->fin = r;
}

//ELIMINAR UN REPARTIDOR DE LA LISTA DE TRANSITO
void eliminarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor){
    if(lista->inicio == NULL){
        printf("La lista de repartidores en transito esta vacia\n");
        return;
    }
    if(lista->inicio == repartidor && lista->fin == repartidor){
        lista->inicio = lista->fin = NULL;
        lista->n--;
        return;
    }
    if(lista->inicio == repartidor){
        lista->inicio->sig->ant = NULL;
        lista->inicio = lista->inicio->sig;
        repartidor->ant = repartidor->sig = NULL;
        return;
    }
    if(lista->fin == repartidor){
        lista->fin->ant->sig = NULL;
        lista->fin = lista->fin->ant;
        repartidor->ant = repartidor->sig = NULL;
        return;
    }
    repartidor->ant->sig = repartidor->sig;
    repartidor->sig->ant = repartidor->ant;
    repartidor->ant = repartidor->sig = NULL;
    return;
}
