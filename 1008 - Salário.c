#include <stdio.h>

int main() {

    int A, B;
    float C;
    scanf("%i %i %f", &A, &B, &C);
    float salario = B * C;

    printf("NUMBER = %i\n", A);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}
