#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

//PRODUCTO
typedef struct Producto{
    struct Producto *ant, *sig;
    char *nombre;
    float precio;
    int existencias;
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

#endif // ELEMENTO_H_INCLUDED