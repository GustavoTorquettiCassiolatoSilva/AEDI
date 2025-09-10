#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int num;
    struct no *esq;
    struct no *dir;
} No;

No* Inserir(No *raiz, int num) {
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

No* MaiorElemento(No* raiz) {
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

No* Remover(No* raiz, int num) {
    if (raiz == NULL) return raiz;

    if (num < raiz->num) {
        raiz->esq = Remover(raiz->esq, num);
    } else if (num > raiz->num) {
        raiz->dir = Remover(raiz->dir, num);
    } else {
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        No* temp = MaiorElemento(raiz->esq);
        raiz->num = temp->num;
        raiz->esq = Remover(raiz->esq, temp->num);
    }
    return raiz;
}

void Infixo(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        Infixo(raiz->esq, primeiro);
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%d", raiz->num);
        *primeiro = 0;
        Infixo(raiz->dir, primeiro);
    }
}

void Prefixo(No *raiz, int *primeiro) {
    if (raiz != NULL) {
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%d", raiz->num);
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
        printf("%d", raiz->num);
        *primeiro = 0;
    }
}

No* Buscar(No *raiz, int chave) {
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
    char comando[10];
    int temp;
    No* raiz = NULL;

    while (scanf(" %s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %d", &temp);
            raiz = Inserir(raiz, temp);
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
            scanf(" %d", &temp);
            No *resultado = Buscar(raiz, temp);
            if (resultado == NULL) {
                printf("%d nao existe\n", temp);
            } else {
                printf("%d existe\n", temp);
            }
        }
        else if (strcmp(comando, "R") == 0) {
            scanf(" %d", &temp);
            raiz = Remover(raiz, temp);
        }
    }
    return 0;
}
