#include <stdio.h>

int main() {

    int X[10];
    int i = 10;
    for(i = 0; i <= 9; i++){
        scanf("%i",&X[i]);
        if(X[i] <= 0){
            X[i] = 1;
        }
    }
    for(i = 0; i < 10; ++i){
        printf("X[%i] = %i\n", i, X[i]);
    }
    return 0;
}
