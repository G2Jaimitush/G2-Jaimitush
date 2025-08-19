#include <stdio.h>
#include <string.h>
int main()
{
    char Texto[126];
    
    printf ("Escribe una frase: ");
    fgets(Texto,sizeof(Texto),stdin);
    Texto[strcspn(Texto, "\n")] = '\0';
    printf ("La frase que ingresaste tiene una longitud de %i. ", strlen(Texto));
    
    return 0;
}