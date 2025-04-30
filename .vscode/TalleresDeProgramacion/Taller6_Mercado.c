#include <stdio.h>
#include <string.h>


int main() {

    int MaximoProductos = 10;
    int MaximoNombre = 30;
    char nombres[MaximoProductos][MaximoNombre];
    float precios[MaximoProductos];
    int cantidad;

REPETIR:
    printf("Ingrese la cantidad de productos (maximo %d): ", MaximoProductos);
    scanf("%d", &cantidad);

    if (cantidad < 1 || cantidad > MaximoProductos) {
        printf("Cantidad inválida. Intente nuevamente.\n");
        goto REPETIR;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);
        
        // Vaciar el buffer antes de leer una cadena con espacios
        fflush(stdin);

        printf("  Nombre: ");
        fgets(nombres[i], MaximoNombre, stdin);

        // Elimina el salto de línea si fgets lo guarda
        nombres[i][strcspn(nombres[i], "\n")] = '\0';

        printf("  Precio: $ ");
        scanf("%f", &precios[i]);
    }

    // Muestra los productos ingresados
    printf("\n--- Productos Ingresados ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }

    return 0;
}

