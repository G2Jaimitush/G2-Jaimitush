#include <stdio.h>
#include "FuncionesTaller6_Mercado.h"


// Función principal
int main() {
    char nombres[MaximoProductos][MaximoNombre];
    float precios[MaximoProductos];
    int cantidad;

    cantidad = pedirCantidadProductos();
    ingresarProductos(nombres, precios, cantidad);
    mostrarProductos(nombres, precios, cantidad);
    menu(nombres, precios, cantidad);

    return 0;
}






