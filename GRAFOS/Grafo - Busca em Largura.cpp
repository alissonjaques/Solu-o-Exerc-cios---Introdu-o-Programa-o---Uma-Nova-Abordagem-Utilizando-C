/* 
	Algoritmo que representa a busa em largura (BFS), recebe como entrada um grafo e 
	seu vértice, faz a busca em largura e imprime a mesma no terminal da aplicacao.
	Autor: Alisson Jaques
*/

#include <stdio.h>  // para entrada e saida de dados
#include <stdlib.h> // para manipulacao de constantes e alocoes dinamicas
#define SIZE 40     // a capacidade maxima de intens da fila 

/*
	A estrutura fila representa uma fila FIFO, utilizada para a varredura da
	busca em largura.
*/
struct fila {
  int itens[SIZE];
  int frente;
  int atras;
};

/*
	Prototipos de funcoes e procedimentos.
*/
struct fila* criaFila();
void enfileirar(struct fila* q, int);
int desenfileirar(struct fila* q);
void display(struct fila* q);
int verificaVazio(struct fila* q);
void mostraFila(struct fila* q);

/*
	A estrutura nodo representa um vertice/nodo do grafo.
*/
struct nodo {
  int vertice;
  struct nodo* proximo;
};

struct nodo* criaNodo(int);

/*
 	A estrutura Grafo representa um grafo, ela possui um numero de vertices e 
 	uma lista de vertices adjacentes, bem como um apontador para o ultimo vertice visitado.
*/
struct Grafo {
  int numVertices;
  struct nodo** listasAdjacentes;
  int* visitado;
};

/*
	Procedimento que realiza a busca em largura (BFS), recebe como argumento um grafo e um inteiro
	como vertice raiz, realizando a busca em largura no grafo.
*/
void bfs(struct Grafo* grafo, int raiz) {
  struct fila* q = criaFila();

  grafo->visitado[raiz] = 1;
  enfileirar(q, raiz);

  while (!verificaVazio(q)) { // enquanto q for diferente de vazio
    mostraFila(q);
    int verticeAtual = desenfileirar(q);
    printf("\nVisitado: %d <- cinza\n", verticeAtual);
	
    struct nodo* temp = grafo->listasAdjacentes[verticeAtual];

    while (temp) { // enquanto existir um vertice adjacente nao visitado (branco)
      int verticeAdjacente = temp->vertice;

      if (grafo->visitado[verticeAdjacente] == 0) {
        grafo->visitado[verticeAdjacente] = 1;
        enfileirar(q, verticeAdjacente);
        printf("Enfileirado: %d\n", verticeAdjacente);
      }
      temp = temp->proximo;
    }
    printf("Desempilhado: %d <- preto\n", verticeAtual);
  }
  
}

// Funcao que cria e devolve um novo vertice para o grafo
struct nodo* criaNodo(int v) {
  struct nodo* novoNodo = (struct nodo*) malloc(sizeof(struct nodo));
  novoNodo->vertice = v;
  novoNodo->proximo = NULL;
  return novoNodo;
}

/*
	Funcao que cria e devolve uma nova estrutura Grafo, recebendo como argumento
	um inteiro que representa a quantidade de vertices desse grafo.
*/
struct Grafo* criaGrafo(int vertices) {
  struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
  grafo->numVertices = vertices;

  grafo->listasAdjacentes = (struct nodo**)malloc(vertices * sizeof(struct nodo*));
  grafo->visitado = (int*)malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    grafo->listasAdjacentes[i] = NULL;
    grafo->visitado[i] = 0;
  }

  return grafo;
}

/*
	Procedimento que adiciona uma nova aresta no grafo, recebe o grafo
	e dois vertices para isso.
*/
void adicionarAresta(struct Grafo* grafo, int src, int dest) {
  struct nodo* novoNodo = criaNodo(dest);
  novoNodo->proximo = grafo->listasAdjacentes[src];
  grafo->listasAdjacentes[src] = novoNodo;

  novoNodo = criaNodo(src);
  novoNodo->proximo = grafo->listasAdjacentes[dest];
  grafo->listasAdjacentes[dest] = novoNodo;
}

/*
	Funcao que cria um nova fila FIFO e a retorna.
*/
struct fila* criaFila() {
  struct fila* q = (struct fila*)malloc(sizeof(struct fila));
  q->frente = -1;
  q->atras = -1;
  return q;
}

// Funcao que chequa se a fila esta vazia
int verificaVazio(struct fila* q) {
  if (q->atras == -1)
    return 1;
  else
    return 0;
}

// Procedimento que adiciona vertices na fila
void enfileirar(struct fila* q, int value) {
  if (q->atras == SIZE - 1)
    printf("\nA fila esta cheia!!");
  else {
    if (q->frente == -1)
      q->frente = 0;
    q->atras++;
    q->itens[q->atras] = value;
  }
}

// Funcao que remove um vertice da fila
int desenfileirar(struct fila* q) {
  int item;
  if (verificaVazio(q)) {
    printf("A fila esta vazia.");
    item = -1;
  } else {
    item = q->itens[q->frente];
    q->frente++;
    if (q->frente > q->atras) {
      /*printf("Desenfileirando da fila.");*/
      q->frente = q->atras = -1;
    }
  }
  return item;
}

// Procedimento que imprime o estado atual da fila
void mostraFila(struct fila* q) {
  int i = q->frente;

  if (verificaVazio(q)) {
    printf("Fila esta vazia.");
  } else {
    printf("\nFila possui ");
    for (i = q->frente; i < q->atras + 1; i++) {
      printf("%d ", q->itens[i]);
    }
  }
}

/*
	A funcao main nao possui argumentos e permite a execucao desse programa.
	Ela permite que o usuario entre com um grafo (passando arestas) e um vertice
	raiz e imprime o resultado da busca em largura desse grafo, considerando o vertice
	raiz informado.
*/
int main() {
	printf("**************************** Algoritmo de Busca em Largura ***************************\n");
  	printf("************************** Visita todos os nodos de um grafo *************************\n\n");
  
	int numeroVertices;
	printf("Informe o numero de vertices do grafo: ");
	scanf("%d",&numeroVertices);
	struct Grafo* Grafo = criaGrafo(numeroVertices);
	int simOuNao = 1;
	int verticeOrigem, verticeDestino;
	printf("\n--------------------------------------------------------------------------------------\n\n");
	while(simOuNao==1){
		printf("Deseja informar uma aresta? (1 - sim / 2 - nao): ");
	  	scanf("%d", &simOuNao);
	  	if(simOuNao==1){
		  printf("Informe o primeiro vertice da aresta: ");
		  scanf("%d", &verticeOrigem);
		  printf("Informe o segundo vertice da aresta: ");
		  scanf("%d", &verticeDestino);
		  adicionarAresta(Grafo, verticeOrigem, verticeDestino);
		} else{
			simOuNao = 2;	
		}
		printf("\n--------------------------------------------------------------------------------------\n\n");
	}
	
	int raiz;
	printf("Informe a raiz do grafo: ");
	scanf("%d",&raiz);		
	printf("\n--------------------------------------------------------------------------------------\n\n");
	printf("Busca em largura: \n");
	bfs(Grafo, raiz);
	
  	printf("\n**************************************************************************************\n\n");
	return 0;
}
