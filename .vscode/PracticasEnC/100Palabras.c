#include <stdio.h>
#include <string.h>

int main (){
    char frase [101];
    printf ("Ingrese una frase que la cual tenga 100 palabras: \n");
    fgets(frase, sizeof(frase), stdin); 
    printf ("La longitud de la frase es de %d palabras\n", strlen(frase));
    if (strlen(frase) < 100){
        printf ("La frase es menor a 100 palabras\n");
        fgets(frase, sizeof(frase), stdin);
    }else if (strlen (frase) > 100){
        printf ("La frase es mayor a 100 palabras\n");
        fgets(frase, sizeof(frase), stdin);
    }
    return 0;
}