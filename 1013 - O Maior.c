#include <stdio.h>
int main(){

    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    if (a >= b && a >= c) {
        printf("%i eh o maior\n", a);
    } else if (b >= a && b >= c) {
        printf("%i eh o maior\n", b);
    } else if (c >= a && c >= b) {
        printf("%i eh o maior\n", c);
    }

    return 0;
}
