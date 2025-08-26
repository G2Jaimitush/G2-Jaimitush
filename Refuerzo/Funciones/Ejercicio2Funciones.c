//Realizar un programa que ordene 3 nmeros enteros ingresados por el usuario, utilizando funciones.

#include <stdio.h>
void OrdenNumeros (int a, int b, int c);

int main()
{
    int num1, num2, num3;
    printf ("Ingrese 3 numeros: \n"); scanf ("%d %d %d",&num1,&num2,&num3);
    
    printf ("Los numeros ordenados de mayor a menor son: \n");
    OrdenNumeros (num1,num2,num3);
    
    return 0;
}

void OrdenNumeros (int a, int b, int c){
    
    if (a >= b && a >= c){
        if (b >= c){
            printf ("%d, %d, %d \n",a,b,c);
        } else {
            printf ("%d, %d, %d \n",a,c,b);
        }
    } else if (b >= a && b >= c){
        if (a >= c){
            printf ("%d, %d, %d \n",b,a,c);
        } else {
            printf ("%d, %d, %d \n",b,c,a);
        }
    } else {
        if (a >= b){
            printf ("%d, %d, %d \n",c,a,b);
        } else {
            printf ("%d, %d, %d \n",c,b,a);
        }
    }

}