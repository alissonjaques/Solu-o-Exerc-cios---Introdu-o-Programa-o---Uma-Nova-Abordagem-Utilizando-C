/*
    Descricao: Algoritmo para ler uma sequência de números inteiros positivos e informar, um a um, 
    se são ímpares ou pares.
    Dados de Entrada: números positivos
    Dados de Saída: Informacao sobre o numeros informados, um a um. Se sao pares ou impares.
    Autor: Alisson Jaques
    
*/
#include<stdio.h> // biblioteca para entrada e saida de dados
/*
    A funcao main permite a execucao desse programa, ela nao possui argumentos.
    Esta funcao le uma uma sequencia de numeros positivos, um por vez, e informa
    se estes são pares ou ímpares.

*/
int main(){ // declara a funcao main

    int numero; // variavel para armezadar o numero inteiro fornecido pelo usuario

    // solicitamos ao usuario que informe um numero inteiro e inicializamos a variavel numero com o mesmo
    printf("Informe os numeros positivos (ao informar um numero negativo o programa sera encerrado):\n\n");
    scanf("%d", &numero);

    while(numero>0){ // enquanto o usuario informar um numero positivo, faca:

        if(numero % 2 == 0){ // se o numero informado for par, entao:

            printf("par\n\n"); // imprimi par

        }
        else{ // senao

            printf("impar\n\n"); // imprimi impar

        } // fim-se

        scanf("%d", &numero); // obtencao do proximo numero

    } // fim while

    printf("\n"); // quebra de linha para melhor organizacao dos dados no terminal

    return 0; // retorno padrao para main

} // fim da funcao main