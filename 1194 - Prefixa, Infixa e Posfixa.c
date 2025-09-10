#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    char informacao;
    struct no *esq;
    struct no *dir;
} No;

No *CriarNo(char informacao){ //errei
    No* resultado = malloc(sizeof(No)); //errei
    resultado->informacao = informacao;
    resultado->esq = NULL;
    resultado->dir = NULL;
    return resultado; }

//prefixo e infixo S1(Red) e S2 (eRd) posfixo (edR)
//Agora, ao invés de manualmente, é necessário construir a árvore recursivamente.

No* ConstruirArvore(char* pre, char* inf, int tamanho){
    if(tamanho == 0) return NULL;

    //primeiro c do pré-fixo é a raiz
    char raiz = pre[0];
    No* noRaiz = CriarNo(raiz);

    //Achar a raiz no infixo
    int pos;
    for (pos = 0; pos < tamanho; pos++){
        if(inf[pos] == raiz) break;
    }
    //criacao de subarvores
    noRaiz->esq = ConstruirArvore(pre + 1, inf, pos);
    noRaiz->dir = ConstruirArvore(pre + 1 + pos, inf + pos + 1, tamanho - pos - 1);
    return noRaiz;
}

//pos fixo (edR)
void PosFixo(No* raiz){
    if(raiz == NULL) return;
    PosFixo(raiz->esq);
    PosFixo(raiz->dir);
    printf("%c", raiz->informacao);
}

int main(){
    int C;
    scanf("%d", &C);
    while (C--){
        int N;
        char pre[53], inf[53]; //prefixo e infixo maximo
        scanf("%d %s %s", &N, pre, inf);

        No* raiz = ConstruirArvore(pre, inf, N);

        PosFixo(raiz);
        printf("\n");
    }
    return 0;
}
