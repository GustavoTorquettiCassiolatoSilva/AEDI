#include <stdio.h>

int main() {
    int senha;

    scanf("%i", &senha);
    while(senha != 2002) {
        printf("Senha Invalida\n");
        scanf("%i", &senha);
    }
    printf("Acesso Permitido\n");

    return 0;
}
