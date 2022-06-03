#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

//INFO PRODUCTO
typedef struct infoProducto{
    char nombre[35];//Contiene un string de tamaño 35 como máximo para el nombre del producto
    float precio;//Contiene un float para el precio del producto
    int existencias;//Contiene un entero para el número de existencias del producto
} infoProducto;

//PRODUCTO
typedef struct Producto{
    struct Producto *ant, *sig;//Contiene dos apuntadores a estructura Producto
    infoProducto *info;//Contiene un apuntador a estructura infoProducto
}Producto;

//CLIENTE
typedef struct Cliente{
    char *nombre;//Contiene un apuntador a caracter(string) para el nombre del cliente
    char *direccion;//Contiene una puntador a caracter(string) para la dirección del cliente
    double telefono;//Contiene un double para el telefono del cliente
    float costo;//Contiene un float para el precio a pagar por parte del cliente
}Cliente;

//REPARTIDOR
typedef struct Repartidor{
    struct Repartidor *ant, *sig;//Contiene dos apuntadores a estructura Repartidor
    void *pedidoAsignado;//Contiene un apuntador a una estructura ListaCarrito(se usa void para evitar problemas de llamamda redonda)
    char *nombre;//Contiene apuntador a caracter(string) para el nombre del repartidor
    int id;//Contiene un entero para el id del repartidor
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
