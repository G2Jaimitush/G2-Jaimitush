//Última aparición de una letra en una frase

#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    char letra;
    char *pos;

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Ingrese una letra: ");
    scanf("%c", &letra);

    pos = strrchr(frase, letra);

    if (pos != NULL) {
        printf("Resultado: %s\n", pos);
    } else {
        printf("La letra '%c' no se encontró en la frase.\n", letra);
    }

    return 0;
}
