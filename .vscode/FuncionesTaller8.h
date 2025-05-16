#include <string.h>

#define MaximoProductos 5

struct Producto {
    char nombre[30];
    float precio;
    int codigo;
    int cantidad;
    int CantidadFabricada;
    float tiempoFabricacion; 
};

// Funciones
int pedirCantidad();
void ingresarProductos(struct Producto productos[], int cantidad);
void mostrarProductos(struct Producto productos[], int cantidad);
void editarProducto(struct Producto productos[], int cantidad);
void EliminarProducto(struct Producto productos[], int cantidad);
void CalcularDemanda(struct Producto productos[], int cantidad, int tiempoDisponible, int recursosDisponibles);


// Definiciones de funciones
int pedirCantidad() {
    int cantidad;

REPETIR:
    printf("Ingrese la cantidad de productos (maximo %d): ", MaximoProductos);
    scanf("%d", &cantidad);
    fflush(stdin);

    if (cantidad < 1 || cantidad > MaximoProductos) {
        printf("Cantidad invalida. Intente nuevamente.\n");
        goto REPETIR;
    }

    return cantidad;
}

void ingresarProductos(struct Producto productos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: ");
        getchar(); // Limpiar el buffer
        fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);
        printf("Precio: $ ");
        fflush(stdin);
        scanf("%f", &productos[i].precio);
        printf("Codigo: ");
        scanf("%d", &productos[i].codigo);
        printf("Cantidad demandada: ");
        scanf("%d", &productos[i].cantidad);
        printf("Tiempo por unidad (horas): ");
        scanf("%f", &productos[i].tiempoFabricacion);
    }
}


void mostrarProductos (struct Producto productos[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Precio: %.2f | Codigo: %d | Cantidad: %d | Tiempo/u: %.2f h\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].cantidad, productos[i].tiempoFabricacion);
    }
}


void buscarProducto(struct Producto productos[], int cantidad){
    int code, opc2;
    printf("\t Si desea buscar por codigo presione (1)\n");
    printf("\t Si desea buscar por nombre presione (2)\n");
    scanf("%d", &opc2);
    fflush(stdin);

    if (opc2 == 1) {
        printf("Ingrese el codigo del producto a buscar: ");
        scanf("%d", &code);
        fflush(stdin);
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].codigo == code) {
                printf("Producto encontrado: %s | Precio: %.2f | Codigo: %d | Tiempo/u: %.2f h\n",productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].tiempoFabricacion);
                return;
            }
        }
        printf("Producto no encontrado.\n");

    }else if (opc2 == 2) {
        printf("Ingrese el nombre del producto a buscar: ");
        fflush(stdin);
        char nombreBusqueda[50];
        fgets(nombreBusqueda, sizeof(nombreBusqueda), stdin);
        // Eliminar el salto de línea al final del nombre
        nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0';


        int encontrado = 0;
        for (int i = 0; i < cantidad; i++) {
            productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0';
            if (strcmp(nombreBusqueda, productos[i].nombre) == 0) {
                printf("Producto encontrado: %s | Precio: %.2f | Codigo: %d | Tiempo/u: %.2f h\n",productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].tiempoFabricacion);
                encontrado = 1;
                break;
            }
        }
    } 
    else {
        printf("Opcion invalida.\n");
    }
}

void Editarproducto(struct Producto productos[], int cantidad) {
    int code, opc2;
    for (int i = 0; i < cantidad; i++){
        printf("Ingrese el codigo del producto a editar: ");
        fflush(stdin);
        scanf("%d", &code);
        if (productos[i].codigo == code) {
            printf("Producto encontrado: %s | Precio: %.2f | Codigo: %d | Tiempo/u: %.2f h\n", productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].tiempoFabricacion);
            break;
        } else {
            printf("Producto no encontrado.\n");
            return;
        }
    }

    
    printf("Selecciona que quieres editar del producto: \n");
    printf ("\t1. Nombre\n");
    printf ("\t2. Codigo\n");
    printf ("\t3. Tiempo de Fabricacion\n");
    printf ("\t4. Cantidad Fabricada\n");
    printf ("\t5. Precio\n");    
    printf ("Seleccione una opcion: "); 
    fflush (stdin);
    scanf("%d", &opc2);

    // Casos
    switch (opc2) {
        case 1:
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese el nuevo nombre del producto: ");
                    fflush(stdin); // Limpiar el buffer
                    fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);
                    productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0'; // Eliminar salto
                    printf("Nombre actualizado a: %s\n", productos[i].nombre);
                    return;
                }
            }
            break;

        case 2:
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese el nuevo codigo del producto: ");
                    fflush(stdin);
                    scanf("%d", &productos[i].codigo);
                    printf("Codigo actualizado a: %d\n", productos[i].codigo);
                    return;
                }
            }
            break;

        case 3:
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese el nuevo Tiempo de Fabricacion del producto: ");
                    fflush(stdin);
                    scanf("%f", &productos[i].tiempoFabricacion);
                    printf("Tiempo de Fabricacion actualizado a: %.2f\n", productos[i].tiempoFabricacion);
                    return;
                }
            }
            break;

        case 4: // cantidad fabricada
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese la nueva cantidad fabricada del producto: ");
                    fflush(stdin);
                    scanf("%d", &productos[i].CantidadFabricada);
                    printf("Cantidad fabricada actualizada a: %d\n", productos[i].CantidadFabricada);
                    return;
                }
            }
            break;

        case 5: // precio
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese el nuevo precio del producto: ");
                    fflush(stdin);
                    scanf("%f", &productos[i].precio);
                    printf("Precio actualizado a: %.2f\n", productos[i].precio);
                    return;
                }
            }
            break;

        default:
            printf("Opción inválida.\n");
            break;
    }
}


void EliminarProducto(struct Producto productos[], int cantidad) {
    int code;
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf("%d", &code);
    fflush(stdin);

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == code) {
            for (int j = i; j < cantidad - 1; j++) {
                productos[j] = productos[j + 1];
            }
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void CalcularDemanda(struct Producto productos[], int cantidad, int tiempoDisponible, int recursosDisponibles) {
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].tiempoFabricacion * productos[i].cantidad <= tiempoDisponible && productos[i].cantidad <= recursosDisponibles) {
            printf("Se cumple con la demanda con los productos %d\n", productos[i].nombre);
        } else {
            printf("No se cumple con la demanda con los productos %d\n", productos[i].nombre);
        }
    }
}


