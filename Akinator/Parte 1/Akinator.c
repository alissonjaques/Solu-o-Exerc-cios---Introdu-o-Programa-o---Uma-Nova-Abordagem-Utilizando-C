#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 4

struct personagem{
    int a;
};

int pontua(char v[]){

    printf("Seu personagem tem cabelo?\n");
    scanf("%s", v);
    if(strcmp(v,"SIM")==0){
        printf("Seu personagem e real?\n");
        scanf("%s", v);
        if(strcmp(v,"NAO")==0){
                printf("Seu personagem e de um livro?\n");
                scanf("%s", v);
                if(strcmp(v,"SIM")==0){
                    printf("Seu personagem usa oculos?\n");
                    scanf("%s", v);
                    if(strcmp(v,"SIM")==0){
                        return 10;
                    }
                    else if(strcmp(v,"NAO")==0){
                        printf("Seu personagem gosta de anoes?\n");
                        scanf("%s", v);
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
                    if(strcmp(v,"SIM")==0){
                        return 2;
                    }
                    else if(strcmp(v,"NAO")==0){
                        printf("Seu personagem e burro?\n");
                        scanf("%s", v);
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
        if(strcmp(v,"SIM")==0){
            return 5;
        }
        else if(strcmp(v,"NAO")==0){
            return 1;
        }
    }

}
int main(){

    char v[TAM];
    int i;

    struct personagem pontos[10];

    for(i=0; i<10; i++){
        pontos[i].a = i+1;
    }

    printf("Pense em alguns dos seguintes personagens:\n\n   Curirin  \n   Batman  \n   Newton\n   Einstein\n   Kratos\n   Aladdin\n   Bilbo\n   Severus Snape\n   Harry Potter\n   Goku\n");

    printf("\n");

    switch(pontua(v)){
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
