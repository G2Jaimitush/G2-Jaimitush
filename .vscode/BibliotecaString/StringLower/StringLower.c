#include <stdio.h>
#include <string.h>

int main() {

    char texto [30];

    printf ("Ingrese un texto tanto con mayusculas como minusculas: ");
    fgets (texto, sizeof(texto),stdin);
    texto[strcspn(texto, "\n")] = '\0';
    
    printf ("El nuevo texto convertido es: %s",strlwr(texto));
    return 0;    

}
