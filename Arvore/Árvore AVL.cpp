/*
	Programa de computador que gerencia árvores AVL. 
	Ele permite inserção, remoção, consulta e listagem dos elementos
	da árvore.
	Autor: Alisson Jaques
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct aux {
	TIPOCHAVE chave;
	struct aux *esq;
	struct aux *dir;
	int fatBal; // fator de fatBalanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NO, *Arvore;

/* 
	Cria um novo nodo (aloca memoria e preenche chaves) nodo com chave=ch e retorna 
    seu endereco 
*/
Arvore criarNovoNo(TIPOCHAVE ch){
	Arvore novoNo = (Arvore)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = ch; // o valor da chave
	novoNo->fatBal = 0; // o valor do fator de balanceamento, 0 por default
	return novoNo;
}

// Retorna o maior chave entre dois inteiros
int max(int a, int b){
	if (a>b) return a;
	return b;
}

// Retorna a altura de uma (sub-)arvore
int altura(Arvore p){
	if (!p) return -1;
	else return 1 + max(altura(p->esq),altura(p->dir));
}

// Verifica se árvore é AVL
bool ehAVL(Arvore p){
	int e,d;
	bool ok = true;
	if(p){
		ok = ehAVL(p->esq);
		if(ok) ok = ehAVL(p->dir);
		if(ok){
			e = altura(p->esq);
			d = altura(p->dir);
			if(e-d > 1 || e-d < -1) ok = false;  
			else ok = true;
		}
	}
	return(ok);
}

// Verifica se árvore é AVL
bool ehAVL2(Arvore p, int* alt){
    if (!p){
       *alt=-1;
       return true;
    }
    bool res;
    int d, e;
    res = ehAVL2(p->dir,&d);
    if (!res) return false;
    res = ehAVL2(p->esq,&e);
    if (!res) return false;
    if (d-e != p->fatBal) printf("### O campo 'fatBal' do no '%i' esta com chave incorreto de fatBalanceamento. ###\n",p->chave);
    if ((d-e<-1) || (d-e>1)) return false;
	*alt = max(d,e)+1; 
	return true;	
}

// Atualiza o fator de balanceamento dos nodos
int atualizarfatBalanceamentoTotal(Arvore raiz){
	if (!raiz) return 0;
	int d = atualizarfatBalanceamentoTotal(raiz->dir);
	int e = atualizarfatBalanceamentoTotal(raiz->esq);
	raiz->fatBal = d-e;
	return max(d,e)+1;
}

/* 
   Rotações à direita (LL e LR) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p 
*/
Arvore rotacaoL(Arvore p){
	printf("Rotacao a esquerda, problema no nodo: %i\n",p->chave);
	Arvore u, v;
	u = p->esq;
	if(u->fatBal == -1) {   // LL
		p->esq = u->dir;
		u->dir = p;
		p->fatBal = 0;
		u->fatBal = 0;
		return u;
	} else if (u->fatBal == 1) {  // LR
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		p->esq = v->dir;
		v->dir = p;
		if(v->fatBal == -1) p->fatBal = 1;
		else p->fatBal = 0;
		if(v->fatBal == 1) u->fatBal = -1;
		else u->fatBal = 0;
		v->fatBal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->fatBal == 0)
		p->esq = u->dir;
		u->dir = p;
		// p->fatBal = -1;    desnecessario pois o fatBalanceamento de p nao chegou a ser mudado para -2
		u->fatBal = 1;
		return u;
	}
}

/* 
   Rotações à esquerda (RR e RL) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p 
*/
Arvore rotacaoR(Arvore p){
	printf("Rotacao a direita, problema no nodo: %i\n",p->chave);
	Arvore u, v;
	u = p->dir;
	if(u->fatBal == 1) {   // RR
		p->dir = u->esq;
		u->esq = p;
		p->fatBal = 0;
		u->fatBal = 0;
		return u;
	} else if (u->fatBal == -1){  // RL
		v = u->esq;
		u->esq = v->dir;
		v->dir = u;
		p->dir = v->esq;
		v->esq = p;
		if(v->fatBal == 1) p->fatBal = -1;
		else p->fatBal = 0;
		if(v->fatBal == -1) u->fatBal = 1;
		else u->fatBal = 0;
		v->fatBal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->fatBal == 0)
		p->dir = u->esq;
		u->esq = p;
		u->fatBal = -1;
		// p->fatBal = 1;    desnecessario pois o fatBalanceamento de p nao chegou a ser mudado para 2
		return u;	
	}
}

/* 
   Inserção AVL: p é inicializado com o endereco do nó raiz e 
   *alterou com false
*/
void inserirAVL(Arvore* pp, TIPOCHAVE ch, bool* alterou){
	Arvore p = *pp;
	if(!p){
		*pp = criarNovoNo(ch);
		*alterou = true;
	} else {
if(ch == p->chave) *alterou = false;
		else if(ch <= p->chave) {
			inserirAVL(&(p->esq), ch, alterou);
			if(*alterou)
				switch (p->fatBal) {
					case 1 : p->fatBal = 0;
					*alterou = false;
					break;
					case 0 : p->fatBal = -1;
					break;
					case -1: *pp = rotacaoL(p);
					*alterou = false;
					break;
				}
		} else {
			inserirAVL(&(p->dir), ch, alterou);
			if(*alterou)
				switch (p->fatBal) {
					case -1: p->fatBal = 0;
					*alterou = false;
					break;
					case 0 : p->fatBal = 1;
					break;
					case 1 : *pp = rotacaoR(p);
					*alterou = false;
					break;
				}
		}
	}
}

/* 
	Retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja
    encontrada. Utiliza busca binaria recursiva
*/
Arvore buscaBinaria(TIPOCHAVE ch, Arvore raiz){
	if (raiz == NULL) return NULL;
	if (raiz->chave == ch) return raiz;
	if (raiz->chave<ch) 
		return buscaBinaria(ch,raiz->dir);
	return buscaBinaria(ch,raiz->esq);
}  

/*
	Função que permite a consulta de elementos na árvore, o algoritmo é o mesmo
	para árvores binárias de busca.
*/
void consultaArvore(Arvore *raiz){
    if(raiz != NULL){
        int chave = 0;
        printf("Informe um chave: ");
        scanf("%i", &chave);
        if(raiz != NULL){
            struct aux* atual = *raiz;
            int alturainfo = 1;
            bool registroEncontrado = false;
            while(atual != NULL){
                if(chave == atual->chave){
                    printf("Resgistro encontrado no nivel %i\n", alturainfo);
                    registroEncontrado = true;
                    break;
                }               
                else if(chave >= atual->chave){
                    alturainfo = alturainfo + 1;
                    atual = atual->dir;
                }
                else{
                    alturainfo = alturainfo + 1;
                    atual = atual->esq;
                }
            }
            if(registroEncontrado == false){
                printf("Resgistro nao encontrado\n");
            }
        }
    }
}

// Busca binária não recursiva devolvendo o nó pai
Arvore buscaNo(Arvore raiz, TIPOCHAVE ch, Arvore *pai){
	Arvore atual = raiz;
	*pai = NULL;
	while (atual) {
		if(atual->chave == ch)
			return(atual);
		*pai = atual;
		if(ch < atual->chave) atual = atual->esq;
		else atual = atual->dir;
	}
	return(NULL);
}

/* 
   Auxiliar da funcao excluirChave, procura a maior chave menor que a chave que 
   serah excluida
*/
Arvore maiorAEsquerda(Arvore p, Arvore *ant){
  *ant = p;
  p = p->esq;
  while (p->dir) {
    *ant = p;
    p = p->dir;
  }
  return(p);
}

// Excluí a chave com chave igual a ch
bool excluirAVL(Arvore* raiz, TIPOCHAVE ch, bool* alterou){
  Arvore atual = *raiz;
  if (!atual) {
    *alterou = false;
    return false;
  }
  if (atual->chave == ch){
    Arvore substituto, pai_substituto;
    if(!atual->esq || !atual->dir) { // tem zero ou um filho
      if(atual->esq) substituto = atual->esq;
      else substituto = atual->dir;
      *raiz = substituto;
      free(atual);
      *alterou = true;
      return true;
    }
    else {   // tem dois filhos
      substituto = maiorAEsquerda(atual,&pai_substituto);
      atual->chave = substituto->chave;
      ch = substituto->chave; // continua o codigo excluindo o substituto
    }
  }
  bool res;
  if (ch > atual->chave) {
    res = excluirAVL(&(atual->dir), ch, alterou);
    printf("Excluir recursivo a direita: %i(%i)\n", atual->chave, atual->fatBal); 
    if (*alterou){
       switch (atual->fatBal){
          case 1: atual->fatBal = 0;
          return true;
          case 0: atual->fatBal = -1;
          *alterou = false;
          return true;
          case -1: *raiz = rotacaoL(atual);
          if (atual->fatBal != 0) *alterou = false;
          return true;
       }
    }
  }else{
    res = excluirAVL(&(atual->esq), ch, alterou);
    printf("Excluir recursivo a esquerda: %i(%i)\n", atual->chave, atual->fatBal); 
    if (*alterou){
       switch (atual->fatBal){
          case -1: atual->fatBal = 0;
          return true;
          case 0: atual->fatBal = 1;
          *alterou = false;
          return true;
          case 1: *raiz = rotacaoR(atual);
          if (atual->fatBal != 0) *alterou = false;
          return true;
       }
    }
  }
  return res;
}

// Rotações à direita (LL e LR)
void rotacaoL2(Arvore *p){
	printf("Rotacao a esquerda, problema no nodo: %i\n",(*p)->chave);
	Arvore u, v;
	u = (*p)->esq;
	if(u->fatBal == -1) {   // LL
		(*p)->esq = u->dir;
		u->dir = *p;
		(*p)->fatBal = 0;
		*p = u;
	} else {  // LR
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		(*p)->esq = v->dir;
		v->dir = *p;
		if(v->fatBal == -1)(*p)->fatBal = 1;
		else (*p)->fatBal = 0;
		if(v->fatBal == 1) u->fatBal = -1;
		else u->fatBal = 0;
		*p = v;
	}
	(*p)->fatBal = 0; // fatBalanço final da raiz (p) da subarvore
}

// Rotações à esquerda (RR e RL)
void rotacaoR2(Arvore *p){
	printf("Rotacao a direita, problema no nodo: %i\n",(*p)->chave);
	Arvore u, v;
	u = (*p)->dir;
	if(u->fatBal == 1) {   // RR
		(*p)->dir = u->esq;
		u->esq = *p;
		(*p)->fatBal = 0;
		*p = u;
	} else {  // RL
		v = u->esq;
		u->esq = v->dir;
		v->dir = u;
		(*p)->dir = v->esq;
		v->esq = *p;
		if(v->fatBal == 1) (*p)->fatBal = -1;
		else (*p)->fatBal = 0;
		if(v->fatBal == -1) u->fatBal = 1;
		else u->fatBal = 0;
		*p = v;
	}
	(*p)->fatBal = 0; // fatBalanço final da raiz (p) da subarvore
}

// Inserção AVL2: p é inicializado com raiz e *alterou com false
void inserirAVL2(Arvore *pp, TIPOCHAVE ch, bool *alterou){
	Arvore p = *pp;
	if(!p){
		*pp = criarNovoNo(ch);
		*alterou = true;
	} else {
		if(ch < p->chave) {
            inserirAVL2(&(p->esq), ch, alterou);
			if(*alterou)
				switch (p->fatBal) {
					case 1 : p->fatBal = 0;
					*alterou = false;
					break;
					case 0 : p->fatBal = -1;
					break;
					case -1: rotacaoL2(pp);
					*alterou = false;
					break;
				}
		} else {
			inserirAVL2(&(p->dir), ch, alterou);
			if(*alterou)
				switch (p->fatBal) {
					case -1: p->fatBal = 0;
					*alterou = false;
					break;
					case 0 : p->fatBal = 1;
					break;
					case 1 : rotacaoR2(pp);
					*alterou = false;
					break;
				}
		}
	}
}

// Função auxiliar na destruição (liberacao da memoria) de uma arvore
void destruirAux(Arvore subRaiz){
	if (subRaiz){
		destruirAux(subRaiz->esq);
		destruirAux(subRaiz->dir);
		free(subRaiz);
	}
}

// libera toda memoria de uma arvore e coloca NULL no chave da raiz
void destruirArvore(Arvore * raiz){
	destruirAux(*raiz);
	*raiz = NULL;
}

// Cria uma árvore vazia e a retorna
Arvore* criarArvore(){
    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));
    if(raiz != NULL){
        *raiz = NULL;   
    }
    return raiz;
}

// Busca a chave ch na arvore
void travessiaAux(Arvore p, int *niv, TIPOCHAVE ch, bool *achou) {
	if(p) {
		(*niv)++;// *niv = *niv + 1;
		if(p->chave == ch) *achou = true;
		else {
			travessiaAux(p->esq, niv, ch, achou);
			if(!(*achou)) travessiaAux(p->dir, niv, ch, achou);
			if(!(*achou)) *niv = *niv - 1;
		}
	}
}

/* 
	Retorna true e o nivel de uma chave (caso seja encontrada) e false caso 
    contrario.
*/
bool travessia(Arvore p, int *niv, TIPOCHAVE ch) {
	*niv = 0;
	Arvore temp = buscaBinaria(ch,p);
	if (temp){
		bool achou = false;
		travessiaAux(p, niv, ch, &achou);
		return true;
	}
	else return false;
}

// Retorna a altura da árvore
int arvoreAltura(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {
        int alt_esq = arvoreAltura(&((*raiz)->esq));
        int alt_dir = arvoreAltura(&((*raiz)->dir));
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

/*
	Imprime os elementos da árvore usando o Pré-ordem;
*/
void mostrarPreOrdem(Arvore *raiz)
{
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {
        printf("Valor: %i \n", (*raiz)->chave);
        mostrarPreOrdem(&((*raiz)->esq));
        mostrarPreOrdem(&((*raiz)->dir));
    }
}

/*
	Imprime os elementos da árvore usando o In-Ordem;
*/
void mostrarInOrdem(Arvore *raiz)
{
   if (raiz != NULL && *raiz != NULL) 
   {
      mostrarInOrdem(&((*raiz)->esq));
      printf("Valor: %i\n", (*raiz)->chave);
      mostrarInOrdem(&((*raiz)->dir)); 
   }
}

/*
	Imprime os elementos da árvore usando o Pós-Ordem;
*/
void mostrarPosOrdem(Arvore *raiz){
    if(raiz != NULL && *raiz != NULL)
	{
        mostrarPosOrdem(&((*raiz)->esq));
        mostrarPosOrdem(&((*raiz)->dir));
        printf("Valor: %i\n", (*raiz)->chave);
    }
}

/* Exibe arvore Pre-Ordem indicando pai de cada no */
void exibirArvore2(Arvore raiz, TIPOCHAVE chavePai){
	if (raiz == NULL) return;
	printf("(%i,%i) ",chavePai,raiz->chave);
	exibirArvore2(raiz->esq,raiz->chave);
	exibirArvore2(raiz->dir,raiz->chave);
}

// A função main não recebe argumentos e permite a execução do programa
int main()
{   
    bool sair = false;
	bool alterou = false;
    int opcao = 0;
    Arvore *raiz = criarArvore();
    int altura = 0;
	TIPOCHAVE ch;
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
        printf("8 - Sair\n\n");
        printf("Digite aqui sua escolha: ");
        scanf("%i", &opcao); 
        fflush(stdin);  
        switch(opcao)
        {
            case 1:
				printf("Informe o valor da chave: ");
				scanf("%d", &ch);
                inserirAVL(raiz,ch,&alterou);
                break;
            case 2:
                printf("Informe o valor da chave: ");
				scanf("%d", &ch);
                excluirAVL(raiz,ch,&alterou);
                break;
            case 3:
            	if(*raiz==NULL){
					printf("\nNao eh possivel listar, arvore vazia.\n\n");
				} else{
					mostrarPreOrdem(raiz); 
                }
                system("PAUSE");
                break;
            case 4:
            	if(*raiz==NULL){
					printf("\nNao eh possivel listar, arvore vazia.\n\n");
				} else{
                	mostrarInOrdem(raiz); 
                }
				system("PAUSE");
                break;
            case 5:
            	if(*raiz==NULL){
					printf("\nNao eh possivel listar, arvore vazia.\n\n");
				} else{
                	mostrarPosOrdem(raiz); 
                }
				system("PAUSE");
                break;
            case 6:
                consultaArvore(raiz); 
                system("PAUSE");
                break;
            case 7:
                altura = arvoreAltura(raiz)-1; 
                printf("\nAltura total da Arvore: %i\n\n", altura);
                system("PAUSE");
                break;
            case 8:
            	sair = true;
                break;
            default :
                printf("\nOpcao invalida, forneca uma opcao valida!\n\n");
                system("PAUSE");
               	break;
        }
    }while(sair == false);
    destruirArvore(raiz);
    printf("\n******************************************\n");
    printf("******************************************\n");
    printf("******************************************\n");
    return 0;
}
