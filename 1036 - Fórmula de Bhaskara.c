#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    if (A == 0) {
        printf("Impossivel calcular\n");
    } else {
        double baskhara = B*B - 4*A*C;

        if (baskhara < 0) {
            printf("Impossivel calcular\n");
        } else {
            double R1 = (-B + sqrt(baskhara)) / (2 * A);
            double R2 = (-B - sqrt(baskhara)) / (2 * A);
            printf("R1 = %.5lf\n", R1);
            printf("R2 = %.5lf\n", R2);
        }
    }

    return 0;
}
