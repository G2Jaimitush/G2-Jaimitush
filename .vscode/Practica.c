#include <stdio.h>
#include <math.h>
int main (){

    //Definicion de variables
    int a = 0,b = 0,c = 0;

    //El usuario ingresa los valores de a, b y c
    printf ("Calcular una ecuacion de segundo grado mediante la formula general\n");
    printf ("ax^2 + bx + c = 0\n");
    printf ("La forumala general es: x = (-b +- √(b^2 - 4ac)) / 2a\n");
    printf ("Ingrese el valor de a: ");
    scanf ("%d", &a);
    printf ("Ingrese el valor de b: ");
    scanf ("%d", &b);
    printf ("Ingrese el valor de c: ");
    scanf ("%d", &c);

    //Se calcula el discriminante
    int discriminante = (b*b) - (4*a*c);
    if (discriminante > 0){
        printf ("La ecuacion tiene dos soluciones reales y diferentes\n");
    }else if (discriminante == 0){
        printf ("La ecuacion tiene una solucion real doble\n");
    }else{
        printf ("La ecuacion no tiene soluciones reales\n");
    }

    //Calcuar la ecuacion cuadratica
    float x1 = (-b + sqrt(discriminante)) / (2*a);
    float x2 = (-b - sqrt(discriminante)) / (2*a);
    printf ("La solucion es: x1 = %.2f, x2 = %.2f\n", x1, x2);
    return 0;
}