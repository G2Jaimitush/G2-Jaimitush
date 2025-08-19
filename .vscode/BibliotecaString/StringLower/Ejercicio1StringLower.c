//Comparar dos cadenas ignorando mayúsculas y minúsculas

#include <stdio.h>
#include <string.h>

int main() {

    char frase1 [30];
    char frase2 [30];
    
    printf ("Escribe la primera frase para comparar: ");
    fgets (frase1, sizeof(frase1),stdin);
    frase1[strcspn(frase1, "\n")] = '\0';
    
    printf ("Escribe la segunda frase para comparar: ");
    fgets (frase2, sizeof(frase2),stdin);
    frase2[strcspn(frase2, "\n")] = '\0';

    if (strcmp(strlwr(frase1), strlwr(frase2)) == 0) {
        printf ("Ambas frase coinciden");
    }else{
        printf ("Ninguna frase coincide");
    }
    
    return 0;    

}

