//Convertir numeros decimales a binarios

#include <stdio.h>

void NumeroBinario (int a);

int main()
{
    int num;
    
    do{
        printf ("Escribe un numero positivo: "); scanf ("%d",&num);
    }while (num < 0);
    
    NumeroBinario(num);

    return 0;
}

void NumeroBinario (int a){
    
    if (a > 1){
        NumeroBinario (a/2);
    }
    printf ("%d",a % 2);
}


