#include "elemento.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Funciones Producto
Producto *crearProducto(char *nombre, float precio, int existencias){
    Producto *e;
    e = malloc(sizeof(Producto));
    e->ant = e->sig = NULL;
    e->nombre = malloc(sizeof(char)*(strlen(nombre)));
    strcpy(e->nombre, nombre);
    e->existencias = existencias;
    e->precio = precio;
    return e;
}

void imprimirProducto(Producto *e){
        printf("Producto: %s\n", e->nombre);
        printf("Existencias: %d\n", e->existencias);
        printf("Costo: %.2f\n", e->precio);
}

//Funciones Cliente
Cliente *nuevoCliente(char *nombre, char *direccion, double telefono, float costo){
    Cliente* c;
    c = malloc(sizeof(Cliente));
    c->costo = costo;
    c->telefono = telefono;
    c->nombre = malloc(sizeof(char)*(strlen(nombre)));
    strcpy(c->nombre, nombre);
    c->direccion = malloc(sizeof(char)*(strlen(direccion)));
    strcpy(c->direccion, direccion);
    return c;
}

void imprimirCliente(Cliente *c){
    printf("Nombre del Cliente: %s\n", c->nombre);
    printf("Direccion: %s\n", c->direccion);
    printf("Telefono: %.0f\n", c->telefono);
    printf("Precio a pagar: %.2f\n", c->costo);
}

//Funciones Repartidor
Repartidor *crearRepartidor (char *nombre, int id){
    Repartidor *e;
    e= malloc(sizeof(Producto));
    e->ant=e->sig=NULL;
    e->nombre = malloc(sizeof(char)*(strlen(nombre)));
    strcpy(e->nombre, nombre);
    e->id=id;
    return e;
}

void imprimirRepartidor(Repartidor *r){
    printf("Nombre del repartidor: %s\n", r->nombre);
    printf("ID: %d\n", r->id);
}
