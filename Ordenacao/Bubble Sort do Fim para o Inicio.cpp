#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
	Percorrer o vetor do fim para o início trocando, com
	uma bolha propagando, o símbolo da direita (quando este for menor do que o da esquerda),
	até a bolha estourar e seguir o processo até a lista estar ordenada.
	
	Autor: Alisson Jaques
	Entrada: um vetor de inteiros
	Saída: o mesmo vetor de inteiros ordenado de forma crescente
*/
void bubbleSort(int *v, int n)
{
    int i, continua, aux, inicio=0;
    do
    {
        continua = 0;
        for(i=n-1; i>= inicio+1; i--)
        {
            if(v[i] < v[i - 1])
            {
                aux = v[i-1];
                v[i-1] = v[i];
                v[i] = aux;
                continua = i;
            }
        }
        inicio++;
    }while(continua != 0);
    
    int k;
    printf("{");
	for(k = 0; k<n; k++){
		if(k!=n-1){
    	   printf("%d, ", v[k]);
		}	
		else{
            printf("%d", v[k]);
		}
	}
	printf("}\n");
}

int main(){
	
	int vetor[10] =  {8, 9, 7, 9, 3, 2, 3, 8, 4, 6};
	int k;
		
	printf("\nVetor de entrada: ");
	
	printf("{");
	for(k = 0; k<10; k++){
		if(k!=9){
    	   printf("%d, ", vetor[k]);
		}	
		else{
            printf("%d", vetor[k]);
		}
	}
	printf("}\n");
	
	
	printf("Vetor de saida ordenado: ");
	
	bubbleSort(vetor,10);
	printf("\n");
	system("pause");
	return 0;
}
