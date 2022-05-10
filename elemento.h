#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

typedef struct Cliente{
    char *nombre;
    char *direccion;
    double telefono;
    int costo;
}Cliente;

typedef struct Repartidor{
    struct Repartidor *ant, *sig;
    char *nombre;
    int id;
}Repartidor;

typedef struct Producto{
    struct Producto *ant, *sig;
    char *nombre;
    int precio;
    int existencias;
}Producto;

//Funciones Producto
Producto *crearProducto(char *nombre, int precio, int existencias);
void imprimirProducto(Producto *e);

//Funciones Cliente
Cliente *nuevoCliente(char *nombre, char *direccion, double telefono, int costo);
void imprimirCliente(Cliente * C);

//FuncionesRepartidor
Repartidor *crearRepartidor (char *nombre, int id);
void imprimirRepartidor(Repartidor * r);

#endif // ELEMENTO_H_INCLUDED