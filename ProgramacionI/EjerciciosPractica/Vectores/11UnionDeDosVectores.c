#include <stdio.h>

void OrdenarVectorMenor (int VectorUnion [], int totalUnion);
void OrdenarVectorMayor (int VectorUnion [], int totalUnion); 

int main() {
    int i;

    // Dimensión de los vectores
    printf("Ingrese la dimension de los vectores: ");
    scanf("%d", &i);

    int Vector1[i], Vector2[i], VectorUnion[i * 2],VectorMayor[i*2], VectorMenor [i*2];
    int totalUnion = 0; // contador para la longitud real de VectorUnion

    // Ingreso de elementos del primer vector
    printf("\tIngrese los elementos del primer vector:\n");
    for (int j = 0; j < i; j++) {
        printf("Ingrese el elemento del primer vector [%d]: ", j);
        scanf("%d", &Vector1[j]);
    }

    // Ingreso de elementos del segundo vector
    printf("\tIngrese los elementos del segundo vector:\n");
    for (int j = 0; j < i; j++) {
        printf("Ingrese el elemento del segundo vector [%d]: ", j);
        scanf("%d", &Vector2[j]);
    }

    //Despliegue de los elementos del primer vector
    printf("\n\tElementos del primer vector:\n");
    for (int j = 0; j < i; j++){            
        printf ("El elemnto del primer vector [%d] es: %d\n",j, Vector1 [j]);
    }

    //Despliegue de los elementos del segundo vector
    printf("\n\tElementos del segundo vector:\n");
    for (int j = 0; j < i; j++){            
        printf ("El elemnto del segundo vector [%d] es: %d\n",j, Vector1 [j]);
    }

    // Unión de Vector1 y Vector2 sin duplicados
    for (int j = 0; j < i; j++) {
        int repetido = 0;
        for (int k = 0; k < totalUnion; k++) {
            if (Vector1[j] == VectorUnion[k]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            VectorUnion[totalUnion++] = Vector1[j];
        }
    }

    for (int j = 0; j < i; j++) {
        int repetido = 0;
        for (int k = 0; k < totalUnion; k++) {
            if (Vector2[j] == VectorUnion[k]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            VectorUnion[totalUnion++] = Vector2[j];
        }
    }

    // Mostrar los elementos del vector unión
    printf("\n\tElementos del vector unión:\n");
    for (int j = 0; j < totalUnion; j++) {
        printf("La union del vector en el elemento [%d]: %d\n", j, VectorUnion[j]);
    }

    // Copiar el vector unión a VectorMayor
    for (int j = 0; j < totalUnion; j++) {
        VectorMayor[j] = VectorUnion[j];
    }
    
    // Copiar el vector unión a VectorMenor
    for (int j = 0; j < totalUnion; j++) {
        VectorMenor[j] = VectorUnion[j];
    }

    //Llamar funcion para ordenar el vector union de Mayor a menor
    OrdenarVectorMayor(VectorMayor, totalUnion);    

    //Llamar funcion para ordenar el vector union de Menor a mayor
    OrdenarVectorMenor(VectorMenor, totalUnion);

    //Odernar el vector union de menor a mayor
    printf ("\tVector ordenado de menor a mayor:\n");
    for (int j = 0; j < totalUnion; j++) {
        printf ("El vector en la posicion [%d] es: %d\n", j, VectorMenor[j]);
    }

    printf ("\tVector ordenado de mayor a menor:\n");
    for (int j = 0; j < totalUnion; j++) {
        printf ("El vector en la posicion [%d] es: %d\n", j, VectorMayor[j]);
    }

        
    return 0;
}

void OrdenarVectorMenor (int VectorUnion [], int totalUnion) {
    int aux = 0;
    // Ordenar de menor a mayor
    for (int a = 0; a < totalUnion - 1; a++) {
        for (int b = 0; b < totalUnion - a - 1; b++) {
            if (VectorUnion[b] > VectorUnion[b + 1]) { // Cambiar el signo para ordenar de menor a mayor
                aux = VectorUnion[b];
                VectorUnion[b] = VectorUnion[b + 1];
                VectorUnion[b + 1] = aux;
            }
        }
    }
}

void OrdenarVectorMayor (int VectorUnion [], int totalUnion){
    int aux = 0;
    // Ordenar de mayor a menor
    for (int a = 0; a < totalUnion - 1; a++) {
        for (int b = 0; b < totalUnion - a - 1; b++) {
            if (VectorUnion[b] < VectorUnion[b + 1]) { // Cambiar el signo para ordenar de menor a mayor
                aux = VectorUnion[b];
                VectorUnion[b] = VectorUnion[b + 1];
                VectorUnion[b + 1] = aux;
            }
        }
    }
}

