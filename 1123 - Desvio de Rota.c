#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define INFINITO INT_MAX
#define MAX_VERTICES 250

typedef struct {
    int numVertices;
    int AdjMatrix[MAX_VERTICES][MAX_VERTICES];
} Grafo;

void InicializarGrafo(Grafo *grafo, int numVertices) {
    grafo->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            grafo->AdjMatrix[i][j] = INFINITO;
        }
    }
}

void InserirGrafo(Grafo *grafo, int origem, int destino, int peso) {
    grafo->AdjMatrix[origem][destino] = peso;
    grafo->AdjMatrix[destino][origem] = peso;
}

int minDistancia(int dist[], int visitado[], int numVertices) {
    int min = INFINITO, min_index = -1;
    for (int v = 0; v < numVertices; v++) {
        if (!visitado[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(Grafo *grafo, int origem, int dist[]) {
    int visitado[MAX_VERTICES] = {0};

    for (int i = 0; i < grafo->numVertices; i++) {
        dist[i] = INFINITO;
    }
    dist[origem] = 0;
    for (int count = 0; count < grafo->numVertices - 1; count++) {
        int u = minDistancia(dist, visitado, grafo->numVertices);
        if (u == -1) break;
        visitado[u] = 1;
        for (int v = 0; v < grafo->numVertices; v++) {
            if (!visitado[v] && grafo->AdjMatrix[u][v] != INFINITO && dist[u] != INFINITO && dist[u] + grafo->AdjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo->AdjMatrix[u][v];
            }
        }
    }
}

int main() {
    Grafo grafo;
    int N, M, C, K;
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;

        InicializarGrafo(&grafo, N);

        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            InserirGrafo(&grafo, U, V, P);
        }
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < N; j++) {
                if (j != i + 1 && j != i) {
                    grafo.AdjMatrix[i][j] = INFINITO;
                }
            }
        }
        int dist[MAX_VERTICES];
        dijkstra(&grafo, K, dist);
        printf("%d\n", dist[C - 1]);
    }

    return 0;
}
