//Concatena dos cadenas fijas y muestra el resultado.

#include <stdio.h>
#include <string.h>
int main()
{
    char Cadena1 [] = "Hola";
    char Cadena2 [] = "Mundo";
    char Final [30]= "";
    
    strcat (Final, Cadena1);
    strcat(Final, " y ");
    strcat (Final, Cadena2);
    printf ("Frase Final: %s", Final);
    
    return 0;
}