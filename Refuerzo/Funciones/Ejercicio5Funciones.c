//Serie de Fibonacci

#include <stdio.h>

int SerieFibonacci (int a);

int main()
{
    int num,i;
    
    printf ("Ingresa la cantidad de elementos: "); scanf ("%d",&num);
    
    for (i = 0; i <= num; i++){
        
        printf ("%d\n",SerieFibonacci(i));
        
    }

    return 0;
}

int SerieFibonacci (int a){
    
    if (a == 0 || a == 1){
        return a;
    }else{
        return (SerieFibonacci(a - 1) + SerieFibonacci(a - 2));
    }
    
}