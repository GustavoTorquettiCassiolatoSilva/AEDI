#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strchr()

typedef struct no{
    char letra;
    struct no *esq;
    struct no *dir;
} No;

No* reconstruirArvore(char* prefixo, char* infixo, int inicio, int fim, int* indicePrefixo) {
    if (inicio > fim) return NULL;

    char raizLetra = prefixo[*indicePrefixo]; //pegar letra atual do prefixo
    (*indicePrefixo)++;

    No* raiz = (No*)malloc(sizeof(No)); //criar um nó com essa letra
    raiz->letra = raizLetra;
    raiz->esq = raiz->dir = NULL;

    if (inicio == fim) return raiz; //se nao tem filhos, retornar raiz

    char* posicao = strchr(infixo, raizLetra); //encontrar a posição da raiz
    int indiceRaiz = posicao - infixo;
    //construir arvores
    raiz->esq = reconstruirArvore(prefixo, infixo, inicio, indiceRaiz - 1, indicePrefixo);
    raiz->dir = reconstruirArvore(prefixo, infixo, indiceRaiz + 1, fim, indicePrefixo);

    return raiz;
}

void liberarArvore(No* raiz){
    if(raiz != NULL){
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

void printposfixo(No* raiz) { // Esquerda, direita, raiz
    if(raiz != NULL){
        printposfixo(raiz->esq);
        printposfixo(raiz->dir);
        printf("%c", raiz->letra);
    }
}

int main(){
    No* raiz = NULL;
    char prefixo[27], infixo[27];

    while(scanf("%s %s", prefixo, infixo) != EOF){
        raiz = NULL; // ZERAR ANTES DE RECONSTRUIR
        int indicePrefixo = 0;
        int tamanho = strlen(infixo); //tamanho da árvore

        raiz = reconstruirArvore(prefixo, infixo, 0, tamanho - 1, &indicePrefixo);

        printposfixo(raiz);
        printf("\n");
        liberarArvore(raiz);
    }
}
