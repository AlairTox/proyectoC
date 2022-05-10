#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "listas.h"
#include "colas.h"
#include "funciones.h"

int main(){
    Pedidos *colaPedidos = crearColaPedidos();
    ListaRepartidoresTransito *listaRepartidores = nuevaListaRepartidoresTransito();
    RepartidoresEspera *colaRepartidores = crearColaRepartidores();
    Repartidor *repartidor = crearRepartidor("Pancrasio", 2584);
    pushRepartidor(colaRepartidores, repartidor);
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
    //agregarProducto(listProd, "eee", 10, 10);//No sé por que se rompe aqui así que la comento
    printf("Impresion antes de la lista\n");
    if(vaciaListaProductos(listProd))
        printf("Lista Vacia\n");
    else imprimirListaProductos(listProd);
    printf("Desea continuar?");
    scanf("%d", &o);
    system("cls");

    if(o){
        int opc, opcionCliente;
        do{
            opc = menuInicial();
            switch (opc)
            {
                case 1:
                    system("cls");
                    do{
                    opcionCliente = menuCliente(listProd, carro1, opcionCliente, colaPedidos);
                    }while(opcionCliente != 4);
                    break;

                case 2:
                    menuGerente(colaPedidos, colaRepartidores, listaRepartidores);
                    break;
                case 3:
                    menuRepartidor(listaRepartidores, colaRepartidores, repartidor);
                    break;
                case 4:
                    menuAlmacenista(listProd);
                    break;
            }
            system("cls");
        }while(opc != 5);
    }
    //printf("Impresion de cola de pedidos\n");
    //imprimirColaPedidos(colaPedidos);
}
