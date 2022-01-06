/* Programa que manipula uma Lista duplamente encadeada para controle de
   estacionamento de restaurante.
   Autores: Alisson Jaques e Deivid Camargos
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemento Elemento;

struct elemento {
	int valor;
	int movimentos;
	Elemento *proximo;
	Elemento *anterior;
};

/* Criar 2 variáveis globais. */
Elemento *inicio;
Elemento *fim;
int tamanho;

/* Criando prototipos de função */
void criaLista();
Elemento *aloca(int valor);
void insereInicio(int valor);
void insereFim(int valor);
void inserePosicao(int valor, int posicao);
Elemento *removeInicio();
Elemento *removeFim();
void imprimeLista();
void imprimeListaContrario();

/* Criar 2 elemmentos nulos na lista. */
void criaLista() {
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

/*Alocar um dado, e como funciona o esquema do lista duplamente encadeada: */
Elemento *aloca(int valor) {
	Elemento * novo = (Elemento*)malloc(sizeof(Elemento));
	novo->valor = valor;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}

Elemento *removeInicio() {
	Elemento *atual = inicio;
	inicio = atual->proximo;
	inicio->anterior = NULL;
	tamanho--;
}

Elemento *removeFim() {

	Elemento *atual = fim;
	if (atual->anterior == NULL){
        fim = NULL;
        inicio = NULL;
        tamanho--;
	}
	else{
        fim = atual->anterior;
        fim->proximo = NULL;
        tamanho--;
	}

	return atual;
}

/* Inserir no inicio da lista: */
void insereInicio(int valor) {
	Elemento *novo = aloca(valor);   /* criar novo elemento */
	novo->movimentos = 0;
	/* verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo. */
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
		novo->movimentos = 10;

	/* Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1. */
	}else{
	    novo->movimentos = 10 - calcQuantidadeCarroEstacionamento();

		Elemento *atual; /* criar novo elemento caso tenha dado no inicio da lista. */
		atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
	}
	tamanho++;
}

/* Inserir no fim da lista: */
void insereFim(int valor) {
	Elemento *novo = aloca(valor);   /* criar novo elemento */
	/* verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo. */
	if(inicio==NULL){
		inicio=novo;
		fim=novo;
	/* Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1. */
	}else{
		Elemento *atual; /* criar novo elemento caso tenha dado no inicio da lista.*/
		atual = fim;
		novo->anterior = atual;
		atual->proximo = novo;
		fim = novo;
	}
	tamanho++;
}

/* Função para imprimir a lista: */
void imprimeLista() {
	Elemento *atual;
	atual = inicio;
	printf("Placa=>QntMovimentos\n\n");
	while(atual){
		printf("%d=>%d  ",atual->valor, atual->movimentos);
		atual=atual->proximo;
	}
}

bool existeVeiculoEstacionamento(int placa) {
	Elemento *atual;
	atual = inicio;
	while(atual){
        if(atual->valor == placa)
            return true;
		atual=atual->proximo;
	}
	return false;
}

Elemento *removeVeiculo(int placa)
{
    Elemento *retorno;
    Elemento *aux;
    bool cond = false;
    int i;
    for(i = 0;i < tamanho+1; i++)
    {

        Elemento *removido = removeFim();
        if (i == 0 && removido->valor == placa) {
            Elemento *atual;
            atual = inicio;
            while(atual){
                atual->movimentos++;
                atual=atual->proximo;
            }
            return removido;
        }
        if(removido->valor == placa){
            removido->movimentos += i;

            retorno = removido;
            cond = true;
        }

        else if(cond == true){
            insereInicio(removido->valor);
            removido->movimentos += 11;
            inicio->movimentos =removido->movimentos;

        }
        else{
            removido->movimentos += 10;

            insereInicio(removido->valor);
            inicio->movimentos = removido->movimentos;

        }
    }
    return retorno;
}

int calcQuantidadeCarroEstacionamento(){
	Elemento *atual;
	atual = inicio;
	int quant = 0;

	while(atual){
        quant++;
		atual=atual->proximo;
	}
	return quant;
}

void limparTela(){
    system("pause");
    system("cls");
}

int main() {
	criaLista();
    int esc;
    bool botao = true;

    printf("*******************************************************************\n");
    printf("-------------------------------------------------------------------\n\n");
    printf("             Bem vindo ao gerenciador de restaurantes!!\n\n");
    printf("-------------------------------------------------------------------\n");
    printf("*******************************************************************\n");
    while(botao)
    {

        limparTela();

        printf("\n***************** Estacionamento Restaurante **********************\n");
        printf("***************************** Menu ********************************\n\n");
        printf("Escolha uma das seguintes opcoes: \n\n");
        printf("1 - Incluir novo carro\n");
        printf("2 - Remover carro\n");
        printf("3 - Mostrar carros no estacionamento\n");
        printf("4 - Sair\n\n");
        printf("Digite sua escolha: ");
        scanf("%d", &esc);

        printf("\n");

        switch(esc){
        case 1:
            system("cls");
            printf("\n************************* Estacionar Carro ************************\n");
            printf("-------------------------------------------------------------------\n\n");
            printf("Digite a placa do veiculo: (apenas valores numericos) ");
            int placa;
            scanf("%d", &placa);

            if(existeVeiculoEstacionamento(placa)){
                printf("\nVeiculo ja se encontra inserido no estacionamento!");
                printf("\n");
                break;
            }

            if(tamanho == 10){
                printf("Estacionamento esta cheio, aguarde alguem retirar o veiculo!");
                printf("\n");
                break;
            }

            insereInicio(placa);

            printf("\n-------------------------------------------------------------------\n");
            printf("*******************************************************************\n");
            break;

        case 2:{
            system("cls");
            printf("\n*************************** Remover Carro *************************\n");
            printf("-------------------------------------------------------------------\n\n");

            if(tamanho == 0){
                printf("                   Estacionamento esta vazio!\n");
                printf("\n-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                break;
            }
            printf("Digite a placa do veiculo que deseja retirar: ");

            int placa;
            scanf("%d", &placa);

            if(!existeVeiculoEstacionamento(placa))
            {
                printf("\nVeiculo nao se encontra inserido no estacionamento!");
                printf("\n-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                printf("\n");
                break;
            }

            Elemento *aux = removeVeiculo(placa);

            printf("\nCarro %d removido com sucesso!\nTotal de movimentos: %d\n", aux->valor, aux->movimentos);

            printf("\n-------------------------------------------------------------------\n");
            printf("*******************************************************************\n");
            break;
        }

        case 3: {
            system("cls");
            printf("\n****************** Lista dos Carros Estacionados ******************\n");
            printf("-------------------------------------------------------------------\n\n");

            imprimeLista();

            printf("\n\n-------------------------------------------------------------------\n");
            printf("*******************************************************************\n");

            printf("\n");
            break;
        }
        esc = 0;
        case 4:
            botao = false;
            break;
        }

    }

    printf("*******************************************************************\n");
    printf("*********************** Programa Encerrado ************************\n");
    printf("*******************************************************************\n\n");
    system("pause");
    return 0;
}

