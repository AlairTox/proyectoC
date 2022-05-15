#include <stdio.h>
#include <stdlib.h>

#include "elemento.h"
#include "listas.h"

//Esta funcion tiene los 21 productos originales y sirve para crear la lista de productos originales
void crearStock(ListaProductos *lista){
    agregarProducto(lista, "AMD Ryzen 9 5950X", 12449.99, 10);
    agregarProducto(lista, "AMD Ryzen 5 5600G", 3630.79, 10);
    agregarProducto(lista, "Intel Core i9 12900K", 12099.99, 10);
    agregarProducto(lista, "Intel Core i7 12700K", 9100.00, 10);
    agregarProducto(lista, "Intel Core i5 12400", 9950.30, 10);
    agregarProducto(lista, "GIGABYTE RTX 3070 Ti", 14169.99, 5);
    agregarProducto(lista, "ASrock Radeon RX 6700 XT", 10300.50, 5);
    agregarProducto(lista, "ASUS RTX 3050", 7700.50, 5);
    agregarProducto(lista, "G.SKILL Ripjaws (16GB)", 1300, 15);
    agregarProducto(lista, "CORSAIR Vengeance (16GB)", 1799.99, 15);
    agregarProducto(lista, "Samsung 980 M.2 (1TB)", 2099.99, 15);
    agregarProducto(lista, "Western Digital NVMe (1TB)", 3500, 15);
    agregarProducto(lista, "Crucial SATA 2.5 (1TB)", 2100, 15);
    agregarProducto(lista, "ASUS ProArt B660 (Intel 12th)", 4899.99, 21);
    agregarProducto(lista, "GIGABYTE A521M (AMD)", 1756.50, 21);
    agregarProducto(lista, "ASUS ROG B550 (AMD)", 4299.99, 21);
    agregarProducto(lista, "GIGABYTE B660 AORUS (Intel 12th)", 4000, 21);
    agregarProducto(lista, "Fractal Design (ATX)", 3900.79, 10);
    agregarProducto(lista, "Corsair iCUE 500X (Mid-Tower ATX)", 3800, 10);
    agregarProducto(lista, "ASUS TUF GAMING VG24VQ 24'", 3900.50, 10);
    agregarProducto(lista, "GIGABYTE G27Q 27'", 4999.99, 10);
}

//Esta funcion crea el .dat con la lista de Productos indicada
void grabarStock(char *archivo, ListaProductos *lista){
    Producto *p = lista->inicio;
    FILE *file;
    file = fopen(archivo, "wb");

    if (file == NULL){
            printf("No se puede abrir el archivo: [%s]\n", archivo);
            exit(-1);
        }
        for(int k = 0; k < lista->n; k++){
            fwrite(p, sizeof(Producto), 1, file);
            p = p->sig;
        }
        fclose(file);
        printf("Archivo generado exitosamente(creo, espero, anhelo, ruego)\n");
        //Lo dejo comentado por si se necesita
        // while(p!=NULL){
        //     fwrite(p, sizeof(struct Producto), 1, file);
        //     p = p->sig;
        // }
        // fclose(file);
        // printf("Archivo generado exitosamente!\n");
    }

//Esta funcion lee el .dat para crear la lista de Productos
void recuperarStock(char *archivo, ListaProductos *lista){
    printf("entramos funcion");
    Producto *p = lista->inicio;
    FILE *file;
    file = fopen(archivo, "rb");

    if (file == NULL){
        printf("No existe el archivo: [%s]\n", archivo);
        exit(-2);
    }

    while(!feof(file)){
        printf("entramos while");
        //ACA problema, esto se la razón de que no funcione pero no sé como solucionarlo
        //Basicamente cuando inicia el programa lo primero que se hace es recuperar el stock para que todo el resto funcione
        //lista->inicio es NULL así que p es NULL, p->sig es NULL, se está asignando información 
        //a direcciones nulas, por lo que esto o no lo guarda o se rompe
        //Solución pensada: usar la función de agregar producto para generar nuevas direcciones en la lista
        //Problema: agregarProducto necesita de nombre, costo y existencias, así que o se puede modificar esa función
        //para que solo se mande la dirección de producto y eso irlo agregando a la lista, pero es moverle mucho
        //Mas o menos sería asi:
        //Producto *p = crearProducto(algo generico, algo generico, algo generico);
        //fread(p, sizeof(struct Producto), 1, file);
        //agregar Producto(lista, p);
        //
        fread(p, sizeof(struct Producto), 1, file);
        p = p->sig;
    }
    printf("terminamos funcion");
    fclose(file);
}

