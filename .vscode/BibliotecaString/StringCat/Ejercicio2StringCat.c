// Concatena tres cadenas fijas con espacios entre ellas y muestra el resultado.

#include <stdio.h>
#include <string.h>
int main()
{
    char Cadena1 [] = "Buenos";
    char Cadena2 [] = "Dias";
    char Cadena3 [] = "Amigo";
    char Final [50]= "";
    
    strcat (Final, Cadena1);
    strcat(Final, " ");
    strcat (Final, Cadena2);
    strcat(Final, " ");
    strcat(Final, Cadena3);    
    printf ("Frase Final: %s", Final);
    
    return 0;
}