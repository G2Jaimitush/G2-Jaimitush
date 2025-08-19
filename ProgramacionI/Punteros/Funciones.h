// Declaraciones de funciones
int Sumar(int *p1, int *p2);
int Restar(int *p1, int *p2);
int Dividir(int *p1, int *p2);
int Multiplicar(int *p1, int *p2);

int Sumar(int *p1, int *p2) {
    return *p1 + *p2;
}

int Restar(int *p1, int *p2) {
    return *p1 - *p2;
}

int Dividir(int *p1, int *p2) {
    return *p1 / *p2;
}

int Multiplicar(int *p1, int *p2) {
    return *p1 * *p2;
}