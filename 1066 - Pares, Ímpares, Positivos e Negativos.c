#include <stdio.h>

int main() {
    int i, valor;
    int pares = 0;
    int impares = 0;
    int positivos = 0;
    int negativos = 0;

    for(i = 0; i < 5; ++i) {
        scanf("%i", &valor);

        if(valor % 2 == 0) {
            pares++;
        } else if (valor % 2 != 0){
            impares++;
        }
        if(valor > 0){
            positivos++;
        }
        else if (valor < 0){
            negativos++;
        }
    }

    printf("%i valor(es) par(es)\n", pares);
    printf("%i valor(es) impar(es)\n", impares);
    printf("%i valor(es) positivo(s)\n", positivos);
    printf("%i valor(es) negativo(s)\n", negativos);

    return 0;
}
