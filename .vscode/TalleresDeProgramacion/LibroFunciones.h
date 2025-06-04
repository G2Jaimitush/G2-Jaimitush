#include <string.h>
#include <math.h>

#define MaximoLibros 10

struct Libros {
    int ID;
    char titulo[100];
    char autor[50];
    int FechaPublicacion;
    char estado[30];
};

int PedirCantidadDeLibros();
void IngresarLibros(struct Libros libros[], int cantidad);
void MostrarLibros(struct Libros libros[], int cantidad);
void EditarLibro(struct Libros libros[], int cantidad);
void MostrarLibro(struct Libros libros[], int cantidad);
void EliminarLibro(struct Libros libros[], int *cantidad, struct Libros eliminados[], int *eliminadosCount);

// Pedir cantidad de libros
int PedirCantidadDeLibros() {
    int cantidad;
    float cantidad_entrada;

REPETIR:
    printf("Ingrese la cantidad de libros (maximo %d): ", MaximoLibros);
    if (scanf("%f", &cantidad_entrada) != 1) {
        printf("Debe de ingresar un numero, ingrese de nuevo: \n");
        while (getchar() != '\n');
        goto REPETIR;
    }

    if (ceilf(cantidad_entrada) != cantidad_entrada) {
        printf("Debe de ingresar un valor entero, ingrese de nuevo:\n");
        while (getchar() != '\n');
        goto REPETIR;
    }

    cantidad = cantidad_entrada;

    if (cantidad < 1 || cantidad > MaximoLibros) {
        printf("Cantidad invalida. Intente nuevamente.\n");
        goto REPETIR;
    }

    return cantidad;
}

// Ingresar Libros
void IngresarLibros(struct Libros Libro[], int cantidad) {
    int codigoRepetido, valido;
    float codigo_entrada;

    for (int i = 0; i < cantidad; i++) {
        // ID del libro
        do {
            codigoRepetido = 0;
            valido = 1;
            printf("\nIngrese el ID del libro %d: ", i + 1);

            if (scanf("%f", &codigo_entrada) != 1) {
                printf("Debe ingresar un numero válido. Intente nuevamente:\n");
                while (getchar() != '\n');
                valido = 0;
            } else {
                while (getchar() != '\n');

                if (ceilf(codigo_entrada) != codigo_entrada) {
                    printf("El ID no puede contener decimales. Intente nuevamente:\n");
                    valido = 0;
                } else if (codigo_entrada <= 0) {
                    printf("El ID no puede ser negativo. Intente nuevamente:\n");
                    valido = 0;
                } else {
                    Libro[i].ID = (int)codigo_entrada;

                    for (int j = 0; j < i; j++) {
                        if (Libro[i].ID == Libro[j].ID) {
                            printf("El ID ya existe. Intente nuevamente:\n");
                            codigoRepetido = 1;
                            valido = 0;
                            break;
                        }
                    }
                }
            }
        } while (codigoRepetido == 1 || !valido);

        // Título del libro
        printf("Ingrese el titulo del libro %d: ", i + 1);
        char cadena[101];
        int exceso, buf;

REPETIRTITULO:
        exceso = 0;
        fgets(cadena, sizeof(cadena), stdin);

        if (cadena[strlen(cadena) - 1] == '\n') {
            cadena[strlen(cadena) - 1] = '\0';
        } else {
            exceso = 1;
        }

        if (exceso) {
            printf("Ingresaste mas de 100 caracteres\n");
            do {
                buf = getchar();
            } while (buf != '\n');
            goto REPETIRTITULO;
        }

        strcpy(Libro[i].titulo, cadena);

        // Autor del libro
        printf("Ingrese el autor del libro %d: ", i + 1);
        char autor[51];
        int exceso_autor, buf_autor;

REPETIRNOMBRE:
        exceso_autor = 0;
        fgets(autor, sizeof(autor), stdin);

        if (autor[strlen(autor) - 1] == '\n') {
            autor[strlen(autor) - 1] = '\0';
        } else {
            exceso_autor = 1;
        }

        if (exceso_autor) {
            printf("Ingresaste mas de 50 caracteres\n");
            do {
                buf_autor = getchar();
            } while (buf_autor != '\n');
            goto REPETIRNOMBRE;
        }

        strcpy(Libro[i].autor, autor);

        // Fecha de publicación

        int fecha;
valid:
        do {
            printf("Ingrese el periodo de publicacion del libro %d: ", i + 1);
            if (scanf("%d", &fecha) != 1 || fecha < 0) {
                printf("Periodo invalido. Debe ser un numero positivo. Intente nuevamente:\n");
                while (getchar()!='\n');
                goto valid;
            } 
            else{
                Libro[i].FechaPublicacion = fecha;
            }
            
            if (fecha < 0 || fecha > 2025) {
                printf("El periodo debe estar entre 0 y 2025. Intente nuevamente:\n");
            }
        } while (fecha < 0 || fecha > 2025); 

        // Estado del libro
        printf("Ingrese el estado del libro %d ('Disponible' o 'Prestado')\n", i + 1);
        printf("\tPresione (1) para 'Disponible' o (2) para 'Prestado': ");
        int estado;
        do {
            if (scanf("%d", &estado) != 1 || (estado != 1 && estado != 2)) {
                printf("Estado invalido. Debe ser 1 o 2. Intente nuevamente:\n");
                while (getchar() != '\n');
            } else {
                if (estado == 1) {
                    strcpy(Libro[i].estado, "Disponible");
                } else {
                    strcpy(Libro[i].estado, "Prestado");
                }
            }
        } while (estado != 1 && estado != 2);
    }
}


// Mostrar la lista de libros
void MostrarLibros(struct Libros libros[], int cantidad) {
    printf("\n%-6s | %-25s | %-20s | %-8s | %-12s\n", 
           "ID", "Titulo", "Autor", "Periodo", "Estado");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        printf("%-6d | %-25s | %-20s | %-8d | %-12s\n",
               libros[i].ID, libros[i].titulo, libros[i].autor, 
               libros[i].FechaPublicacion, libros[i].estado);
    }
}

// Para libros individuales
void mostrarencontrado(int i, struct Libros libros[]) {
    printf("\n%-6s | %-25s | %-20s | %-8s | %-12s\n", 
           "ID", "Titulo", "Autor", "Periodo", "Estado");
    printf("-------------------------------------------------------------------------------\n");

    printf("%-6d | %-25s | %-20s | %-8d | %-12s\n",
           libros[i].ID, libros[i].titulo, libros[i].autor,
           libros[i].FechaPublicacion, libros[i].estado);
}

// Búsqueda de libros
int buscarProducto(struct Libros libros[], int cantidad) {
    int code,opc;
    REPETIR:
    printf ("Ingrese como desea buscar el libro mediante ID o Nombre\n");
    printf ("\tPresione (1) para ID o (2) para Titulo: ");
    scanf("%d", &opc);
    getchar(); // Limpiar el buffer
    if (opc == 1){
        printf("Ingrese el ID del producto a buscar: ");
        scanf("%d", &code);
        getchar(); // Limpiar el buffer
        for (int i = 0; i < cantidad; i++) {
            if (libros[i].ID == code) {
                printf("Libro encontrado: ");
                mostrarencontrado(i, libros);
                return i;
            }
        }
    } else if (opc == 2) {
        printf("Ingrese el titulo del producto a buscar: ");
    } else {
        printf("Opcion invalida. Debe ser 1 o 2.\n");
        goto REPETIR;
    }
}

// Actualizar el estado
void Editarestado(struct Libros libros[], int cantidad) {
    int i = buscarProducto(libros, cantidad);
    if (i == -1) return;

    printf("Ingrese el estado del libro %d ('Disponible' o 'Prestado')\n", i + 1);
    printf("\tPresione (1) para 'Disponible' o (2) para 'Prestado': ");
    int estado;
    do {
        if (scanf("%d", &estado) != 1 || (estado != 1 && estado != 2)) {
            printf("Estado invalido. Debe ser 1 o 2. Intente nuevamente:\n");
            while (getchar() != '\n');
        } else {
            if (estado == 1) {
                strcpy(libros[i].estado, "Disponible");
            } else {
                strcpy(libros[i].estado, "Prestado");
            }
        }
    } while (estado != 1 && estado != 2);   
    mostrarencontrado(i, libros); 
}


// Editar Libros
void EditarLibro(struct Libros libros[], int cantidad) {
    int opc, code, opc1;
    int encontrado = 0;

    printf("Ingrese como desea editar el libro mediante el nombre o ID\n");
    printf("\tPresione (1) para ID o (2) para Titulo: ");
    scanf("%d", &opc);

    if (opc == 1) {
        printf("Ingrese el ID del libro a editar: ");
        scanf("%d", &code);
        getchar();

        for (int i = 0; i < cantidad; i++) {
            if (libros[i].ID == code) {
                encontrado = 1;
                printf("Libro encontrado: ");
                mostrarencontrado(i, libros);

                printf("\nSeleccione la opcion que desea editar:\n");
                printf("1. Editar ID\n");
                printf("2. Editar Titulo\n");
                printf("3. Editar Autor\n");
                printf("4. Editar Periodo\n");
                printf("5. Salir\n");
                printf("Opcion: ");
                scanf("%d", &opc1);
                getchar(); // Limpiar el buffer

                switch (opc1) {
                    case 1:{
                        int nuevoID;
                        printf("Ingrese el nuevo ID: ");
                        scanf("%d", &nuevoID);
                        libros[i].ID = nuevoID;
                        printf("ID actualizado a %d.\n", nuevoID);
                        break;
                    }
                    case 2: {
                        char nuevoTitulo[100];
                        printf("Ingrese el nuevo titulo: ");
                        fgets(nuevoTitulo, sizeof(nuevoTitulo), stdin);
                        if (nuevoTitulo[strlen(nuevoTitulo) - 1] == '\n')
                            nuevoTitulo[strlen(nuevoTitulo) - 1] = '\0';
                        strcpy(libros[i].titulo, nuevoTitulo);
                        printf("Titulo actualizado a '%s'.\n", nuevoTitulo);
                    break;
                    }

                    case 3: {
                        char nuevoAutor[50];
                        printf("Ingrese el nuevo autor: ");
                        fgets(nuevoAutor, sizeof(nuevoAutor), stdin);
                        if (nuevoAutor[strlen(nuevoAutor) - 1] == '\n')
                            nuevoAutor[strlen(nuevoAutor) - 1] = '\0';
                        strcpy(libros[i].autor, nuevoAutor);
                        printf("Autor actualizado a '%s'.\n", nuevoAutor);
                    break;
                    }

                    case 4: {
                        int nuevoPeriodo;
                        printf("Ingrese el nuevo periodo de publicacion: ");
                        while (scanf("%d", &nuevoPeriodo) != 1 || nuevoPeriodo < 0 || nuevoPeriodo > 2025) {
                            printf("Periodo invalido. Intente nuevamente:\n");
                            while (getchar() != '\n');
                        }
                        libros[i].FechaPublicacion = nuevoPeriodo;
                        printf("Periodo actualizado a %d.\n", nuevoPeriodo);
                    break;
                    }

                    case 5:
                        printf("Saliendo de la edicion del libro.\n");
                    break;

                    default:
                        printf("Opcion invalida.\n");
                } break;
            }
        }

        if (!encontrado){
            printf("Libro no encontrado.\n");
        }
            
    }else if (opc == 2){
        printf("Ingrese el titulo del libro a editar: ");
        fflush(stdin);
        char tituloBusqueda[100];
        fgets(tituloBusqueda, sizeof(tituloBusqueda), stdin);
        //Eliminar el salto de línea al final del título
        tituloBusqueda[strcspn(tituloBusqueda, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < cantidad; i++) {
            libros[i].titulo[strcspn(libros[i].titulo, "\n")] = '\0'; // Eliminar salto de línea
            if (strcmp(tituloBusqueda, libros[i].titulo) == 0) {
                encontrado = 1;
                printf("Libro encontrado: ");
                mostrarencontrado(i, libros);

                    printf("\nSeleccione la opcion que desea editar:\n");
                    printf("1. Editar ID\n");
                    printf("2. Editar Titulo\n");
                    printf("3. Editar Autor\n");
                    printf("4. Editar Periodo\n");
                    printf("5. Salir\n");
                    printf("Opcion: ");
                    scanf("%d", &opc1);
                    getchar(); // Limpiar el buffer

                    switch (opc1) {
                    case 1:{
                        int nuevoID;
                        printf("Ingrese el nuevo ID: ");
                        scanf("%d", &nuevoID);
                        libros[i].ID = nuevoID;
                        printf("ID actualizado a %d.\n", nuevoID);
                        break;
                    }
                    case 2: {
                        char nuevoTitulo[100];
                        printf("Ingrese el nuevo titulo: ");
                        fgets(nuevoTitulo, sizeof(nuevoTitulo), stdin);
                        if (nuevoTitulo[strlen(nuevoTitulo) - 1] == '\n')
                            nuevoTitulo[strlen(nuevoTitulo) - 1] = '\0';
                        strcpy(libros[i].titulo, nuevoTitulo);
                        printf("Titulo actualizado a '%s'.\n", nuevoTitulo);
                    break;
                    }

                    case 3: {
                        char nuevoAutor[50];
                        printf("Ingrese el nuevo autor: ");
                        fgets(nuevoAutor, sizeof(nuevoAutor), stdin);
                        if (nuevoAutor[strlen(nuevoAutor) - 1] == '\n')
                            nuevoAutor[strlen(nuevoAutor) - 1] = '\0';
                        strcpy(libros[i].autor, nuevoAutor);
                        printf("Autor actualizado a '%s'.\n", nuevoAutor);
                    break;
                    }

                    case 4: {
                        int nuevoPeriodo;
                        printf("Ingrese el nuevo periodo de publicacion: ");
                        while (scanf("%d", &nuevoPeriodo) != 1 || nuevoPeriodo < 0 || nuevoPeriodo > 2025) {
                            printf("Periodo invalido. Intente nuevamente:\n");
                            while (getchar() != '\n');
                        }
                        libros[i].FechaPublicacion = nuevoPeriodo;
                        printf("Periodo actualizado a %d.\n", nuevoPeriodo);
                    break;
                    }
                    
                    case 5:
                        printf("Saliendo de la edicion del libro.\n");
                    break;

                    default:
                        printf("Opcion invalida.\n");
                }break;
            }
        }
        if (!encontrado) {
            printf("Libro no encontrado.\n");
        } 
                
    }else{
        printf("Opcion invalida. Debe ser 1 o 2.\n");
    }
}


//Mostrar todos los libros ingresados e actualizados
void MostrarLibro(struct Libros libros[], int cantidad) {
    printf("\n%-6s | %-25s | %-20s | %-8s | %-12s\n", 
           "ID", "Titulo", "Autor", "Periodo", "Estado");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        printf("%-6d | %-25s | %-20s | %-8d | %-12s\n",
               libros[i].ID, libros[i].titulo, libros[i].autor, 
               libros[i].FechaPublicacion, libros[i].estado);
    }
}


// Eliminar un libro
void EliminarLibro(struct Libros libros[], int *cantidad, struct Libros eliminados[], int *eliminadosCount){
    int code;
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf("%d", &code);
    fflush(stdin);

    for (int i = 0; i < *cantidad; i++) {
        if (libros[i].ID == code) {
            // Copiar el producto a la lista de eliminados
            eliminados[*eliminadosCount] = libros[i];
            (*eliminadosCount)++;

            // Eliminar el producto del arreglo original
            for (int j = i; j < *cantidad - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*cantidad)--;

            printf("Producto eliminado y almacenado en la lista de eliminados.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}