#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 200 

/*
	Cada caractere é representado por um número inteiro e possui uma ordem consecutiva em
	ASCII, então basta trocar o vetor de inteiro no algoritmo QuickSort	para um vetor de char.
	
	Autor: Alisson Jaques
	Entrada: um texto qualquer
	Saída: o texto ordenado em ordem alfabetica, caractere por caractere
*/
int SelecionaPivo(char *v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;    
    pivo = v[inicio];
	while(esq < dir)
    {
        while(v[esq] <= pivo) { esq++;}
        while(v[dir] > pivo) { dir--;}
        if(esq < dir)
        {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }       
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(char *v, int inicio, int fim){
    int pivo;
    if(fim > inicio)
    {
        pivo = SelecionaPivo(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo + 1, fim);
    }
}

int main(){
	
	int k;
	
	char linha[MAX];
	printf("Informe o texto: ");
    gets(linha);
    fflush(stdin);
    printf("\n");
	printf("\nString de entrada: ");
	
	printf("{%s}\n",linha);
	
	printf("String de saida ordenada: ");
	
	quickSort(linha,0,strlen(linha)-1);
	printf({"%s\n}",linha);
	
	system("pause");
	return 0;
}
