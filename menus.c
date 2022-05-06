#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int menuInicial(void){
    int opcion;
    do{
        printf("Te encuentras en el menú inicial\n");
        printf("Ingresa [1]: Cliente\n");
        printf("ingresa [2]: Gerente\n");
        printf("Ingresa [3]: Repartidor\n");
        printf("Ingresa [4]: Almacenista\n");
        printf("ingresa [5]: Salir del Programa\n");
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > 5);
    return opcion;
}

void menuCliente(void){
    int opcionCliente;
    do{
        printf("Este es el menu para Clientes\n");
        printf("Ingresa [1]: Seleccionar Productos\n");
        printf("Ingresa [2]: Revisar el carrito de Compras\n");
        printf("ingresa [3]: Realizar Pedido\n");
        printf("Ingresa [4]: Salir de este menu\n");
        scanf("%d", &opcionCliente);
    }while(opcionCliente < 1 || opcionCliente > 4);
    switch(opcionCliente){
        case 1:
            seleccionProducto();
        break;
        case 2:
            revisarCarrito();
        break;
        case 3: 
            realizarPedido();
        break;
        case 4:
            return;
        break;
    }
}

void menuGerente(void){
    int opcionGerente;
    do{
        printf("Este es el menu del Gerente\n");
        printf("Ingresa [1]: Ver la cola de Pedidos\n");
        printf("Ingresa [2]: Ver la cola de repartidores en espera\n");
        printf("Ingresa [3]: Ver la lista de repartidores en transito\n");
        printf("Ingresa [4]: Asignar un pedido\n");
        printf("Ingresa [5]: Salir de este menu\n");
        scanf("%d", &opcionGerente);
    }while(opcionGerente < 1 || opcionGerente > 5);
    switch(opcionGerente){
        case 1:
            verPedidos();
        break;
        case 2:
            repartidoresEspera();
        break;
        case 3: 
            repartidoresTransito();
        break;
        case 4:
            asignarPedido();
        break;
        case 5:
            return; 
        break;
    }    
}

void menuRepartidor(void){
    int opcionRepartidor;
    do{
        printf("Este es el menu del Repartidor\n");
        printf("Ingresa [1]: Ver Pedido Asignado\n");
        printf("Ingresa [2]: Notificar una entrega de pedido\n");
        printf("Ingresa [3]: Salir de este menu\n");
    }while(opcionRepartidor < 1 || opcionRepartidor > 3);
    switch(opcionRepartidor){
        case 1:
            pedidoAsignado();
        break;
        case 2:
            entregaPedido();
        break;
        case 3: 
            return;
        break;
    }    
}

void menuAlmacenista(void){
    int opcionAlmacenista;
    do{
        printf("Este es el menu del Almacenista\n");
        printf("Ingresa [1]: Mostrar la lista de Productos\n");
        printf("Ingresa [2]: Registrar la llegada de un producto\n");
        printf("Ingresa [3]: Salir de este menu\n");
    }while(opcionAlmacenista < 1 || opcionAlmacenista > 3);
    switch(opcionAlmacenista){
        case 1:
            listaProductos();
        break;
        case 2:
            agregarProductos();
        break;
        case 3: 
            return;
        break;
    }    
}
