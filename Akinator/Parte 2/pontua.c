#include"pontua.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pontos(char v[]){//Essa fun��o tem como param�tro uma string(SIM ou NAO) e retorna um ponto, cada personagem tem um ponto.

    FILE *arquivo;//Aqui criamos o arquivo que armazenara as respostas dada pelos usu�rios.

    arquivo = fopen("resposta.txt", "a");//Nesta parte abrimos o arquivo para utiliza��o, note que damos um nome para o mesmo e o colocamos do tipo a, ou seja, sempre que o usu�rio der uma resposta a mesma ser� adicionada sem sobrescrever a anterior.

    if(arquivo==NULL){//Verifica se foi poss�vel abrir o arquivo.
        printf("Erro ao abrir arquivo\n");
        return 0;
    }

    printf("Seu personagem tem cabelo?\n");//M�todo que conclu� qual personagem � atrav�s da l�gica e retorna um n�mero espec�fico.
    scanf("%s", v);
    fprintf(arquivo,"%s ",v);
    if(strcmp(v,"SIM")==0){//Aqui, utilizamos compara��o entre strings para a tomada de decis�o, essa fun��o esta definida em string.h.
        printf("Seu personagem e real?\n");
        scanf("%s", v);
        fprintf(arquivo,"%s ",v);
        if(strcmp(v,"NAO")==0){
                printf("Seu personagem e de um livro?\n");
                scanf("%s", v);
                fprintf(arquivo,"%s ",v);
                if(strcmp(v,"SIM")==0){
                    printf("Seu personagem usa oculos?\n");
                    scanf("%s", v);
                    fprintf(arquivo,"%s ",v);
                    if(strcmp(v,"SIM")==0){
                        return 10;
                    }
                    else if(strcmp(v,"NAO")==0){
                        printf("Seu personagem gosta de anoes?\n");
                        scanf("%s", v);
                        fprintf(arquivo,"%s ",v);
                        if(strcmp(v,"NAO")==0){
                            return 9;
                        }
                        else if(strcmp(v,"SIM")==0){
                            return 7;
                        }
                    }
                }
                else if(strcmp(v,"NAO")==0){
                    printf("Seu personagem e muito serio?\n");
                    scanf("%s", v);
                    fprintf(arquivo,"%s ",v);
                    if(strcmp(v,"SIM")==0){
                        return 2;
                    }
                    else if(strcmp(v,"NAO")==0){
                        printf("Seu personagem e burro?\n");
                        scanf("%s", v);
                        fprintf(arquivo,"%s ",v);
                        if(strcmp(v,"SIM")==0){
                            return 8;
                        }
                        else if(strcmp(v,"NAO")==0){
                            return 6;
                        }
                    }

                }
        }
        else if(strcmp(v,"SIM")==0){
            printf("Seu personagem sabe tocar violino?\n");
            scanf("%s", v);
            fprintf(arquivo,"%s ",v);
            if(strcmp(v,"SIM")==0){
                return 4;
            }
            else if(strcmp(v,"NAO")==0){
                return 3;
            }
        }
    }
    else if(strcmp(v,"NAO")==0){
        printf("Seu personagem ja foi um deus?\n");
        scanf("%s", v);
        fprintf(arquivo,"%s ",v);
        if(strcmp(v,"SIM")==0){
            return 5;
        }
        else if(strcmp(v,"NAO")==0){
            return 1;
        }
    }
    fclose(arquivo);
}
