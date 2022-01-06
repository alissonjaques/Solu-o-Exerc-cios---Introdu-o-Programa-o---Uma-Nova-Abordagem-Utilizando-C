/*
    Descricao:

	Escreva um algoritmo em C seguindo os principios de Lista encadeada
	visto em aula permitindo ao usuario realizar as seguintes funcoes:
	1 - Cadastrar Clientes
	2 - Importar Vendas
	3 - Listar Clientes

	O cadastro de cliente deve ter no minimo os seguintes dados:
	int codigo;
	char nome[50];
	int score;

	A opcao de numero 1 permitira ao usuário informar os dados do cliente o
	Score nao deve ser informado pois ao cadastrar o cliente o valor do score e
	0. A opcao de numero 2 permitira importar um arquivo que deve extar na
	pasta da aplicacao com o nome de Vendas.txt. O arquivo a ser lido segue o
	seguinte formato Codigo cliente + '|' + Valor da Venda conforme pode ser
	visto abaixo.

	100|100,00
	101|200,00
	100|150,00
	3000|1000,00

	Ao ler as vendas e necessario atualizar o score do cliente, a regra para
	atualizacao e de 1 % do valor da venda sempre arredondado para cima. De
	acordo com exemplo anterior o Cliente 100 teria o score de 3, o cliente 101
	de 2 e o cliente 3000 de 10. O arredondamento deve ser feito para cada venda.
	Uma exigencia do algoritmo e que a lista seja ordenada decrescente pelo
	score, logo toda vez que um cliente tiver seu score alterado sera necessario
	reordena-lo na lista. A opcao 3 sera somente mostrar a lista que ja estara
	ordenada decrescente pelo score de cada cliente.

    Autor: Alisson Jaques

*/

#include<stdio.h>  /* Biblioteca para entrada e saida de dados */
#include<stdlib.h> /* Biblioteca para manipulacao de constantes */
#include<string.h> /* Biblioteca para manipulacao de strings */

#define MAX 30  /* capacidade maxima de caracteres, em uma linha, no arquivo vendas.txt */
#define TCOD 7  /* capacidade de representar 999999 clientes nas vendas */
#define TVAL 11 /* capacidade de representar uma venda de ate 1 milhao de reais */

/*
    Criacao do tipo de dados Cliente, que possui campos para representar um cliente qualquer
    e um endereco para o proximo cliente da lista encadeada.
*/
typedef struct clientes{
    int codigo;    /* O codigo do cliente */
    char nome[50]; /* O nome do cliente */
    int score;     /* O score do cliente */
    struct clientes * proximo; /* O endereco de memoria do proximo cliente da lista encadeada */
}Cliente;

/*
	A funcao cadastrarCliente(Cliente) recebe como argumento uma lista encadeada (o endereco de memoria da cabeca da lista)
	e possibilita o cadastro e o armazenamento de um novo cliente no sistema.
*/
void cadastrarCliente(Cliente *celula){
    if(celula->proximo==NULL){ /* se a lista estiver vazia, faca: */
        Cliente *novaCelula;                    /* declara um apontador do tipo Cliente */
        novaCelula = malloc (sizeof (Cliente)); /* aloca memoria para o novo cliente */

		/*
			Campos auxiliares
		*/
        int codigo;
        char nome[50];
        int score = 0; /* Por default, o campo score e inicializado com zero */

		/*
			Solicita os dados do cliente e inicializa as variaveis auxiliares com os mesmos.
			Por fim, as variaveis auxiliares preenchidas sao copiadas para os campos da estrutura
			e esta e adicionada a lista encadeada.
		*/
        printf("\n======================= Cadastro de Cliente =======================\n\n");
        printf("Informe o codigo do cliente: ");
        scanf("%d",&codigo);
        fflush(stdin);
        printf("Informe o nome do cliente: ");
        gets(nome);
        fflush(stdin);
        printf("\n");
        novaCelula->codigo = codigo;
        strcpy(novaCelula->nome,nome);
        novaCelula->score = score;
        novaCelula->proximo = NULL;
        celula->proximo = novaCelula;
        printf("-------------------------------------------------------------------\n");
        printf("----------------- Cliente Cadastrado com Sucesso! -----------------\n");
        printf("-------------------------------------------------------------------\n\n");
    }
    else{ /* senao, faca: */
		/* Variaveis auxiliares */
        int codigo;
        int botao = 1;

		/* Solicita o codigo do cliente e o armazena na varial auxiliar correspondente */
        printf("\n======================= Cadastro de Cliente =======================\n\n");
        printf("Informe o codigo do cliente: ");
        scanf("%d",&codigo);
        fflush(stdin);

		/*
			Verifica se ja existe um cliente com o mesmo codigo, cadastrado no sistema.
			Se existir, a variavel botao e acionada.
		*/
        Cliente *p;
        for (p = celula->proximo; p != NULL; p = p->proximo){
            if(codigo==p->codigo){
                botao = 0;
            }
        }

        if(botao==1){ /* Se nao existir cliente com o codigo informado, faca: */
            /*
				Campos auxiliares
			*/
			Cliente *novaCelula;
            novaCelula = malloc (sizeof (Cliente));
            char nome[50];
            int score = 0; /* Por default, o campo score e inicializado com zero */

			/*
				Solicita os dados do cliente e inicializa as variaveis auxiliares com os mesmos.
				Por fim, as variaveis auxiliares preenchidas sao copiadas para os campos da estrutura
				e esta e adicionada a lista encadeada.
			*/
            printf("Informe o nome do cliente: ");
            gets(nome);
            fflush(stdin);
            printf("\n");
            novaCelula->codigo = codigo;
            strcpy(novaCelula->nome,nome);
            novaCelula->score = score;
            novaCelula->proximo = celula->proximo;
            celula->proximo = novaCelula;
            printf("-------------------------------------------------------------------\n");
            printf("----------------- Cliente Cadastrado com Sucesso! -----------------\n");
            printf("-------------------------------------------------------------------\n\n");
        }
        else{ /* Senao, informa que ja existe cliente cadastrado no sistema, com o mesmo codigo. */
            printf("\n-------------------------------------------------------------------\n");
            printf("Cadastro nao realizado. Ja existe um cliente cadastrado com esse codigo.\n");
            printf("-------------------------------------------------------------------\n\n");
        } /* Fim-se */
    } /*Fim-se*/
} /* Fim da funcao cadastrarCliente(Cliente) */

/*
	A funcao cocatenarLetra(char[],char) recebe como parametro uma string e um caractere
	e concateca o caractere no final da string (o nome string esta representando um vetor de
	carecteres mesmo).
*/
void concatenarLetra(char cod[], char letra){
    int tamanho = strlen(cod); /* armazena o tamanho do vetor de caracteres */
    cod[tamanho] = letra;      /* inseri o caractere, passado como argumento, no final do vetor */
    cod[tamanho + 1] = '\0';   /* recoloca o terminador */
} /* Fim da funcao concatenarLetra(char[],char) */

/*
	A funcao retornaValor(char[]) recebe como argumento um texto que representa um numero real e
	retorna um numero flutuante equivalente ao conteudo do texto.
*/
float retornaValor(char val[]){
    float valorInteiro = atoi(val); /* armazena a parte inteira do numero */
    float valorDecimal;             /* variavel para armazenar a parte decimal do numero */
    float valor;                    /* variavel que representa o numero equivalente ao texto */
    char decimal[3];                /* variavel texto que representa duas casas decimais e o \0 */
    int i, indice=0;                /* variaveis de controle */
    int botao = 1;                  /* botao controlador */

    for(i=0; i<strlen(val); i++){ /* enquanto nao percorrer toda a string passada como argumento, faca:*/
        if(val[i]==','){ /* se encontrar ',' faca: */
            botao = 0;   /* aciona o botao */
        }
        else if(botao==0){ /* se o botao estiver acionado, faca: */
            decimal[indice] = val[i]; /* preenche o vetor decimal com o valor atual de val[i] */
            indice++; /* incrementa o indice em uma unidade */
        }
    }

    valorDecimal = atoi(decimal);       /* converte o conteudo de texto em seu valor literal numerico */
    valorDecimal = valorDecimal/100;    /* para obter a parte decimal e preciso dividir o valor encontrado por 100 */
    valor = valorInteiro + valorDecimal;/* o numero convertido completo, com a parte inteira e decimal */

    return valor; /* retorna o numero flututante equivalente ao texto */
} /* Fim da funcao retornaValor(char[]) */

/*
	A funcao calculaScore recebe como argumento o valor da venda e calcula o score correspondente, o retornando.
	O score e proporcional a 1% do valor da venda e sempre arredondado para cima (caso ocorra um valor
	fracionario).
*/
int calculaScore(float valor){

	int score;                          /* o score*/
    float numeroReal = 0.01*valor;      /* 1% do valor da venda */
    int numeroInteiro = (int)numeroReal;/* parte inteira do 1% do valor da venda */

    if(numeroReal>numeroInteiro){ /* Se 1% do valor da venda for maior que sua parte inteira */
        score = numeroInteiro+1; /* entao o score sera arredondado para cima */
    }
    else{ /* Senao: */
        score = numeroInteiro; /* o score nao sera arredondado para cima */
    }

    return score; /* retorna o score calculado */
} /*Fim da funcao calculaScore */

/*
	A funcao importarVendas(Cliente,int) le um arquivo de vendas, no formato txt, atualiza o score dos clientes,
	com os dados deste arquivo, e ordena a lista encadeada em ordem decrescente de score.
*/
void importarVendas(Cliente *cabeca,int controlador){
    if(cabeca==NULL){ /*Se a cabeca da lista ser nula, faca: */
        printf("\nNao foi possivel importar as vendas, pois nao ha clientes cadastrados.\n");
    }
    else if(cabeca->proximo==NULL){ /*Se a lista estiver vazia, faca: */
        printf("\nNao foi possivel importar as vendas, pois nao ha clientes cadastrados.\n");
    }
    else{ /* Senao, faca: */

		FILE *vendas;    /* apontador para o arquivo de vendas */
        char linha[MAX]; /* um vetor de caracteres que armazenara o conteudo de uma linha do arquivo */
        char *resultado; /* apontador para uma linha do arquivo */
        int botao = 1;   /* botao de controle */

        int codigo;      /* o codigo do cliente */
        char cod[TCOD];  /* o codigo do cliente na linha do arquivo */

        float valor;     /* o valor da venda */
        char val[TVAL];  /* o valor da venda na linha do arquivo */

		/*
			Esse laco permite que o usuario possa cadastrar clientes (que possuam codigo no arquivo vendas)
			depois de importar as vendas, sem impactar nos dados de score dos clientes cadastrados anteriormente.
		*/
        Cliente *p;
        for (p = cabeca->proximo; p != NULL; p = p->proximo){
            p->score = 0;
        }

        /* Abre um arquivo de texto para leitura */
        vendas = fopen("vendas.txt", "r");

        if (vendas == NULL){ /* Se ocorrer um erro na abertura */
            printf("Ocorreu um erro ao abrir o arquivo.\n");
            return;
        }

        while (!feof(vendas)){ /* enquanto nao percorrer todas as linhas do arquivo, faca :*/
            /* Le uma linha (inclusive com o '\n') */
            resultado = fgets(linha, MAX, vendas);  /* O 'fgets' le ate 29 caracteres ou ate o '\n' */
            /*
				Variaveis auxiliares
			*/
			int indice = 0;
            int j;

			int score; /* o score da venda */

			/* Limpa as os dados dos vetores de caracteres cod e val, a cada ciclo */
            strcpy(cod, "");
            strcpy(val, "");

            if (resultado){ /* se foi possível ler */
                for(j = 0; j<strlen(linha); j++){ /* Enquanto nao percorrer toda a linha do arquivo, faca: */
                    if(botao==1){ /*Se o botao nao foi acionado, faca: */
                        if(linha[j]!='|'){ /*Se o simbolo atual nao for '|', faca: */
                            concatenarLetra(&(*cod),linha[j]); /* concatena o caracter do arquivo no vetor cod*/
                        }
                        else{ /*senao (o simbolo atual e '|'), faca:*/
                            botao = 0;  /* aciona o botao */
                            indice = 0; /* zera o indice */
                        }
                    }
                    else{ /*Senao (o botao foi acionado), faca: */
                        concatenarLetra(&(*val),linha[j]); /* concatena o caracter do arquivo no vetor cod*/
                        if(linha[j]=='\n'){ /* se o simbolo atual da linha for o ultimo (\n), faca: */
                            botao = 1;  /* desaciona o botao */
                            indice = 0; /* zera o indice */
                        }
                    } /* Fim-se */
                } /* Fim for */
            } /* Fim-se */

            codigo = atoi(cod);            /* obtem o valor do codigo com a funcao atoi(char[]) */
            valor = retornaValor(&(*val)); /* obtem o valor da venda com a funcao atoi(char[]) */
            score = calculaScore(valor);   /* obtem o valor do score com a funcao calculaScore(char[]) */

			/*
				Esse laco atualiza o valor do score para o cliente cadastrado no sistema, de acordo com o arquivo
				vendas.txt
			*/
            Cliente *p;
            for (p = cabeca->proximo; p != NULL; p = p->proximo){
                if(codigo==p->codigo){
                    p->score += score;
                }
            }

			/*
				Este for aninhado e responsavel por ordenar a lista encadeada de forma decrescente,
				de acordo com o valor do score do cliente cadastrado.
			*/
            Cliente *k; /* Campo auxiliar */
            Cliente *l; /* Campo auxiliar */
            for (k = cabeca->proximo; k != NULL; k = k->proximo){ /* enquanto nao percorrer toda a lista encadeada, faca: */
                for (l = k; l != NULL; l = l->proximo){ /* enquanto nao percorrer toda a lista encadeada, a partir do elemento do for anterior, faca:*/
                    if(k->score < l->score){ /* se o escore do objeto anterior for menor que o atual, faca:*/
                       /*
						Campos auxilares que guardam os dados do objeto sendo comparado
					   */
					   int codigoTemp = k->codigo;
                       char nomeTemp[50];
                       strcpy(nomeTemp,k->nome);
                       int scoreTemp = k->score;

					   /*
					    Atualiza os dados do objeto com menor score
					   */
                       k->codigo = l->codigo;
                       strcpy(k->nome,l->nome);
                       k->score = l->score;

					   /*
						Atualiza os dados do objeto com maior score
					   */
                       l->codigo = codigoTemp;
                       strcpy(l->nome,nomeTemp);
                       l->score = scoreTemp;
                    } /* Fim-se*/
                } /* Fim for */
            } /* Fim for */
        } /*Fim while*/

        fclose(vendas); /* Desaloca a memoria do arquivo vendas.txt */

        if(controlador){ /* Se o usuario clicar em importar vendas, faca: */
            printf("\n-------------------------------------------------------------------\n");
            printf("------------------ Vendas Importadas com Sucesso! -----------------\n");
            printf("-------------------------------------------------------------------\n");
        }
    }
    printf("\n"); /* Quebra de linha para organizacao dos dados no terminal */
} /*Fim da funcao importarVendas(Cliente,int) */

/*
	A funcao liberarMemoriaLista(Cliente) libera todas as memorias alocadas para
	os elementos da lista encadeada.
*/
void liberarMemoriaLista(Cliente *cabeca){
    Cliente *noAtual;
    noAtual = cabeca;
    while (noAtual != NULL){ /* Enquanto noAtual for diferente de nulo, faca: */
        cabeca = noAtual->proximo;
        free(noAtual);
        noAtual = cabeca;
    }
} /* Fim da funcao liberarMemoriaLista(Cliente) */

/*
	A funcao listarClientes(Cliente) imprime no terminal todos os clientes cadastrados no sistema.
*/
void listarClientes(Cliente *cabeca){
    printf("\n================= Lista de Clientes Cadastrados ===================\n");

    if(cabeca==NULL){ /* Se a cabeca da lista for nula, faca: */
        printf("\nNenhum cliente cadastrado.\n");
    }
    else{ /* Senao, faca: */
        if(cabeca->proximo==NULL){ /* Se a lista estiver vazia, faca: */
            printf("\nNenhum cliente cadastrado.\n");
        }
        else{ /* Senao, faca: */
			/*
				Este for imprimi todos os clientes cadastrados no sistema.
			*/
            Cliente *p;
            for (p = cabeca->proximo; p != NULL; p = p->proximo){
                printf("\n-------------------------------------------------------------------\n");
                printf("\nCodigo do cliente: %d\n", p->codigo);
                printf("Nome do cliente: %s\n", p->nome);
                printf("Score do cliente: %d\n", p->score);
            }
            printf("\n-------------------------------------------------------------------\n");
        }
    }
    printf("\n===================================================================\n");
} /* Fim da funcao listarClientes(Cliente) */

/*
	A funcao main() permite a execucao deste programa, ela representa uma aplicacao que possibilita
	o cadastro, importacao de arquivos e listagem de clientes de acordo com o score.
*/
int main(){

    Cliente *cabeca; 								/* A cabeca da lista encadeada */
    cabeca = (Cliente *) malloc (sizeof (Cliente)); /* Aloca memoria para a cabeca da lista encadeada */
    int botao = 1;							        /* Botao controlador */

    /* Verifica se conseguiu alocar */
	if (!cabeca) {
		printf("Nao conseguiu alocar a memoria.\n");
		exit(1);
	}

    cabeca->proximo = NULL; /* a cabeca da lista encadeada comeca apontando para NULL */

    int opcao; /* Armazena a opcao escolhida pelo usuario */

    do{ /*faca: */

		   /*
			O menu da aplicacao solicita ao usuario que escolha uma opcao e chama funcoes
			correspondentes de acordo com a escolha do usuario.
		   */
           printf("\n====================== Digitador de Texto =======================\n");
           printf("============================= Menu ================================\n\n");
           printf("Escolha uma das seguintes opcoes: \n\n");
           printf("1 - Incluir uma nova linha de texto\n");
           printf("2 - Importar Vendas\n");
           printf("3 - Listar Clientes\n");
           printf("4 - Sair\n\n");
           printf("Digite sua escolha: ");
           scanf("%i",&opcao);
           fflush(stdin);

           switch(opcao){ /*Caso opcao seja: */
               case 1: /* Cadastrar cliente, faca: */
                   if(botao==1){
                        cadastrarCliente(&(*cabeca));
                        botao = 0;
                   }
                   else{
                        cadastrarCliente(&(*cabeca));
                        importarVendas(&(*cabeca),botao);
                   }
                   system("pause");
                   system("cls");
                   break;
               case 2: /* Importar vendas, faca: */
                   importarVendas(&(*cabeca),1);
                   system("pause");
                   system("cls");
                   break;
               case 3: /* Listar Clientes, faca: */
                   listarClientes(&(*cabeca));
                   system("pause");
                   system("cls");
                   break;
               case 4: /* Sair da aplicacao, faca: */
                   break;
               default:
                   printf("\nOpcao invalida. Por favor, insira uma opcao valida.\n");
                   system("pause");
                   system("cls");
                   break;
           }
    }while(opcao!=4); /* Enquanto o usuario nao escolher sair da aplicacao */

    liberarMemoriaLista(&(*cabeca)); /* Libera a memoria para todos os elementos da lista encadeada */

    printf("\n===================================================================\n");
    printf("======================= Programa Encerrado ========================\n");
    printf("===================================================================\n\n");
    system("pause");
    return 0;
} /* Fim da funcao main() */
