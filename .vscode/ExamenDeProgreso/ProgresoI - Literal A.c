#include <stdio.h>
#include <math.h>
int main (){

    //Definicion de variables
    int a = 0,b = 0,c = 0;

    //El usuario ingresa los valores de a, b y c
    printf ("Calcular una ecuacion de segundo grado mediante la formula general\n");
    printf ("\tax^2 + bx + c = 0\n");
    printf ("La forumala general es: x = (-b +- √(b^2 - 4ac)) / 2a\n");
    printf ("\n");
    printf ("Ingrese el valor de a (TERMINO ELEVADO AL CUADRADO): ");
    scanf ("%d", &a);
    printf ("Ingrese el valor de b (TERMINO SOLO CON LA VARIABLE): ");
    scanf ("%d", &b);
    printf ("Ingrese el valor de c (TERMINO INDEPENDIENTE): ");
    scanf ("%d", &c);

    //Se calcula el discriminante
    int discriminante = (b*b) - (4*a*c);
    
    //Se indicacuando el DISCRIMINANTO es MAYOR a 0, IGUAL a 0 y MENOR 0 
    if (discriminante > 0){
        printf ("\tLa ecuacion tiene dos soluciones reales y diferentes\n");
        
        //Se determina los valores de X1 y X2
        float x1 = (-b + sqrt(discriminante)) / (2*a);
        float x2 = (-b - sqrt(discriminante)) / (2*a);
        printf ("La solucion es: x1 = %.2f, x2 = %.2f\n", x1, x2);
        
    }else if (discriminante == 0){
        printf ("La ecuacion tiene una solucion real doble\n");

        float x1 = (-b + sqrt(discriminante)) / (2*a);
        float x2 = (-b - sqrt(discriminante)) / (2*a);
        printf ("La soluciones es: x1 Y x2 = %.2f", x1);

    }else{
        printf ("La ecuacion no tiene soluciones reales si no imaginarias\n");
    }

    return 0;
}