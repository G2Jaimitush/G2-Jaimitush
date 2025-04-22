#include <stdio.h>
#include <math.h>
int main (){
    funcionTrigonometrica();
    return 0;
}

void funcionTrigonometrica(){
    float x, cambio = 0;
    printf ("Escribe un numero: ");
    scanf ("%f", &x);

    cambio = acos (x);
    printf ("El resultado de la funcion arco coseno es: %f\n", cambio);
    cambio = asin (x);
    printf ("El resultado de la funcion arco seno es: %f\n", cambio);
    cambio = atan (x);
    printf ("El resultado de la funcion arco tangente es: %f\n", cambio);
    cambio = acos (x);
    printf ("El resultado de la funcion de coseno es: %f\n", cambio);
    cambio = asin (x);
    printf ("El resultado de la funcion de seno es: %f\n", cambio);
    cambio = atan (x);
    printf ("El resultado de la funcion de tangente es: %f\n", cambio);
    
}