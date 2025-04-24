
#include <stdio.h>

// EJERCICIO 1: Registro de gastos semanales por categoría
void totalPorCategoria(float gastos[7][3], float total[3]) {
    for(int j = 0; j < 3; j++) {
        total[j] = 0;
        for(int i = 0; i < 7; i++)
            total[j] += gastos[i][j];
    }
}

// EJERCICIO 2: Seguimiento de temperatura diaria por ciudad
void promedioCiudad(float temp[5][3], float prom[3]) {
    for(int j = 0; j < 3; j++) {
        prom[j] = 0;
        for(int i = 0; i < 5; i++)
            prom[j] += temp[i][j];
        prom[j] /= 5;
    }
}

// EJERCICIO 3: Sistema de notas por estudiante
void promedioEstudiantes(float notas[3][4], float prom[3]) {
    for(int i = 0; i < 3; i++) {
        prom[i] = 0;
        for(int j = 0; j < 4; j++)
            prom[i] += notas[i][j];
        prom[i] /= 4;
    }
}

// EJERCICIO 4: Suma de dos inventarios en bodegas
void sumarInventarios(int A[2][3], int B[2][3], int resultado[2][3]) {
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            resultado[i][j] = A[i][j] + B[i][j];
}

// EJERCICIO 5: Control de asistencia semanal
void contarAsistencia(int asistencia[4][5], int total[4]) {
    for(int i = 0; i < 4; i++) {
        total[i] = 0;
        for(int j = 0; j < 5; j++)
            total[i] += asistencia[i][j];
    }
}

// EJERCICIO 6: Registro de ventas diarias
float totalVentas(float ventas[], int n) {
    float suma = 0;
    for(int i = 0; i < n; i++)
        suma += ventas[i];
    return suma;
}
float promedio(float total, int n) {
    return total / n;
}

// EJERCICIO 7: Análisis de consumo de energía por electrodoméstico
int mayorConsumo(float consumos[], int n) {
    int pos = 0;
    for(int i = 1; i < n; i++)
        if(consumos[i] > consumos[pos])
            pos = i;
    return pos;
}

// EJERCICIO 8: Control de stock de productos
void verificarFaltantes(int stock[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(stock[i][j] == 0)
                printf("Falta producto %d en sucursal %d\n", j+1, i+1);
}

// EJERCICIO 9: Control de votos electrónicos en zonas
int zonaGanadora(int votos[], int n) {
    int max = 0;
    for(int i = 1; i < n; i++)
        if(votos[i] > votos[max])
            max = i;
    return max;
}
int totalVotos(int votos[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++)
        total += votos[i];
    return total;
}

// EJERCICIO 10: Rotación de turnos semanales
void rotarTurnos(int turnos[3][7]) {
    for(int i = 0; i < 3; i++) {
        int temp = turnos[i][6];
        for(int j = 6; j > 0; j--)
            turnos[i][j] = turnos[i][j-1];
        turnos[i][0] = temp;
    }
}
void mostrarTurnos(int turnos[3][7]) {
    for(int i = 0; i < 3; i++) {
        printf("Empleado %d: ", i+1);
        for(int j = 0; j < 7; j++)
            printf("%d ", turnos[i][j]);
        printf("\n");
    }
}

int main() {
    // Puedes probar cada función individualmente aquí
    // Por ejemplo, este es un ejemplo para ejercicio 1
    float gastos[7][3] = {
        {10, 5, 2}, {12, 3, 4}, {11, 4, 2},
        {10, 5, 3}, {9, 6, 2}, {13, 2, 5}, {10, 5, 1}
    };
    float totalGastos[3];
    totalPorCategoria(gastos, totalGastos);
    printf("Total Alimentación: %.2f\nTotal Transporte: %.2f\nTotal Entretenimiento: %.2f\n", totalGastos[0], totalGastos[1], totalGastos[2]);

    return 0;
}