#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listas.h"

//FUNCIONES DE LA LISTA DE PRODUCTOS------------------------------
//Creación de la lista de productos
ListaProductos *nuevaListaProductos(void){
    ListaProductos *p;
    p = malloc(sizeof(ListaProductos));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

//Verficia si la lista de productos está vacía
int vaciaListaProductos(ListaProductos *lista){
    return lista->inicio == NULL;
}

//Imprime la lista de productos
void imprimirListaProductos(ListaProductos *lista){
    Producto *p;

    if(vaciaListaProductos(lista)){
        printf("Lista vacía\n");
        return;
    }

    p = lista->inicio;

    while(p != NULL){
        imprimirProducto(p);
        p = p->sig;
    }

    printf("-------------------------\n");
    return;
}

//Agrega productos a la lista de productos
void agregarProducto(ListaProductos *lista, char *nombre, float precio, int existencias){
    Producto *e = crearProducto(nombre, precio, existencias);

    if(vaciaListaProductos(lista)){
        lista->inicio = e;
        lista->fin = e;
        lista->n = 1;
        return;
    }

    e->ant = lista->fin;
    lista->fin->sig = e;
    lista->fin = e;
    lista->n += 1;
    return;
}

//FUNCIONES DE LA LISTA DE REPARTIDORES---------------------------------------------------------
//Creación de la lista de repartidores
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void){
    ListaRepartidoresTransito  *p;
    p = malloc(sizeof(ListaRepartidoresTransito));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

//Verifica si la lista de repartidores está vacía
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista){
    return lista->inicio == NULL;
}

//Impresión de la lista de repartidores
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito * lista){
    Repartidor *p;
    printf("------------------------------------------------\n");
    printf("           REPARTIDORES EN TRÁNSITO\n");
    printf("------------------------------------------------\n");
    if(vaciaListaRepartidoresTransito(lista)){
        printf("No hay repartidores en tránsito\n");
        return;
    }

    p = lista->inicio;

    while(p != NULL){
        printf("Nombre: %s\n", p->nombre);
        printf("ID: %d\n", p->id);
        p = p->sig;
        printf("------------------------------------------------\n");
    }

    printf("\n");
    return;
}

//Agrega un repartidor a la lista de repartidores
void agregarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor){
    Repartidor *r = crearRepartidor (repartidor->nombre, repartidor->id);
    r->pedidoAsignado = repartidor->pedidoAsignado;

    if(vaciaListaRepartidoresTransito(lista)){
        lista->inicio = r;
        lista->fin = r;
        return;
    }

    r->ant = lista->fin;
    lista->fin->sig = r;
    lista->fin = r;
}

//Elimina un repartidor de la lista de repartidores
void eliminarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor){
    if (lista->inicio == NULL){
        printf("La lista de repartidores en tránsito esta vacía\n");
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
    return;
}

//FUNCIONES DE CARRITO---------------------------------------------------------
//Creación de carrito
ListaCarrito* nuevoCarrito(void){
    ListaCarrito *c;
    c = malloc(sizeof(ListaCarrito));
    c->inicio = c->fin = NULL;
    c->cliente = NULL;
    return c;
}

//Impresión del carrito
void imprimirCarrito(ListaCarrito *carrito){
    Producto *p;

    if(vacioCarrito(carrito)){
        printf("Su carrito esta vacío\n");
        return;
    }

    p = carrito->inicio;

    while(p!=NULL){
        imprimirProducto(p);
        p = p->sig;
    }


    if(carrito->cliente != NULL){
        printf("------------------------------------------------\n");
        printf("              INFORMACIÓN DEL CLIENTE\n");
        imprimirCliente(carrito->cliente);
    }

    return;
}

//Verifica si el carrito está vacío
int vacioCarrito(ListaCarrito *carrito){
    return carrito->inicio == NULL;
}

//Agrega un producto al carrito
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
    return;
}

//Agrega los datos del cliente al carrito
void agregarCliente(ListaCarrito *carrito, char *nombre, char *direccion, double telefono, float costo){
    Cliente *c = nuevoCliente(nombre, direccion, telefono, costo);
    carrito->cliente = c;
}

//Elimina un producto del carrito
void eliminarProductoCarrito(Producto *p, ListaCarrito *carrito){
    if(carrito->inicio == carrito->fin){
        carrito->inicio = carrito->fin = NULL;
    }
    else if(p == carrito->inicio){
        carrito->inicio = carrito->inicio->sig;
        carrito->inicio->ant = NULL;
        p->sig = NULL;
    }
    else if(p == carrito->fin){
        carrito->fin = carrito->fin->ant;
        carrito->fin->sig = NULL;
        p->ant = NULL;
    }
    else{
        p->ant->sig = p->sig;
        p->sig->ant = p->ant;
        p->sig = p->ant = NULL;
    }
    return;
}
