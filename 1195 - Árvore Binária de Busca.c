#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int informacao;
    struct no *esq;
    struct no *dir;
} No;

No *CriarNo(int informacao){
    No* resultado = malloc(sizeof(No));
    resultado->informacao = informacao;
    resultado->esq = NULL;
    resultado->dir = NULL;
    return resultado;
}

bool inserir(No **ganchopointer, int informacao){
    No *gancho = *ganchopointer;
    if(gancho == NULL){
        (*ganchopointer) = CriarNo(informacao);
        return true;
    }
    if (informacao == gancho->informacao){
        return false;
    }
    if(informacao < gancho->informacao){
        return inserir(&(gancho->esq), informacao);
    } else {
        return inserir(&(gancho->dir), informacao);
    }
}

void PreFixo(No* raiz, bool *primeiro) {
    if (raiz == NULL) return;
    if (*primeiro) {
        printf("%d", raiz->informacao);
        *primeiro = false;
    } else {
        printf(" %d", raiz->informacao);
    }
    PreFixo(raiz->esq, primeiro);
    PreFixo(raiz->dir, primeiro);
}

void InFixo(No* raiz, bool *primeiro) {
    if (raiz == NULL) return;
    InFixo(raiz->esq, primeiro);
    if (*primeiro) {
        printf("%d", raiz->informacao);
        *primeiro = false;
    } else {
        printf(" %d", raiz->informacao);
    }
    InFixo(raiz->dir, primeiro);
}

void PosFixo(No* raiz, bool *primeiro) {
    if (raiz == NULL) return;
    PosFixo(raiz->esq, primeiro);
    PosFixo(raiz->dir, primeiro);
    if (*primeiro) {
        printf("%d", raiz->informacao);
        *primeiro = false;
    } else {
        printf(" %d", raiz->informacao);
    }
}

int main(){
    int C, N;
    scanf("%i", &C);

    for(int i = 1; i <= C; i++){
        scanf("%d", &N);

        No *raiz = NULL;

        for(int j = 0; j < N; j++){
            int valor;
            scanf("%d", &valor);
            inserir(&raiz, valor);
        }

        printf("Case %d:\n", i);

        bool primeiro = true;
        printf("Pre.: ");
        PreFixo(raiz, &primeiro);
        printf("\n");

        primeiro = true;
        printf("In..: ");
        InFixo(raiz, &primeiro);
        printf("\n");

        primeiro = true;
        printf("Post: ");
        PosFixo(raiz, &primeiro);
        printf("\n\n");
    }
}
