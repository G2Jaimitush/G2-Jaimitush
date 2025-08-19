#include <stdio.h>
#include <string.h>
int main()
{
    char cadena [] = "Hola";
    
    strrev(cadena);
    
    printf("Cadena Revertida: %s",cadena);
    return 0;
}