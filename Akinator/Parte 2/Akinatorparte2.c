#include"pontua.c"//Importa a biblioteca pontua.h onde o método de analise de respostas e feito.

#define TAM 4

int main(){

    char v[TAM];//Declara uma string capaz de receber "SIM" ou "NAO".
    int i;

    printf("Pense em alguns dos seguintes personagens:\n\n   Curirin  \n   Batman  \n   Newton\n   Einstein\n   Kratos\n   Aladdin\n   Bilbo\n   Severus Snape\n   Harry Potter\n   Goku\n");

    printf("\n");

    switch(pontos(v)){//Um switch que utiliza uma função de pontua.h, nessa função é retornado um número, para cada número retornado switch dara um case.
        case 1:
            printf("O personagem que voce pensou foi:\n\n   Curirin\n");
            break;
        case 2:
            printf("O personagem que voce pensou foi:\n\n   Batman\n");
            break;
        case 3:
            printf("O personagem que voce pensou foi:\n\n   Newton\n");
            break;
        case 4:
            printf("O personagem que voce pensou foi:\n\n   Einstein\n");
            break;
        case 5:
            printf("O personagem que voce pensou foi:\n\n   Kratos\n");
            break;
        case 6:
            printf("O personagem que voce pensou foi:\n\n   Aladdin\n");
            break;
        case 7:
            printf("O personagem que voce pensou foi:\n\n   Bilbo\n");
            break;
        case 8:
            printf("O personagem que voce pensou foi:\n\n   Goku\n");
            break;
        case 9:
            printf("O personagem que voce pensou foi:\n\n   Severus Snape\n");
            break;
        case 10:
            printf("O personagem que voce pensou foi:\n\n   Harry Potter\n");
            break;

    }

    return 0;
}
