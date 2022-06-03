#include "elemento.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//FUNCIONES PRODUCTO
//Creaci�n de producto
Producto *crearProducto(char *nombre, float precio, int existencias){
    Producto *e;//Declaración de apuntador a producto
    e = malloc(sizeof(Producto));//Reserva de memoria para una estructura Producto
    e->ant = e->sig = NULL;//Inicialización de los campos anterior y siguiente(Apuntan a NULL)
    e->info = malloc(sizeof(infoProducto));//Reserva de memoria para una estructura infoProducto en el campo info
    strcpy(e->info->nombre, nombre);//Asignacion de nombre del producto en el campo info en el campo nombre
    e->info->existencias = existencias;//Asignacion de número de existencias en el campo info en el campo existencias
    e->info->precio = precio;//Asignación de precio en el campo info en el campo precio
    return e;//Se regresa la dirección del producto
}

//Impresi�n de producto
void imprimirProducto(Producto *e){
        printf("Producto: %s\n", e->info->nombre);//Impresión del nombre del producto
        printf("Existencias: %d\n", e->info->existencias);//Impresión de las existencias del producto
        printf("Costo: %.2f\n", e->info->precio);//Impresión del precio del producto
        return;
}

//FUNCIONES CLIENTE
//Creaci�n del cliente
Cliente *nuevoCliente(char *nombre, char *direccion, double telefono, float costo){
    Cliente* c;//Declaracion de apuntador a Cliente
    c = malloc(sizeof(Cliente));//Reserva de espacio para una estructura de tipo Cliente
    c->costo = costo;//Asignación del precio a pagar 
    c->telefono = telefono;//Asignación del telefono del cliente
    c->nombre = malloc(sizeof(char)*(strlen(nombre)));//Reserva de espacio para el nombre del cliente
    strcpy(c->nombre, nombre);//Asignación del nombre del cliente
    c->direccion = malloc(sizeof(char)*(strlen(direccion)));//Reserva de espacio para la dirección del cliente
    strcpy(c->direccion, direccion);//Asingación de la dirección del cliente
    return c;//Se regresa la dirección del cliente
}

//Impresi�n del Cliente
void imprimirCliente(Cliente *c){
    printf("Nombre del Cliente: %s\n", c->nombre);//Impresión del nombre del cliente
    printf("Direccion: %s\n", c->direccion);//Impresión de la dirección del cliente
    printf("Telefono: %.0f\n", c->telefono);//Impresión del telefono del cliente
    printf("Precio a pagar: %.2f\n", c->costo);//Impresión del precio a pagar
    return;
}

//FUNCIONES REPARTIDOR
//Creaci�n del repartidor
Repartidor *crearRepartidor (char *nombre, int id){
    Repartidor *e;//Declaración de apuntador a repartidor
    e = malloc(sizeof(Producto));//Reserva de espacio de una estructura Repartidor
    e->ant = e->sig = NULL;//Inicialización de campos anterior y siguiente(NULL)
    e->nombre = malloc(sizeof(char)*(strlen(nombre)));//Reserva de espacio para el nombre del repartidor
    e->pedidoAsignado = NULL;//Inicialización de campo pedidoAsignado(NULL)
    strcpy(e->nombre, nombre);//Asignación de nombre del repartidor
    e->id = id;//Asignación del id del cliente
    return e;//Se regresa la dirección del Repartidor
}

//Impresi�n del repartidor
void imprimirRepartidor(Repartidor *r){
    printf("Nombre del repartidor: %s\n", r->nombre);//Impresión del nombre del repartidor
    printf("ID: %d\n", r->id);//Impresión de id del repartidor
    return;
}

//FUNCIONES INFOPRODUCTO
//Inicializaci�n de infoProducto
infoProducto *inicializarInfoProducto(){
    infoProducto *a;//Declaración de apuntador a infoProducto
    a = malloc(sizeof(infoProducto));//Reserva de espacio para una estructura InfoProducto
    a->existencias = 0;//Inicialización de existencias
    a->nombre[0] = 'a';//Inicialización de nombre
    a->precio = 0;//Inicilización de precio
    return a;//Se regresa la dirección de infoProducto
}
