#include <stdio.h>

int main() {

    double A[3];
    double B[3];
    scanf("%lf %lf %lf", &A[0], &A[1], &A[2]);
    scanf("%lf %lf %lf", &B[0], &B[1], &B[2]);
    int i;
    double valor = A[1] * A[2] + B[1] * B[2];
    printf("VALOR A PAGAR: R$ %.2lf\n", valor);

    return 0;
}
