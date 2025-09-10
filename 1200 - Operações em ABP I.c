#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char num;
    struct no *esq;
    struct no *dir;
} No;

No* Inserir(No *raiz, char num) {
    if (raiz == NULL) {
        No *criar = (No*)malloc(sizeof(No));
        criar->num = num;
        criar->esq = criar->dir = NULL;
        return criar;
    }
    if (num < raiz->num) {
        raiz->esq = Inserir(raiz->esq, num);
    } else {
        raiz->dir = Inserir(raiz->dir, num);
    }
    return raiz;
}

void Infixo(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        Infixo(raiz->esq, primeiro);

        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->num);
        *primeiro = 0;

        Infixo(raiz->dir, primeiro);
    }
}

void Prefixo(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->num);
        *primeiro = 0;

        Prefixo(raiz->esq, primeiro);
        Prefixo(raiz->dir, primeiro);
    }
}

void POSFIXO(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        POSFIXO(raiz->esq, primeiro);
        POSFIXO(raiz->dir, primeiro);

        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->num);
        *primeiro = 0;
    }
}

No* Buscar(No *raiz, char chave) {
    if (raiz == NULL || raiz->num == chave) {
        return raiz;
    }
    if (chave < raiz->num) {
        return Buscar(raiz->esq, chave);
    } else {
        return Buscar(raiz->dir, chave);
    }
}

int main() {
    char comando[10], temp2;
    No* raiz = NULL;

    while (scanf(" %s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &temp2);
            raiz = Inserir(raiz, temp2);
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            Infixo(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            Prefixo(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            POSFIXO(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &temp2);
            No *resultado = Buscar(raiz, temp2);
            if (resultado == NULL) {
                printf("%c nao existe\n", temp2);
            } else {
                printf("%c existe\n", temp2);
            }
        }
    }
    return 0;
}
