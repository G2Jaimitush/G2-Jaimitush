#include <stdio.h>

int sumar(int num1, int num2); // Prototipo de la funcion sumar

int main (){

    int a, b;
    printf ("Ingrese el primer numero: ");
    scanf ("%d", &a);
    printf ("Ingrese el segundo numero: ");
    scanf ("%d", &b);
    printf ("La suma de %d y %d es: %d\n", a, b, sumar(a, b)); // Llamada a la funcion sumar
    return 0;
}


int sumar (int num1, int num2){ // Definicion de la funcion sumar
    return num1 + num2;
}// Retorna la suma de los dos numeros