#include <string.h>

#define MaximoProductos 10
#define MaximoNombre 30

// Declaraciones de funciones
int pedirCantidadProductos();
void ingresarProductos(char nombres[][MaximoNombre], float precios[], int cantidad);
void mostrarProductos(char nombres[][MaximoNombre], float precios[], int cantidad);
void buscarProducto(char nombres[][MaximoNombre], float precios[], int cantidad);
void productoMasCaro(char nombres[][MaximoNombre], float precios[], int cantidad);
void productoMasBarato(char nombres[][MaximoNombre], float precios[], int cantidad);
void precioPromedio(float precios[], int cantidad);
void menu(char nombres[][MaximoNombre], float precios[], int cantidad);
void limpiarBuffer();

// Funciones auxiliares
void limpiarBuffer() {
    fflush(stdin);
}

int pedirCantidadProductos() {
    int cantidad;

REPETIR:
    printf("Ingrese la cantidad de productos (maximo %d): ", MaximoProductos);
    scanf("%d", &cantidad);
    limpiarBuffer();

    if (cantidad < 1 || cantidad > MaximoProductos) {
        printf("Cantidad invalida. Intente nuevamente.\n");
        goto REPETIR;  // vuelve arriba
    }

    return cantidad;
}


void ingresarProductos(char nombres[][MaximoNombre], float precios[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("  Nombre: ");
        fgets(nombres[i], MaximoNombre, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
        printf("  Precio: $ ");
        scanf("%f", &precios[i]);
        limpiarBuffer();
    }
}

void mostrarProductos(char nombres[][MaximoNombre], float precios[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

void buscarProducto(char nombres[][MaximoNombre], float precios[], int cantidad) {
    char nombreBusqueda[MaximoNombre];
    printf("\nIngrese el nombre del producto a buscar: ");
    fgets(nombreBusqueda, MaximoNombre, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombreBusqueda, nombres[i]) == 0) {
            printf("Producto encontrado: %s - $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void productoMasCaro(char nombres[][MaximoNombre], float precios[], int cantidad) {
    int max = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[max]) {
            max = i;
        }
    }
    printf("Producto mas caro: %s - $%.2f\n", nombres[max], precios[max]);
}

void productoMasBarato(char nombres[][MaximoNombre], float precios[], int cantidad) {
    int min = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[min]) {
            min = i;
        }
    }
    printf("Producto mas barato: %s - $%.2f\n", nombres[min], precios[min]);
}

void precioPromedio(float precios[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += precios[i];
    }
    float promedio = suma / cantidad;
    printf("Precio promedio: $%.2f\n", promedio);
}

void menu(char nombres[][MaximoNombre], float precios[], int cantidad) {
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
        limpiarBuffer();

        switch (opcion) {
            case 1:
                buscarProducto(nombres, precios, cantidad);
                break;
            case 2:
                mostrarProductos(nombres, precios, cantidad);
                break;
            case 3:
                productoMasCaro(nombres, precios, cantidad);
                break;
            case 4:
                productoMasBarato(nombres, precios, cantidad);
                break;
            case 5:
                precioPromedio(precios, cantidad);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
}