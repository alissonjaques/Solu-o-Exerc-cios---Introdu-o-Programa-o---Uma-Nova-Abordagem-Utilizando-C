#include<stdio.h> // biblioteca para entrada e saida de dados

/*
    
    A funcao main permite a execução desse programa, ela nao
    recebe argumentos e fornece uma tabela de conversao de 
    temperatura (graus fahrenheit para celsius).
    Autor: Alisson Jaques
*/
int main (){ // declara a funcao

    float celsius;  // temperatura em graus celsius
    int fahrenheit; // temperatura em graus fahrenheit

    for(fahrenheit = 0; fahrenheit<=150; fahrenheit++){ // enquanto nao percorrer 151 ciclos, faca:

        celsius = 5 * (((float)fahrenheit - 32)/9); // Obtencao da temperatura em graus celsius em funcao da temperatura em
                                                    // graus fahrenheit

        // imprime a temperatura em graus fahrenheit e se valor correspondente em graus celsius
        printf("Graus Fahrenheit: %d | Graus Celsius: %f\n", fahrenheit,celsius);

    } // fim do for

    return 0; // retorno padrao para main

} // fim da funcao main