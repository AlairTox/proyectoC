#include "elemento.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//FUNCIONES PRODUCTO
//Creación de producto
Producto *crearProducto(char *nombre, float precio, int existencias){
    Producto *e;
    e = malloc(sizeof(Producto));
    e->ant = e->sig = NULL;
    e->info = malloc(sizeof(infoProducto));
    strcpy(e->info->nombre, nombre);
    e->info->existencias = existencias;
    e->info->precio = precio;
    return e;
}

//Impresión de producto
void imprimirProducto(Producto *e){
        printf("Producto: %s\n", e->info->nombre);
        printf("Existencias: %d\n", e->info->existencias);
        printf("Costo: %.2f\n", e->info->precio);
        return;
}

//FUNCIONES CLIENTE
//Creación del cliente
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

//Impresión del Cliente
void imprimirCliente(Cliente *c){
    printf("Nombre del Cliente: %s\n", c->nombre);
    printf("Direccion: %s\n", c->direccion);
    printf("Telefono: %.0f\n", c->telefono);
    printf("Precio a pagar: %.2f\n", c->costo);
    return;
}

//FUNCIONES REPARTIDOR
//Creación del repartidor
Repartidor *crearRepartidor (char *nombre, int id){
    Repartidor *e;
    e = malloc(sizeof(Producto));
    e->ant = e->sig = NULL;
    e->nombre = malloc(sizeof(char)*(strlen(nombre)));
    e->pedidoAsignado = NULL;
    strcpy(e->nombre, nombre);
    e->id = id;
    return e;
}

//Impresión del repartidor
void imprimirRepartidor(Repartidor *r){
    printf("Nombre del repartidor: %s\n", r->nombre);
    printf("ID: %d\n", r->id);
    return;
}

//FUNCIONES INFOPRODUCTO
//Inicialización de infoProducto
infoProducto *inicializarInfoProducto(){
    infoProducto *a;
    a = malloc(sizeof(infoProducto));
    a->existencias = 0;
    a->nombre[0] = 'a';
    a->precio = 0;
    return a;
}
