#include <stdio.h>
#define MAX 100

int main() {

    int largura, altura;  //mudar x para largura e y para altura
    char mapa[MAX][MAX];
    int visitado[MAX][MAX] = {0};

    scanf("%d", &largura);
    scanf("%d", &altura);

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            scanf(" %c", &mapa[i][j]); //scannear os itens nas dimens�es do mapa
        }
    }

    int i = 0, j = 0; //posi��o atual
    int vertical = 0, horizontal = 0; //movimento (o personagem ir� seguir a cada momento o que estiver como 1 e ignorar o 0).

    while (1) { //loop at� return
        if (i < 0 || i >= altura || j < 0 || j >= largura) { //atravessar as beiradas do mapa: return.
            printf("!\n");
            return 0;
        }
        if (visitado[i][j] == 1) { //nao pode passar pelo mesmo terreno novamente.
            printf("!\n");
            return 0;
        }
        visitado[i][j] = 1;

        if (mapa[i][j] == '*') { //encontrar ba�.
            printf("*\n");
            return 0;
        }

        if (mapa[i][j] == '>') { //dire��o por setas
            vertical = 0; horizontal = 1;
        }
        else if (mapa[i][j] == '<') {
            vertical = 0; horizontal = -1;
        }
        else if (mapa[i][j] == 'v') {
            vertical = 1; horizontal = 0;
        }
        else if (mapa[i][j] == '^') {
            vertical = -1; horizontal = 0;
        }

        i += vertical; //muda as vari�veis ao encontrar uma seta, mudando o movimento cont�nuo no mapa.
        j += horizontal;
    }
}
