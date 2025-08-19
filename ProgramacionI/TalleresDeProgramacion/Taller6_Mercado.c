#include <stdio.h>
#include "FuncionesTaller6_Mercado.h"

int main() {
    char nombres[MaximoProductos][MaximoNombre];
    float precios[MaximoProductos];
    int cantidad = pedirCantidad();

    ingresarProductos(nombres, precios, cantidad);
    mostrarProductos(nombres, precios, cantidad);

    int opcion;
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
            case 1: buscarProducto(nombres, precios, cantidad); 
                break;
            case 2: mostrarProductos(nombres, precios, cantidad); 
                break;
            case 3: mostrarMasCaro(nombres, precios, cantidad); 
                break;
            case 4: mostrarMasBarato(nombres, precios, cantidad); 
                break;
            case 5: calcularPromedio(precios, cantidad); 
                break;
            case 6: printf("Saliendo del programa...\n"); 
                break;
            default: printf("Opcion no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}






