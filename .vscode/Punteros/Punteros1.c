#include <stdio.h>

int main() {
    int var = 10; // Declaramos una variable entera
    int *ptr; // Declaramos un puntero a entero

    ptr = &var; // El puntero almacena la dirección de la variable 'var'

    // Imprimimos el valor de la variable
    printf("El valor de var es: %d\n", var);

    // Usamos el puntero para acceder al valor de la variable
    printf("El valor de var usando el puntero es: %d\n", *ptr);

    // Imprimimos la dirección de la variable
    printf("La direccion de var es: %p\n", &var);

    // Imprimimos la dirección almacenada en el puntero
    printf("La direccion almacenada en el puntero es: %p\n", ptr);

    // Cambiamos el valor de la variable usando el puntero
    *ptr = 20;
    printf("El nuevo valor de var es: %d\n", var);

    return 0;
}