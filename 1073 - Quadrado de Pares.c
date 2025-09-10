#include <stdio.h>
#include <math.h>

int main() {

    int N;
    scanf("%i", &N);
    int par = 2;
    while(par <= N){
        int par2 = pow(par, 2);
        printf("%i^2 = %i\n", par, par2);
        par = par +2;
    }

    return 0;
}
