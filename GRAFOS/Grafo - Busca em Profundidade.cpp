/*
	Algoritmo que realizada a busca em profundidade tendo como entrada um
	grafo e um vertice raiz, informados pelo usuario.
	
	Autor: Alisson Jaques
*/

#include <stdio.h>  // para entrada e saida de dados
#include <stdlib.h> // para alocacao dinamica

// A estrutura nodo representa um vertice do grafo
struct nodo {
  int vertice;
  struct nodo* proximo;
};

struct nodo* criarNodo(int v); // prototipo da funcao que cria um novo nodo

/*  
	A estrutura Grafo representa um grafo, cada vertice possui uma lista de 
	nodos adjacentes.
*/
struct Grafo {
  int numVertices;
  int* visitado;
  struct nodo** listasAdjacentes;
};

/*
	Este procedimento representa o algoritmo de busca em profundidade (DFS),
	utilizado para visitar todos os vertices do grafo.
*/
void DFS(struct Grafo* grafo, int vertice) {
  struct nodo* listaAdjacente = grafo->listasAdjacentes[vertice];
  struct nodo* temp = listaAdjacente;

  grafo->visitado[vertice] = 1;
  printf(" Vertice visitado: %d \n", vertice);

  while (temp != NULL) { // enquanto temp for diferente de nulo
    int connectedVertex = temp->vertice;

    if (grafo->visitado[connectedVertex] == 0) {
      DFS(grafo, connectedVertex);
    }
    temp = temp->proximo;
  }
}

// Cria e retorna um nodo, recebendo como argumento o valor do vertice desse nodo
struct nodo* criarNodo(int v) {
  struct nodo* novoNodo = (nodo*)malloc(sizeof(struct nodo));
  novoNodo->vertice = v;
  novoNodo->proximo = NULL;
  return novoNodo;
}

// Cria e retorna um novo grafo, recebendo como argumento um numero de vertices desse grafo
struct Grafo* criarGrafo(int vertices) {
  struct Grafo* grafo = (Grafo*)malloc(sizeof(struct Grafo));
  grafo->numVertices = vertices;

  grafo->listasAdjacentes = (nodo**)malloc(vertices * sizeof(struct nodo*));

  grafo->visitado = (int*)malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    grafo->listasAdjacentes[i] = NULL;
    grafo->visitado[i] = 0;
  }
  return grafo;
}

/*
	Esse procedimento cria a relacao vertice nodos, para um grafo, vertice origem e
	e vertice destino, passados como argumentos.
*/
void relacionaVerticeComSeusNodos(struct Grafo* grafo, int origem, int destino) {
  // relacao origem / destino
  struct nodo* novoNodo = criarNodo(destino);
  novoNodo->proximo = grafo->listasAdjacentes[origem];
  grafo->listasAdjacentes[origem] = novoNodo;

  // relacao destino / origem
  novoNodo = criarNodo(origem);
  novoNodo->proximo = grafo->listasAdjacentes[destino];
  grafo->listasAdjacentes[destino] = novoNodo;
}

// Esse procedimento imprime o grafo, com sua estrutura de vertices.
void mostrarGrafo(struct Grafo* grafo) {
  int v;
  for (v = 0; v < grafo->numVertices; v++) {
    struct nodo* temp = grafo->listasAdjacentes[v];
    printf(" Listas adjacentes do vertice %d: ", v);
    while (temp) {
      printf("%d -> ", temp->vertice);
      temp = temp->proximo;
    }
    printf("\n");
  }
}

int main() {
  struct Grafo* Grafo = criarGrafo(4); // cria um novo grafo com 4 vertices
  relacionaVerticeComSeusNodos(Grafo, 0, 1); // vertice 0 -> 1
  relacionaVerticeComSeusNodos(Grafo, 0, 2); // vertice 0 -> 2
  relacionaVerticeComSeusNodos(Grafo, 1, 2); // vertice 1 -> 2
  relacionaVerticeComSeusNodos(Grafo, 2, 3); // vertice 2 -> 3

  printf("************************* Algoritmo de Busca em Profundidade *************************\n");
  printf("************************** Visita todos os nodos de um grafo *************************\n\n");
  
  mostrarGrafo(Grafo);
  printf("\n");
  DFS(Grafo, 2); // visita todos os nodos do grafo criado
  printf("\n**************************************************************************************\n\n");
  return 0;
}
