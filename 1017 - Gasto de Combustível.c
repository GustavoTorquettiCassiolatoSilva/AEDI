#include <stdio.h>

int main() {
    int A, B;
    scanf("%i %i", &A, &B);
    double distancia = A * B;
    double resposta = distancia / 12.0;

    printf("%.3lf\n", resposta);

    return 0;
}
