#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "listas.h"
#include "colas.h"
#define MAX_CHAR 100

//FUNCIONES CLIENTE------------------------------------------------------------------------------------------------------------------------
//Conversión de caracteres de minúculas a mayúsculas
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

//Impresión de la navegación entre productos
void impresionNavegacion(void){
    printf("Para ver el siguiente producto, pulse D\n");
    printf("Para ver el producto anterior, pulse A\n");
    printf("Para ver el primer producto, pulse W\n");
    printf("Para ver el ultimo producto, pulse S\n");
    printf("Para salir del menu, pulse X\n");
}

//Selección de cantidad de producto a agregar al carrito
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

//Navegación de la lista de productos, se puede acceder a la función para agregar productos al carrito
int navegacionProductos(ListaProductos *lista, ListaCarrito *carrito, int check){
    char opc;
    Producto *p;
    check = 0;

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

//Navegación por el carrito, permite elimnar prodctos de este total o parcialmente
int revisarCarrito(ListaCarrito *carrito, int check){
    char opc;
    Producto *p, *a;
    int opcEliminar, unidadesMenos;
    check = 0;

    if(vacioCarrito(carrito)){
        printf("No hay ningun articulo en su carrito.\n");
        system("Pause");
        check = 1;
        system("cls");
        return check;
    }else{
        p = carrito->inicio;
        a = carrito->inicio;
        float total = 0;

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

                case 'T': //calculo del precio total a pagar
                    while(a != NULL){
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

//Recoleccion de datos del cliente para finalizar el pedido, se hace push a la cola de pedidos
int realizarPedido(ListaCarrito *carrito, Pedidos *colaPedidos, int check){
    Producto *p = carrito->inicio;
    check = 0;
    char nombre[MAX_CHAR], direccion[MAX_CHAR], opcPedido;
    double telefono;
    float pago = 0;
    while(p != NULL){
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

//FUNCIONES GERENTE------------------------------------------------------------------------------------------------------------------
//Se muestra el pedido y repartidor con mas tiempo de espera para decidir si se le asigna el pedido, se hace pop a ambas colas y se
//añade al repartidor a la lista de repartidores
int asignarPedido(ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Pedidos *colaPedidos, int check){
    check = 0;
    char opc;
    Repartidor *repartidorOcupado;
    ListaCarrito *pedidoAsignado;
    printf("Repartidor con mas tiempo en la cola\n");
    if(colaRepartidores->fin != NULL){
        imprimirRepartidor(colaRepartidores->fin);
    }else{
        printf("No hay repartidores en la cola\n");
    }
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
            printf("Pedido Asignado\n");
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

//FUNCIONES REPARTIDOR-----------------------------------------------------------------------------------------------------------------
//Se muestra el pedido asignado al repartidor
void pedidoAsignado(Repartidor *repartidor){
    if(repartidor->pedidoAsignado == NULL){
        printf("Por el momento no tienes ningun pedido asignado\n");
    }else{
        printf("Hola %s, se te asigno este pedido:\n", repartidor->nombre);
        imprimirCarrito(repartidor->pedidoAsignado);
    }
}

//Se le pregunta al repartidor si el pedido se ha entregado, en caso afirmativo se le regresa a la cola de pedidos
int entregaPedido(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, int check){
    check = 0;
    int opc;
    printf("Hola %s, pulsa [Y] para confirmar la entrega del pedido, de lo contrario pulsa [N]", repartidor->nombre);
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


//FUNCIONES ALMACENISTA--------------------------------------------------------------------------------------------------------------
//Se agrega un producto en cantidad o en su totalidad a la lista de productos
void agregarProductos(ListaProductos *lista){
    char nombre[MAX_CHAR];
    int cantidad = 0;
    float precio = 0;
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
        if(strcmpi(nombre, p->nombre)){
            p->precio = precio;
            p->existencias += cantidad;
            return;
        }
        p = p->sig;
    }
    agregarProducto(lista, nombre, precio, cantidad);
    return;
}

//Navegación de productos para el almacenista
int verificarListaProductos(ListaProductos *lista, int check){
    check = 0;
    char opc;
    Producto *p;

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

                default:
                    printf("Opcion incorrecta. Intente de nuevo.\n");
                    system("Pause");
                    break;
                }
            }while(!check);
        }
        return check;
}

