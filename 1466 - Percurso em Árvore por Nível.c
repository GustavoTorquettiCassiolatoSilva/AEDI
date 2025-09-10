#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *esq, *dir;
} No;

typedef struct fila {
    No* no;
    struct fila *prox;
} Fila;

No* Inserir(No* raiz, int numero) {
    if (raiz == NULL) {
        No* Novo = (No*)malloc(sizeof(No));
        Novo->esq = Novo->dir = NULL;
        Novo->numero = numero;
        return Novo;
    }
    if (numero < raiz->numero) {
        raiz->esq = Inserir(raiz->esq, numero);
    } else {
        raiz->dir = Inserir(raiz->dir, numero);
    }
    return raiz;
}

Fila* Enfileirar(Fila* fim, No* no) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->no = no;
    novo->prox = NULL;
    if (fim) fim->prox = novo;
    return novo;
}

Fila* Desenfileirar(Fila* inicio) {
    Fila* temp = inicio;
    inicio = inicio->prox;
    free(temp);
    return inicio;
}

void BFS(No* raiz) {
    if (raiz == NULL) return;

    Fila *inicio = NULL, *fim = NULL;
    inicio = fim = Enfileirar(fim, raiz);

    while (inicio != NULL) {
        No* no_atual = inicio->no;
        printf("%i", no_atual->numero);

        if (no_atual->esq) fim = Enfileirar(fim, no_atual->esq);
        if (no_atual->dir) fim = Enfileirar(fim, no_atual->dir);

        inicio = Desenfileirar(inicio);
        if (inicio) printf(" ");
    }
}

int main() {
    No* raiz = NULL;
    int C, N, temp;
    scanf("%i", &C);
    int caso = 1;
    for (int i = 0; i < C; i++) {
        raiz = NULL;
        scanf("%i", &N);
        for (int j = 0; j < N; j++) {
            scanf("%i", &temp);
            raiz = Inserir(raiz, temp);
        }
        printf("Case %i:\n", caso);
        BFS(raiz);
        printf("\n\n");
        caso = caso + 1;
    }
    return 0;
}
