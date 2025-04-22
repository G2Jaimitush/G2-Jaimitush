#include <stdio.h>

//Se utiliza void porque no se espera que la funcion devuelva nada
void OrdenarVector(int vector[], int i);

int main() {
    int i;

    // Declaración del tamaño del vector
    printf("Escribe la dimension del vector: ");
    scanf("%d", &i);

    int vector[i];
    int vectorMenor[i];

    // Llenar el vector
    for (int j = 0; j < i; j++) {
        printf("Al vector [%d] sea igual = ", j);
        scanf("%d", &vector[j]);
    }

    // Mostrar el vector original
    for (int j = 0; j < i; j++) {
        printf("El vector en la posicion [%d] es = %d\n", j, vector[j]);
    }

    // Copiar el vector
    for (int j = 0; j < i; j++) {
        vectorMenor[j] = vector[j];
    }

    //Ordenar Vector De Manera Descendente
    OrdenarVector(vectorMenor, i);

    // Mostrar vector ordenado
    printf("-----------------------------------------\n");
    for (int j = 0; j < i; j++) {
        printf("El vector en la posicion [%d] es = %d\n", j, vectorMenor[j]);
    }

    return 0;
}

//Solo arregla el vector, no devuelve nada
void OrdenarVector(int vector[], int i){
    int aux = 0;
    // Ordenar de menor a mayor
    for (int a = 0; a < i - 1; a++) {
        for (int b = 0; b < i - a - 1; b++) {
            if (vector[b] > vector[b + 1]) { //Solo cambia el signo de mayor a menor
                aux = vector[b];
                vector[b] = vector[b + 1];
                vector[b + 1] = aux;
            }
        }
    }
}