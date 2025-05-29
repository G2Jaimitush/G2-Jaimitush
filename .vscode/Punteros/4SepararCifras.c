#include <stdio.h>

// Función que separa los dígitos por referencia
void separarDigitos(int numero, int *centena, int *decena, int *unidad) {
    *centena = numero / 100;
    *decena = (numero / 10) % 10;
    *unidad = numero % 10;
}

int main() {
    int num, centena, decena, unidad;

    do {
        printf("Ingrese un número de 3 cifras: ");
        scanf("%d", &num);
        if (num < 100 || num > 999) {
            printf("Error: debe ser un número de tres cifras.\n");
        }
    } while (num < 100 || num > 999);

    // Llamada a la función pasando las direcciones
    separarDigitos(num, &centena, &decena, &unidad);

    // Mostrar resultados
    printf("Dígito 1 (centena): %d\n", centena);
    printf("Dígito 2 (decena): %d\n", decena);
    printf("Dígito 3 (unidad): %d\n", unidad);

    return 0;
}
