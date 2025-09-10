#include <stdio.h>
int main(){
    float M[12][12];
    int L;
    scanf("%i\n", &L);
    char T;

    scanf(" %c", &T);

    int i, j = 0;
    for (i = 0; i <12; ++i){
        for (j = 0; j < 12; ++j){
            scanf("%f", &M[i][j]);
        }
    }
    float soma = 0;
    if (T == 'S'){
        for (j = 0; j < 12; ++j){
            soma = soma + M[j][L];
        }
        printf("%.1f\n", soma);
    }
    float media = 0;
    if (T == 'M'){
        for (j = 0; j < 12; ++j){
            media = media + M[j][L];
        }
        printf("%.1f\n", media/12);
    }

}
