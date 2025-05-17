#include <string.h>

#define MaximoProductos 5

struct Producto {
    char nombre[30];
    float precio;
    int codigo;
    int cantidad;
    int CantidadRecursos;
    int CantidadFabricada;
    float tiempoFabricacion; 
};
    //Llamada de funciones y estructura
struct Producto productos[MaximoProductos];
struct Producto eliminados[MaximoProductos];
int eliminadosCount = 0;


// Funciones
int pedirCantidad();
void ingresarProductos(struct Producto productos[], int cantidad);
void mostrarProductos(struct Producto productos[], int cantidad);
void editarProducto(struct Producto productos[], int cantidad);
void EliminarProducto(struct Producto productos[], int *cantidad,struct Producto eliminados[], int *eliminadosCount);
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
         
        //lectura de nombre y validacion de caracteres:
         char cadena[31]; // Máximo 50 caracteres + '\0'
         int exceso,buf;
   RepNom:
    exceso = 0;
     
    fgets(cadena, sizeof(cadena), stdin);

    // Elimina el salto de línea si está presente
    if (cadena[strlen(cadena) - 1] == '\n') {//si en la posición 50 hay un salto de línea
        cadena[strlen(cadena) - 1] = '\0'; //eliminar salto
        
    } else {
        // Si no hay '\n', significa que el usuario ingresó más de 50 caracteres
        exceso = 1;
    }

    // Limpiar el búfer si hubo exceso de caracteres
    if (exceso) {
        printf("Ingresaste más de 30 caracteres \n");
        do {
         buf = getchar(); // Leer un carácter
    } while (buf != '\n'); //elimina caracteres sobrantes hasta el salto de línea uno por uno
        goto RepNom;
    }
    strcpy(productos[i].nombre, cadena);

        //Ingrear precio y validacion de que sea mayor a 0
        do{
        printf("Precio: $ ");
        fflush(stdin);
        scanf("%f", &productos[i].precio);
            if (productos[i].precio <= 0) {
                printf("\tEl precio debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos[i].precio <= 0);
        
        printf("Codigo: ");
        scanf("%d", &productos[i].codigo);


        //Ingresar cantidad de demanda y validacion de que sea mayor a 0
        do{
            printf("Cantidad de demandada: ");
            scanf("%d", &productos[i].cantidad);
            if(productos[i].cantidad <= 0){
                printf("\tLa cantidad debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos[i].cantidad <= 0);

        do{
            printf ("Ingrese la cantidad de recursos para la fabricacion por unidad: ");
            scanf("%d", &productos[i].CantidadRecursos);
            if (productos[i].CantidadRecursos <= 0) {
                printf("\tLa cantidad de recursos debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos [i].CantidadRecursos <= 0);

        //Ingresar cantidad fabricada y validacion de que sea mayor a 0
        do{
            printf("Tiempo por unidad (horas): ");
            scanf("%f", &productos[i].tiempoFabricacion);
            if (productos[i].tiempoFabricacion <= 0) {
                printf("\tEl tiempo de fabricacion debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos[i].tiempoFabricacion <= 0);
    }
}


void mostrarProductos (struct Producto productos[], int cantidad) {
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s | Precio: %.2f | Codigo: %d | Cantidad: %d | Recursos X Unidad %d | Tiempo/u: %.2f h\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].cantidad,productos[i].CantidadRecursos, productos[i].tiempoFabricacion);
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
                printf("%d. %s | Precio: %.2f | Codigo: %d | Cantidad: %d | Recursos X Unidad %d | Tiempo/u: %.2f h\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].cantidad,productos[i].CantidadRecursos, productos[i].tiempoFabricacion);
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
            printf("%d. %s | Precio: %.2f | Codigo: %d | Cantidad: %d | Recursos X Unidad %d | Tiempo/u: %.2f h\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].codigo, productos[i].cantidad,productos[i].CantidadRecursos, productos[i].tiempoFabricacion);
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
    printf ("\t5. Recursos por Unidad\n");
    printf ("\t6. Precio\n");    
    printf ("\t7. Salir del menu de edicion\n");
    printf ("Seleccione una opcion: "); 
    fflush (stdin);
    scanf("%d", &opc2);

    // Casos
    switch (opc2) {
        case 1: // Cambio de Nombre
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

        case 2: //Cambio de Codigo
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

        case 3: //Tiempo de Fabricacion
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

        case 4: // Cantidad fabricada
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

        case 5: // Recursos por unidad
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese la nueva cantidad de recursos por unidad del producto: ");
                    fflush(stdin);
                    scanf("%d", &productos[i].CantidadRecursos);
                    printf("Recursos por unidad actualizados a: %d\n", productos[i].CantidadRecursos);
                    return;
                }
            }
            break;

        case 6: // Salir
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

        case 7: // Salir
            printf("Saliendo del menu de edicion...\n");
        break;

        default:
            printf("Opción inválida.\n");
        break;
    }
}


void EliminarProducto(struct Producto productos[], int *cantidad, struct Producto eliminados[], int *eliminadosCount){
    int code;
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf("%d", &code);
    fflush(stdin);

    for (int i = 0; i < *cantidad; i++) {
        if (productos[i].codigo == code) {
            // Copiar el producto a la lista de eliminados
            eliminados[*eliminadosCount] = productos[i];
            (*eliminadosCount)++;

            // Eliminar el producto del arreglo original
            for (int j = i; j < *cantidad - 1; j++) {
                productos[j] = productos[j + 1];
            }
            (*cantidad)--;

            printf("Producto eliminado y almacenado en la lista de eliminados.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}


void CalcularDemanda(struct Producto productos[], int cantidad, int tiempoDisponible, int recursosDisponibles) {
    int tiempoAcumulado = 0;
    int recursosAcumulados = 0;

    printf("Tiempo disponible: %d horas\n", tiempoDisponible);
    printf("Recursos disponibles: %d unidades\n", recursosDisponibles);
    printf("--- Demanda General ---\n");

    // Calcular acumulados
    for (int i = 0; i < cantidad; i++) {
        tiempoAcumulado += productos[i].tiempoFabricacion * productos[i].cantidad;
        recursosAcumulados += productos[i].CantidadRecursos * productos[i].cantidad;
    }

    // Mostrar resultados de tiempo
    printf("Tiempo total requerido: %d horas\n", tiempoAcumulado);
    if (tiempoAcumulado <= tiempoDisponible) {
        printf("Se cumple con la demanda de tiempo.\n");
    } else {
        printf("No se cumple con la demanda de tiempo. Excede por %d horas.\n", tiempoAcumulado - tiempoDisponible);
    }

    // Mostrar resultados de recursos
    printf("Recursos totales requeridos: %d unidades\n", recursosAcumulados);
    if (recursosAcumulados <= recursosDisponibles) {
        printf("Se cumple con la demanda de recursos.\n");
    } else {
        printf("No se cumple con la demanda de recursos. Excede por %d unidades.\n", recursosAcumulados - recursosDisponibles);
    }
}



