#include <stdio.h>
int main(){

    int vector [5] = {5, 4, 3, 2, 1};
    int max = 0; // Inicializacion del vector

    // Encontrar el valor maximo
    for (int i = 1; i < 5; i++){
        if (vector[i] > max){
            max = vector[i];
        }
    }
    printf("El valor maximo es: %d\n", max);

    for (int i = 0; i < 5; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    // Ordenar el vector de menor a mayor
    for (int i = 0; i < 5; i++){
        for (int j = i + 1; j < 5; j++){
            if (vector[i] > vector[j]){
                int temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
    // Imprimir el vector ordenado
    printf("El vector ordenado es: ");
    for (int i = 0; i < 5; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    return 0;
}