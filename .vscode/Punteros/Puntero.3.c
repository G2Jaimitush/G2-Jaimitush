/*Ejercicio 1: Intercambiar Valores
Este ejercicio muestra cómo intercambiar los valores de dos 
variables utilizando una función con parámetros por referencia.*/

#include <stdio.h>

// Función para intercambiar valores
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    printf("Antes del intercambio: x = %d, y = %d\n", x, y);
    
    // Llamada a la función intercambiar
    intercambiar(&x, &y);
    
    printf("Después del intercambio: x = %d, y = %d\n", x, y);
    return 0;
}

/*Ejercicio 2: Sumar Elementos de un Arreglo
Este ejercicio muestra cómo sumar los elementos de un arreglo 
utilizando una función con parámetros por valor y por referencia.*/

#include <stdio.h>

// Función para sumar elementos de un arreglo
void sumarElementos(int arr[], int n, int *suma) {
    *suma = 0;
    for (int i = 0; i < n; i++) {
        *suma += arr[i];
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int suma = 0;
    
    // Llamada a la función sumarElementos
    sumarElementos(arreglo, n, &suma);
    
    printf("La suma de los elementos del arreglo es: %d\n", suma);
    return 0;
}

/*Estos ejemplos muestran cómo utilizar punteros para modificar 
valores directamente en la memoria y cómo pasar parámetros por 
referencia para que las funciones puedan modificar los valores 
originales.*/