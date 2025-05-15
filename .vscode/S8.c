#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int codigo;
    int cantidad;
    float precio;
} Producto;

void eliminarProducto(Producto productos[], int *cantidad);

int main() {
    int numProductos;
    
    // Definir número de productos
    printf("Ingrese la cantidad de productos máximo: ");
    scanf("%d", &numProductos);
    
    Producto productos[numProductos]; // Array de productos

    // Ingreso de productos
    printf("\tIngreso de Productos\n");
    for (int i = 0; i < numProductos; i++) {
        fflush(stdin);
        printf("\nProducto %d:\n", i + 1);
        printf("Ingrese el nombre del producto: ");
        fgets(productos[i].nombre, 30, stdin);
        productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0';  // Eliminar salto de línea
        printf("Ingrese código: ");
        scanf("%d", &productos[i].codigo);
        printf("Ingrese la cantidad: ");
        scanf("%d", &productos[i].cantidad);
        printf("Ingrese el precio: ");
        scanf("%f", &productos[i].precio);
        fflush(stdin);
    }

    // despliegue productos 1
    printf("\nLista de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d: %s (Código: %d, Cantidad: %d, Precio: %.2f)\n",
               i + 1, productos[i].nombre, productos[i].codigo, productos[i].cantidad, productos[i].precio);
    }

    // Eliminar un producto
    eliminarProducto(productos, &numProductos);

    // despliegue lista actualizada
    printf("\nLista actualizada de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto %d: %s (Código: %d, Cantidad: %d, Precio: %.2f)\n",
               i + 1, productos[i].nombre, productos[i].codigo, productos[i].cantidad, productos[i].precio);
    }

    return 0;
}

void eliminarProducto(Producto productos[], int *cantidad) {
    char nombreBusqueda[30];
    printf("\nIngrese el nombre del producto a eliminar: ");
    fflush(stdin);
    fgets(nombreBusqueda, 30, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';  // Eliminar el salto de línea

    int encontrado = -1;
    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(nombreBusqueda, productos[i].nombre) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Producto encontrado: %s - $%.2f\n", productos[encontrado].nombre, productos[encontrado].precio);

        // Eliminar el producto desplazando el resto del array
        for (int i = encontrado; i < *cantidad - 1; i++) {
            productos[i] = productos[i + 1];
        }
        
        (*cantidad)--;  // Reducir cantidad de productos
        printf("Producto eliminado.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}