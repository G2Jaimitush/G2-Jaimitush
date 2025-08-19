#include <stdio.h>
#include "LibroFunciones.h"

int main (){

    struct Libros libros[10];
    struct Libros eliminados[10];
    int eliminadosCount = 0;
    int opc;
    printf ("Bienvenido a la Biblioteca!\n");

    int cantidad = PedirCantidadDeLibros();
    IngresarLibros(libros, cantidad);
    MostrarLibros(libros, cantidad);

    do{
        printf ("------ Menu de Opciones ------\n");
        printf ("1. Buscar un libro\n");
        printf ("2. Editar el estado de un libro\n");
        printf ("3. Editar un libro (ID - Titulo - Autor - Periodo - Estado)\n");
        printf ("4. Mostrar todos los libros\n");
        printf ("5. Eliminar un libro\n");
        printf ("6. Agregar un libro\n");
        printf ("7. Salir\n");
        printf ("Seleccione una opcion: ");
        scanf("%d", &opc);
        fflush(stdin);
        switch (opc){
            case 1:
                buscarProducto(libros, cantidad);
            break;
            
            case 2:
                Editarestado(libros, cantidad);
            break;

            case 3:
                EditarLibro(libros, cantidad);
            break;

            case 4:
                MostrarLibros(libros, cantidad);
            break;

            case 5:
                EliminarLibro(libros, &cantidad, eliminados, &eliminadosCount);
            break;
            
            case 6:
                Agregarlibro(libros, &cantidad);
            break;

            default:
                printf ("Opcion invalida, intente de nuevo\n");
            break;
        }
    }while (opc != 7);

    return 0;

}