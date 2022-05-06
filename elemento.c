#include "elemento.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

//Funciones Producto
Producto *crearProducto(char *nombre, int precio, int existencias){
    Producto *e;
    e = malloc(sizeof(Producto));
    e->ant = e->sig = NULL;
    strcpy(nombre, e->nombre);
    e->existencias = existencias;
    e->precio = precio;
    return e;
}

void imprimirProducto(Producto *e){
        printf("Producto: %s\n", e->nombre);
        printf("Existencias: %d\n", e->existencias);
        printf("Costo: %d\n", e->precio);
}

//Funciones Cliente
Cliente *nuevoCliente(char *nombre, char *direccion, int telefono, int costo){
    Cliente* c;
    c = malloc(sizeof(Cliente));
    c->costo = costo;
    c->telefono = telefono;
    strcpy(nombre, c->nombre);
    strcpy(direccion, c->direccion);
}

void imprimirCliente(Cliente *c){
    printf("Nombre del Cliente: %s\n", c->nombre);
    printf("Direccion: %s\n", c->direccion);
    printf("Telefono: %d\n", c->telefono);
    printf("Precio a pagar: %d\n", c->costo);
}

//Funciones Repartidor
Repartidor *crearRepartidor (char *nombre, int id){
    Repartidor *e;
    e= malloc(sizeof(Producto));
    e->ant=e->sig=NULL;
    strcpy(nombre, e->nombre);
    e->id=id;
    return e;
}

void imprimirRepartidor(Repartidor *r){
    printf("Nombre del repartidor: %s\n", r->nombre);
    printf("ID: %d\n", r->id);
}