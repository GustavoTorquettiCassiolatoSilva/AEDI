#include <stdio.h>

int main() {

    int N;
    scanf("%i", &N);
    int km = 0;

    for(int i = 0; i < N; i++){
        int T, V = 1;
        scanf("%i %i", &T, &V);
        if(T && V != 0){
            km = km + (T * V);
        }
    }
    printf("%i\n", km);

    return 0;
}
