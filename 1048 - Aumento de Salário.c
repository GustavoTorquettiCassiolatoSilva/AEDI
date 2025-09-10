#include <stdio.h>

int main() {

    double N;
    scanf("%lf", &N);
    if(N >= 0 && N <= 400){
        printf("Novo salario: %.2lf\n", N * 1.15);
        printf("Reajuste ganho: %.2lf\n", N*0.15);
        printf("Em percentual: 15 %\n");
    } else if(N > 400 && N <= 800){
        printf("Novo salario: %.2lf\n", N * 1.12);
        printf("Reajuste ganho: %.2lf\n", N*0.12);
        printf("Em percentual: 12 %\n");
    } else if(N > 800 && N <= 1200){
        printf("Novo salario: %.2lf\n", N * 1.10);
        printf("Reajuste ganho: %.2lf\n", N*0.10);
        printf("Em percentual: 10 %\n");
    } else if(N > 1200 && N <= 2000){
        printf("Novo salario: %.2lf\n", N * 1.07);
        printf("Reajuste ganho: %.2lf\n", N*0.07);
        printf("Em percentual: 7 %\n");
    } else if(N > 2000){
        printf("Novo salario: %.2lf\n", N * 1.04);
        printf("Reajuste ganho: %.2lf\n", N*0.04);
        printf("Em percentual: 4 %\n");
    }

    return 0;
}
