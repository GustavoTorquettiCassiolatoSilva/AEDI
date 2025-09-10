#include <stdio.h>
int main(){
    int A;
    int B;
    scanf("%i %i", &A, &B);
    int PROD = A * B;
    printf("PROD = %i\n", PROD);
}
#include <stdio.h>
#include <math.h>

void contar(int dinheiro, int *nota100, int *nota50, int *nota20, int *nota10, int *nota5, int *nota2,
            int *moeda1) {
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
            }

int main() {
    int dinheiro;
    int nota100 = 0, nota50 = 0, nota20 = 0, nota10 = 0, nota5 = 0, nota2 = 0;
    int moeda1 = 0;

    scanf("%int", &dinheiro);
    int dinheiro2 = dinheiro;

    contar(dinheiro, &nota100, &nota50, &nota20, &nota10, &nota5, &nota2,
           &moeda1);

    printf("%i\n", dinheiro2);
    printf("%i nota(s) de R$ 100,00\n", nota100);
    printf("%i nota(s) de R$ 50,00\n", nota50);
    printf("%i nota(s) de R$ 20,00\n", nota20);
    printf("%i nota(s) de R$ 10,00\n", nota10);
    printf("%i nota(s) de R$ 5,00\n", nota5);
    printf("%i nota(s) de R$ 2,00\n", nota2);
    printf("%i nota(s) de R$ 1,00\n", moeda1);
}
