#include <stdio.h>

int main() {

    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);
    double pi = 3.14159;

    printf("TRIANGULO: %.3lf\n", (A * C)/2);
    printf("CIRCULO: %.3lf\n", pow(C,2) * pi);
    printf("TRAPEZIO: %.3lf\n", (A+B)*C/2);
    printf("QUADRADO: %.3lf\n", B * B);
    printf("RETANGULO: %.3lf\n", A * B);

    return 0;
}
