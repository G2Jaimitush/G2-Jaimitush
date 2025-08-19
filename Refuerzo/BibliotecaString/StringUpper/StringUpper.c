#include <stdio.h>
#include <string.h>
int main()
{
    char texto[32];
    
    printf ("Ingrese un cadena de texto\n");
    fgets (texto,sizeof(texto),stdin);
    
    printf ("La nueva cadena de texto es: %s",strupr(texto));

    return 0;
}
