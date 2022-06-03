#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "listas.h"
#include "colas.h"
#define MAX_CHAR 100

//FUNCIONES CLIENTE------------------------------------------------------------------------------------------------------------------------
//Conversi�n de caracteres de min�culas a may�sculas
char convertirMayus(char caracter){
    if (isalpha(caracter)){//Determina si el caracter ingresado pertenece al abecedario
        if(caracter>=97 && caracter<=122){//Si el caracter es minúscula se convierte en mayúscula
            caracter-=32;
            return caracter;
        }else
            return caracter;
    }else
        return caracter;
}

//Impresi�n de la navegaci�n entre productos
void impresionNavegacion(void){
    printf("------------------------------------------------\n");
    printf("                    NAVEGACI�N\n");
    printf("------------------------------------------------\n");
    printf("Para ver el siguiente producto, pulse D\n");
    printf("Para ver el producto anterior, pulse A\n");
    printf("Para ver el primer producto, pulse W\n");
    printf("Para ver el �ltimo producto, pulse S\n");
    printf("Para salir del men�, pulse X\n");
    printf("------------------------------------------------\n");
    return;
}

//Selecci�n de cantidad de producto a agregar al carrito
void seleccionProducto(Producto *p, ListaCarrito *carrito){
    int articulos;

    printf("�Cu�ntos art�culos desea agregar a su carrito? \t");
    scanf("%d", &articulos);//Se pregunta cuantos articulos se van a agregar al carrito

    if(articulos > p->info->existencias){//Si el número de articulos pedidos son mayores a las existencias
        printf("No puede pedir tantos art�culos. Intente de nuevo.\n");
    }else{
        agregarProductoCarrito(carrito, p->info->nombre, p->info->precio, articulos);//Se agrega el respectivo producto al carrito
        printf("El producto ha sido agregado al carrito.\n");
    }
    return;
}

//Navegaci�n de la lista de productos, se puede acceder a la funci�n para agregar productos al carrito
int navegacionProductos(ListaProductos *lista, ListaCarrito *carrito, int check){
    char opc;
    Producto *p;
    check = 0;

    if(vaciaListaProductos(lista)){//Si la lista de productos está vacía
        printf("No hay ning�n art�culo disponible.\n");
        system("Pause");
        check = 1;
        system("cls");
        return check;
    }else{//Si la lista de productos no está vacía
        p = lista->inicio;
        do{
            system("cls");
            impresionNavegacion();//Se imprime las posibles navegaciones que se puede realizar
            printf("Para agregar un producto a su carrito, pulse +\n");
            printf("------------------------------------------------\n");
            printf("                    CAT�LOGO\n");
            imprimirProducto(p);//Se imprime el producto actual
            printf("------------------------------------------------\n");
            fflush(stdin);
            opc = getchar();//Se obtiene la opción deseada
            fflush(stdin);
            opc = convertirMayus(opc);//Se convierte a mayus en caso de ser necesario
            switch(opc){//Esto no lo voy a explicar más por que pss ahí dice
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
                        printf("\nYa se encuentra en el �ltimo elemento de la lista\n");
                        system("Pause");
                        break;
                    }
                    p = lista->fin;
                    break;

                case 'X': //salir de este menu
                    check = 1;
                    system("cls");
                    break;

                case '+': //a�adir al carro
                    seleccionProducto(p, carrito);
                    system("Pause");
                    break;

                default:
                    printf("Opci�n incorrecta. Intente de nuevo.\n");
                    system("Pause");
                break;
            }
        }while(!check);
    }
    return check;
}

//Navegaci�n por el carrito, permite elimnar prodctos de este total o parcialmente
int revisarCarrito(ListaCarrito *carrito, int check){
    char opc;
    Producto *p, *a;
    int opcEliminar, unidadesMenos;
    check = 0;

    if(vacioCarrito(carrito)){
        printf("------------------------------------------------\n");
        printf("                   SU CARRITO\n");
        printf("No hay ning�n art�culo en su carrito.\n");
        printf("------------------------------------------------\n");
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
            printf("------------------------------------------------\n");
            printf("                   SU CARRITO\n");
            imprimirProducto(p);
            printf("------------------------------------------------\n");
            fflush(stdin);
            opc = getchar();//Se obtiene la opción deseada
            fflush(stdin);
            opc = convertirMayus(opc);//Se convierte en mayus en caso de ser necesario
            switch(opc){//xd
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
                        printf("\nYa se encuentra en el �ltimo elemento de su carrito\n");
                        system("Pause");
                        break;
                    }
                    p = carrito->fin;
                    break;

                case 'T': //calculo del precio total a pagar
                    while(a != NULL){
                        total = total + (a->info->precio * a->info->existencias);
                        a = a->sig;
                    }
                    printf("Su pago total actualmente es de: $ %.2f\n", total);
                    a = carrito->inicio;
                    total = 0;
                    system("Pause");
                    break;

                case 'X': //salir de este menu
                    check = 1;
                    system("cls");
                    break;

                case '-': //eliminar del carrito
                    printf("------------------------------------------------\n");
                    printf("              ELIMINAR DEL CARRITO\n");
                    printf("------------------------------------------------\n");
                    printf("Presione [1] Eliminar todo el producto \nPresione [2] Reducir n�mero de existencias\n");
                    scanf("%d", &opcEliminar);

                    if(opcEliminar == 1){
                        eliminarProductoCarrito(p, carrito);//Se elimina todo el producto como dice justo arriba
                        printf("Producto eliminado. \n");
                        system("Pause");
                        return check;
                    }else if(opcEliminar == 2){//Si desea eliminar solo cierta cantidad de producto
                        printf("Ingrese cu�ntas unidades desea eliminar: \t");
                        scanf("%d", &unidadesMenos);

                        if(unidadesMenos > p->info->existencias){//Si desea eliminar más existencias de las que hay en el carrito
                            printf("�Error! No puede eliminar tantas unidades. Intente de nuevo.\n");
                            system("Pause");
                        }else if(unidadesMenos == p->info->existencias){//Si quiere eliminar la misma cantidad de producto como de existencia que hay en el carrito
                            eliminarProductoCarrito(p, carrito);
                            printf("Producto eliminado. \n");
                            system("Pause");
                            return check;
                        }else{
                            p->info->existencias = p->info->existencias - unidadesMenos;//Se restan las unidades de las existencias en el carrito
                        }
                    }else{
                        printf("Opci�n incorrecta. Intente de nuevo.\n");
                        system("Pause");
                    }

                    break;

                default:
                    printf("Opci�n incorrecta. Intente de nuevo.\n");
                    system("Pause");
                break;
            }

        }while(!check);
    }
    return check;
}

//Recoleccion de datos del cliente para finalizar el pedido, se hace push a la cola de pedidos
int realizarPedido(ListaProductos *lista, ListaCarrito *carrito, Pedidos *colaPedidos, int check){
    Producto *p = carrito->inicio;
    Producto *a = lista->inicio;
    check = 0;
    char nombre[MAX_CHAR], direccion[MAX_CHAR], opcPedido;
    double telefono;
    float pago = 0;

    while(p != NULL){//Mientras que no se llegue al final del carrito
        pago = pago + (p->info->precio * p->info->existencias);//Se va aumentando el precio a pagar 
        p = p->sig;//Se avanza al siguiente producto
    }

    printf("------------------------------------------------\n");
    printf("                RESUMEN DEL PEDIDO\n");
    printf("------------------------------------------------\n");
    printf("                    SU CARRITO\n\n");
    imprimirCarrito(carrito);
    printf("------------------------------------------------\n");
    printf("Total del pedido: %.2f\n", pago);
    printf("�Desea finalizar su pedido? [Y/N]\n");
    printf("------------------------------------------------\n");
    fflush(stdin);
    opcPedido = getchar();
    fflush(stdin);

    if(opcPedido == 'Y' || opcPedido == 'y'){//Si desea hacer el pedido
        p = carrito->inicio;
        while(a != NULL){//Mientras no se llegue al final de la lista de productos
            if(strcmp(a->info->nombre, p->info->nombre) == 0){//Si el nombre del carrito y lista de productos coinciden
                a->info->existencias = (a->info->existencias) - (p->info->existencias);//Se restan las existencias de la lista de productos
                if(p!=carrito->fin)//Se avanza en el carrito
                    p = p->sig;
            }
            a = a->sig;//Se avanza en la lista de productos
        }
        printf("------------------------------------------------\n");//Se le pide la información al cliente
        printf("              INFORMACI�N DE ENV�O\n");
        printf("------------------------------------------------\n");
        printf("Ingrese su nombre completo:\t");
        fflush(stdin);
        gets(nombre);
        fflush(stdin);
        printf("Ingrese su direcci�n:\t");
        fflush(stdin);
        gets(direccion);
        fflush(stdin);
        printf("Ingrese su tel�fono:\t");
        scanf("%lf", &telefono);
        system("cls");
        agregarCliente(carrito, nombre, direccion, telefono, pago);//Se agrega el cliente al carrito
        pushPedido(colaPedidos, carrito);//Se añade el carrito a la cola de pedidos 
        printf("------------------------------------------------\n");
        printf("�Su pedido se ha realizado exitosamente!\n");
        printf("------------------------------------------------\n");
        check = 1;
    } else if (opcPedido == 'N' || opcPedido == 'n'){//Si no desea finalizar el pedido
        printf("Se le regresar� al men� principal para clientes.\n");
        printf("Carrito desechado\n");
        check = 1;
        return check;
    } else{
        printf("Ingrese una opci�n v�lida.\n");
        return check;
    }
    return check;
}

//FUNCIONES GERENTE------------------------------------------------------------------------------------------------------------------
//Se muestra el pedido y repartidor con mas tiempo de espera para decidir si se le asigna el pedido, se hace pop a ambas colas y se
//a�ade al repartidor a la lista de repartidores
int asignarPedido(ListaRepartidoresTransito *listaRepartidores, RepartidoresEspera *colaRepartidores, Pedidos *colaPedidos, int check){
    check = 0;
    char opc;
    printf("------------------------------------------------\n");
    printf("             ASIGNACI�N DE UN PEDIDO\n");
    printf("------------------------------------------------\n");
    Repartidor *repartidorOcupado;
    ListaCarrito *pedidoAsignado;
    printf("Repartidor con m�s tiempo en la cola:\n");

    if(colaRepartidores->fin != NULL){//Si la cola de repartidores no está vacía
        imprimirRepartidor(colaRepartidores->fin);//Se imprime el último repartidor en la cola
    }else{
        printf("No hay repartidores en la cola\n");
    }

    printf("\nPedido con m�s tiempo en la cola:\n");
    if(colaPedidos->fin == NULL){//Si la cola de pedidos está vacía
        printf("No hay ning�n pedido\n");
        check = 1;
        return check;
    } else{
        imprimirCarrito(colaPedidos->fin);//Se imprime el último pedido de la cola de pedidos
        printf("�Desea asignar el pedido?[Y/N]\t");
        fflush(stdin);
        opc = getchar();
        fflush(stdin);

        if(opc == 'Y' || opc == 'y'){//Si desea asignar el pedido
            printf("Pedido Asignado\n");
            repartidorOcupado = popRepartidor(colaRepartidores);//Se elimina el último repartidor de la cola
            pedidoAsignado = popPedido(colaPedidos);//Se elimina el último pedido de la cola
            repartidorOcupado->pedidoAsignado = pedidoAsignado;//se le asigna el pedido al repartidor
            agregarRepartidor(listaRepartidores, repartidorOcupado);//Se asigna el repartidor a la lista
        } else if(opc == 'N' || opc == 'n'){//Si no desea asignar el pedido
            printf("Se le regresar� al men� principal para gerente.\n");
            check = 1;
            return check;
        } else{
            printf("Ingrese una opci�n valida\n");
            return check;
        }
    }
    return check;
}

//FUNCIONES REPARTIDOR-----------------------------------------------------------------------------------------------------------------
//Se muestra el pedido asignado al repartidor
void pedidoAsignado(Repartidor *repartidor){
    if(repartidor->pedidoAsignado == NULL){//Si no tiene un pedido asignado
        printf("Por el momento no tiene ning�n pedido asignado.\n");
    } else{
        printf("Hola %s, se le asign� este pedido:\n", repartidor->nombre);
        imprimirCarrito(repartidor->pedidoAsignado);//Se imprime el pedido asignado
    }
    return;
}

//Se le pregunta al repartidor si el pedido se ha entregado, en caso afirmativo se le regresa a la cola de pedidos
int entregaPedido(Repartidor *repartidor, ListaRepartidoresTransito *lista, RepartidoresEspera *colaRepartidores, int check){
    check = 0;
    int opc;
    printf("Hola %s, pulse [Y] para confirmar la entrega del pedido, de lo contrario pulse [N]\n", repartidor->nombre);
    fflush(stdin);
    opc = getchar();
    fflush(stdin);

    if(opc == 'Y' || opc == 'y'){//Si ya entregó el pedido
        eliminarRepartidor(lista, repartidor);//Se elimina el repartidor de la lista
        repartidor->pedidoAsignado = NULL;//Se desliga el pedido del repartidor
        pushRepartidor(colaRepartidores, repartidor);//Se regresa el repartidor a la cola
        printf("------------------------------------------------\n");
        printf("               �PEDIDO FINALIZADO!\n");
        printf("------------------------------------------------\n");
        printf("Ha regresado a la cola de repartidores, espere un nuevo pedido\n");
        check = 1;
    } else if(opc == 'N' || opc == 'n'){//Si aún no entrega el pedido
        printf("Se le regresara al men� principal para repartidores.\n");
        check = 1;
        return check;
    } else{
        printf("Ingrese una opci�n v�lida\n");
        return check;
    }
    return check;
}

Repartidor *pedirUsuario(RepartidoresEspera *colaRepartidores, ListaRepartidoresTransito *listaRepartidores){
    Repartidor *r = colaRepartidores->fin;
    int id = 0;
    printf("---------------------(^._.^)---------------------\n");
    printf("                El Huarache Veloz\n\n\n");
    printf("-------------------------------------------------\n");
    printf("                  INCIAR SESI�N\n");
    printf("-------------------------------------------------\n");
    printf("Ingrese su ID: \t");
    scanf("%d", &id);//Se obtiene el id del repartidor

    do{//Busqueda en la cola
        if(r->id == id){//Si el repartidor está en la cola
            printf("Bienvenid@ %s\n", r->nombre);
            return r;//Se regresa la dirección del repartidor
        }
        r = r->ant;
    }while(r != NULL);

    r = listaRepartidores->inicio;

    if(listaRepartidores->inicio == NULL){//Si la lista está vacía
        return NULL;
    }

    do{//Busqueda en la lista
        if(r->id == id){//Si el repartidor está en la lista
            printf("Bienvenid@ %s\n", r->nombre);
            return r;//Se regresa la dirección del repartidor
        }
        r = r->sig;
    }while(r != NULL);

    return NULL;//Se regresa un NULL indicando que no hay un repartidor con ese id
}

//FUNCIONES ALMACENISTA--------------------------------------------------------------------------------------------------------------
//Se agrega un producto en cantidad o en su totalidad a la lista de productos
void agregarProductos(ListaProductos *lista){
    char nombre[MAX_CHAR];
    int cantidad = 0;
    float precio = 0;
    Producto *p = lista->inicio;

    printf("------------------------------------------------\n");
    printf("               AGREGAR PRODUCTOS\n");
    printf("------------------------------------------------\n");
    printf("Ingrese el nombre del producto:\t");
    fflush(stdin);
    gets(nombre);
    fflush(stdin);
    printf("Ingrese la cantidad a almacenar:\t");
    scanf("%d", &cantidad);
    printf("Ingrese el precio del producto:\t");
    scanf("%f", &precio);

    while(vaciaListaProductos(lista)){
        if(strcmpi(nombre, p->info->nombre)){//Si ya hay un producto en la lista con el nombre 
            p->info->precio = precio;//Se modifica el precio 
            p->info->existencias += cantidad;//Se incrementa las existencias
            return;
        }
        p = p->sig;//Se avanza en la lista
    }

    agregarProducto(lista, nombre, precio, cantidad);//Se agrega el producto
    return;
}

//Navegaci�n de productos para el almacenista
int verificarListaProductos(ListaProductos *lista, int check){
    check = 0;
    char opc;
    Producto *p;

    if(vaciaListaProductos(lista)){//Si la lista de productos está vacía
        printf("No hay ning�n art�culo disponible.\n");
        system("Pause");
        check = 1;
        system("cls");
        return check;
    } else{//Si la lista de productos no está vacía
        p = lista->inicio;
        do{
            system("cls");
            impresionNavegacion();//Se imprime el menú de navegación
            imprimirProducto(p);//Se imprime el producto
            fflush(stdin);
            opc = getchar();//Se obtiene la opción necesaria
            fflush(stdin);
            opc = convertirMayus(opc);//Se convierte a mayus en caso de ser necesario

            switch(opc){//Si
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
                        printf("\nYa se encuentra en el �ltimo elemento de la lista\n");
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
                    printf("Opci�n incorrecta. Intente de nuevo.\n");
                    system("Pause");
                break;
            }
        }while(!check);
    }
    return check;
}

