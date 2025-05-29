#include <string.h>
#include <math.h>
#include <ctype.h>
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
void CalcularDemanda(struct Producto productos[], int cantidad, float tiempoDisponible, int recursosDisponibles);


// Definiciones de funciones
int pedirCantidad() {
    int cantidad;
    float cantidad_entrada;

REPETIR:
    printf("Ingrese la cantidad de productos (maximo %d): ", MaximoProductos);
    if (scanf("%f", &cantidad_entrada)!=1)
    {
        printf("Debe de ingresar un número, ingrese de nuevo: \n ");
        while (getchar()!='\n');
        goto REPETIR;
    }
    //Comprueba si el valor es entero o flotante
    if(ceilf(cantidad_entrada)!=cantidad_entrada){
        printf("Debe de ingresar un valor entero, ingrese de nuevo:\n");
        while (getchar()!='\n');
        goto REPETIR;
    }
    cantidad=cantidad_entrada;
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
        printf("Ingresaste mas de 30 caracteres \n");
        do {
         buf = getchar(); // Leer un carácter
    } while (buf != '\n'); //elimina caracteres sobrantes hasta el salto de línea uno por uno
        goto RepNom;
    }
    strcpy(productos[i].nombre, cadena);

        //Ingrear precio y validacion de que sea mayor a 0
        do{
            valid:
            printf("Precio: $ ");
            fflush(stdin);
            if (scanf("%f",&productos[i].precio)!=1){
                printf("Debe de ingresar un numero, ingrese de nuevo: \n ");
                while (getchar()!='\n');
                goto valid;
            }
            if (productos[i].precio <= 0) {
                printf("\tEl precio debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos[i].precio <= 0);
        

        //Ingreso del codigo
        int CodidoRepetido;
        int valido;
        float codigo_entrada;
        do{
            CodidoRepetido = 0; //Reinicia a que el codigo no sea repetido
            valido = 1;
            printf("Codigo: ");
            fflush(stdin);
            if (scanf("%f", &codigo_entrada) != 1) {
                printf("\tDebe ingresar un número válido. Intente nuevamente.\n");
                while (getchar() != '\n');
                valido = 0;
            } else if (ceilf(codigo_entrada) != codigo_entrada) {
                printf("\tEl codigo no puede contener decimales. Intente nuevamente.\n");
                while (getchar() != '\n');
                valido = 0;
            } else if (codigo_entrada < 0) {
                printf("\tEl codigo no puede ser negativo. Intente nuevamente.\n");
                valido = 0;
            }

        if (valido) {
            productos[i].codigo = (int)codigo_entrada;

            for (int j = 0; j < i; j++) {
                if (productos[i].codigo == productos[j].codigo) {
                    printf("\tEl codigo ya existe. Intente nuevamente.\n");
                    CodidoRepetido = 1;
                    break;
                }
            }
        }

    } while (CodidoRepetido == 1 || codigo_entrada < 0 || ceilf(codigo_entrada) != codigo_entrada);


        //Ingresar cantidad de demanda y validacion de que sea mayor a 0
        do{
            float demanda_entrada;
            valid_demanda: 
            demanda_entrada=0;
            printf("Cantidad de demandada: ");
            if (scanf("%f",&demanda_entrada)!=1){
                printf("Debe de ingresar un numero, ingrese de nuevo: \n ");
                while (getchar()!='\n');
                goto valid_demanda;
            }
            //Comprueba si el valor es entero o flotante
            if(ceilf(demanda_entrada)!=demanda_entrada){
                printf("Debe de ingresar un valor entero, ingrese de nuevo:\n ");
                while (getchar()!='\n');
                goto valid_demanda;
            }
            productos[i].cantidad=demanda_entrada;
            if(productos[i].cantidad <= 0){
                printf("\tLa cantidad debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos[i].cantidad <= 0);

        do{
            float recursos_entrada;
            valid_recursos: 
            printf ("Ingrese la cantidad de recursos para la fabricacion por unidad: ");
            if (scanf("%f",&recursos_entrada)!=1){
                printf("Debe de ingresar un número, ingrese de nuevo: \n ");
                while (getchar()!='\n');
                goto valid_recursos;
            }
            //Comprueba si el valor es entero o flotante
            if(ceilf(recursos_entrada)!=recursos_entrada){
                printf("Debe de ingresar un valor entero, ingrese de nuevo:\n ");
                while (getchar()!='\n');
                goto valid_recursos;
            }
            productos[i].CantidadRecursos=recursos_entrada;
            if (productos[i].CantidadRecursos <= 0) {
                printf("\tLa cantidad de recursos debe ser mayor a 0. Intente nuevamente.\n");
            }
        }while (productos [i].CantidadRecursos <= 0);

        //Ingresar cantidad fabricada y validacion de que sea mayor a 0
        do{
            valid1:
            printf("Tiempo por unidad (horas): ");
            if (scanf("%f",&productos[i].tiempoFabricacion)!=1){
                printf("Debe de ingresar un número, ingrese de nuevo: \n ");
                while (getchar()!='\n');
                goto valid1;
            }
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
    int code, opc2, indice = -1;
    int CodigoRepetido;
    float recursos_entrada;
    float recursos_unidad;
    float codigo_entrada;
    int valido;

    printf("Ingrese el codigo del producto a editar: ");
    fflush(stdin);
    scanf("%d", &code);
    // Buscar el producto
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].codigo == code) {
            indice = i;
            break;
        }
    }

    // Verificar si se encontró
    if (indice == -1) {
        printf("Producto no encontrado.\n");
        return;
    }
    
    // Mostrar el producto encontrado
    printf ("Prodcto Encontrado: \n");
    printf("%d. %s | Precio: %.2f | Codigo: %d | Cantidad: %d | Recursos X Unidad: %d | Tiempo/u: %.2f h\n",indice + 1, productos[indice].nombre, productos[indice].precio,productos[indice].codigo, productos[indice].cantidad,productos[indice].CantidadRecursos, productos[indice].tiempoFabricacion);

    // Menú de edición
    
    printf("Selecciona que quieres editar del producto: \n");
    printf ("\t1. Nombre\n");
    printf ("\t2. Precio\n");
    printf ("\t3. Codigo\n");
    printf ("\t4. Cantidad\n");
    printf ("\t5. Recursos por Unidad\n");
    printf ("\t6. Tiempo\n");    
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

        case 2: //Cambio de Precio
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

        case 3: //Cambio de Codigo
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    do{
                        CodigoRepetido = 0; //Reinicia a que el codigo no sea repetido
                        valido = 1;
                        printf("Ingrese el nuevo codigo del producto: ");
                        fflush(stdin);
                        if (scanf("%f", &codigo_entrada) != 1) {
                        printf("Debe ingresar un número válido. Intente nuevamente:\n");
                        while (getchar() != '\n');
                        valido = 0;
                    }else if (ceilf(codigo_entrada) != codigo_entrada) {
                        printf("El codigo no puede contener decimales. Intente nuevamente:\n");
                        while (getchar() != '\n');
                        valido = 0;
                    }else if (codigo_entrada <= 0) {
                        printf("El codigo no puede ser negativo. Intente nuevamente:\n");
                        valido = 0;
                    } else{
                        productos[i].codigo = (int)codigo_entrada;

                    // Verificar si el código ya existe en otro producto
                    for (int j = 0; j < cantidad; j++) {
                        if (j != i && productos[i].codigo == productos[j].codigo) {
                            printf("El codigo ya existe. Intente nuevamente:\n");
                            CodigoRepetido = 1;
                            valido = 0;
                            break;
                        }
                    }
                }

            } while (valido == 0 || CodigoRepetido == 1);

            printf("Codigo actualizado a: %d\n", productos[i].codigo);
            return;
            }
        }
        break;

        case 4: // Cantidad de demanda por Producto
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
            REPETIR:
                printf("Ingrese la nueva cantidad demandada del producto: ");
                fflush(stdin);

                if (scanf("%f", &recursos_entrada) != 1) {
                    printf("Debe de ingresar un número válido. Intente nuevamente:\n");
                    while (getchar() != '\n'); // Limpiar buffer
                    goto REPETIR;
                }

                if (ceilf(recursos_entrada) != recursos_entrada) {
                    printf("Debe de ingresar un valor entero. Intente nuevamente:\n");
                    while (getchar() != '\n');
                    goto REPETIR;
                }

                if (recursos_entrada <= 0) {
                    printf("La cantidad debe ser mayor a 0. Intente nuevamente:\n");
                    goto REPETIR;
                }
                productos[i].cantidad = (int)recursos_entrada;
                printf("Cantidad demandada actualizada a: %d\n", productos[i].cantidad);
            return;
            }
        }
        break;


        case 5: // Recursos por unidad
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    REPETIR_RECURSOS:
                    printf("Ingrese la nueva cantidad de recursos por unidad del producto: ");
                    fflush(stdin);
                    if (scanf("%f", &recursos_unidad) != 1) {
                        printf("Debe de ingresar un número válido. Intente nuevamente:\n");
                        while (getchar() != '\n'); // Limpiar buffer
                        goto REPETIR_RECURSOS;
                    }

                    if (ceilf(recursos_unidad) != recursos_unidad) {
                        printf("Debe de ingresar un valor entero. Intente nuevamente:\n");
                        while (getchar() != '\n');
                        goto REPETIR_RECURSOS;
                    }

                    if (recursos_unidad <= 0) {
                        printf("La cantidad de recursos debe ser mayor a 0. Intente nuevamente:\n");
                        goto REPETIR_RECURSOS;
                    }
                    productos[i].CantidadRecursos = (int)recursos_unidad;
                    printf("Recursos por unidad actualizados a: %d\n", productos[i].CantidadRecursos);
                    return;
                }
            }
            break;

        case 6: // Cambio de Tiempo
            for (int i = 0; i < cantidad; i++) {
                if (productos[i].codigo == code) {
                    printf("Ingrese el nuevo tiempo de fabricacion por unidad del producto: ");
                    fflush(stdin);
                    scanf("%f", &productos[i].tiempoFabricacion);
                    printf("Tiempo de fabricacion actualizado a: %.2f\n", productos[i].tiempoFabricacion);
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


void CalcularDemanda(struct Producto productos[], int cantidad, float tiempoDisponible, int recursosDisponibles) {
    float tiempoAcumulado = 0;
    int recursosAcumulados = 0;

    printf("Tiempo disponible: %.2f horas\n", tiempoDisponible);
    printf("Recursos disponibles: %d unidades\n", recursosDisponibles);
    printf("--- Demanda General ---\n");

    // Calcular acumulados
    for (int i = 0; i < cantidad; i++) {
        tiempoAcumulado += productos[i].tiempoFabricacion * productos[i].cantidad;
        recursosAcumulados += productos[i].CantidadRecursos * productos[i].cantidad;
    }

    // Mostrar resultados de tiempo
    printf("Tiempo total requerido: %.2f horas\n", tiempoAcumulado);
    if (tiempoAcumulado <= tiempoDisponible) {
        printf("Se cumple con la demanda de tiempo.\n");
    } else {
        printf("No se cumple con la demanda de tiempo. Excede por %.2f horas.\n", tiempoAcumulado - tiempoDisponible);
    }

    // Mostrar resultados de recursos
    printf("Recursos totales requeridos: %d unidades\n", recursosAcumulados);
    if (recursosAcumulados <= recursosDisponibles) {
        printf("Se cumple con la demanda de recursos.\n");
    } else {
        printf("No se cumple con la demanda de recursos. Excede por %d unidades.\n", recursosAcumulados - recursosDisponibles);
    }
}