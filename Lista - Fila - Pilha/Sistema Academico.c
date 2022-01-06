#include<stdio.h>  /* Biblioteca para entrada e saida de dados */
#include<string.h> /* Biblioteca para manipulacao de strings */
/*
	Este algoritmo representa um programa de computador que possibilita
	o cadastro de usuários (inclusao, remocao e alteracao do dado score).
	Entradas: Um lista de alunos e dados informados para cadastro de alunos e 
	atualizacao de score.
	
	Saidas: lista de alunos escrita em um arquivo de texto, impressao de lista de
	alunos, ordenada em ordem descrescente de score, no terminal e impressao da 
	posicao do aluno.
	
	Autor: Alisson Jaques
*/
/*
	A estrutura Aluno que possui campos que representam um aluno
	e um campo apontador para o proximo aluno.
*/
typedef struct aluno{
    char nome[50];
    int idade;
    char cpf[12];
    int score;
    struct aluno * proximo;
}Aluno;

typedef enum { false, true } boolean; /* criacao do tipo booleano */

/*
	A funcao verificaCpf(Lista Aluno,char[]) recebe como parametros a lista encadeada e 
	um CPF e verifica se existe na lista encadeada um aluno com esse CPF.
	Parametro: cabeca a cabeca da lista encadeada
	Parametro: cpf o cpf do aluno
	Retorno: true se existir aluno com o cpf informado, false caso contrario
*/
boolean verificaCpf(Aluno *cabeca, char cpf[]){
    Aluno *aux;
    for(aux = cabeca->proximo; aux!=NULL; aux = aux->proximo){ /* enquanto nao percorrer toda a lista encadeada, faca: */
        if(strcmp(aux->cpf,cpf)==0){ /* se encontrar o aluno, retorna true */
            return true;
        }
    }
    return false; /* nao encontrou o aluno, retorna false */
}

/*
	A funcao incluirNovoAluno(Lista Aluno) permite a inclusao de um novo aluno no sistema,
	via interacao com o usuario da aplicacao.
	Parametro: cabeca a cabeca da lista encadeada
	Retorno: true se for possivel incluir o aluno informado, false caso contrario
*/
boolean incluirNovoAluno(Aluno *cabeca){
    if(cabeca->proximo==NULL){ /* se a lista estiver vazia, faca: */
        Aluno * novoAluno;					 /* apontador para tipo Aluno */
        novoAluno = malloc (sizeof (Aluno)); /* aloca memoria para novoAluno */
		
		/* campos auxiliares */
        char nome[50];
        int idade;
        char cpf[12];
        int score = 0;
		
		/* 
		   solicita os dados necessarios para representar um aluno e incializa os campos auxilares 
		   com os mesmos.
		*/
        printf("Informe o nome do aluno: ");
        gets(nome);
        fflush(stdin);
        printf("Informe a idade do aluno: ");
        scanf("%i",&idade);
        fflush(stdin);
        printf("Informe o cpf do aluno (apenas numeros): ");
        gets(cpf);
        fflush(stdin);
        printf("\n");
		
		/* copia os campos obtidos para seus correspondentes, na struct novoAluno */
        strcpy(novoAluno->nome,nome);
        novoAluno->idade = idade;
        strcpy(novoAluno->cpf,cpf);
        novoAluno->score = score;
        novoAluno->proximo = NULL;  /* a primeira struct inserida sempre sera, tambem, a ultima da lista */
        cabeca->proximo = novoAluno; /* a cabeca passa a apontar para o primeiro elemento inserido na lista */
        return true; 
    }
    else{ /* senao, faca: */
        Aluno * novoAluno;					/* apontador para tipo Aluno */
        novoAluno = malloc (sizeof (Aluno));/* aloca memoria para novoAluno */
		
		/* campos auxiliares */
        char nome[50];
        int idade;
        char cpf[12];
        int score = 0;
		
		/* 
		   solicita os dados necessarios para representar um aluno e incializa os campos auxilares 
		   com os mesmos.
		*/
		
        printf("Informe o nome do aluno: ");
        gets(nome);
        fflush(stdin);
        printf("Informe a idade do aluno: ");
        scanf("%i",&idade);
        fflush(stdin);
        printf("Informe o cpf do aluno (apenas numeros): ");
        gets(cpf);
        fflush(stdin);
        printf("\n");

        if(verificaCpf(&(*cabeca),cpf)==true){ /* verifica se o CPF informado ja esta cadastrado no sistema */
            return false; /* se estiver, retorna falso */
        }
		
		/* copia os campos obtidos para seus correspondentes, na struct novoAluno */
        strcpy(novoAluno->nome,nome);
        novoAluno->idade = idade;
        strcpy(novoAluno->cpf,cpf);
        novoAluno->score = score;
        novoAluno->proximo = cabeca->proximo; /* inseri o elemento no inicio da lista encadeada */
        cabeca->proximo = novoAluno; /* atualiza o elemento que a cabeca aponta */
        mergeSort(&cabeca); /* ordena os elementos da lista, por ordem decrescente de score */
        return true;
    }
}

/*
	A funcao removerAluno(Lista Aluno, char[]) recebe como argumentos a lista encadeada e um 
	CPF e remove da lista, se esta contiver o CPF, o aluno com o CPF informado.
	Parametro: cabeca a cabeca da lista encadeada
	Parametro: cpf o CPF do aluno
*/
void removerAluno(Aluno *cabeca, char cpf[]){
    Aluno *aux;
    Aluno *anterior;
    for(aux = cabeca; aux!=NULL; aux = aux->proximo){ /* enquanto nao encontrar o CPF informado, faca: */
        if(strcmp(aux->cpf,cpf)==0){ /* se encontrar o cpf informado, saia do for */
            break;
        }
        anterior = aux; /* armazena o elemento anterior (da ultima iteracao) */
    }

    if(aux!=NULL){ /* se encontrar o CPF */
        printf("\nEstudante %s removido com sucesso!\n",aux->nome); /* informa que o aluno foi removido com sucesso */
        anterior->proximo = aux->proximo; /* retira o elemento da lista */
        free(aux); /* libera a memoria alocada do elemento removido */
    }
    else{ /* senao */
        printf("\nNao foi possivel remover, CPF nao corresponde a um aluno cadastrado no sistema."); /* informa que nao possui aluno com o CPF informado */
    }
}

/*
	A funcao mostrarAlunosCadastrados(Lista Aluno) imprimi no terminal todos os alunos cadastrados no sistema.
	Parametro: cabeca a cabeca da lista encadeada
*/
void mostrarAlunosCadastrados(Aluno *cabeca){
    Aluno *aux;
    for(aux = cabeca->proximo; aux!=NULL; aux = aux->proximo){ /* enquanto nao percorrer toda a lista encadeada, faca: */
        printf("Nome: %s\n", aux->nome);
        printf("Idade: %d\n", aux->idade);
        printf("CPF: %s\n", aux->cpf);
        printf("Score: %d\n\n", aux->score);
    }
}

/*
	A funcao liberarMemoriaLista(Aluno) libera todas as memorias alocadas para
	os elementos da Lista Encadeada.
	Parametro: cabeca a cabeca da lista encadeada
*/
void liberarMemoriaLista(Aluno *cabeca){
    Aluno *noAtual;
    noAtual = cabeca;
    while (noAtual != NULL){ /* Enquanto noAtual for diferente de nulo, faca: */
        cabeca = noAtual->proximo;
        free(noAtual);
        noAtual = cabeca;
    }
} /* Fim da funcao liberarMemoriaLista(Aluno) */

/*
	A funcao localizarPosicaoAluno(Lista Aluno, char[]) recebe como argumento a lista
	encadeada e um CPF e informa, no terminal, a posicao do aluno na lista.
	Parametro: cabeca a cabeca da lista encadeada
	Parametro: cpf o CPF do aluno
*/
void localizarPosicaoAluno(Aluno *cabeca, char cpf[]){
    Aluno *aux;
    int contador = 0;

    for(aux = cabeca->proximo; aux!=NULL; aux = aux->proximo){ /* enquanto nao encontrar o aluno, faca */
        contador ++; /* incrementa o contador */
        if(aux!=NULL){
            if(strcmp(aux->cpf,cpf)==0){ /* se encontrar o aluno */
                break; /* sai do for */
            }
        }
    }

    if(aux!=NULL){ /* se encontrar o aluno */
        printf("\nPosicao do aluno %s: %d\n", aux->nome, contador); /* informa a posicao do aluno encontrado */
    }
    else{/*senao, faca: */
        printf("\nNao existe aluno cadastrado no sistema com o CPF informado.\n"); /* percorreu toda a lista, mas nao encontrou o aluno */
    }
}

/*
	A funcao atualizarScoreAluno(Lista Aluno, char[], int) recebe como argumentos
	a lista encadeada, um CPF e um score e atualiza o score do aluno no sistema.
	Parametro: cabeca a cabeca da lista encadeada
	Parametro: cpf o CPF do aluno
	Parametro: score o novo score do aluno
*/
void atualizarScoreAluno(Aluno *cabeca, char cpf[], int score){
    Aluno *aux;
    for(aux=cabeca->proximo; aux!=NULL; aux = aux->proximo){ /* enquanto nao percorrer toda a lista encadeada, faca: */
        if(strcmp(aux->cpf,cpf)==0){ /* se achar o aluno */
            aux->score = score; /* atualiza o score do aluno */
            printf("\nScore do aluno %s atualizado com sucesso!\n\n", aux->nome);
            break; /* sai do for, para evitar execucao de instrucoes desnecessarias */
        }
    }
}

/* protótipos de funcao */
Aluno *  sortedMerge(Aluno *a, Aluno *b);
void dividir(Aluno *  fonte, Aluno** frenteRef, Aluno** trasRef);

/* A funcao mergeSort(Aluno) classifica a lista encadeada em ordem decrescente de score,
   movendo os ponteiros que armazenam struct de Aluno.
   Parametro cabecaRef a cabeca da lista encadeada
 */
void mergeSort(Aluno** cabecaRef){
    Aluno *  cabeca = *cabecaRef;
    Aluno *  a;
    Aluno *  b;

    if ((cabeca == NULL) || (cabeca->proximo == NULL)) { /* se a lista encadeada estiver vazia */
        return;
    }

    /* Divide a lista encadeada em duas sublistas 'a' e 'b' */
    dividir(cabeca, &a, &b);

    /* dividir para conquistar, através de chamadas recursivas passamos as novas sublistas */
    mergeSort(&a);
    mergeSort(&b);

    /* uni as duas listas encadeadas */
    *cabecaRef = sortedMerge(a, b);
}

Aluno *  sortedMerge(Aluno *a, Aluno *b){
    Aluno *  resultado = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->score > b->score) {
        resultado = a;
        resultado->proximo = sortedMerge(a->proximo, b);
    }
    else {
        resultado = b;
        resultado->proximo = sortedMerge(a, b->proximo);
    }
    return (resultado);
}

/* 
	Esta funcao divide os nós da lista dada em metades frontal e traseira.
    Se o comprimento for ímpar, o nó extra deve ir para a lista da frente.
    Usa a estratégia de ponteiro rapido/devagar.

*/
void dividir(Aluno *fonte, Aluno** frenteRef, Aluno** trasRef){
    Aluno *  rapido;
    Aluno *  devagar;
    devagar = fonte;
    rapido = fonte->proximo;

    /* Avance 'rapido' dois nós, e avance 'devagar' um nó */
    while (rapido != NULL) {
        rapido = rapido->proximo;
        if (rapido != NULL) {
            devagar = devagar->proximo;
            rapido = rapido->proximo;
        }
    }

    /* 'devagar' está antes do ponto médio da lista, então divida-o em dois nesse ponto.*/
    *frenteRef = fonte;
    *trasRef = devagar->proximo;
    devagar->proximo = NULL;
}

/*
	A funcao preencherListaComArquivo(Lista Aluno) recebe como argumento a 
	lista encadeada e preenche essa lista com os dados dos alunos, escritos
	no arquivo alunos.txt
	
	Parametro: cabeca a cabeca da lista encadeada
	Retorno true se o arquivo existir, false caso contrario
*/
boolean preencherListaComArquivo(Aluno *cabeca){
    FILE *arquivo = fopen("alunos.txt","r"); /* cria um apontador do tipo arquivo e abre o arquivo para leitura */
    /* campos auxiliares: */
	char nome[50];
    int idade;
    char cpf[12];
    int score;
	
    if(arquivo==NULL){ /* se nao for possivel abrir o arquivo */
        return false; /* retorna false */
    }
    else{ /* senao */
        while((fscanf(arquivo,"%[^|]|%d|%[^|]|%d\n", &nome,&idade,&cpf,&score))!=EOF){ /* enquanto nao percorrer todas as linhas do arquivo, faca:*/
            if(cabeca->proximo==NULL){ /* se a lista estiver vazia, faca: */
                Aluno * novoAluno;
                novoAluno = malloc (sizeof (Aluno));
				
				/* copia os campos obtidos, da linha do arquivo, para seus correspondentes, na struct novoAluno */
                strcpy(novoAluno->nome,nome);
                novoAluno->idade = idade;
                strcpy(novoAluno->cpf,cpf);
                novoAluno->score = score; 
                novoAluno->proximo = NULL;   /* a primeira struct inserida sempre sera, tambem, a ultima da lista */
                cabeca->proximo = novoAluno; /* a cabeca passa a apontar para o primeiro elemento inserido na lista */
            }
            else{ /* senao */
                Aluno * novoAluno;
                novoAluno = malloc (sizeof (Aluno));

                strcpy(novoAluno->nome,nome);
                novoAluno->idade = idade;
                strcpy(novoAluno->cpf,cpf);
                novoAluno->score = score;
                novoAluno->proximo = cabeca->proximo; /* inseri o elemento no inicio da lista encadeada */
                cabeca->proximo = novoAluno; /* atualiza o elemento que a cabeca aponta */
                mergeSort(&cabeca); /* ordena a lista encadeada na insercao */
            }
        }
    }
    fclose(arquivo); /* fecha o arquivo */
    return true; /* retorna true */
}

/*
	A funcao escreverNoArquivo(Lista Aluno) recebe como argumento a lista 
	encadeada e escreve em um arquivo todos os alunos cadastrados no sistema.
*/
void escreverNoArquivo(Aluno *cabeca){
    FILE *arquivo = fopen("alunos.txt","w"); /* cria um apontador do tipo arquivo e abre um arquivo para escrita (se o arquivo nao existir, ele sera criado)*/
    Aluno *aux; /* campo auxiliar */

    for(aux = cabeca->proximo; aux!=NULL; aux = aux->proximo){ /* enquanto nao percorrer toda a lista encadeada, faca: */
        fprintf(arquivo, "%s|%d|%s|%d\n", aux->nome,aux->idade,aux->cpf,aux->score); /* escreve os dados do aluno atual na linha do arquivo */
    }
    fclose(arquivo); /* fecha o arquivo */
}

/*
	A funcao main permite a execucao desse programa e representam
	um sistema de cadastro de alunos, rankeados por score, de forma 
	decrescente.
*/
int main(){
    
	Aluno *cabeca;								/* a cabeca da lita encadeada */
    cabeca = (Aluno *) malloc (sizeof (Aluno)); /* aloca memoria para a cabeca */
    
	/* camos auxiliares*/
	char cpf[12];
    int score;

    /* Verifica se conseguiu alocar */
	if (!cabeca) {
		printf("Nao conseguiu alocar a memoria.\n");
		exit(1);
	}

    cabeca->proximo = NULL; /* a cabeca da lista encadeada comeca apontando para NULL */

    if(preencherListaComArquivo(&(*cabeca))==false){ /* se o arquivo alunos.txt nao existir */
        printf("*******************************************************************\n");
        printf("-------------------------------------------------------------------\n\n");
        printf("Erro, nao foi possivel abrir o arquivo\n\n");
        printf("-------------------------------------------------------------------\n");
        printf("*******************************************************************\n");
        system("pause");
        system("cls");
    }

    int opcao; /* Armazena a opcao escolhida pelo usuario */

    do{ /* faca: */
        /*
			O menu da aplicacao solicita ao usuario que escolha uma opcao e chama funcoes
			correspondentes de acordo com a escolha do usuario.
        */
        printf("\n********************** Cadastro de Alunos *************************\n");
        printf("***************************** Menu ********************************\n\n");
        printf("Escolha uma das seguintes opcoes: \n\n");
        printf("1 - Incluir novo aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Atualizar score do aluno\n");
        printf("4 - Localizar posicao do aluno\n");
        printf("5 - Mostrar alunos cadastrados\n");
        printf("6 - Sair\n\n");
        printf("Digite sua escolha: ");
        scanf("%i",&opcao);
        fflush(stdin);

        switch(opcao){ /* caso, opcao seja: */
            case 1: /* cadastrar aluno */
                system("cls");
                printf("\n************************** Cadastrar Aluno ************************\n");
                printf("-------------------------------------------------------------------\n\n");

                if(incluirNovoAluno(&(*cabeca))==true){ /* se o aluno nao estiver cadastrado no sistema, faz o cadastro */
                    printf("-------------------------------------------------------------------\n");
                    printf("                  Aluno cadastrado com sucesso!                    \n");
                }
                else{ /* senao, informa que o aluno ja esta cadastrado no sistema */
                    printf("-------------------------------------------------------------------\n");
                    printf("Nao foi possivel realizar o cadastro, CPF ja cadastrado no sistema.\n");
                }

                printf("-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");

                system("pause");
                system("cls");
                break;
            case 2: /* remover aluno */
                system("cls");
                printf("\n*************************** Remover Aluno *************************\n");
                printf("-------------------------------------------------------------------\n\n");

                if(cabeca->proximo==NULL){ /* se a lista estiver vazia, nao sera possivel remover */
                    printf("Nao eh possivel remover, lista vazia.\n");
                }
                else{ /* senao, obtem o cpf e chama a funcao de remocao */
                    printf("Informe o cpf do aluno a ser removido: ");
                    gets(cpf);
                    fflush(stdin);
                    removerAluno(&(*cabeca),cpf);
                }

                printf("\n-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                system("pause");
                system("cls");
                break;
            case 3: /* atualizar score */
                system("cls");
                printf("\n************************ Atualizar Score Aluno ********************\n");
                printf("-------------------------------------------------------------------\n\n");

                if(cabeca->proximo==NULL){ /* se a lista estiver vazia, nao sera possivel atualizar o score */
                    printf("Nao eh possivel atualizar, lista vazia.\n\n");
                }
                else{ /* senao */
                    printf("Informe o cpf do aluno: ");
                    gets(cpf);
                    fflush(stdin);
                    if(verificaCpf(&(*cabeca),cpf)==true){ /* se o aluno informado estiver cadastrado no sistema */
                        printf("Informe o novo Score do aluno: "); /* solicita o novo score */
                        scanf("%d",&score);
                        fflush(stdin);
                        atualizarScoreAluno(&(*cabeca),cpf,score); /* chama a funcao para atualizacao do score */
                        mergeSort(&cabeca);
                    }
                    else{ /* senao, informa o CPF informado nao esta cadastrado no sistema */
                        printf("\nNao eh possivel atualizar, CPF informado nao esta cadastrado no sistema.\n\n");
                    }
                }

                printf("-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                system("pause");
                system("cls");
                break;
            case 4: /* informar posicao do aluno */
                system("cls");
                printf("\n*************************** Posicao Aluno *************************\n");
                printf("-------------------------------------------------------------------\n\n");

                if(cabeca->proximo==NULL){ /* se a lista estiver vazia, informa que nao eh possivel localizar */
                    printf("Nao eh possivel localizar, lista vazia.\n");
                }
                else{ /* senao, solicita o cpf e, se esse estiver cadastrado no sistema, informa a localizacao do aluno na lista encadeada */
                    printf("Informe o cpf do aluno: ");
                    gets(cpf);
                    fflush(stdin);

                    localizarPosicaoAluno(&(*cabeca),cpf);
                }
                printf("\n-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                system("pause");
                system("cls");
                break;
            case 5: /* imprimir alunos cadastrados */
                system("cls");
                printf("\n************************ Alunos Cadastrados ***********************\n");
                printf("-------------------------------------------------------------------\n\n");
                if(cabeca->proximo==NULL){ /* se a lista estiver vazia */
                    printf("Lista vazia, nao ha alunos cadastrados.\n\n");
                }
                else{ /* senao */
                    mostrarAlunosCadastrados(&(*cabeca)); /* imprime os alunos cadastrados no sistema */
                }
                printf("-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                system("pause");
                system("cls");
                break;
            case 6: /* escolher sair da aplicacao */
                break;
            default: /* escolher uma opcao invalida */
                system("cls");
                printf("*******************************************************************\n");
                printf("-------------------------------------------------------------------\n\n");
                printf("Opcao invalida. Por favor, insira uma opcao valida.\n\n");
                printf("-------------------------------------------------------------------\n");
                printf("*******************************************************************\n");
                system("pause");
                system("cls");
        }
    }while(opcao!=6); /* enquanto o usuario nao escolher sair da aplicacao */

    escreverNoArquivo(&(*cabeca));  /* escreve no arquivo alunos.txt os alunos cadastrados no sistema */
    liberarMemoriaLista(&(*cabeca));/* desaloca a memoria de todos os elementos da lista encadeada */

    printf("\n*******************************************************************\n");
    printf("*********************** Programa Encerrado ************************\n");
    printf("*******************************************************************\n\n");
    system("pause");
    return 0;
}
