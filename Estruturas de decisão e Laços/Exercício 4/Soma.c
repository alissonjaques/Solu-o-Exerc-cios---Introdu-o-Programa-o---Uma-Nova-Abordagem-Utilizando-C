#include<stdio.h> // biblioteca para entra e saida de dados

/*
    A funcao main permite a execucao desse programa, ela nao
    possui argumentos e calcula a soma:
    S = ((37x38)/1) - ((36x37)/2) + ((35x36)/3) - ... + ((1x2)/37)
    
    Autor: Alisson Jaques

*/
int main(){ // declara a funcao

    int i;         // variavel de controle do laco
    float n, soma; 

    n = 37;
    soma = 0;
    for(i=1; i<=37; i++){ // enquanto nao percorrer 37 ciclos, faca:

        if(i % 2 == 0){ // se a iteracao for par, faca

            soma = soma - (n*(n+1))/(float)i; // s = s - (n*(n+1))/i

        }
        else{ // senao, faca:
            
            soma = soma + (n*(n+1))/(float)i; // s = s + (n*(n+1))/i
        
        } // fim-se

        n--;
    } // fim for

    printf("S = %f\n", soma); // imprimimos o valor da soma

    return 0; // retorno padrao para main

} // fim da funcao main