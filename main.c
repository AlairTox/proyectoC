#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "listas.h"
#include "menus.h"
#include "menus.h"
#include "listas.h"
#include "colas.h"
#include "funciones.h"
#include "stock.h"

int main(void){
    setlocale(LC_CTYPE, "SPANISH");
    Repartidor *repartidor;
    Pedidos *colaPedidos = crearColaPedidos();
    ListaProductos *listProd = nuevaListaProductos();
    ListaCarrito *carrito = nuevoCarrito();
    ListaRepartidoresTransito *listRep = nuevaListaRepartidoresTransito();
    RepartidoresEspera *colaRep = crearColaRepartidores();
    inicializarColaRepartidores(colaRep);
    inicializarListaProductos(listProd);

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
                    system("cls");
                    opcionGerente = menuGerente(opcionGerente, colaPedidos, colaRep, listRep);
                }while(opcionGerente != 5);
                break;

            case 3:
                system("cls");
                repartidor = pedirUsuario(colaRep, listRep);
                if(repartidor == NULL){
                    printf("No existe un repartidor con ese ID, se te regresar� al menu inicial\n");
                    opcionRepartidor = 3;
                    system("pause");
                }
                do{
                    opcionRepartidor = menuRepartidor(opcionRepartidor, listRep, colaRep, repartidor);
                }while(opcionRepartidor != 3);
                break;

            case 4:

                do{
                    system("cls");
                    opcionAlmacenista = menuAlmacenista(opcionAlmacenista, listProd);
                }while(opcionAlmacenista != 3);
                break;
        }
        system("cls");
    }while(opc != 5);

    printf("----------------------(^._.^)----------------------\n");
    printf("                El Huarache Veloz\n\n\n");
    printf("---------------------------------------------------\n");
    printf("                 �Vuelva pronto!\n\n\n");
    printf("                     CR�DITOS:\n");
    printf("             Magally Escamilla Su�rez\n");
    printf("             Darwin Leonel Luna Alberto\n");
    printf("                Alair Toxtega Mu�oz\n");
    printf("---------------------------------------------------");
    grabarStock("stock.dat", listProd);//Guardado del Stock

    return 0;
}
