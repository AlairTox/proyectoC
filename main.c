#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "listas.h"
#include "menus.h"
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
    
    RepartidoresEspera *colaRep = crearColaRepartidores();
    inicializarColaRepartidores(colaRep);
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
    grabarStock("stock.dat", lista);

    //crearStock(listProd);//FUNCION A REPARAR
    
    //recuperarStock("stock.dat", listProd);

    printf("Impresion antes de la lista\n");
    if(vaciaListaProductos(listProd))
        printf("Lista Vacia\n");
    else imprimirListaProductos(listProd);

    ListaRepartidoresTransito *listRep = nuevaListaRepartidoresTransito();

    printf("Inicializacion del programa completa. Desea continuar?");
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
                        opcionCliente = menuCliente(opcionCliente, listProd, colaPedidos);
                    }while(opcionCliente != 4);
                    break;
                case 2:
                    do{
                        opcionGerente = menuGerente(opcionGerente, colaPedidos, colaRep, listRep);
                    }while(opcionGerente != 5);
                    break;
                case 3:
                    do{
                        opcionRepartidor = menuRepartidor(opcionRepartidor, listRep, colaRep);
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

    return 0;
}