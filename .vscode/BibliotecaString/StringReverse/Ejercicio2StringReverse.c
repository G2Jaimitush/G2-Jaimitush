

#include <stdio.h>
#include <string.h>
int main()
{
    char frase [64];
    char copia [64];
    
    printf ("Ingrese una frase: ");
    fgets (frase, sizeof(frase),stdin);
    frase[strcspn (frase, "\n")] = '\0';
    
    strcpy (copia,frase);
    
    strrev (copia);
    printf ("La frase invertida es: %s\n", copia);
    printf ("La frase invertida en mayusculas es: %s\n", strupr(copia));
    printf ("La frase invertida en minusculas es: %s\n", strlwr(copia));
    printf ("La frase tiene una longitud de: %i\n", strlen(copia));
    printf ("La frase original es: %s\n", frase);
    return 0;
}