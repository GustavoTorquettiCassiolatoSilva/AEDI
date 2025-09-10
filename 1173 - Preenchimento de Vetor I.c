#include <stdio.h>
#include <math.h>

int main() {

    int N[10];
    scanf("%i", &N[0]);
    int i = 0;
    for(i = 1; i < 10; i++){
        N[i] = N[0] * pow(2,i);
    }
    for(i = 0; i < 10; i++){
        printf("N[%i] = %i\n",i, N[i]);
    }
    return 0;
}
