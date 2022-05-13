#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "listas.h"
#include "colas.h"
#include "funciones.h"

int main(){
    Pedidos *colaPedidos = crearColaPedidos();
    int o=0;
    ListaProductos *listProd = nuevaListaProductos();
    ListaCarrito *carro1 = nuevoCarrito();
    printf("Lista creada\n");
    if(vaciaListaProductos(listProd))
        printf("Lista Vacia\n");
    else imprimirListaProductos(listProd);
    agregarProducto(listProd, "Pan", 10, 150);
    agregarProducto(listProd, "Wawa", 20, 350);
    agregarProducto(listProd, "Galletas", 40, 50);
    agregarProducto(listProd, "eee", 10, 10);
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
        int opc, opcionCliente, opcionGerente, opcionRepartidor;
        do{
            opc = menuInicial();
            switch (opc)
            {
                case 1:
                    system("cls");
                    do{
                        opcionCliente = menuCliente(listProd, carro1, opcionCliente, colaPedidos);
                    }while(opcionCliente!=4);
                    break;
                case 2:
                    do{
                        opcionGerente = menuGerente(colaPedidos, colaRep, listRep, opcionGerente);
                    }while(opcionGerente!=5);
                    break;
                case 3:
                    do{
                        opcionRepartidor =menuRepartidor(repLibre, listRep, colaRep, opcionRepartidor);
                    }while(opcionRepartidor!=3);
                    break;
                case 4:
                    menuAlmacenista();
                    break;
            }
            system("cls");
        }while(opc != 5);
    }

    printf("Impresion de cola de pedidos\n");
    imprimirColaPedidos(colaPedidos);
    printf("Termino de impresion de cola de pedidos\n");
}
