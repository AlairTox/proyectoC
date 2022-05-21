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
    ListaProductos *listProd = nuevaListaProductos();
    ListaCarrito *carrito = nuevoCarrito();
    ListaRepartidoresTransito *listRep = nuevaListaRepartidoresTransito();
    RepartidoresEspera *colaRep = crearColaRepartidores();
    inicializarColaRepartidores(colaRep);

    FILE *file = fopen("stock.dat", "rb");

    if (file == NULL){
        crearStock(listProd);
        grabarStock("stock.dat", listProd);
        printf("Stock creado\n");
    }else
        recuperarStock("stock.dat", listProd);

    int opc, opcionCliente, opcionGerente, opcionRepartidor, opcionAlmacenista;
    do{
        opc = menuInicial(opc);
        switch (opc){

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
                do{
                    opcionRepartidor = menuRepartidor(opcionRepartidor, listRep, colaRep, repartidor);
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

    grabarStock("stock.dat", listProd); //para guardar el stock actualizado

    return 0;
}
