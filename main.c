#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "listas.h"
#include "colas.h"
#include "funciones.h"
#include "stock.h"

int main(void){
    Pedidos *colaPedidos = crearColaPedidos();
    int o = 0;
    ListaProductos *lista = nuevaListaProductos();
    ListaProductos *listProd = nuevaListaProductos();
    ListaCarrito *carro1 = nuevoCarrito();
    printf("Lista creada\n");
    if(vaciaListaProductos(lista))
        printf("Lista Vacia\n");
    else imprimirListaProductos(lista);

    agregarProducto(lista, "AMD Ryzen 9 5950X", 12449.99, 10);
    agregarProducto(lista, "AMD Ryzen 5 5600G", 3630.79, 10);
    agregarProducto(lista, "Intel Core i9 12900K", 12099.99, 10);
    agregarProducto(lista, "Intel Core i7 12700K", 9100.00, 10);
    agregarProducto(lista, "Intel Core i5 12400", 9950.30, 10);
    printf("Stock creado");
    //grabarStock("stock.dat", lista);
    //recuperarStock("stock.dat", listProd);

    printf("Impresion antes de la lista\n");
    if(vaciaListaProductos(listProd))
        printf("Lista Vacia\n");
    else imprimirListaProductos(listProd);
    RepartidoresEspera *colaRep = crearColaRepartidores();
    Repartidor *repLibre = crearRepartidor("Pancrasio", 2504);
    //Repartidor *repLibre2 = crearRepartidor("Cosito Raz", 2204);
    pushRepartidor(colaRep, repLibre);
    //pushRepartidor(colaRep, repLibre2);
    ListaRepartidoresTransito *listRep = nuevaListaRepartidoresTransito();
    agregarRepartidor(listRep, "Cosito Raz", 2504);

    printf("Desea continuar?");
    scanf("%d", &o);
    system("cls");

    if(o){
        int opc, opcionCliente, opcionGerente, opcionRepartidor, opcionAlmacenista;
        do{
            opc = menuInicial(opc);
            switch (opc)
            {
                case 1:
                    system("cls");
                    do{
                        opcionCliente = menuCliente(opcionCliente, listProd, carro1, colaPedidos);
                    }while(opcionCliente != 4);
                    break;
                case 2:
                    do{
                        opcionGerente = menuGerente(opcionGerente, colaPedidos, colaRep, listRep);
                    }while(opcionGerente != 5);
                    break;
                case 3:
                    do{
                        opcionRepartidor = menuRepartidor(opcionRepartidor, repLibre, listRep, colaRep);
                    }while(opcionRepartidor != 3);
                    break;
                case 4:
                    do{
                        opcionAlmacenista = menuAlmacenista(opcionAlmacenista, listProd);
                    }while(opcionAlmacenista != 3);
                    break;
            }
            system("cls");
        }while(opc != 5);
    }

    printf("Impresion de cola de pedidos\n");
    imprimirColaPedidos(colaPedidos);
    printf("Termino de impresion de cola de pedidos\n");
}
