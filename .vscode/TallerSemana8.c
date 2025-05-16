#include <stdio.h>
#include "FuncionesTaller8.h"

int main() {
    int cantidad = pedirCantidad();

    // Variables para tiempo y recursos
    int TiempoDisponible;
    int RecursosDisponibles;


    // Pedir tiempo y recursos disponibles
    printf ("Ingrese el tiempo total disponible (horas): ");
    scanf("%d", &TiempoDisponible);
    printf ("Ingrese los recursos totales disponibles: ");
    scanf("%d", &RecursosDisponibles);

    struct Producto productos[MaximoProductos];
    ingresarProductos(productos, cantidad);
    printf("\n--- Productos Ingresados ---\n");
    mostrarProductos(productos, cantidad);

    int opcion;
    do {
        
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por codigo o por nombre\n");
        printf("2. Mostrar todos los productos\n");        
        printf("3. Editar producto ( Nombre - Codigo - Tiempo de Fabricacion - Cantidad de Producto - Precio)\n");
        printf("4. Eliminar algun producto por codigo\n");
        printf("5. Verificar si cumple con la demanda (horas - recursos)\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                buscarProducto(productos, cantidad);
                break;

            case 2:
                mostrarProductos(productos, cantidad);
                break;

            case 3:
                Editarproducto(productos, cantidad);
                break;

            case 4:
                EliminarProducto(productos, cantidad);
                break;
            
            case 5:
                CalcularDemanda(productos, cantidad, TiempoDisponible, RecursosDisponibles);
                break;

            case 6:
                printf ("Gracias por usar el programa. Adios! :)\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}






