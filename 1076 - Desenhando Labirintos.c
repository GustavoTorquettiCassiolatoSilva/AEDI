#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 49

typedef struct graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Grafo;

void InicializarGrafo(Grafo* grafo, int numVertices) {
    grafo->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            grafo->adjMatrix[i][j] = 0;
        }
    }
}

void AdicionaAresta(Grafo* grafo, int origem, int destino) {
    grafo->adjMatrix[origem][destino] = 1;
    grafo->adjMatrix[destino][origem] = 1;
}

void DFS(Grafo* grafo, int vertice, int visitados[], int* movimentos) {
    visitados[vertice] = 1;
    for (int i = 0; i < grafo->numVertices; i++) {
        if (grafo->adjMatrix[vertice][i]) {
            if (!visitados[i]) {
                (*movimentos) += 2;
                DFS(grafo, i, visitados, movimentos);
            }
        }
    }
}

int main() {
    Grafo grafo;
    int T, N, V, A, temp1, temp2;

    scanf("%i", &T);

    for (int i = 0; i < T; i++) {
        scanf("%i", &N);
        scanf("%i %i", &V, &A);
        InicializarGrafo(&grafo, V);
        for (int j = 0; j < A; j++) {
            scanf("%i %i", &temp1, &temp2);
            AdicionaAresta(&grafo, temp1, temp2);
        }
        int visitados[MAX_VERTICES];
        memset(visitados, 0, sizeof(visitados));
        int movimentos = 0;
        DFS(&grafo, N, visitados, &movimentos);
        printf("%i\n", movimentos);
    }

    return 0;
}
