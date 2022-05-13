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
        agregarProductoCarrito(carrito, p->nombre, p->precio, articulos);
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
}

int revisarCarrito(ListaCarrito *carrito){
    //permite navegar el carrito y eliminar productos de este
    char opc;
    Producto *p, *a;
    int check=0, opcEliminar, unidadesMenos;

    if(vacioCarrito(carrito)){
        printf("No hay ningun articulo en su carrito.\n");
        system("Pause");
        check=1;
        system("cls");
        return check;
    }else{
        p = carrito->inicio;
        a = carrito->inicio;
        float total=0;

        do{
            system("cls");
            impresionNavegacion();
            printf("Para eliminar un producto de su carrito, pulse -\n");
            printf("Para verificar su pago total, pulse T\n");
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

                case 'T': //calcular total
                    while(a!=NULL){
                        total = total + (a->precio * a->existencias);
                        a = a->sig;
                    }
                    printf("Su pago total actualmente es de: %.2f\n", total);
                    a = carrito->inicio;
                    total = 0;
                    system("Pause");
                    break;

                case 'X': //salir de este menu
                    check = 1;
                    system("cls");
                    break;

                case '-': //eliminar del carrito
                    printf("\n1 - Eliminar todo el producto \n2 - Reducir numero de existencias\n");
                    scanf("%d", &opcEliminar);
                    if(opcEliminar == 1){
                        eliminarProductoCarrito(p, carrito);
                        printf("Producto eliminado. \n");
                        system("Pause");
                        return check;
                    }else if(opcEliminar == 2){
                        printf("Ingrese cuantas unidades desea eliminar: \t");
                        scanf("%d", &unidadesMenos);
                        if(unidadesMenos > p->existencias){
                            printf("No puede eliminar tantas unidades.\n");
                            system("Pause");
                        }else if(unidadesMenos == p->existencias){
                            eliminarProductoCarrito(p, carrito);
                            printf("Producto eliminado. \n");
                            system("Pause");
                            return check;
                        }else{
                            p->existencias = p->existencias - unidadesMenos;
                        }
                    }else{
                        printf("Opcion incorrecta. Intente de nuevo.\n");
                        system("Pause");
                    }

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

int realizarPedido(ListaCarrito *carrito, Pedidos *colaPedidos){
    Producto *p = carrito->inicio;
    int check = 0;
    char nombre[MAX_CHAR], direccion[MAX_CHAR], opcPedido;
    double telefono;
    float pago=0;
    while(p!=NULL){
        pago = pago + (p->precio * p->existencias);
        p = p->sig;
    }
    printf("Este es su pedido final: \n");
    printf("***************************\n");
    imprimirCarrito(carrito);
    printf("\nPago total: %.2f\n\n", pago);
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
        system("cls");
        agregarCliente(carrito, nombre, direccion, telefono, pago);
        pushPedido(colaPedidos, carrito);
        printf("Su pedido se ha realizado exitosamente!\n");
        check = 1;
    }
    else if(opcPedido == 'N' || opcPedido == 'n'){
        printf("Se le regresara al menu principal para clientes.\n");
        check = 1;
        return check;
    }
    else{
        printf("Ingrese una opcion valida\n");
        return check;
    }
    return check;
}

//Funciones Gerente------------------------------------------------------------------------------------------------------------------
int asignarPedido(ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Pedidos *colaPedidos){
    int check = 0;
    char opc;
    Repartidor *repartidorOcupado;
    ListaCarrito *pedidoAsignado;
    printf("Repartidor con mas tiempo en la cola\n");
    imprimirRepartidor(colaRepartidores->fin);
    printf("Pedido con mas tiempo en la cola\n");
    if(colaPedidos->fin == NULL){
        printf("No hay ningun pedido\n");
        check = 1;
        return check;
    }else{
        imprimirCarrito(colaPedidos->fin);
        printf("Desesa asignar el pedido?[Y/N]\n");
        fflush(stdin);
        opc = getchar();
        fflush(stdin);
        if(opc == 'Y' || opc == 'y'){
            printf("leido :]");
            repartidorOcupado = popRepartidor(colaRepartidores); //aqui se rompe
            pedidoAsignado = popPedido(colaPedidos);
            repartidorOcupado->pedidoAsignado = pedidoAsignado;
            agregarRepartidor(listaRepartidores, repartidorOcupado->nombre, repartidorOcupado->id);
        }else if(opc == 'N' || opc == 'n'){
            printf("Se le regresara al menu principal para gerente.\n");
            check = 1;
            return check;
        }else{
            printf("Ingrese una opcion valida\n");
            return check;
        }
    }
    return check;
}

//Funciones Repartidor-----------------------------------------------------------------------------------------------------------------

void pedidoAsignado(Repartidor *repartidor){
    if(repartidor->pedidoAsignado == NULL){
        printf("Por el momento no tienes ningun pedido asignado\n");
        return;
    }else{
        printf("Hola %s, se te asigno este pedido:\n", repartidor->nombre);
        imprimirCarrito(repartidor->pedidoAsignado);
    }
}

int entregaPedido(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores){
    int opc, check = 0;
    printf("Hola %s, pulsa [Y] para confirmar la entrega del pedido, de lo contrario pulsa [N]",repartidor->nombre);
    fflush(stdin);
    opc = getchar();
    fflush(stdin);
    if(opc == 'Y' || opc == 'y'){
        eliminarRepartidor(lista, repartidor);
        pushRepartidor(colaRepartidores, repartidor);
        printf("Has regresado a la cola de repartidores, espera un nuevo pedido\n");
        check = 1;
    }
    else if(opc == 'N' || opc == 'n'){
        printf("Se le regresara al menu principal para repartidores.\n");
        check = 1;
        return check;
    }
    else{
        printf("Ingrese una opcion valida\n");
        return check;
    }
    return check;
}


//Funciones Almacenista--------------------------------------------------------------------------------------------------------------
void agregarProductos(ListaProductos *lista){
    char nombre[MAX_CHAR];
    int cantidad=0;
    float precio=0;
    Producto *p = lista->inicio;
    printf("Ingrese el nombre del producto:     ");
    fflush(stdin);
    gets(nombre);
    fflush(stdin);
    printf("Ingrese la cantidad a almacenar:    ");
    scanf("%d", &cantidad);
    printf("Ingrese el precio del producto:     ");
    scanf("%f", &precio);
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
