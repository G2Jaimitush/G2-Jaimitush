#include <stdio.h>

/*
 Intercambiar valores. Este ejercicio muestra cómo intercambiar los valores de las 
 variables utilizando una función con parámetros por referencia (punteros).
*/

void CambioVariable(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int num1, num2;
    
    printf("Ingrese el valor del numero 1: ");
    scanf("%d", &num1);
    
    printf("Ingrese el valor del numero 2: ");
    scanf("%d", &num2);

    int *p1 = &num1;
    int *p2 = &num2;

    printf("Antes del cambio:\n");
    printf("Numero 1 = %d, Numero 2 = %d\n", *p1, *p2);

    // Llamada correcta pasando punteros
    CambioVariable(p1, p2);

    printf("Despues del cambio:\n");
    printf("Numero 1 = %d, Numero 2 = %d\n", *p1, *p2);
    
    
    // Llamar la direeccion de memoria
    printf ("La direccion de memoria %d numero 1 es: %p\n", num1, &num1);
    printf ("La direccion de memoria %d numero 2 es: %p\n",num2, &num2);

    return 0;
}