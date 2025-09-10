#include <stdio.h>
#include <string.h>

#define ITENS 1000
#define LETRAS 21

int repetir(char lista[ITENS][LETRAS], int tamanho, char item[LETRAS]) {
    for (int i = 0; i < tamanho; i++) {
        int j = 0;
        while (lista[i][j] != '\0' && item[j] != '\0') {
            if (lista[i][j] != item[j]) {
                break;
            }
            j++;
        }
        if (lista[i][j] == item[j]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char linha[10000];
        char lista[ITENS][LETRAS];
        int tlista = 0;

        fgets(linha, sizeof(linha), stdin);

        char *item = strtok(linha, " \n");

        while (item != NULL) {
            if (!repetir(lista, tlista, item)) {
                for (int j = 0; item[j] != '\0'; j++) {
                    lista[tlista][j] = item[j];
                }
                lista[tlista][strlen(item)] = '\0';
                tlista++;
            }
            item = strtok(NULL, " \n");
        }

        char temp[LETRAS];
        for (int j = 0; j < tlista - 1; j++) {
            for (int k = j + 1; k < tlista; k++) {
                int compare = 0;
                int l = 0;
                while (lista[j][l] != '\0' && lista[k][l] != '\0') {
                    if (lista[j][l] < lista[k][l]) {
                        compare = -1;
                        break;
                    } else if (lista[j][l] > lista[k][l]) {
                        compare = 1;
                        break;
                    }
                    l++;
                }
                if (compare == 0 && lista[j][l] == '\0' && lista[k][l] == '\0') {
                    compare = 0;
                }

                if (compare > 0) {
                    for (int l = 0; lista[j][l] != '\0'; l++) {
                        temp[l] = lista[j][l];
                    }
                    temp[strlen(lista[j])] = '\0';

                    for (int l = 0; lista[k][l] != '\0'; l++) {
                        lista[j][l] = lista[k][l];
                    }
                    lista[j][strlen(lista[k])] = '\0';

                    for (int l = 0; temp[l] != '\0'; l++) {
                        lista[k][l] = temp[l];
                    }
                    lista[k][strlen(temp)] = '\0';
                }
            }
        }

        for (int j = 0; j < tlista; j++) {
            printf("%s", lista[j]);
            if (j < tlista - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
