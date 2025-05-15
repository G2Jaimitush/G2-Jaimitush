#include <stdio.h>
#include "S8Corregido.h"

int main() {
    Producto productos[MAX_PRODUCTOS];
    int cantidad;
    float tiempoDisponible;
    int recursosDisponibles;

    cantidad = pedirCantidad();

    printf("Ingrese el tiempo total disponible (horas): ");
    scanf("%f", &tiempoDisponible);
    printf("Ingrese los recursos totales disponibles: ");
    scanf("%d", &recursosDisponibles);

    ingresarProductos(productos, cantidad);

    int opcion;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar nombre de producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Editar cantidades\n");
        printf("6. Editar tiempo de fabricacion\n");
        printf("7. Calcular totales y verificar factibilidad\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();  // limpia después del scanf

        switch (opcion) {
            case 1: buscarProducto(productos, cantidad); break;
            case 2: mostrarProductos(productos, cantidad); break;
            case 3: editarNombre(productos, cantidad); break;
            case 4: eliminarProducto(productos, &cantidad); break;
            case 5: editarCantidad(productos, cantidad); break;
            case 6: editarTiempo(productos, cantidad); break;
            case 7: {
                float totalTiempo = calcularTiempoTotal(productos, cantidad);
                int totalRecursos = calcularRecursosTotales(productos, cantidad);
                printf("\nTiempo total requerido: %.2f horas\n", totalTiempo);
                printf("Recursos necesarios: %d\n", totalRecursos);
                if (totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles)
                    printf("La fábrica PUEDE cumplir con la demanda.\n");
                else
                    printf("La fábrica NO puede cumplir con la demanda.\n");
                break;
            }
            case 8: printf("Saliendo...\n"); break;
            default: printf("Opción no válida\n");
        }

    } while(opcion != 8);

    return 0;
}

