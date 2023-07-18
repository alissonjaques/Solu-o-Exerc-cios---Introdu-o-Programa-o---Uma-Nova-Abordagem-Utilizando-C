#include <stdio.h> // Biblioteca para entrada e saida de dados

/*

    A funcao principal main permite a execucao desse programa.
    Ela calcula a temperatura em graus celsius correspondente a 
    temperatura em graus fahrenheit passada pelo usuario.
	Autor: Alisson Jaques

*/
int main(){ // declara a funcao

    float fahrenheit, celsius; // Temperaturas
     
    printf("Informe a temperatura em graus Fahrenheit:\n"); // Solicitamos ao usuario que informe o valor em fahrenheit
    scanf("%f", &fahrenheit); // Armazenamos o valor informado na variavel fahrenheit

    celsius = 5 * ((fahrenheit - 32)/9); // Equação para obter a temperatura em graus celsius
	
	// Informamos a temperatura em graus celsius correspondente à entrada em graus fahrenheit
    printf("Temperatura correspondente em graus Celcius: %f\n", celsius); 

    return 0; // retorno padrao

} // fim da funcao main