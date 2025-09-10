#include <stdio.h>

int main() {

    int A, B;
    scanf("%i %i", &A, &B);
    if(A < B){
        int tempo = B - A;
        printf("O JOGO DUROU %i HORA(S)\n", tempo);
    }
    else{
        int tempo = (24 - A) + B;
        printf("O JOGO DUROU %i HORA(S)\n", tempo);
    }
    return 0;
}
