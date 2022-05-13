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
    if (lista->inicio == NULL){
        printf("La lista de repartidores en transito esta vacia\n");
    } else if (lista->inicio == repartidor && lista->fin == repartidor){
        lista->inicio = lista->fin = NULL;
        lista->n--;
    } else if (lista->inicio == repartidor){
        lista->inicio->sig->ant = NULL;
        lista->inicio = lista->inicio->sig;
        repartidor->ant = repartidor->sig = NULL;
    } else if (lista->fin == repartidor){
        lista->fin->ant->sig = NULL;
        lista->fin = lista->fin->ant;
        repartidor->ant = repartidor->sig = NULL;
    } else {
    repartidor->ant->sig = repartidor->sig;
    repartidor->sig->ant = repartidor->ant;
    repartidor->ant = repartidor->sig = NULL;
    }
}

//FUNCIONES DE CARRITO---------------------------------------------------------
//CREAR NUEVO CARRITO
ListaCarrito* nuevoCarrito(void){
    ListaCarrito *c;
    c = malloc(sizeof(ListaCarrito));
    c->inicio = c->fin = NULL;
    c->cliente = NULL;
    return c;
}

//IMPRIMIR EL CARRITO
void imprimirCarrito(ListaCarrito *carrito){
    Producto *p;
    if(vacioCarrito(carrito)){
        printf("Su carrito esta vacio\n");
        return;
    }
    p = carrito->inicio;
    while(p!=NULL){
        imprimirProducto(p);
        p = p->sig;
    }
    printf("-------------------------\n");
    if(carrito->cliente != NULL){
        imprimirCliente(carrito->cliente);
    }
}

//VERIFICAR SI EL CARRITO ESTA VACIO
int vacioCarrito(ListaCarrito *carrito){
    return carrito->inicio == NULL;
}

//AGREGAR PRODUCTO AL CARRITO
void agregarProductoCarrito(ListaCarrito *carrito, char *nombre, float precio, int existencias){
    Producto *e = crearProducto(nombre, precio, existencias);
    if(vacioCarrito(carrito)){
        carrito->inicio = e;
        carrito->fin = e;
        return;
    }
    e->ant = carrito->fin;
    carrito->fin->sig = e;
    carrito->fin = e;
}

//AGREGAR DATOS DEL CLIENTE AL CARRITO
void agregarCliente(ListaCarrito *carrito, char *nombre, char *direccion, double telefono, float costo){
    Cliente *c = nuevoCliente(nombre, direccion, telefono, costo);
    carrito->cliente = c;
}
