#include <stdio.h>
#include <time.h>

int main (){
    funcionAleatoria();
    return 0;
}

void funcionAleatoria (){
    int num;
    srand (time(NULL)); 
    num = 1 + rand() % ((10 - 1) - 1); // Genera un número aleatorio entre 1 y 100
    printf("El número aleatorio es: %d\n", num);
}