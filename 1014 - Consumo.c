#include <stdio.h>

int main() {

    int X;
    double Y;
    scanf("%i %lf", &X, &Y);
    double velocidade = X/Y;
    printf("%.3lf km/l\n", velocidade);

    return 0;
}
