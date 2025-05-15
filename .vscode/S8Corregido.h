#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 30

typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
    float tiempoFabricacion;
    int recursosPorUnidad;
} Producto;

// Funciones
void limpiarBuffer();
int pedirCantidad();
void ingresarProductos(Producto productos[], int cantidad);
void mostrarProductos(Producto productos[], int cantidad);
void buscarProducto(Producto productos[], int cantidad);
void editarNombre(Producto productos[], int cantidad);
void editarCantidad(Producto productos[], int cantidad);
void editarTiempo(Producto productos[], int cantidad);
void eliminarProducto(Producto productos[], int *cantidad);
float calcularTiempoTotal(Producto productos[], int cantidad);
int calcularRecursosTotales(Producto productos[], int cantidad);


void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int pedirCantidad() {
    int cantidad;
repetir:
    printf("Ingrese la cantidad de productos (max %d): ", MAX_PRODUCTOS);
    scanf("%d", &cantidad);
    if (cantidad < 1 || cantidad > MAX_PRODUCTOS) {
        printf("Cantidad inválida. Intente de nuevo.\n");
        goto repetir;
    }
    return cantidad;
}

void ingresarProductos(Producto productos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        limpiarBuffer();
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: ");
        fgets(productos[i].nombre, MAX_NOMBRE, stdin);
        productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0';
        printf("Precio: $ ");
        scanf("%f", &productos[i].precio);
        printf("Cantidad demandada: ");
        scanf("%d", &productos[i].cantidad);
        printf("Tiempo por unidad (horas): ");
        scanf("%f", &productos[i].tiempoFabricacion);
        printf("Recursos por unidad: ");
        scanf("%d", &productos[i].recursosPorUnidad);
    }
}

void mostrarProductos(Producto productos[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Precio: %.2f | Cantidad: %d | Tiempo/u: %.2f h | Recursos/u: %d\n",
               i+1,
               productos[i].nombre,
               productos[i].precio,
               productos[i].cantidad,
               productos[i].tiempoFabricacion,
               productos[i].recursosPorUnidad);
    }
}

void buscarProducto(Producto productos[], int cantidad) {
    char buscar[MAX_NOMBRE];
    limpiarBuffer();
    printf("Nombre del producto a buscar: ");
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].nombre, buscar) == 0) {
            printf("Producto encontrado: %s | Precio: %.2f\n",
                   productos[i].nombre, productos[i].precio);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarNombre(Producto productos[], int cantidad) {
    char buscar[MAX_NOMBRE];
    limpiarBuffer();
    printf("Nombre del producto a editar: ");
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].nombre, buscar) == 0) {
            printf("Nuevo nombre: ");
            fgets(productos[i].nombre, MAX_NOMBRE, stdin);
            productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0';
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarCantidad(Producto productos[], int cantidad) {
    char buscar[MAX_NOMBRE];
    limpiarBuffer();
    printf("Nombre del producto para editar cantidad: ");
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].nombre, buscar) == 0) {
            printf("Nueva cantidad: ");
            scanf("%d", &productos[i].cantidad);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void editarTiempo(Producto productos[], int cantidad) {
    char buscar[MAX_NOMBRE];
    limpiarBuffer();
    printf("Nombre del producto para editar tiempo: ");
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i].nombre, buscar) == 0) {
            printf("Nuevo tiempo por unidad: ");
            scanf("%f", &productos[i].tiempoFabricacion);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(Producto productos[], int *cantidad) {
    char buscar[MAX_NOMBRE];
    limpiarBuffer();
    printf("Nombre del producto a eliminar: ");
    fgets(buscar, MAX_NOMBRE, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(productos[i].nombre, buscar) == 0) {
            for (int j = i; j < *cantidad - 1; j++) {
                productos[j] = productos[j + 1];
            }
            (*cantidad)--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

float calcularTiempoTotal(Producto productos[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += productos[i].tiempoFabricacion * productos[i].cantidad;
    }
    return total;
}

int calcularRecursosTotales(Producto productos[], int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += productos[i].recursosPorUnidad * productos[i].cantidad;
    }
    return total;
}
