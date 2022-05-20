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
    Repartidor *repartidor;
    Pedidos *colaPedidos = crearColaPedidos();
    int o = 0;
    ListaProductos *lista = nuevaListaProductos();
    ListaProductos *listProd = nuevaListaProductos();
    ListaCarrito *carrito = nuevoCarrito();
    
    RepartidoresEspera *colaRep = crearColaRepartidores();
    inicializarColaRepartidores(colaRep);
    printf("Lista creada\n");
    if(vaciaListaProductos(lista))
        printf("Lista Vacia\n");
    else imprimirListaProductos(lista);

    crearStock(lista);
    printf("Stock creado");
    grabarStock("stock.dat", lista);
    recuperarStock("stock.dat", listProd);

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
                    carrito = nuevoCarrito();
                    system("cls");
                    do{
                        opcionCliente = menuCliente(opcionCliente, listProd, carrito, colaPedidos);
                    }while(opcionCliente != 4);
                    break;
                case 2:
                    do{
                        opcionGerente = menuGerente(opcionGerente, colaPedidos, colaRep, listRep);
                    }while(opcionGerente != 5);
                    break;
                case 3:
                    repartidor = pedirUsuario(colaRep, listRep);
                    if(repartidor == NULL){
                        printf("No existe un repartidor con ese ID, se te regresara al menu inicial\n");
                        opcionRepartidor = 3;
                        system("pause");        
                    }
                    while(opcionRepartidor != 3){
                        opcionRepartidor = menuRepartidor(opcionRepartidor, listRep, colaRep, repartidor);
                    }
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