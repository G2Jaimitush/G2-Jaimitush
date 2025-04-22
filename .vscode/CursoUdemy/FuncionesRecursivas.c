/*
Funcion Recursiva
Recursividad:    Una Funcion que se llama a si misma
1) Caso Base
2) Caso Recursivo

a(x){
    if (n=1)
    {
        return n;
    }else
    {
        a(x); //Se vuelve a llamar dentro de la misma funcion
    }
    
}*/

//Factorial con metodo recursivo 

#include <stdio.h>

long factorial(int n);

int main() {

    int n;

    printf("Escribe un numero\n");
    scanf("%i",&n);

    printf("El factorial del numero es %li\n",factorial(n));

    return 0;
}
/*
3! = 3*2*1
4! = 4*3!
5! = 5*4!
6! = 6*5!
*/
long factorial(int n){

    if (n<=1)
    {
        return 1;
    }else
    {
        return (n*factorial(n-1));
    }

}