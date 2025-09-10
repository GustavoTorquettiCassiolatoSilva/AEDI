#include <stdio.h>
#include <string.h>

int main() {
    char lista1[1000];
    char novalista[1000];
    char novosamigos[50];
    char amigosfinal[2000];
    int i = 0, j = 0;

    fgets(lista1, sizeof(lista1), stdin);
    lista1[strcspn(lista1, "\n")] = '\0';

    fgets(novalista, sizeof(novalista), stdin);
    novalista[strcspn(novalista, "\n")] = '\0';

    fgets(novosamigos, sizeof(novosamigos), stdin);
    novosamigos[strcspn(novosamigos, "\n")] = '\0';

    if (strcmp(novosamigos, "nao") == 0) {
        for (i = 0; lista1[i] != '\0'; i++) {
            amigosfinal[i] = lista1[i];
        }

        if (i > 0 && novalista[0] != '\0') {
            if (amigosfinal[i - 1] != ' ') {
                amigosfinal[i++] = ' ';
            }
        }

        for (j = 0; novalista[j] != '\0'; j++, i++) {
            amigosfinal[i] = novalista[j];
        }
        amigosfinal[i] = '\0';
    } else {
        char *pos = strstr(lista1, novosamigos);
        int amigolugar = (pos != NULL) ? (pos - lista1) : -1;

        if (amigolugar != -1) {
            for (i = 0; i < amigolugar; i++) {
                amigosfinal[i] = lista1[i];
            }

            if (i > 0 && amigosfinal[i - 1] != ' ') {
                amigosfinal[i++] = ' ';
            }

            for (j = 0; novalista[j] != '\0'; j++, i++) {
                amigosfinal[i] = novalista[j];
            }

            amigosfinal[i++] = ' ';

            for (j = amigolugar; lista1[j] != '\0'; j++, i++) {
                amigosfinal[i] = lista1[j];
            }
            amigosfinal[i] = '\0';
        } else {
            for (i = 0; lista1[i] != '\0'; i++) {
                amigosfinal[i] = lista1[i];
            }

            if (i > 0 && novalista[0] != '\0') {
                if (amigosfinal[i - 1] != ' ') {
                    amigosfinal[i++] = ' ';
                }
            }

            for (j = 0; novalista[j] != '\0'; j++, i++) {
                amigosfinal[i] = novalista[j];
            }
            amigosfinal[i] = '\0';
        }
    }

    printf("%s\n", amigosfinal);
    return 0;
}
