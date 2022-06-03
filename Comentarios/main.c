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
    setlocale(LC_CTYPE, "SPANISH");//Se agregan los caracteres para poder manejar acentos y signos de puntuación
    Repartidor *repartidor;//Todo esto son declaraciones e inicializaciones de las estrcuturas a usar
    Pedidos *colaPedidos = crearColaPedidos();
    ListaProductos *listProd = nuevaListaProductos();
    ListaCarrito *carrito = nuevoCarrito();
    ListaRepartidoresTransito *listRep = nuevaListaRepartidoresTransito();
    RepartidoresEspera *colaRep = crearColaRepartidores();
    inicializarColaRepartidores(colaRep);
    inicializarListaProductos(listProd);

    int opc, opcionCliente, opcionGerente, opcionRepartidor, opcionAlmacenista;
    do{//Inicio del programa como tal, este ciclo se repite hasta que el usuario lo quiera
        opc = menuInicial(opc);//Se presenta el menú inicial, pidiendo que escoja un submenú
        switch (opc){

            case 1:
                carrito = nuevoCarrito();//Se crea un carrito para cada cliente
                system("cls");
                do{
                    opcionCliente = menuCliente(opcionCliente, listProd, carrito, colaPedidos);//Presentación del menú para el cleinte
                }while(opcionCliente != 4);
                break;

            case 2:
                do{
                    system("cls");
                    opcionGerente = menuGerente(opcionGerente, colaPedidos, colaRep, listRep);//Presentación del menú para el gerente
                }while(opcionGerente != 5);
                break;

            case 3:
                system("cls");
                repartidor = pedirUsuario(colaRep, listRep);//Se le pide al repartidor su id
                if(repartidor == NULL){//Si el id no está en la lista de repartidores
                    printf("No existe un repartidor con ese ID, se te regresar� al menu inicial\n");
                    opcionRepartidor = 3;
                    system("pause");
                }
                do{
                    opcionRepartidor = menuRepartidor(opcionRepartidor, listRep, colaRep, repartidor);//Presentación del menú para el repartidor
                }while(opcionRepartidor != 3);
                break;

            case 4:

                do{
                    system("cls");
                    opcionAlmacenista = menuAlmacenista(opcionAlmacenista, listProd);//Presentación del menú para el almacenista
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
