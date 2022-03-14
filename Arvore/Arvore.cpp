/*

estritamente binaria  = Quando todos os nao tem dois filhos com excesscao dos nos
folhas

arvore N area = AEDs III 

completa  = e quando todos os nao tem dois filhos com excesscao dos nos folhas

altura de uma Arvore = A altura de um no x em uma arrvore binaria eh a distancia
entre x e o seu descendente mais afastado. Mais precisamente, a altura de x eh o 
numero de passos no mais longo caminho que leva de x ate uma folha.

quase completa = Se a diferenca de altura entre as sub-arvores de qualquer no eh 
no maximo 1.

profundidade = A profundidade de um no eh a distancia deste no ate a raiz. 
Um conjunto de nos com a mesma profundidade eh denominado nivel da arvore.
A maior profundidade de um no, eh a altura da avore.

*/
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<stdbool.h>
#include<locale.h>
#include<string.h>

typedef struct Nodo* Arvore;

int soma; // a soma dos valores contidos nos nodos
int contadorNodos;


struct Nodo{
	int chave;
    int valor;
    struct Nodo *esq;
    struct Nodo *dir;
};

typedef struct reg{
	Arvore *nodo;
    struct reg *prox;
}Pilha;

Pilha *cabeca;

/*  
	Questao a) Adicionar nodos na arvore
	Solucao:
*/
void InsereArvore(Arvore *raiz)
{	
	int chave = 0;
    int valor = 0;
    printf("Informe uma chave: ");
    scanf("%i", &chave);
    printf("Informe um valor: ");
    scanf("%i", &valor);
    
	int retorno = 0;
    if(raiz != NULL)
    {	    	
        struct Nodo* novo = (struct Nodo*)malloc(sizeof(struct Nodo));
        novo->chave = chave;
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        if(*raiz == NULL)
        {
            *raiz = novo;
        }
        else
        {	
        	struct Nodo* atual = *raiz;
            struct Nodo* anterior = NULL;
            while(atual != NULL)
            {
                anterior = atual;
                if(chave >= atual->chave)
                {
                    atual = atual->dir;
                }
                else
                {
                    atual = atual->esq;
                }
            }
            if(chave >= anterior->chave)
            {
                anterior->dir = novo;
            }
            else
            {
                anterior->esq = novo;
            }
        }
    }
}

/*
	Questão b): algoritmo recursivo para mostrar o numero de nos em uma arvore binaria
*/
int TotalNodoArvore(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {
        int alt_esq = TotalNodoArvore(&((*raiz)->esq));
        int alt_dir = TotalNodoArvore(&((*raiz)->dir));
        retorno = alt_esq + alt_dir + 1;
    }
}

void criapilha (void) {
   cabeca = (Pilha *) malloc (sizeof (Pilha)); // cabeca
   cabeca->prox = NULL; 
}

void empilha (Arvore *nodo) { 
   Pilha *nova;
   nova = (Pilha *)malloc (sizeof (Pilha));
   nova->nodo = nodo;
   nova->prox  = cabeca->prox;
   cabeca->prox = nova; 
}

Arvore* desempilha (void) {
   Pilha *p;
   p = cabeca->prox;
   Arvore *retorno = p->nodo;
   cabeca->prox = p->prox;
   return retorno; 
}

void Liberapilha(Pilha *cabeca){
    Pilha *noAtual;
    noAtual = cabeca;
    while (noAtual != NULL){ /* Enquanto noAtual for diferente de nulo, faca: */
        cabeca = noAtual->prox;
        free(noAtual);
        noAtual = cabeca;
    }
} 

/*
	Questao C) algoritmo não-recursivo para mostrar o número de nós em uma árvore binária
*/ 
void TotalNodosSemRecursao(Arvore *raiz) {
   criapilha ();  // pilha de nós 
   empilha (raiz);
   Arvore *x;
   while (true) {
      x = desempilha ();
	  if (x != NULL) {
         empilha(x);
         empilha(&((*x)->esq));
      }
      else {
      	 if (cabeca->prox==NULL) break;
         x = desempilha ();
         contadorNodos++;
         empilha(&((*x)->dir));
      }
   }
   Liberapilha (cabeca);
}

/*
	Questao d): algoritmo recursivo para mostrar a soma do [Valor] de todos os nos em uma arvore binaria
	Solucao:
*/
void TotalNodoValorArvore(Arvore *raiz)
{
    if(raiz != NULL && *raiz != NULL)
    {
    	int valor = (*raiz)->valor;
    	soma = soma + valor;
		TotalNodoValorArvore(&((*raiz)->esq));
        TotalNodoValorArvore(&((*raiz)->dir));
    }
}

/*
	Questao e): algoritmo não-recursivo para mostrar a soma do [Valor] de todos os nos em uma arvore binaria
	Solucao:
*/
void TotalNodoValorArvoreSemRecursao(Arvore *raiz) {
   soma = 0;
   criapilha ();  // pilha de nós 
   empilha (raiz);
   Arvore *x;
   while (true) {
      x = desempilha ();
	  if (x != NULL) {
         empilha(x);
         empilha(&((*x)->esq));
      }
      else {
      	 if (cabeca->prox==NULL) break;
         x = desempilha ();
         soma = soma + (*x)->valor;
         empilha(&((*x)->dir));
      }
   }
   Liberapilha (cabeca);
}

/* 
	Questao f) algoritmo recursivo para mostrar A profundidade de uma árvore binaria
*/
int ArvoreAltura(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {
        int alt_esq = ArvoreAltura(&((*raiz)->esq));
        int alt_dir = ArvoreAltura(&((*raiz)->dir));
        if(alt_esq > alt_dir)
        {
            retorno = alt_esq + 1;
        }
        else
        {
            retorno = alt_dir + 1;
        }
    }
}

Arvore* CriarArvore()
{
    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));
    if(raiz != NULL)
    {
        *raiz = NULL;   
    }
    return raiz;
}

void LiberaNodo(struct Nodo* nodo)
{
    if(nodo != NULL)
    {
        LiberaNodo(nodo->esq);
        LiberaNodo(nodo->dir);
        free(nodo);
        nodo = NULL;
    }
}

void LiberaArvore(Arvore *raiz)
{
    if(raiz != NULL)
    {
        LiberaNodo(*raiz);
        free(raiz);
    }
}

int ArvoreEstaVazia(Arvore *raiz)
{
    int retorno = 0;
    if(raiz == NULL)
    {
        retorno = 1;
    }
    else if(*raiz == NULL)
    {
        retorno = 1;
    }   
    return retorno;
}

void ListarArvore(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {
        printf("Chave: %i \n", (*raiz)->chave);
        printf("Valor: %i \n", (*raiz)->valor);
        ListarArvore(&((*raiz)->esq));
        ListarArvore(&((*raiz)->dir));
    }
}

Arvore RemoveNodoAtualArvore(struct Nodo *nodoRemover)
{
    struct Nodo * nodo1, *nodo2;
    if(nodoRemover->esq == NULL)
    {
        nodo2 = nodoRemover->dir;
        free(nodoRemover);
    }
    else    {   nodo1 = nodoRemover;
        nodo2 = nodoRemover->esq;
        while(nodo2->dir != NULL)
        {
            nodo1 = nodo2;
            nodo2 = nodo2->dir;
        }
        if(nodo1 != nodoRemover)
        {
            nodo1->dir = nodo2->esq;
            nodo2->esq = nodoRemover->esq;
        }
        nodo2->dir = nodoRemover->dir;
        free(nodoRemover);  
        nodoRemover = NULL; 
    }
    return nodo2;
}

void RemoveArvore(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL)
    {
        int chave = 0;
        printf("Informe uma chave para deletar o nodo: ");
        scanf("%i", &chave);
        struct Nodo* atual = *raiz;
        struct Nodo* anterior = NULL;
        while(atual != NULL)
        {
            if(chave == atual->chave)
            {
                if(atual == *raiz)
                {
                    *raiz = RemoveNodoAtualArvore(atual);
                }
                else
                {
                    if(anterior->dir == atual)
                    {
                        anterior->dir = RemoveNodoAtualArvore(atual);
                    }
                    else
                    {
                        anterior->esq = RemoveNodoAtualArvore(atual);
                    }
                }
                break;
            }
            else
            {
                anterior = atual;
                if(chave > atual->chave)
                {
                    atual = atual->dir;
                }
                else
                {
                    atual = atual->esq;
                }
            }
        }
    }
}

void ConsultaArvore(Arvore *raiz)
{
    if(raiz != NULL)
    {
        int chave = 0;
        printf("Informe uma chave: ");
        scanf("%i", &chave);
        if(raiz != NULL)
        {
            struct Nodo* atual = *raiz;
            int alturainfo = 1;
            bool registroEncontrado = false;
            while(atual != NULL)
            {
                if(chave == atual->chave)
                {
                    printf("Resgistro encontrado na altura %i\n", alturainfo);
                    registroEncontrado = true;
                    break;
                }               
                else if(chave >= atual->chave)
                {
                    alturainfo = alturainfo + 1;
                    atual = atual->dir;
                }
                else
                {
                    alturainfo = alturainfo + 1;
                    atual = atual->esq;
                }
            }
            if(registroEncontrado == false)
            {
                printf("Resgistro nao encontrado\n");
            }
        }
    }
}
int main()
{   
    bool sair = false;
    int opcao = 0;
    Arvore *raiz = CriarArvore();
    int altura = 0;
    do
    {           
        system("cls");
        printf("******************************************\n");
        printf("****************** Menu ******************\n");
        printf("******************************************\n\n");
        printf("Escolha uma das seguintes opcoes: \n\n");
		printf("1 - Inserir\n");
        printf("2 - Deletar\n");
        printf("3 - Listar\n");
        printf("4 - Consultar\n");
        printf("5 - Altura Arvore\n");
        printf("6 - Total de Nodos da Arvore\n");
        printf("7 - Total de todos os valores dos nodos:\n");
        printf("8 - Profundidade da Arvore\n");
        printf("9 - Sair\n\n");
        printf("Digite aqui sua escolha: ");
        scanf("%i", &opcao); 
        fflush(stdin);  
        switch(opcao)
        {
            case 1:
                InsereArvore(raiz);
                break;
            case 2:
                RemoveArvore(raiz);
                break;
            case 3:
                ListarArvore(raiz); 
                system("PAUSE");
                break;
            case 4:
                ConsultaArvore(raiz); 
                system("PAUSE");
                break;
            case 5:
                altura = ArvoreAltura(raiz); 
                printf("\nAltura total da Arvore: %i\n\n", altura);
                system("PAUSE");
                break;
            case 6:
				printf("\nTotal de nodos da arvore: %i\n\n", TotalNodoArvore(raiz));
            	system("PAUSE");
				break;
			case 7:
				soma = 0;
				TotalNodoValorArvore(raiz);
            	printf("\nSoma dos valores dos nodos: %i\n\n", soma);
            	system("PAUSE");
				break;
            case 8:;
            
				break;
			case 9:
            	sair = true;
                break;
            default :
                printf("\nOpcao invalida, forneca uma opcao valida!\n\n");
                system("PAUSE");
               	break;
        }
    }while(sair == false);
    LiberaArvore(raiz);
    printf("\n******************************************\n");
    printf("******************************************\n");
    printf("******************************************\n");
    return 0;
}
