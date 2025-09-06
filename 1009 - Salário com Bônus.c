#include <stdio.h>

int main() {
    char A[100];
    double B, C;
    scanf("%s %lf %lf", &A, &B, &C);
    double salario = B + (C * 0.15);

    printf("TOTAL = R$ %.2f\n", salario);

    return 0;
}
