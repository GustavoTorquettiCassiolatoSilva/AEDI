#include <stdio.h>

int main() {

    int N;
    scanf("%i", &N);
    int i;
    for(i = 1; i < 11; i++){
        printf("%i x %i = %i\n", i, N, N*i);
    }

    return 0;
}
