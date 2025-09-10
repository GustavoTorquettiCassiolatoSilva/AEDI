#include <stdio.h>
#include <math.h>

void contar(double dinheiro, double *nota100, double *nota50, double *nota20, double *nota10, double *nota5, double *nota2,
            double *moeda1, double *moeda05, double *moeda025, double *moeda010, double *moeda005, double *moeda001) {
    dinheiro = round(dinheiro * 100) / 100;

    while (dinheiro >= 100.0) {
        (*nota100)++;
        dinheiro -= 100.0;
    }
    while (dinheiro >= 50.0) {
        (*nota50)++;
        dinheiro -= 50.0;
    }
    while (dinheiro >= 20.0) {
        (*nota20)++;
        dinheiro -= 20.0;
    }
    while (dinheiro >= 10.0) {
        (*nota10)++;
        dinheiro -= 10.0;
    }
    while (dinheiro >= 5.0) {
        (*nota5)++;
        dinheiro -= 5.0;
    }
    while (dinheiro >= 2.0) {
        (*nota2)++;
        dinheiro -= 2.0;
    }

    while (dinheiro >= 1.0) {
        (*moeda1)++;
        dinheiro -= 1.0;
    }
    while (dinheiro >= 0.50) {
        (*moeda05)++;
        dinheiro -= 0.50;
    }
    while (dinheiro >= 0.25) {
        (*moeda025)++;
        dinheiro -= 0.25;
    }
    while (dinheiro >= 0.10) {
        (*moeda010)++;
        dinheiro -= 0.10;
    }
    while (dinheiro >= 0.05) {
        (*moeda005)++;
        dinheiro -= 0.05;
    }
    while (dinheiro >= 0.009) {
        (*moeda001)++;
        dinheiro -= 0.01;
    }
}

int main() {
    double dinheiro;
    double nota100 = 0, nota50 = 0, nota20 = 0, nota10 = 0, nota5 = 0, nota2 = 0;
    double moeda1 = 0, moeda05 = 0, moeda025 = 0, moeda010 = 0, moeda005 = 0, moeda001 = 0;

    scanf("%lf", &dinheiro);

    contar(dinheiro, &nota100, &nota50, &nota20, &nota10, &nota5, &nota2,
           &moeda1, &moeda05, &moeda025, &moeda010, &moeda005, &moeda001);

    printf("NOTAS:\n");
    printf("%.0f nota(s) de R$ 100.00\n", nota100);
    printf("%.0f nota(s) de R$ 50.00\n", nota50);
    printf("%.0f nota(s) de R$ 20.00\n", nota20);
    printf("%.0f nota(s) de R$ 10.00\n", nota10);
    printf("%.0f nota(s) de R$ 5.00\n", nota5);
    printf("%.0f nota(s) de R$ 2.00\n", nota2);

    printf("MOEDAS:\n");
    printf("%.0f moeda(s) de R$ 1.00\n", moeda1);
    printf("%.0f moeda(s) de R$ 0.50\n", moeda05);
    printf("%.0f moeda(s) de R$ 0.25\n", moeda025);
    printf("%.0f moeda(s) de R$ 0.10\n", moeda010);
    printf("%.0f moeda(s) de R$ 0.05\n", moeda005);
    printf("%.0f moeda(s) de R$ 0.01\n", moeda001);

    return 0;
}
