#include <stdio.h>
#include "TallerOptimizacion.h"

int main() {
    char nombres[MaximoProductos][MaximoNombre];
    float precios[MaximoProductos],promedio;
    int cantidad = pedirCantidad();
   // int *ptr=&nombres;
    
    float Prom (float precios[], int cantidad),suma;

    ingresarProductos(nombres, precios, cantidad);
    mostrarProductos(nombres, precios, cantidad);

    int opcion;
    
    do {   
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por nombre\n");
        printf("2. Mostrar todos los productos y el precio total del inventario\n");
        printf("3. Editar nombre\n");
        printf("4. Eliminar producto\n");
        printf("5. Editar cantidades\n");
        printf ("6. Editar tiempo total de fabricación requerido\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: buscarProducto(nombres, precios, cantidad); 
                break;
            case 2: mostrarProductos(nombres, precios, cantidad); 
                break;
            case 3:  editarProducto(nombres, precios, cantidad); 
                break;
            case 4: eliminarProducto(nombres, precios, cantidad); //mejorar función para que elimine y se recorra
                break;
            case 5: 
           //Ingresar función (reutilizar edición de nombre)
                break;
            case 6:
            //ingresar función
                break;
            default: printf("Opcion no válida. Intente de nuevo.\n");
        }
    } while (opcion != 7);

    return 0;
}