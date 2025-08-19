//Transformación combinada de texto

#include <stdio.h>
#include <string.h>
int main()
{
    char palabra [32];
    char copia [32];
    
    printf ("Ingrese una palabra o una frase: ");
    fgets (palabra, sizeof(palabra),stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
    
    strcpy (copia, palabra);
    
    printf ("La palabra o frase %s en minusculas es: %s\n",palabra,strlwr(palabra));
    printf ("La palabra o frase %s en mayusculas es: %s\n",palabra,strupr(palabra));
    printf ("La palabra o frase %s tiene una longitud de: %i\n",copia, strlen(copia));
    printf ("Copia de la palabra o frase es: %s\n",copia);
    
    return 0;
}