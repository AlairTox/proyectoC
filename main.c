#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "listas.h"
#include "colas.h"
#include "funciones.h"

int main(){
    Pedidos *colaPedidos = crearColaPedidos(2);
    int o=0;
    printf("Pruebas Productos\n\n");
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
    if(vaciaListaProductos(listProd))
        printf("Lista Vacia\n");
    else imprimirListaProductos(listProd);
    printf("DEsea continuar?");
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
                    menuGerente();
                    break;
                case 3:
                    menuRepartidor();
                    break;
                case 4:
                    menuAlmacenista();
                    break;
            }
            system("cls");
        }while(opc != 5);
    }
    imprimirColaPedidos(colaPedidos);
}