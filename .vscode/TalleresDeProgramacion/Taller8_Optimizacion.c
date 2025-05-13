#include <stdio.h>
#include <string.h>

#define MaximoProductos 10
#define MaximoNombre 30

// Prototipos
int pedirCantidad();
void ingresarProductos(char nombres[][MaximoNombre], float precios[], int cantidades[], float tiempos[], int recursos[], int cantidad);
void mostrarProductos(char nombres[][MaximoNombre], float precios[], int cantidades[], float tiempos[], int recursos[], int cantidad);
void buscarProducto(char nombres[][MaximoNombre], float precios[], int cantidad);
void editarNombre(char nombres[][MaximoNombre], int cantidad);
void editarCantidad(int cantidades[], int cantidad, char nombres[][MaximoNombre]);
void editarTiempo(float tiempos[], int cantidad, char nombres[][MaximoNombre]);
void eliminarProducto(char nombres[][MaximoNombre], float precios[], int cantidades[], float tiempos[], int recursos[], int *cantidad);
float calcularTiempoTotal(float tiempos[], int cantidades[], int cantidad);
int calcularRecursosTotales(int recursos[], int cantidades[], int cantidad);

int main() {
    char nombres[MaximoProductos][MaximoNombre];
    float precios[MaximoProductos];
    int cantidades[MaximoProductos];
    float tiempos[MaximoProductos];
    int recursos[MaximoProductos];

    float tiempoDisponible;
    int recursosDisponibles;

    int cantidad = pedirCantidad();

    printf("Ingrese el tiempo total disponible (horas): ");
    scanf("%f", &tiempoDisponible);
    printf("Ingrese los recursos totales disponibles: ");
    scanf("%d", &recursosDisponibles);

    ingresarProductos(nombres, precios, cantidades, tiempos, recursos, cantidad);

    int opcion;
    do {
        printf("\n--- Men\u00fa ---\n");
        printf("1. Buscar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar nombre de producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Editar cantidades\n");
        printf("6. Editar tiempo de fabricaci\u00f3n\n");
        printf("7. Calcular totales y verificar factibilidad\n");
        printf("8. Salir\n");
        printf("Seleccione una opci\u00f3n: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: buscarProducto(nombres, precios, cantidad); break;
            case 2: mostrarProductos(nombres, precios, cantidades, tiempos, recursos, cantidad); break;
            case 3: editarNombre(nombres, cantidad); break;
            case 4: eliminarProducto(nombres, precios, cantidades, tiempos, recursos, &cantidad); break;
            case 5: editarCantidad(cantidades, cantidad, nombres); break;
            case 6: editarTiempo(tiempos, cantidad, nombres); break;
            case 7: {
                float totalTiempo = calcularTiempoTotal(tiempos, cantidades, cantidad);
                int totalRecursos = calcularRecursosTotales(recursos, cantidades, cantidad);
                printf("\nTiempo total requerido: %.2f horas\n", totalTiempo);
                printf("Recursos necesarios: %d\n", totalRecursos);
                if (totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles)
                    printf("La f\u00e1brica PUEDE cumplir con la demanda.\n");
                else
                    printf("La f\u00e1brica NO puede cumplir con la demanda.\n");
                break;
            }
            case 8: printf("Saliendo...\n"); break;
            default: printf("Opci\u00f3n no v\u00e1lida\n");
        }

    } while(opcion != 8);
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

void ingresarProductos(char nombres[][MaximoNombre], float precios[], int cantidades[], float tiempos[], int recursos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        getchar();
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: ");
        fgets(nombres[i], MaximoNombre, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
        printf("Precio: $ ");
        scanf("%f", &precios[i]);
        printf("Cantidad demandada: ");
        scanf("%d", &cantidades[i]);
        printf("Tiempo por unidad (horas): ");
        scanf("%f", &tiempos[i]);
        printf("Recursos por unidad: ");
        scanf("%d", &recursos[i]);
    }
}

void mostrarProductos(char nombres[][MaximoNombre], float precios[], int cantidades[], float tiempos[], int recursos[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Precio: %.2f | Cantidad: %d | Tiempo/u: %.2f h | Recursos/u: %d\n", i+1, nombres[i], precios[i], cantidades[i], tiempos[i], recursos[i]);
    }
}

void buscarProducto(char nombres[][MaximoNombre], float precios[], int cantidad) {
    char buscar[MaximoNombre];
    getchar();
    printf("Nombre del producto a buscar: ");
    fgets(buscar, MaximoNombre, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("Producto encontrado: %s | Precio: %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarNombre(char nombres[][MaximoNombre], int cantidad) {
    char buscar[MaximoNombre];
    getchar();
    printf("Nombre del producto a editar: ");
    fgets(buscar, MaximoNombre, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("Nuevo nombre: ");
            fgets(nombres[i], MaximoNombre, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = '\0';
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarCantidad(int cantidades[], int cantidad, char nombres[][MaximoNombre]) {
    char buscar[MaximoNombre];
    getchar();
    printf("Nombre del producto para editar cantidad: ");
    fgets(buscar, MaximoNombre, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("Nueva cantidad: ");
            scanf("%d", &cantidades[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarTiempo(float tiempos[], int cantidad, char nombres[][MaximoNombre]) {
    char buscar[MaximoNombre];
    getchar();
    printf("Nombre del producto para editar tiempo: ");
    fgets(buscar, MaximoNombre, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("Nuevo tiempo por unidad: ");
            scanf("%f", &tiempos[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][MaximoNombre], float precios[], int cantidades[], float tiempos[], int recursos[], int *cantidad) {
    char buscar[MaximoNombre];
    
    // Limpiar buffer de entrada
    while (getchar() != '\n');

    printf("Nombre del producto a eliminar: ");
    fgets(buscar, MaximoNombre, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';  // Eliminar salto de línea

    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            for (int j = i; j < *cantidad - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                precios[j] = precios[j + 1];
                cantidades[j] = cantidades[j + 1];
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
            }
            (*cantidad)--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}


float calcularTiempoTotal(float tiempos[], int cantidades[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += tiempos[i] * cantidades[i];
    }
    return total;
}

int calcularRecursosTotales(int recursos[], int cantidades[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += recursos[i] * cantidades[i];
    }
    return total;
}