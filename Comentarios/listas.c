#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listas.h"

//FUNCIONES DE LA LISTA DE PRODUCTOS------------------------------
//Creaci�n de la lista de productos
ListaProductos *nuevaListaProductos(void){
    ListaProductos *p;//Declaración de apuntador a ListaProductos
    p = malloc(sizeof(ListaProductos));//Reserva de espacio para una estructura ListaProductos
    p->inicio = p->fin = NULL;//Inicialización de campos inicio y fin(NULL)
    p->n = 0;//Inicialización de número de productos en la lista
    return p;//Se regresa la dirección de la lista
}

//Verifica si la lista de productos est� vac�a
int vaciaListaProductos(ListaProductos *lista){
    return lista->inicio == NULL;//Se regresa un True o False dependiendo si la lista está vacía
}

//Imprime la lista de productos
void imprimirListaProductos(ListaProductos *lista){
    Producto *p;//Declaración de apuntador a un Producto

    if(vaciaListaProductos(lista)){//Si la lista está vacía
        printf("Lista vac�a\n");
        return;
    }

    p = lista->inicio;//Asignación del inicio de la lista al apuntador

    while(p != NULL){//Mientras el apuntador no apunte a tierra
        imprimirProducto(p);//Se imprime el Producto
        p = p->sig;//Ahora el apuntador apunta al producto siguiente
    }

    printf("-------------------------\n");
    return;
}

//Agrega productos a la lista de productos
void agregarProducto(ListaProductos *lista, char *nombre, float precio, int existencias){
    Producto *e = crearProducto(nombre, precio, existencias);//Creación de un producto

    if(vaciaListaProductos(lista)){//Si la lista está vacía
        lista->inicio = e;//El inicio de la lista será el nuevo producto
        lista->fin = e;//El fin de la lista será el nuevo producto
        lista->n = 1;//El numero de productos en la lista es 1
        return;
    }

    e->ant = lista->fin;//El nuevo producto en su campo anterior apunta al final de la lista
    lista->fin->sig = e;//El producto final de la lista en su campo siguiente apunta al nuevo Porducto
    lista->fin = e;//El nuevo final de la lista es el nuevo producto
    lista->n += 1;//Se aumenta en uno el numero de productos de la lista
    return;
}

//FUNCIONES DE LA LISTA DE REPARTIDORES---------------------------------------------------------
//Creaci�n de la lista de repartidores
ListaRepartidoresTransito *nuevaListaRepartidoresTransito(void){
    ListaRepartidoresTransito  *p;//Declaración de apuntador a una listaRepartidoresTransito
    p = malloc(sizeof(ListaRepartidoresTransito));//Reserva de espacio para una estructura ListaRepartidoresTransito
    p->inicio = p->fin = NULL;//Inicialización de los campos inicio y fin(NULL)
    p->n = 0;//Inicialización del número de repartidores en la lista
    return p;//Se regresa la dirección de la lista
}

//Verifica si la lista de repartidores est� vac�a
int vaciaListaRepartidoresTransito(ListaRepartidoresTransito *lista){
    return lista->inicio == NULL;//Se regresa True o False dependiendo de si la lista está vacía
}

//Impresi�n de la lista de repartidores
void imprimirListaRepartidoresTransito(ListaRepartidoresTransito * lista){
    Repartidor *p;//Delaración de apuntador a repartidor
    printf("------------------------------------------------\n");
    printf("           REPARTIDORES EN TR�NSITO\n");
    printf("------------------------------------------------\n");
    if(vaciaListaRepartidoresTransito(lista)){//Si la lista de repartidores está vacía
        printf("No hay repartidores en tr�nsito\n");
        return;
    }

    p = lista->inicio;//El apuntador apunta al inicio de la lista

    while(p != NULL){//Mientras el apuntador no apunte a tierra
        printf("Nombre: %s\n", p->nombre);//Impresion del nombre del repartidor
        printf("ID: %d\n", p->id);//Impresion del id del repartidor
        p = p->sig;//El apuntador ahora apunta al siguiente 
        printf("------------------------------------------------\n");
    }

    printf("\n");
    return;
}

//Agrega un repartidor a la lista de repartidores
void agregarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor){
    Repartidor *r = crearRepartidor (repartidor->nombre, repartidor->id);//Creación de repartidor
    r->pedidoAsignado = repartidor->pedidoAsignado;//Asignación de pedido al repartidor

    if(vaciaListaRepartidoresTransito(lista)){//Si la lista está vacía
        lista->inicio = r;//El inicio y fin de la lista apuntara al nuevo repartidor
        lista->fin = r;
        return;
    }

    r->ant = lista->fin;//El nuevo repartidor en su campo anterior apunta al fin de la lista
    lista->fin->sig = r;//El repartidor en el fin de la lista en su campo siguiente apunta al nuevo repartidor
    lista->fin = r;//El nuevo fin de la lista es el nuevo repartidor
}

//Elimina un repartidor de la lista de repartidores
void eliminarRepartidor(ListaRepartidoresTransito *lista, Repartidor *repartidor){
    if (lista->inicio == NULL){//Si la lista está vacía
        printf("La lista de repartidores en tr�nsito esta vac�a\n");
    } else if (lista->inicio == repartidor && lista->fin == repartidor){//Si la lista tiene un solo repartidor
        lista->inicio = lista->fin = NULL;//El inicio y fin de la lista apuntan a tierra
        lista->n--;//Se resta 1 al número de repartidores en al lista
    } else if (lista->inicio == repartidor){//si el repartidor a eliminar está al inicio de la lista
        lista->inicio->sig->ant = NULL;//El segundo repartidor de la lista en su campo anterior ahora apunta a tierra
        lista->inicio = lista->inicio->sig;//El nuevo inicio de la lista es el segundo repartidor en esta
        repartidor->ant = repartidor->sig = NULL;//el repartidor eliminado se desliga de la lista(campos inicio y fin a NULL)
    } else if (lista->fin == repartidor){//Si el repartidor a eliminar está en el fin de la lista
        lista->fin->ant->sig = NULL;//El penultimo repartidor de la lista en su campo siguiente ahora apunta a NULL
        lista->fin = lista->fin->ant;//El nuevo final de la lista es el penultimo en esta
        repartidor->ant = repartidor->sig = NULL;//Se desliga el repartidor de la lista
    } else {//Si el repartidor a eliminar está en medio de la lista
    repartidor->ant->sig = repartidor->sig;//El repartidor anterior en su campo siguiente ahora apuntara al repartidor siguiente 
    repartidor->sig->ant = repartidor->ant;//El repartidor siguiente en su campo anterior ahora apuntara al repartidor anterior
    repartidor->ant = repartidor->sig = NULL;//Se desliga el repartidor a eliminar de  la lista
    }
    return;
}

//FUNCIONES DE CARRITO---------------------------------------------------------
//Creaci�n de carrito
ListaCarrito* nuevoCarrito(void){
    ListaCarrito *c;//Declaración de apuntador a una ListaCarrito
    c = malloc(sizeof(ListaCarrito));//Reserva de espacio para una estrcutura ListaCarrito
    c->inicio = c->fin = NULL;//Inicialización de campos inicio y fin(NULL)
    c->cliente = NULL;//Inicialización del campo cliente(NULLL)
    return c;//Regreso de la dirección de la lista
}

//Impresi�n del carrito
void imprimirCarrito(ListaCarrito *carrito){
    Producto *p;//Declaración de apuntador a Porducto

    if(vacioCarrito(carrito)){//Si el carrito no tiene ningún producto
        printf("Su carrito esta vac�o\n");
        return;
    }

    p = carrito->inicio;//El apuntador apunta al inicio del carrito

    while(p!=NULL){//Mientras el apuntador no apunte a tierra
        imprimirProducto(p);//Se imprime el Producto 
        p = p->sig;//Ahora el apuntador apunta al producto siguiente
    }


    if(carrito->cliente != NULL){//Si el carrito en su campo cliente no apunta a NULL
        printf("------------------------------------------------\n");
        printf("              INFORMACI�N DEL CLIENTE\n");
        imprimirCliente(carrito->cliente);//Se imprime la información del cliente
    }

    return;
}

//Verifica si el carrito est� vac�o
int vacioCarrito(ListaCarrito *carrito){
    return carrito->inicio == NULL;//Regresa un True o False dependiendo de si la lista está vacía
}

//Agrega un producto al carrito
void agregarProductoCarrito(ListaCarrito *carrito, char *nombre, float precio, int existencias){
    Producto *e = crearProducto(nombre, precio, existencias);//Creación de un producto

    if(vacioCarrito(carrito)){//Si el carrito está vacío
        carrito->inicio = e;//El inicio y fin de la lista apuntaran al nuevo producto
        carrito->fin = e;
        return;
    }

    e->ant = carrito->fin;//El nuevo producto en su campo anterior apunta al fin de la lista
    carrito->fin->sig = e;//El fin de la lista en su campo siguiente apunta al nuevo producto
    carrito->fin = e;//El nuevo fin de la lista ahora es el nuevo producto
    return;
}

//Agrega los datos del cliente al carrito
void agregarCliente(ListaCarrito *carrito, char *nombre, char *direccion, double telefono, float costo){
    Cliente *c = nuevoCliente(nombre, direccion, telefono, costo);//Creación de cliente
    carrito->cliente = c;//Asignación del cliente a la lista en su campo cliente
}

//Elimina un producto del carrito
void eliminarProductoCarrito(Producto *p, ListaCarrito *carrito){
    if(carrito->inicio == carrito->fin){//Si la lista solo tiene un producto
        carrito->inicio = carrito->fin = NULL;//El inicio y fin de la lista ahora apuntan a NULL
    }
    else if(p == carrito->inicio){//Si el producto está al inicio de la lista
        carrito->inicio = carrito->inicio->sig;//El nuevo inicio de la lista ahora es el segundo producto de la lista
        carrito->inicio->ant = NULL;//El inicio de la lista en su campo anterior apunta a NULL
        p->sig = NULL;//El producto eliminado en su campo siguiente apunta a tierra
    }
    else if(p == carrito->fin){//Si el producto está en el final de la lista
        carrito->fin = carrito->fin->ant;//El nuevo final de la lista es el penultimo producto de esta
        carrito->fin->sig = NULL;//El final de la lista en su campo siguiente apunta a NULL
        p->ant = NULL;//El producto eliminado en su campo anterior apunta a tierra
    }
    else{//Si el producto está en medio de la lista
        p->ant->sig = p->sig;//El producto anterior en su campo siguiente ahora apunta al producto siguiente
        p->sig->ant = p->ant;//El producto siguiente en su campo siguiente ahora apunta al producto anterior
        p->sig = p->ant = NULL;//El producto eliminado se desliga de la lista(siguiente y fin apuntan a NULL)
    }
    return;
}
