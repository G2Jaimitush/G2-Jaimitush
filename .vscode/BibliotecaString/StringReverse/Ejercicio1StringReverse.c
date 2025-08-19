//Verificar si una palabra es un palíndromo

#include <stdio.h>
#include <string.h>
int main()
{
    char palabra[64];
    char copia[64];
    
    printf ("Este es un programa para verificar si una palabra es palindromo\n");
    printf ("Ingrese una palabra: ");
    fgets(palabra,sizeof(palabra),stdin);
    palabra[strcspn(palabra,"\n")]='\0';
    
    strcpy(copia,palabra);
    strlwr(palabra);
    strlwr(copia);
    
    strrev (copia);
    
    if(strcmp (palabra,copia) == 0 ){
        printf ("Es palindromo\n");
    }else{
        printf("No es palindromo");
    }
    
    return 0;
}