#include <stdio.h>
int main() {

    double A;
    double B;
    double C;
    scanf("%lf %lf %lf\n", &A, &B, &C);
    double media = ((2 * A) + (3 * B) + (5 * C)) / 10;
    printf("MEDIA = %.1lf\n",media);

    return 0;
}
