#include<stdio.h>

int main(){

    int valor = 1, maior, segundoMaior;
    maior = valor;
    segundoMaior = -99;

    do{

        printf("Informe um valor:\n");
        scanf("%d", &valor);

        if(valor>=maior){

            segundoMaior = maior;
            maior = valor;

        }
        else{

            if(valor>=segundoMaior){

                segundoMaior = valor;

            }
        }

    }while(valor!=0);

    printf("Maior: %d\n", maior);

    printf("Segundo Menor: %d\n", segundoMaior);

    return 0;

}