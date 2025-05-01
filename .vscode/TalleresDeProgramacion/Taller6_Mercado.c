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
        printf("Cantidad invalida. Intente nuevamente.\n");
        goto REPETIR;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);

        fflush(stdin); // Limpia el buffer antes de leer cadena con espacios

        printf("  Nombre: ");
        fgets(nombres[i], MaximoNombre, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0'; // Elimina salto de línea

        printf("  Precio: $ ");
        scanf("%f", &precios[i]);
    }

    // Mostrar productos ingresados
    printf("\n--- Productos Ingresados ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }

    // Menú de opciones
    int opcion;
    char nombreBusqueda[MaximoNombre];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por nombre\n");
        printf("2. Mostrar todos los productos\n");
        printf("3. Mostrar producto mas caro\n");
        printf("4. Mostrar producto mas barato\n");
        printf("5. Calcular precio promedio\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                printf("\nIngrese el nombre del producto a buscar: ");
                 // Lee la cadena ingresada desde el teclado (con espacios permitidos) y la guarda en nombreBusqueda
                fgets(nombreBusqueda, MaximoNombre, stdin);
                nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0'; // Quitar salto de línea

                int encontrado = 0;
                for (int i = 0; i < cantidad; i++) {
                    // Compara si el nombre ingresado coincide exactamente con el nombre del producto i
                    if (strcmp(nombreBusqueda, nombres[i]) == 0) {
                        printf("Producto encontrado: %s - $%.2f\n", nombres[i], precios[i]);
                        encontrado = 1;
                        break;
                    }
                }

                // Si no se encontró el producto, se muestra el mensaje de producto no encontrado
                if (!encontrado) {
                    printf("Producto no encontrado.\n");
                }
                break;

            case 2:
                printf("\n--- Lista de Productos ---\n");
                for (int i = 0; i < cantidad; i++) {
                    printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
                }
                break;

            case 3: {
                int maxProducto = 0;
                for (int i = 1; i < cantidad; i++) {
                    if (precios[i] > precios[maxProducto]) {
                        maxProducto = i;
                    }
                }
                printf("Producto mas caro: %s - $%.2f\n", nombres[maxProducto], precios[maxProducto]);
                break;
            }

            case 4: {
                int minProducto = 0;
                for (int i = 1; i < cantidad; i++) {
                    if (precios[i] < precios[minProducto]) {
                        minProducto = i;
                    }
                }
                printf("Producto mas barato: %s - $%.2f\n", nombres[minProducto], precios[minProducto]);
                break;
            }

            case 5: {
                float suma = 0;
                for (int i = 0; i < cantidad; i++) {
                    suma += precios[i];
                }
                float promedio = suma / cantidad;
                printf("Precio promedio: $%.2f\n", promedio);
                break;
            }

            case 6:{
                printf("Saliendo del programa...\n");
                break;
            }
            default:
                printf("Opcion no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}




