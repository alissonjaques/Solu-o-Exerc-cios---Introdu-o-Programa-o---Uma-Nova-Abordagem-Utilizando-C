#include<stdio.h> // biblioteca para entrada e saida de dados

/*

    A funcao main permite a execucao desse programa, ela nao
    recebe nenhum argumento e calcula o resultado da soma
    S = 1/1 + 3/2 + 5/3 + ... + 99/50
	
	Autor: Alisson Jaques

*/
int main(){ // declara a funcao

    float soma; // a soma da expressao
    int i;      // variavel de controle do laco

    soma = 1;

    for(i=1; i<=49; i++){ // enquanto nao percorrer 49 ciclos, faca:

        soma = soma + ((2*(float)i+1)/((float)i+1)); // soma = soma + (2i+1)/(i+1)

    } // fim for

    printf("S = %f\n", soma); // mostra na tela o valor da soma

    return 0; // retorno padrao para main

} // fim da funcao main
