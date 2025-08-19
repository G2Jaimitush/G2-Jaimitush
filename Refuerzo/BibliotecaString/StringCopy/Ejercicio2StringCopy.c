// Pide una frase, cópiala en otra variable y cambia la copia sin alterar la original.

#include <stdio.h>
#include <string.h>

int main(){

    char Frase [100];
    char Copia [100];

    printf ("Ingrese una frase: ");
    fgets(Frase, sizeof(Frase), stdin);

    strcpy(Copia, Frase);

    Copia [0] = 'X';
    Copia [2] = 'A';

    printf ("Frase Original: %s", Frase);
    printf ("Frase Copiada: %s", Copia);
}
