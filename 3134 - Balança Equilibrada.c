#include <stdio.h>

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    int A = (int)(a * 10);
    int B = (int)(b * 10);
    int C = (int)(c * 10);
    int D = (int)(d * 10);

    if ((A + B == C + D) || (A + C == B + D) || (A + D == B + C) ||
        (A == B + C + D) || (B == A + C + D) || (C == A + B + D) || (D == A + B + C)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
