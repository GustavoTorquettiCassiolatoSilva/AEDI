#include <stdio.h>

int main(){
    float A[100];
    float posicao[100];
    float numero[100];
    int i, cont = 0;

    for(i = 0; i < 100; i++){
        scanf("%f", &A[i]);
        if(A[i] <= 10){
            posicao[cont] = i;
            numero[cont] = A[i];
            cont++;
        }
    }
    for(i = 0; i < cont; i++){
        printf("A[%.0f] = %.1f\n", posicao[i], numero[i]);
    }
    return 0;
}
