/*
	Solu��o atividade cria��o TAD para representar uma arvore binaria.
	Autor: Alisson Jaques	
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>
#include<string.h>

typedef struct Nodo* Arvore;

int soma; // a soma dos valores contidos nos nodos
int contadorNodos;

struct Nodo{
    int valor;
    struct Nodo *esq;
    struct Nodo *dir;
};

/*
	a) Permita que o usu�rio entre com valores a serem armazenados na �rvore, para isso
	crie uma fun��o para inser��o;
*/
void InsereArvore(Arvore *raiz)
{	
    int valor = 0;
    printf("Informe um valor: ");
    scanf("%i", &valor);
    
	int retorno = 0;
    if(raiz != NULL)
    {	    	
        struct Nodo* novo = (struct Nodo*)malloc(sizeof(struct Nodo));
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
                if(valor >= atual->valor)
                {
                    atual = atual->dir;
                }
                else
                {
                    atual = atual->esq;
                }
            }
            if(valor >= anterior->valor)
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
	b) Permita que o usu�rio efetue pesquisas de determinado elemento, de modo a
	verificar sua exist�ncia na �rvore, para isso crie uma fun��o para busca;
*/
void ConsultaArvore(Arvore *raiz)
{
    if(raiz != NULL)
    {
        int valor = 0;
        printf("Informe um valor: ");
        scanf("%i", &valor);
        if(raiz != NULL)
        {
            struct Nodo* atual = *raiz;
            int alturainfo = 1;
            bool registroEncontrado = false;
            while(atual != NULL)
            {
                if(valor == atual->valor)
                {
                    printf("Resgistro encontrado no nivel %i\n", alturainfo);
                    registroEncontrado = true;
                    break;
                }               
                else if(valor >= atual->valor)
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

/*
	Quest�o b): algoritmo recursivo para mostrar o numero de nos em uma arvore binaria
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

/* 
	c) Crie uma fun��o para verificar qual a altura da �rvore;
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

/*
	d) Crie uma fun��o para remover elementos da �rvore. O usu�rio dever� interagir com
	o programa para que ele possa entrar com quais elementos deseja-se efetuar a
	remo��o;
*/
void RemoveArvore(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL)
    {
        int valor = 0;
        printf("Informe um valor a ser deletado: ");
        scanf("%i", &valor);
        struct Nodo* atual = *raiz;
        struct Nodo* anterior = NULL;
        while(atual != NULL)
        {
            if(valor == atual->valor)
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
                if(valor > atual->valor)
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

/*
	e) Imprima os elementos da �rvore usando o Pr�-ordem;
*/
void mostrarPreOrdem(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {
        printf("Valor: %i \n", (*raiz)->valor);
        mostrarPreOrdem(&((*raiz)->esq));
        mostrarPreOrdem(&((*raiz)->dir));
    }
}

/*
	f) Imprima os elementos da �rvore usando o In-Ordem;
*/
void mostrarInOrdem(Arvore *raiz)
{
   if (raiz != NULL && *raiz != NULL) 
   {
      mostrarInOrdem(&((*raiz)->esq));
      printf("Valor: %i\n", (*raiz)->valor);
      mostrarInOrdem(&((*raiz)->dir)); 
   }
}

/*
	g) Imprima os elementos da �rvore usando o P�s-Ordem;
*/
void mostrarPosOrdem(Arvore *raiz){
    if(raiz != NULL && *raiz != NULL)
	{
        mostrarPosOrdem(&((*raiz)->esq));
        mostrarPosOrdem(&((*raiz)->dir));
        printf("Valor: %i\n", (*raiz)->valor);
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
        printf("3 - Listar Pre-Ordem\n");
        printf("4 - Listar In-Ordem\n");
        printf("5 - Listar Pos-Ordem\n");
		printf("6 - Consultar\n");
        printf("7 - Altura Arvore\n");
        printf("8 - Total de Nodos da Arvore\n");
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
                mostrarPreOrdem(raiz); 
                system("PAUSE");
                break;
            case 4:
                mostrarInOrdem(raiz); 
                system("PAUSE");
                break;
            case 5:
                mostrarPosOrdem(raiz); 
                system("PAUSE");
                break;
            case 6:
                ConsultaArvore(raiz); 
                system("PAUSE");
                break;
            case 7:
                altura = ArvoreAltura(raiz)-1; 
                printf("\nAltura total da Arvore: %i\n\n", altura);
                system("PAUSE");
                break;
            case 8:
				printf("\nTotal de nodos da arvore: %i\n\n", TotalNodoArvore(raiz));
            	system("PAUSE");
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
