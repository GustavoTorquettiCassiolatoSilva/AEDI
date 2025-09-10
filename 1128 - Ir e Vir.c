#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 2000

typedef struct No {
    int vertice;
    struct No *prox;
} No;

typedef struct {
    No *lista[MAX_VERTICES];
    No *listaTransposta[MAX_VERTICES];
    int numVertices;
} Grafo;

void IniciarGrafo(Grafo *grafo, int numVertices) {
    grafo->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        grafo->lista[i] = NULL;
        grafo->listaTransposta[i] = NULL;
    }
}

void AdicionarAresta(Grafo *grafo, int origem, int destino, int dupla) {
    No *novo = (No *)malloc(sizeof(No));
    novo->vertice = destino;
    novo->prox = grafo->lista[origem];
    grafo->lista[origem] = novo;

    No *novoT = (No *)malloc(sizeof(No));
    novoT->vertice = origem;
    novoT->prox = grafo->listaTransposta[destino];
    grafo->listaTransposta[destino] = novoT;

    if (dupla == 2) {
        No *novo2 = (No *)malloc(sizeof(No));
        novo2->vertice = origem;
        novo2->prox = grafo->lista[destino];
        grafo->lista[destino] = novo2;

        No *novoT2 = (No *)malloc(sizeof(No));
        novoT2->vertice = destino;
        novoT2->prox = grafo->listaTransposta[origem];
        grafo->listaTransposta[origem] = novoT2;
    }
}
void DFS(Grafo *grafo, int v, int visitado[], No *listaAdj[]) {
    visitado[v] = 1;
    No *atual = listaAdj[v];
    while (atual) {
        if (!visitado[atual->vertice]) {
            DFS(grafo, atual->vertice, visitado, listaAdj);
        }
        atual = atual->prox;
    }
}
int Verificar(Grafo *grafo) {
    int visitado[MAX_VERTICES] = {0};

    DFS(grafo, 0, visitado, grafo->lista);
    for (int i = 0; i < grafo->numVertices; i++) {
        if (!visitado[i]) return 0;
    }
    for (int i = 0; i < grafo->numVertices; i++) {
        visitado[i] = 0;
    }
    DFS(grafo, 0, visitado, grafo->listaTransposta);
    for (int i = 0; i < grafo->numVertices; i++) {
        if (!visitado[i]) return 0;
    }
    return 1;
}
int main() {
    Grafo grafo;
    int N, M, V, W, P;//Numero de intersecções (Vertices) e numero de ruas (arestas)
    //origem e destino, se p = 1, então é mão unica, se p = 2, então a rua é de mao dupla

    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        IniciarGrafo(&grafo, N);
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &V, &W, &P);
            AdicionarAresta(&grafo, V - 1, W - 1, P);
        }
        printf("%d\n", Verificar(&grafo));
    }
    return 0;
}
