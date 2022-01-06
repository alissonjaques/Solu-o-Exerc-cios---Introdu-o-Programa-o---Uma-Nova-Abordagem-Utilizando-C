/*
	Algoritmo que utiliza do conceito de pilha para manipular um digitador de texto.
	Entradas: opcao para escrever uma linha de texto, linha de texto, opcao para excluir uma linha,
	opcao para mostrar o texto e opcao para sair da aplicacao.
	Saida: o texto digitado ate o momento
	Autor: Alisson Jaques
*/

#include <stdio.h>  /* Biblioteca para entrada e saida de dados */
#include <stdlib.h> /* Biblioteca para manipulacao de constantes */
#include <string.h> /* Biblioteca para manipulacao de strings */

#define MAX 200 /* capacidade maxima de caracteres em uma linha */

/*
	A estrutura de dados representa uma Pilha (duplamente encadeada) que armazena as linhas 
	digitadas pelo usuario, a primeira linha a ser digitada eh a ultima a sair e a ultima 
	digitada eh a primeira a sair.
*/
typedef struct celulas{
    char linha[MAX];           /* uma linha de texto */
    struct celulas * anterior; /* a linha de texto anterior a atual */
    struct celulas * proximo;  /* a linha de texto seguinte a atual */
}Pilha;

/*
	A funcao inserirLinha(Pilha) permite a insercao de linhas de texto na aplicacao, cada linha de texto
	eh um elemento da Pilha.
*/
void inserirLinha(Pilha * celula){
    if(celula->proximo==NULL){ /* se a pilha estiver vazia, faca: */
        Pilha *novaCelula;                    /* declara um apontador do tipo Pilha */
        novaCelula = malloc (sizeof (Pilha)); /* aloca memoria para a nova estrutura */

        char linha[MAX];

        /*
            Solicita o texto e inicializa o vetor de caracteres com o mesmo.
			Por fim, o vetor de caracteres eh copiado para o campo linha da estrutura
			e esta eh adicionada a pilha.
        */
        printf("\n======================== Inserindo Linha ========================\n\n");
        printf("Informe o texto: ");
        gets(linha);
        fflush(stdin);
        printf("\n");
        strcpy(novaCelula->linha,linha);
        novaCelula->proximo = NULL;
        novaCelula->anterior = celula;
        celula->proximo = novaCelula;
        printf("-------------------------------------------------------------------\n");
        printf("-------------------- Linha Inserida com Sucesso! ------------------\n");
        printf("-------------------------------------------------------------------\n\n");
    }
    else{ /* senao, faca: */

		Pilha *novaCelula;                    /* declara um apontador do tipo Pilha */
        novaCelula = malloc (sizeof (Pilha)); /* aloca memoria para a nova estrutura */

        char linha[MAX];

		/*
            Solicita o texto e inicializa o vetor de caracteres com o mesmo.
			Por fim, o vetor de caracteres eh copiado para o campo linha da estrutura
			e esta eh adicionada a pilha.
        */
        printf("\n======================== Inserindo Linha ========================\n\n");
        printf("Informe o texto: ");
        gets(linha);
        fflush(stdin);
        printf("\n");
        strcpy(novaCelula->linha,linha);
        novaCelula->proximo = celula->proximo;
        novaCelula->anterior = celula;
        celula->proximo->anterior = novaCelula;
        celula->proximo = novaCelula;
        printf("-------------------------------------------------------------------\n");
        printf("-------------------- Linha Inserida com Sucesso! ------------------\n");
        printf("-------------------------------------------------------------------\n\n");
    }
} /* fim da funcao inserirLinha(Pilha) */

/*
	A funcao removerLinha(Pilha) remove a linha do topo da Pilha.
*/
void removerLinha(Pilha * celula){
    char linha[MAX]; /* campo auxiliar*/
    Pilha * aux;
    aux = celula->proximo; /* guarda o elemento do topo da pilha*/
    celula->proximo = aux->proximo; /* a cabeca da pilha aponta para o novo topo da mesma */
    if(aux->proximo!=NULL){ /* se a pilha nao estiver vazia */
        aux->proximo->anterior = celula; /* atualiza o elemento anterior do novo topo da pilha */
    }
    strcpy(linha,aux->linha); /* guarda a linha que sera excluida */
    free(aux); /* libera a memoria do antigo topo da pilha */
    printf("A linha abaixo foi removida com sucesso!!\nLinha Removida: %s",linha); /* mostra a linha que foi removida da pilha */
}

/*
	A funcao retornaUltimoElemento(Pilha) retorna o ultimo elemento da pilha, ou seja, o primeiro
	elemento que foi inserido na mesma.
*/
Pilha * retornaUltimoElemento(Pilha * cabeca){
    Pilha *p; /* elemento controlador do laco */
    Pilha *ultimo; /* o ultimo elemento da pilha */
    for (p = cabeca->proximo; p != NULL; p = p->proximo){
        if(p->proximo==NULL){
            ultimo = p;
        }
    }
    return ultimo;
} /* fim da funcao retornaUltimoElemento(Pilha) */

/*
	A funcao mostarTexto(Pilha) mostra o texto digitado ate o momento, para tanto
	ela percorre a pilha de forma inversa, utilizando o campo anterior dos elementos
	da mesma.
*/
void mostrarTexto(Pilha * cabeca){
    /*
      Este for imprimi todo o texto digitado ate agora
    */
    Pilha *p = retornaUltimoElemento(&(*cabeca));
    Pilha *aux;
    printf("\n-------------------------------------------------------------------\n\n");
    for(aux = p; aux!=cabeca; aux = aux->anterior){
        printf("%s\n",aux->linha);
    }
    printf("\n-------------------------------------------------------------------\n");
} // fim da funcao mostrarTexto(Pilha)
 
/*
	A funcao liberarMemoriaPilha(Pilha) libera todas as memorias alocadas para
	os elementos da pilha.
*/
void liberarMemoriaPilha(Pilha *cabeca){
    Pilha *noAtual;
    noAtual = cabeca;
    while (noAtual != NULL){ /* Enquanto noAtual for diferente de nulo, faca: */
        cabeca = noAtual->proximo;
        free(noAtual);
        noAtual = cabeca;
    }
} /* Fim da funcao liberarMemoriaPilha(Pilha) */

int main(){
    Pilha *cabeca; 								/* A cabeca da pilha que ira apontar para o topo da mesma */
    cabeca = (Pilha *) malloc (sizeof (Pilha)); /* aloca memoria para a cabeca da pilha */


    /* Verifica se conseguiu alocar */
	if (!cabeca) {
		printf("Nao foi possivel alocar a memoria.\n");
		exit(1);
	}
    cabeca->anterior = NULL; /* o campo anterior da pilha comeca apontando para NULL */
    cabeca->proximo = NULL;  /* o campo proximo da pilha comeca apontando para NULL */

	int opcao; /* Armazena a opcao escolhida pelo usuario */

	do{
        /*
            O menu da aplicacao solicita ao usuario que escolha uma opcao e chama funcoes
            correspondentes de acordo com a escolha do usuario.
        */
        printf("\n====================== Digitador de Texto =========================\n");
        printf("============================= Menu ================================\n\n");
        printf("Escolha uma das seguintes opcoes: \n\n");
        printf("1 - Incluir uma nova linha de texto\n");
        printf("2 - Remover ultima linha digitada\n");
        printf("3 - Mostrar o texto digitado\n");
        printf("4 - Sair\n\n");
        printf("Digite sua escolha: ");
        scanf("%i",&opcao);
        fflush(stdin);

        switch(opcao){ /* Caso opcao seja: */
            case 1: /* Incluir uma nova linha de texto, faca: */
                inserirLinha(&*(cabeca));
                system("pause");
                system("cls");
                break;
            case 2: /* Remover ultima linha digitada, faca: */
                printf("\n===================== Removendo Ultima Linha ====================\n\n");
                printf("\n-------------------------------------------------------------------\n");
                if(cabeca->proximo==NULL){
                    printf("\nRemocao nao realizada, nao ha texto digitado.\n");
                }
                else{
                    removerLinha(&*(cabeca));
                }
                printf("\n-------------------------------------------------------------------\n");
                printf("\n===================================================================\n");
                system("pause");
                system("cls");
                break;
            case 3: /* Mostrar o texto digitado, faca: */
                printf("\n================== Texto Digitado Pelo Usuario ====================\n");
                if(cabeca->proximo==NULL){
                    printf("\nNenhum texto foi digitado.\n");
                }
                else{
                    mostrarTexto(&*(cabeca));
                }
                printf("\n===================================================================\n");
                system("pause");
                system("cls");
                break;
            case 4: /* Sair da aplicacao, faca: */
                break;
            default:
                printf("\n===================================================================\n");
                printf("\nOpcao invalida. Por favor, insira uma opcao valida.\n");
                printf("\n===================================================================\n");
                system("pause");
                system("cls");
        }
	}while(opcao!=4); /* Enquanto o usuario nao escolher sair da aplicacao */

    liberarMemoriaPilha(&*(cabeca)); /* Libera a memoria para todos os elementos da pilha */

    printf("\n===================================================================\n");
    printf("======================= Programa Encerrado ========================\n");
    printf("===================================================================\n\n");
    system("pause");
    return 0;
} /* fim da funcao main() */
