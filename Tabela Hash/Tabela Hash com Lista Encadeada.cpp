/*
	Programa de computador que representa o algoritmo de Tabela Hash com listas encadeadas,
	mostrando a quantidade de colisões no ato de inserção – imprimindo na tela quando houver
	uma colisão. Este programa possui funções de impressão, busca, inserção e remoção. 

	Autor: Alisson Jaques
*/

#include <stdio.h>     // para emtradas e saídas de dados
#include <stdlib.h>    // para constantes
#include <malloc.h>    // para alocação dinâmica
#include <stdbool.h>   // para trabalhar com tipo booleano

#define TAM 11 // a quantidade máxima de índices da Tabela Hash

int contadorColisoes = 0;

/*
    Estrutura que representa um nó, onde cada nó armazena uma chave
*/
typedef struct no{
    int chave;
    struct no *proximo;
}No;

/*
	Estrutura que representa a lista encadeada
*/
typedef struct{
    No *inicio;
    int tam;
}Lista;

/*
    Inicializa todas as listas da tabela.
*/
void inicializarLista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

/*
    Procedimento que inseri um elemento no início na lista, recebida como argumento.
*/
void inserirNaLista(Lista *lista, int chave){
    No *novo = (No*) malloc(sizeof(No));

    if(novo){
        novo->chave = chave;
        novo->proximo = lista->inicio;
        
        if(lista->inicio!=NULL){ // se a lista já tiver conteúdo, informa que houve colisão e incrementa o contador de colisões
        	contadorColisoes++;
			printf("Houve colisao nessa insercao! Total de colisoes ate o momento: %d\n", contadorColisoes);
		}
		
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("\nErro, nao foi poassivel alocar memoria!\n");
}

// Função para buscar um elemento. Retorna o elemento encontrado ou zero caso contrário.
int buscarNaLista(Lista *lista, int chave){
    No *aux = lista->inicio;
    while(aux && aux->chave != chave)
        aux = aux->proximo;
    if(aux)
        return aux->chave;
    return 0;
}

/*
    Função hash (chave mod tamanho_do_vetor)
*/
int funcaoHash(int chave){
    return chave % TAM;
}

/*
	Procedimento que recebe a tabela e uma chave, e remove
	a respectiva chave da tabela hash.
*/
void removerChave(Lista t[], int chave){
	int id = funcaoHash(chave);
    int retorno =  buscarNaLista(&t[id], chave);
    
	if(retorno != 0){ // se a chave estiver na tabela
    	int chave_;
		Lista *lista = &t[id];
		No *aux = lista->inicio;
    	No *anterior = aux;
		if(aux->chave==chave){ // se a chave for o primeiro elemento da lista
			chave_ = aux->chave;
			lista->inicio = aux->proximo;
			free(aux);
			printf("Chave %d removida com sucesso!\n", chave_);
		} else{
			while(aux && aux->chave != chave){ // enquanto não achar o nó que possui a chave, atualiza o nó
				anterior = aux;
				aux = aux->proximo;
			}
			if(aux){ // se aux não for nulo
				chave_ = aux->chave;
				anterior->proximo=aux->proximo;
				free(aux);	
				printf("Chave %d removida com sucesso!\n", chave_);			
			}
		}		
		
	}    	
    else{
    	printf("Nao foi possivel remover, a chave informada nao esta armazenda na tabela!\n");
	}        
}

// Procedimento para imprimir a lista recebida como argumento.
void imprimirLista(Lista *lista){
    No *aux = lista->inicio;
    while(aux!=NULL){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

/*
    Procedimento que percorre a tabela inicializando cada lista
*/
void inicializarTabela(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

/*
    Procedimento para inserir um elemento na tabela hash
*/
void inserir(Lista t[], int chave){
    int id = funcaoHash(chave);
    inserirNaLista(&t[id], chave);
}

/*
    Procedimento para realizar uma busca na tabela.
*/
int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscarNaLista(&t[id], chave);
}

/*
     Procedimento para imprimir toda a tabela.
*/
void imprimir(Lista t[]){
    int i;
	printf("\nIndice  Chaves\n");    
    for(i = 0; i < TAM; i++){
        printf("[%2d] => ", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
    printf("\n");
}

/*
	A função main não recebe argumentos e permite a execução deste
	programa. Ela possui um menu que permite que o usuário manipule
	uma tabela hash.
*/
int main(){
	
	/*
		Variáveis e campos auxiliares
	*/
	int opcao, chave, retorno;
	Lista tabela[TAM];
	bool sair = false;
    inicializarTabela(tabela);
	
    do{           
        system("cls");
        printf("******************************************\n");
        printf("****************** Menu ******************\n");
        printf("******************************************\n\n");
        printf("Escolha uma das seguintes opcoes: \n\n");
		printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Imprimir\n");
        printf("4 - Remover\n");
        printf("5 - Sair\n\n");
        printf("Digite aqui sua escolha: ");
        scanf("%i", &opcao); 
        fflush(stdin);  
        switch(opcao){
            case 1: // inserção 
                printf("Insira uma chave: ");
				scanf("%d", &chave);
           		inserir(tabela, chave);
           		system("PAUSE");
                break;
            case 2: // consulta
                printf("Informe uma chave para a busca: ");
            	scanf("%d", &chave);
            	retorno = busca(tabela, chave);
            	if(retorno != 0)
                	printf("Chave encontrada: %d\n", retorno);
            	else
                	printf("Chave nao encontrada!\n");
            	system("PAUSE");
                break;
            case 3: // impressão
                imprimir(tabela);
                system("PAUSE");
                break;
            case 4: // remoção
            	printf("Informe uma chave para remocao: ");
            	scanf("%d", &chave);
            	removerChave(tabela,chave);
            	system("PAUSE");
            	break;
            case 5: // sair
            	sair = true;
                break;
            default : // opção inválida
                printf("\nOpcao invalida, forneca uma opcao valida!\n\n");
                system("PAUSE");
               	break;
        }
    }while(sair == false);
    
    printf("\n******************************************\n");
    printf("******************************************\n");
    printf("******************************************\n");
    
	return 0;
}
