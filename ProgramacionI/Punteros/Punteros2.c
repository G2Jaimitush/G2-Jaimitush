/*
 Un programa en C que demuestra cómo funcionan los punteros 
 utilizando funciones; este ejemplo incluye comentarios para 
 ayudar a los estudiantes a entender cada parte del código:
*/
#include <stdio.h>

// Función que toma un puntero a entero y modifica el valor al que apunta
void modificarValor(int *ptr) {
    *ptr = 20; // Cambiamos el valor al que apunta el puntero
}

int main() {
    int var = 10; // Declaramos una variable entera
    int *ptr; // Declaramos un puntero a entero

    ptr = &var; // El puntero almacena la dirección de la variable 'var'

    // Imprimimos el valor inicial de la variable
    printf("El valor inicial de var es: %d\n", var);

    // Llamamos a la función y pasamos el puntero
    modificarValor(ptr);

    // Imprimimos el valor de la variable después de la modificación
    printf("El valor de var después de modificarValor es: %d\n", var);

    // Imprimimos la dirección de memoria de la variable
    printf("La dirección de var es: %p\n", &var);

    return 0;   
}