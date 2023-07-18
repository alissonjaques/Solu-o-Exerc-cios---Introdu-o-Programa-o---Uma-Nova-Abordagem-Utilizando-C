#include"pontua.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pontos(char v[]){//Essa função tem como paramêtro uma string(SIM ou NAO) e retorna um ponto, cada personagem tem um ponto.

    FILE *arquivo;//Aqui criamos o arquivo que armazenara as respostas dada pelos usuários.

    arquivo = fopen("resposta.txt", "a");//Nesta parte abrimos o arquivo para utilização, note que damos um nome para o mesmo e o colocamos do tipo a, ou seja, sempre que o usuário der uma resposta a mesma será adicionada sem sobrescrever a anterior.

    if(arquivo==NULL){//Verifica se foi possível abrir o arquivo.
        printf("Erro ao abrir arquivo\n");
        return 0;
    }

    printf("Seu personagem tem cabelo?\n");//Método que concluí qual personagem é através da lógica e retorna um número específico.
    scanf("%s", v);
    fprintf(arquivo,"%s ",v);
    if(strcmp(v,"SIM")==0){//Aqui, utilizamos comparação entre strings para a tomada de decisão, essa função esta definida em string.h.
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
