#include <string.h>

#define MaximoProductos 10
#define MaximoNombre 30

int pedirCantidad();
void ingresarProductos(char (*nombres)[MaximoNombre], float *tiempos, int *cantidades, int *recursos, int cantidad);
void mostrarProductos(char (*nombres)[MaximoNombre], float *tiempos, int *cantidades, int *recursos, int cantidad);
void buscarProducto(char (*nombres)[MaximoNombre], float *tiempos, int *cantidades, int *recursos, int cantidad);
void editarProducto(char (*nombres)[MaximoNombre], float *tiempos, int *cantidades, int *recursos, int cantidad);
void eliminarProducto(char (*nombres)[MaximoNombre], float *tiempos, int *cantidades, int *recursos, int *cantidad);
void editarCantidad(char (*nombres)[MaximoNombre], int *cantidades, int cantidad);
void editarTiempo(char (*nombres)[MaximoNombre], float *tiempos, int cantidad);
void verificarCapacidad(float *tiempos, int *recursos, int *cantidades, int cantidad, float tiempoDisponible, int recursoDisponible);

int pedirCantidad() {
    int cantidad;

    REPETIR:
    printf("Ingrese la cantidad de productos (max %d): ", MaximoProductos);
    scanf("%d", &cantidad);

    if (cantidad < 1 || cantidad > MaximoProductos) {
        printf("Cantidad inválida. Debe estar entre 1 y %d.\n", MaximoProductos);
        goto REPETIR;
    }

    return cantidad;
}


