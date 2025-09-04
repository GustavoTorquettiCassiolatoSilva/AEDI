#include <stdio.h>

int main() {

    double pi = 3.14159;
    double raio;
    scanf("%lf", &raio);
    double area = (raio * raio) * pi;
    printf("A=%.4lf\n", area);
    return 0;
}
