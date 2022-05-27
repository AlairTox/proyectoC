#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

//INFO PRODUCTO
typedef struct infoProducto{
    char nombre[35];
    float precio;
    int existencias;
} infoProducto;

//PRODUCTO
typedef struct Producto{
    struct Producto *ant, *sig;
    infoProducto *info;
}Producto;

//CLIENTE
typedef struct Cliente{
    char *nombre;
    char *direccion;
    double telefono;
    float costo;
}Cliente;

//REPARTIDOR
typedef struct Repartidor{
    struct Repartidor *ant, *sig;
    void *pedidoAsignado;
    char *nombre;
    int id;
}Repartidor;

//Funciones Producto
Producto *crearProducto(char *nombre, float precio, int existencias);
void imprimirProducto(Producto *e);

//Funciones Cliente
Cliente *nuevoCliente(char *nombre, char *direccion, double telefono, float costo);
void imprimirCliente(Cliente * c);

//FuncionesRepartidor
Repartidor *crearRepartidor (char *nombre, int id);
void imprimirRepartidor(Repartidor * r);

//Funcion infoProducto
infoProducto *inicializarInfoProducto();

#endif // ELEMENTO_H_INCLUDED
