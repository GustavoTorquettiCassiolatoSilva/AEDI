#include <stdio.h>

int main() {

    int Codigo;
    float Numero;
    scanf("%i %f", &Codigo, &Numero);

    if(Codigo == 1){
        printf("Total: R$ %.2f\n", Numero*4.0);
    }
    else if(Codigo == 2){
        printf("Total: R$ %.2f\n", Numero*4.5);
    }
    else if(Codigo == 3){
        printf("Total: R$ %.2f\n", Numero*5.0);
    }
    else if(Codigo == 4){
        printf("Total: R$ %.2f\n", Numero*2.0);
    }
    else if(Codigo == 5){
        printf("Total: R$ %.2f\n", Numero*1.5);
    }

    return 0;
}
