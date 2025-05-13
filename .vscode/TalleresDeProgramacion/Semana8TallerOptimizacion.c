#include <stdio.h>
#include "TallerOptimizacion.h"

int main() {
    char nombres[MaximoProductos][MaximoNombre];
    float tiempos[MaximoProductos];
    int cantidades[MaximoProductos], recursos[MaximoProductos];
    int cantidad = pedirCantidad();

    ingresarProductos(nombres, tiempos, cantidades, recursos, cantidad);
    mostrarProductos(nombres, tiempos, cantidades, recursos, cantidad);

    int opcion;
    float tiempoDisponible = 1000.0;
    int recursoDisponible = 500;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por nombre\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar nombre\n");
        printf("4. Eliminar producto\n");
        printf("5. Editar cantidades\n");
        printf("6. Editar tiempo de fabricacion\n");
        printf("7. Verificar si se puede cumplir con la demanda\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: buscarProducto(nombres, tiempos, cantidades, recursos, cantidad); break;
            case 2: mostrarProductos(nombres, tiempos, cantidades, recursos, cantidad); break;
            case 3: editarProducto(nombres, tiempos, cantidades, recursos, cantidad); break;
            case 4: eliminarProducto(nombres, tiempos, cantidades, recursos, &cantidad); break;
            case 5: editarCantidad(nombres, cantidades, cantidad); break;
            case 6: editarTiempo(nombres, tiempos, cantidad); break;
            case 7: verificarCapacidad(tiempos, recursos, cantidades, cantidad, tiempoDisponible, recursoDisponible); break;
            case 8: break;
            default: printf("Opcion invalida\n");
        }
    } while (opcion != 8);

    return 0;
}
