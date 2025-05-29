#include <stdio.h>
#include "FuncionesTaller8.h"

int main() {
    printf ("Bienvenido! \n Este programa optimiza la produccion en una Fabrica de Componentes Electronicos \n\n");
    
    int cantidad = pedirCantidad();

    // Variables para tiempo y recursos
    float TiempoDisponible,RecursosDisponibles_entrada;
    int RecursosDisponibles;


    // Pedir tiempo y recursos disponibles 
    do{
        printf ("Ingrese el tiempo total disponible (horas): ");
        if (scanf("%f",&TiempoDisponible)!=1)
        {
            //Comprueba si el valor no tiene letras
            printf("Debe de ingresar un número, ingrese de nuevo: \n");
            while (getchar()!='\n');
            goto valid;
        }
        if (TiempoDisponible <= 0) {
                printf("\tEl tiempo debe ser mayor a 0. Intente nuevamente.\n");
        }
    }while (TiempoDisponible <= 0);

    
    
    do{
        valid: 
        printf ("Ingrese los recursos totales disponibles: ");
        if (scanf("%f",&RecursosDisponibles_entrada)!=1){
            printf("Debe de ingresar un número, ingrese de nuevo:\n");
            while (getchar()!='\n');
        goto valid;
        }
        //Comprueba si el valor es entero o flotante
        if(ceilf(RecursosDisponibles_entrada)!=RecursosDisponibles_entrada){
            printf("Debe de ingresar un valor entero, ingrese de nuevo:\n");
            while (getchar()!='\n');
        goto valid;
        }
        RecursosDisponibles=RecursosDisponibles_entrada;
        if (RecursosDisponibles <= 0) {
            printf("\tLos recursos deben ser mayores a 0. Intente nuevamente.\n");
        }
    }while (RecursosDisponibles <= 0);
    

    //Llamada de funciones y estructura
    ingresarProductos(productos, cantidad);
    mostrarProductos(productos, cantidad);

    int opcion;
    do {
        
        printf("\n--- Menu ---\n");
        printf("1. Buscar producto por codigo o por nombre\n");
        printf("2. Mostrar todos los productos\n");        
        printf("3. Editar producto ( Nombre - Precio - Codigo - Cantidad - Recurso X Unidad - Tiempo)\n");
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
                EliminarProducto(productos, &cantidad,eliminados,&eliminadosCount);
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