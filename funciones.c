#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "listas.h"
#include "colas.h"
#define MAX_CHAR 100

//FUNCIONES CLIENTE
char convertirMayus(char caracter){
    if (isalpha(caracter)){
        if(caracter>=97 && caracter<=122){
            caracter-=32;
            return caracter;
        }else
            return caracter;
    }else
        return caracter;
}

void impresionNavegacion(void){
    printf("Para ver el siguiente producto, pulse D\n");
    printf("Para ver el producto anterior, pulse A\n");
    printf("Para ver el primer producto, pulse W\n");
    printf("Para ver el ultimo producto, pulse S\n");
    printf("Para salir del menu, pulse X\n");
}

void seleccionProducto(Producto *p, ListaCarrito *carrito){
    int articulos;
    printf("Cuantos articulos desea anadir a su carrito? \t");
    scanf("%d", &articulos);
    if(articulos > p->existencias){
        printf("No puede pedir tantos articulos\n");
    }else{
        //p->existencias = (p->existencias - articulos);
        agregarPedido(carrito, p->nombre, p->precio, articulos);
        printf("El producto ha sido agregado al carrito.\n");
    }
}

int navegacionProductos(ListaProductos *lista, ListaCarrito *carrito){
    //Permite moverse a lo largo del menu de productos y añadir al carrito
    char opc;
    Producto *p;
    int check=0;

    if(vaciaListaProductos(lista)){
        printf("No hay ningun articulo disponible.\n");
        system("Pause");
        check = 1;
        system("cls");
        return check;
    }else{
        p = lista->inicio;
        do{
            system("cls");
            impresionNavegacion();
            printf("Para agregar un producto a su carrito, pulse +\n");
            imprimirProducto(p);
            fflush(stdin);
            opc = getchar();
            fflush(stdin);
            opc = convertirMayus(opc);
            switch(opc){
                case 'D': //ir al siguiente
                    if(p == lista->fin){
                        p = lista->inicio;
                        break;
                    }
                    p = p->sig;
                    break;

                case 'A': //ir al anterior
                    if(p == lista->inicio){
                        p = lista->fin;
                        break;
                    }
                    p = p->ant;
                    break;

                case 'W': //ir al inicio
                    if(p == lista->inicio){
                        printf("\nYa se encuentra en el primer elemento de la lista\n");
                        system("Pause");
                        break;
                    }
                    p = lista->inicio;
                    break;

                case 'S': //ir al final
                    if(p == lista->fin){
                        printf("\nYa se encuentra en el ultimo elemento de la lista\n");
                        system("Pause");
                        break;
                    }
                    p = lista->fin;
                    break;

                case 'X': //salir de este menu
                    check = 1;
                    system("cls");
                    break;

                case '+': //añadir al carro
                    seleccionProducto(p, carrito);
                    system("Pause");
                    break;

                default:
                    printf("Opcion incorrecta. Intente de nuevo.\n");
                    system("Pause");
                    break;
                }
            }while(!check);
        }
        return check;
    }

/*void eliminarProductoCarrito(Producto *p){
    //pendiente: que funcione bien esto
    Producto *nodoBorrado = p;
    p->ant->sig = p->sig;
    p->sig->ant = p->ant;
    p->sig = p->ant = NULL;
}*/

int revisarCarrito(ListaCarrito *carrito){
    //permite navegar el carrito y eliminar productos de este
    char opc;
    Producto *p;
    int check=0;

    if(vacioCarrito(carrito)){
        printf("No hay ningun articulo en su carrito.\n");
        system("Pause");
        check=1;
        system("cls");
        return check;
    }else{
        p = carrito->inicio;
        do{
            system("cls");
            impresionNavegacion();
            printf("Para eliminar un producto de su carrito, pulse -\n");
            imprimirProducto(p);
            fflush(stdin);
            opc = getchar();
            fflush(stdin);
            opc = convertirMayus(opc);
            switch(opc){
                case 'D': //ir al siguiente
                    if(p == carrito->fin){
                        p = carrito->inicio;
                        break;
                    }
                    p = p->sig;
                    break;

                case 'A': //ir al anterior
                    if(p == carrito->inicio){
                        p = carrito->fin;
                        break;
                    }
                    p = p->ant;
                    break;

                case 'W': //ir al inicio
                    if(p == carrito->inicio){
                        printf("\nYa se encuentra en el primer elemento de su carrito\n");
                        system("Pause");
                        break;
                    }
                    p = carrito->inicio;
                    break;

                case 'S': //ir al final
                    if(p == carrito->fin){
                        printf("\nYa se encuentra en el ultimo elemento de su carrito\n");
                        system("Pause");
                        break;
                    }
                    p = carrito->fin;
                    break;

                case 'X': //salir de este menu
                    check = 1;
                    system("cls");
                    break;

                case '-': //eliminar del carrito
                    //eliminarProductoCarrito(p);
                    printf("Producto eliminado\n");
                    system("Pause");
                    break;

                default:
                    printf("Opcion incorrecta. Intente de nuevo.\n");
                    system("Pause");
                    break;
                }
            }while(!check);
        }
    return check;
    }

void realizarPedido(ListaCarrito *carrito, Pedidos *colaPedidos){
    //Producto *p = carrito->inicio;
    char nombre[MAX_CHAR], direccion[MAX_CHAR], opcPedido;
    double telefono;
    //float pago;
    //pendiente: obtener el total de pago
    printf("Este es su pedido final: \n");
    printf("***************************\n");
    imprimirCarrito(carrito);
    printf("Desea finalizar su pedido? [Y/N] \n");
    fflush(stdin);
    opcPedido = getchar();
    fflush(stdin);
    if(opcPedido == 'Y' || opcPedido == 'y'){
        printf("Ingrese su nombre completo:\t");
        fflush(stdin);
        gets(nombre);
        fflush(stdin);
        printf("Ingrese su direccion:\t");
        fflush(stdin);
        gets(direccion);
        fflush(stdin);
        printf("Ingrese su telefono:\t");
        scanf("%lf", &telefono);
        agregarCliente(carrito, nombre, direccion, telefono, 200);
        pushPedido(colaPedidos, carrito);
        //printf("Debe pagar: %.2f pesos\n", pago);
        printf("\nSu pedido se ha realizado exitosamente\n");
    }
    else if(opcPedido == 'N' || opcPedido == 'n'){
        printf("Se le regresara al menu principal para clientes.\n");
        system("Pause");
        return;
    }
    else{
        printf("Opcion incorrecta. \n");
        system("Pause");
    }
}

//Funciones Gerente------------------------------------------------------------------------------------------------------------------
void verPedidos(Pedidos *colaPedidos){
    imprimirColaPedidos(colaPedidos);
}

void repartidoresEspera(RepartidoresEspera *colaRepartidores){
    imprimirRepartidoresEspera(colaRepartidores);
}

//Funciones Almacenista--------------------------------------------------------------------------------------------------------------
void agregarProductos(ListaProductos *lista){
    char nombre[MAX_CHAR];
    int cantidad=0;
    int precio=0;
    Producto *p = lista->inicio;
    printf("Ingrese el nombre del producto:     ");
    fflush(stdin);
    gets(nombre);
    fflush(stdin);
    printf("Ingrese la cantidad a almacenar:    ");
    scanf("%d", &cantidad);
    printf("Ingrese el precio del producto:     ");
    scanf("%d", &precio);
    while(vaciaListaProductos(lista)){
        if(strcmpi (nombre, p->nombre)){
            p->precio = precio;
            p->existencias += cantidad;
            return;
        }
        p = p->sig;
    }
    agregarProducto(lista, nombre, precio, cantidad);
    return;
}
//
void pedidoAsignado(){

}
//FUNCIONES Producto
void grabarProducto(char *archivo, struct Producto p[])
    {
        FILE *file;
        file = fopen(archivo, "wt");

        if (file == NULL)
        {
            printf("No se puede abrir el archivo: [%s]\n", archivo);
            exit(-1);
        }
        for(int k=0; k<21;k++) {
            fwrite(&p[k], sizeof(struct Producto), 1, file);
        }


        fclose(file);
        printf("Archivo generado exitosamente!\n");
    }

void recuperarProducto(char *archivo, struct Producto v[])
{
    FILE *file;
    file = fopen(archivo, "r");

    if (file == NULL)
    {
        printf("No existe el archivo: \n");
        exit(-2);
    }

    for (int k = 0; k < 21; k++)
    {
        fread(&v[k], sizeof(struct Producto), 21, file);
    }
    fclose(file);
}
