#include <stdio.h>
#include <math.h>

int main() {

    double pi = 3.14159;
    double r;
    scanf("%lf", &r);
    double volume = 4.0/3 * pi * pow(r,3);

    printf("VOLUME = %.3lf\n", volume);
    return 0;
}
