#include <stdio.h>

int main() {

    int in = 0;
    int out = 0;
    int N, i;
    scanf("%i", &N);
    for(i = 0; i < N; i++){
        int X;
        scanf("%i", &X);
        if(X >= 10 && X <= 20){
            in = in + 1;
        }
        else{
            out = out + 1;
        }
    }
    printf("%i in\n", in);
    printf("%i out\n", out);

    return 0;
}
