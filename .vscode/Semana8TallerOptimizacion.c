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
    float tiempoDisponible = 1000.0; // Ejemplo
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
            default: printf("Opción inválida\n");
        }
    } while (opcion != 8);

    return 0;
}

int pedirCantidad() {
    int cantidad;
    do {
        printf("Ingrese la cantidad de productos (max %d): ", MaximoProductos);
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > MaximoProductos);
    return cantidad;
}

void ingresarProductos(char nombres[][MaximoNombre], float tiempos[], int cantidades[], int recursos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: ");
        fflush(stdin);
        fgets(nombres[i], MaximoNombre, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;

        printf("Tiempo de fabricacion por unidad: ");
        scanf("%f", &tiempos[i]);

        printf("Cantidad demandada: ");
        scanf("%d", &cantidades[i]);

        printf("Recursos por unidad: ");
        scanf("%d", &recursos[i]);
    }
}

void mostrarProductos(char nombres[][MaximoNombre], float tiempos[], int cantidades[], int recursos[], int cantidad) {
    printf("\n--- Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Tiempo: %.2f h | Cantidad: %d | Recursos por unidad: %d\n", i + 1, nombres[i], tiempos[i], cantidades[i], recursos[i]);
    }
}

void buscarProducto(char nombres[][MaximoNombre], float tiempos[], int cantidades[], int recursos[], int cantidad) {
    char nombre[MaximoNombre];
    printf("Nombre a buscar: ");
    fflush(stdin);
    fgets(nombre, MaximoNombre, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Encontrado: %s | Tiempo: %.2f | Cantidad: %d | Recursos: %d\n", nombres[i], tiempos[i], cantidades[i], recursos[i]);
            return;
        }
    }
    printf("No encontrado.\n");
}

void editarProducto(char nombres[][MaximoNombre], float tiempos[], int cantidades[], int recursos[], int cantidad) {
    char nombre[MaximoNombre];
    printf("Producto a editar: ");
    fflush(stdin);
    fgets(nombre, MaximoNombre, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Nuevo nombre: ");
            fflush(stdin);
            fgets(nombres[i], MaximoNombre, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = 0;
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][MaximoNombre], float tiempos[], int cantidades[], int recursos[], int *cantidad) {
    char nombre[MaximoNombre];
    printf("Producto a eliminar: ");
    fflush(stdin);
    fgets(nombre, MaximoNombre, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            for (int j = i; j < *cantidad - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiempos[j] = tiempos[j + 1];
                cantidades[j] = cantidades[j + 1];
                recursos[j] = recursos[j + 1];
            }
            (*cantidad)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarCantidad(char nombres[][MaximoNombre], int cantidades[], int cantidad) {
    char nombre[MaximoNombre];
    printf("Producto para editar cantidad: ");
    fflush(stdin);
    fgets(nombre, MaximoNombre, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Nueva cantidad: ");
            scanf("%d", &cantidades[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarTiempo(char nombres[][MaximoNombre], float tiempos[], int cantidad) {
    char nombre[MaximoNombre];
    printf("Producto para editar tiempo: ");
    fflush(stdin);
    fgets(nombre, MaximoNombre, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Nuevo tiempo: ");
            scanf("%f", &tiempos[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void verificarCapacidad(float tiempos[], int recursos[], int cantidades[], int cantidad, float tiempoDisponible, int recursoDisponible) {
    float tiempoTotal = 0;
    int recursosTotales = 0;

    for (int i = 0; i < cantidad; i++) {
        tiempoTotal += tiempos[i] * cantidades[i];
        recursosTotales += recursos[i] * cantidades[i];
    }

    printf("\nTiempo requerido: %.2f horas\n", tiempoTotal);
    printf("Recursos necesarios: %d unidades\n", recursosTotales);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursoDisponible) {
        printf("La fábrica puede cumplir con la demanda.\n");
    } else {
        printf("No se puede cumplir con la demanda por limitaciones de tiempo o recursos.\n");
    }
}