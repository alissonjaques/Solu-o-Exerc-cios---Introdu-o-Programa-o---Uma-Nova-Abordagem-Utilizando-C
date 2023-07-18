/*
    Descricao: calcular os anos que levarao para que a populacao do pais A seja maior ou igual a populacao 
    do pais B 
    Dados de entrada: não possui.
    Saida do programa: A quantidade de anos nescessarios para que a populacao do pais A seja maior ou igual
    a populacao do pais B
    Autor: Alisson Jaques

*/
#include<stdio.h> // biblioteca para entrada e saida de dados

/*
    A função main permite a execução desse programa, ela não possuí argumentos.
    Esta função calcula e imprimi a quantidade de anos que uma população de um país
    A ultrapassará uma de um país B.
*/
int main(){ // declara a funcao

    float populacaoA, populacaoB; // para armazenar dados das populações A e B
    int anos; // anos que levarão para a população A ultrapasse a população B

    // inicializações
    populacaoA = 9000;
    populacaoB = 20000;
    anos = 0;

    while(populacaoA<populacaoB){ // enquanto a população de A for menor que a de B, faça:

        anos++; // somamos mais um na quantidade de anos
        populacaoA = populacaoA + 0.03*populacaoA; // atualizamos a população de A
        populacaoB = populacaoB + 0.015*populacaoB;// atualizamos a população de B

    }// fim while
    
    printf("\n"); // quebra de linha para melhor organização dos dados no terminal
    
    // informamos a quantidade de anos procurada
    printf("O numero de anos para a populacao do pais A ultrapassar ou se igualar a populacao do pais B eh: %d\n\n", anos);

    return 0; // retorno padrao para main

} // fim da funcao main