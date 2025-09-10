#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct aresta{ //criado a estrutura de arestas para armazenar informa��es sobre as mesmas
    int origem, destino, peso;
} Aresta;

typedef struct grafo { //numero de v�rtices e matriz adjacencia
    int numVertices;
    int numArestas;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    Aresta arestas[MAX_VERTICES * MAX_VERTICES]; // Ajuste para acomodar todas as arestas poss�veis
} Grafo;

void inicializarGrafo(Grafo* grafo, int numVertices){ //cria um grafo novo dentro do grafo e cria a matriz la dentro.
    grafo->numVertices = numVertices;
    grafo->numArestas = 0;
    for(int i = 0; i<numVertices; i++){
        for(int j = 0; j<numVertices; j++){
            grafo->adjMatrix[i][j] = 0;
        }
    }
}

void adicionaAresta(Grafo* grafo, int origem, int destino, int peso){
    grafo->adjMatrix[origem][destino] = peso; //ADICIONAR PESO DE ARESTAS
    grafo->adjMatrix[destino][origem] = peso;
    grafo->arestas[grafo->numArestas].origem = origem;
    grafo->arestas[grafo->numArestas].destino = destino;
    grafo->arestas[grafo->numArestas].peso = peso;
    grafo->numArestas++;
}

void exibeMatrizAdjacencia(Grafo* grafo){
    for(int i = 0; i< grafo->numVertices; i++){
        for(int j = 0; j< grafo->numVertices; j++){
            printf("%d ", grafo->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int minKey(int chave[], int incluido[], int numVertices) { //Fun��o para encontrar o v�rtice com o menor custo que ainda n�o foi inclu�do na MST
    int min = INF, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (!incluido[v] && chave[v] < min) {
            min = chave[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim(Grafo* grafo) { //calcular o custo total m�nimo
    int numVertices = grafo->numVertices;
    int chave[MAX_VERTICES];      //menores custos de inclus�o na MST
    int incluido[MAX_VERTICES];   //rastrear v�rtices inclu�dos na MST
    int parent[MAX_VERTICES];     //armazenar a MST gerada

    //todos os custos como infinito e nenhum vertice inclu�do na MST
    for (int i = 0; i < numVertices; i++) {
        chave[i] = INF;
        incluido[i] = 0;
    }

    chave[0] = 0;     //primeiro v�rtice
    parent[0] = -1;   //primeiro v�rtice � a raiz da MST

    for (int count = 0; count < numVertices - 1; count++) {
        //seleciona o vertice com o menor custo que ainda n�o foi incluido na MST
        int u = minKey(chave, incluido, numVertices);
        incluido[u] = 1; //marca esse vertice como inclu�do na MST

        //atualiza os custos dos v�rtices ao lado do v�rtice selecionado
        for (int v = 0; v < numVertices; v++) {
            if (grafo->adjMatrix[u][v] && !incluido[v] && grafo->adjMatrix[u][v] < chave[v]) {
                parent[v] = u; //atualiza o pai de v
                chave[v] = grafo->adjMatrix[u][v]; //atualiza o custo de v
            }
        }
    }

    int mstCost = 0;
    for (int i = 1; i < numVertices; i++) {
        mstCost += grafo->adjMatrix[i][parent[i]];
    }
    printf("%d\n", mstCost);
}

int main(){
    //COMO USAR V�RTICES E ARESTAS RECEBIDAS POR USU�RIO!
    int R, C;
    scanf("%d %d", &R, &C); //Quantidade de v�rtices e arestas, em ordem

    Grafo grafo;
    inicializarGrafo(&grafo, R); //inicializa o grafo com a quantidade de vertices recebida.

    for(int i = 0; i<C; i++){ //recebe arestas pela quantidade de arestas recebida
        int V, W, P; //V e W um par de roteadores que est�o ligado [Origem][Destino] e P o valor [ponderado]
        scanf("%d %d %d", &V, &W, &P);
        adicionaAresta(&grafo, V - 1, W - 1, P); //n�o esquecer do -1
    }

    prim(&grafo);

    return 0;
}
