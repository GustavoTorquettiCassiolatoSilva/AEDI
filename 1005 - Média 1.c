#include <stdio.h>

int main() {

    double A;
    double B;
    scanf("%lf %lf\n", &A, &B);
    double media = ((3.5 * A) + (7.5 * B)) / 11;
    printf("MEDIA = %.5lf\n",media);

    return 0;
}
