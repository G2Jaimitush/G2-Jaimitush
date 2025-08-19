#include <stdio.h>
#include <string.h>

int main() {

    char Cadena1 []= "Jaime"; 
    char Cadena2 [] = "Velastegui";
    //Tanto la cadena 1 como la 2 no debe exceder los caracteres maximo de la cadena final
    char Final [100] = " "; // Inicializar la cadena final

    //Concatenar las cadenas
    strcat (Final, Cadena1);
    strcat (Final, " - ");
    strcat (Final, Cadena2);

    printf("Cadena Final: %s", Final);
}
