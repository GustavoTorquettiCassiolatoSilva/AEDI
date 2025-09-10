#include <stdio.h>

int main() {

    int X;
    scanf("%i", &X);
    int impar = 1;
    while(impar <= X){
        printf("%i\n", impar);
        impar = impar + 2;
    }

    return 0;
}
