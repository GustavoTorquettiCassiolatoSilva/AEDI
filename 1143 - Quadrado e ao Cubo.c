#include <stdio.h>
#include <math.h>

int main() {
    int i;
    int N = 0;
    scanf("%i", &N);
    for(i = 1; i<N + 1; i++){
        int N2 = pow(i, 2);
        int N3 = pow(i, 3);
        printf("%i %i %i\n", i, N2, N3);
    }

    return 0;
}
