#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

void crearStock(ListaProductos *lista);
void grabarStock(char *archivo, ListaProductos *lista);
void recuperarStock(char *archivo, ListaProductos *lista);
void inicializarListaProductos(ListaProductos *lista);

#endif // STOCK_H_INCLUDED
