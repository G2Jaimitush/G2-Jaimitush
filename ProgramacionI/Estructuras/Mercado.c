#include <stdio.h>

struct Producto {
    char nombre[50];
    int codigo;
    float precio;
    int cantidad; 
};

int main (){
    struct Producto productos [3];
    int i;

    // Ingresar informacion de los productos

    for (i = 0; i < 3; i++){
        printf ("Ingrese el nombre del producto %d: ", i + 1);
        scanf ("%s", productos[i].nombre);
        printf ("Ingrese el codigo del producto %d: ", i + 1);
        scanf ("%d", &productos[i].codigo);
        printf ("Ingrese el precio del producto %d: ", i + 1);
        scanf ("%f", &productos[i].precio);
        printf ("Ingrese la cantidad del producto %d: ", i + 1);
        scanf ("%d", &productos[i].cantidad);
    }

    // Mostrar la informacion de los productos
    printf ("-------------------------------\n");
    for (i = 0; i < 3; i++){
        printf ("Informacion del producto %d:\n", i + 1);
        printf ("Nombre: %s\n", productos[i].nombre);
        printf ("Codigo: %d\n", productos[i].codigo);
        printf ("Precio: %.2f\n", productos[i].precio);
        printf ("Cantidad: %d\n", productos[i].cantidad);
    }

    return 0;
}