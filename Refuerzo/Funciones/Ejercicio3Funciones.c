//Determinar si un numero es par o impar, utilizando funciones.

#include <stdio.h>
void NumeroPar (int a);

int main()
{
    int num;
    
    printf ("Ingrese un numero para comprobar si es par o impar: "); scanf ("%d",&num);
    NumeroPar (num);
    
    return 0;
}

void NumeroPar (int a){
    if (a % 2 == 1){
        printf ("El numero es impar\n");
    }else{
        printf ("El numero es par\n");
    }
}