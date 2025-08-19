#include <stdio.h>

void convertirTiempo(int totalSegundos, int *horas, int *minutos, int *segundos) {
    *horas = totalSegundos / 3600;
    totalSegundos %= 3600;

    *minutos = totalSegundos / 60;
    *segundos = totalSegundos % 60;
}

int main() {
    int segundosTotales, h, m, s;

    printf("Ingrese una cantidad de segundos: ");
    scanf("%d", &segundosTotales);

    convertirTiempo(segundosTotales, &h, &m, &s);

    printf("Tiempo convertido: %d horas, %d minutos, %d segundos\n", h, m, s);
    return 0;
}
