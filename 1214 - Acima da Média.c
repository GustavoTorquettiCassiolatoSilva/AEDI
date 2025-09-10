#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        scanf("%d", &N);

        int medias[N];
        int soma = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &medias[i]);
            soma += medias[i];
        }

        float mediaTurma = soma / (float)N;
        int MediaAcima = 0;
        for (int i = 0; i < N; i++) {
            if (medias[i] > mediaTurma) {
                MediaAcima++;
            }
        }
        float porcento = (MediaAcima / (float)N) * 100;
        printf("%.3f%%\n", porcento);
    }
    return 0;
}
