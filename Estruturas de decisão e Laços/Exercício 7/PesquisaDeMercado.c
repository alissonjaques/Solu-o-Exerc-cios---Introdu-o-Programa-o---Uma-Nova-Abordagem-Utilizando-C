#include<stdio.h>

int main(){

    int i, quantidadeNao, quantidadeSim, quantidadeNaoMasculino, quantidadeSimFeminino, quantidadeMasculino, quantidadeFeminino;
    float porcentagemNaoMasculino, porcentagemSimFeminino;
    char sexo, gosto;

    quantidadeFeminino = 0;
    quantidadeMasculino = 0;
    quantidadeNao = 0;
    quantidadeSim = 0;
    quantidadeNaoMasculino = 0;
    quantidadeSimFeminino = 0;
    printf("\n\n**********************Pesquisa de Mercado**************************\n\n");
    for(i=0; i<3; i++){

        printf("Sexo: ");
        scanf("%s", &sexo);

        do{

            if(sexo == 'f'){

                quantidadeFeminino++;

            }
            else{

                if(sexo == 'm'){

                    quantidadeMasculino++;

                }
                else{

                    printf("Informe um sexo valido: ");
                    scanf("%s", &sexo);

                    if(sexo == 'f'){

                        quantidadeFeminino++;

                    }
                    if(sexo == 'm'){

                        quantidadeMasculino++;

                    }
                }
             }
        }while(sexo != 'f' && sexo != 'm');

        printf("Gostou do produto novo? ");
        scanf("%s", &gosto);

        do{

            if(gosto == 's'){

                quantidadeSim++;

                if(sexo == 'f'){

                    quantidadeSimFeminino++;

                }

            }
            else{

                if(gosto == 'n'){

                    quantidadeNao++;

                    if(sexo == 'm'){

                        quantidadeNaoMasculino++;

                    }

                }
                else{

                    printf("Informe uma opcao valida para o gosto: ");
                    scanf("%s", &gosto);


                    if(gosto == 's'){

                        quantidadeSim++;

                        if(sexo == 'f'){

                        quantidadeSimFeminino++;

                        }

                    }

                     if(gosto == 'n'){

                        quantidadeNao++;

                        if(sexo == 'm'){

                            quantidadeNaoMasculino++;

                        }

                    }
                }
            }
        }while(gosto != 's' && gosto != 'n');

    }

    if(quantidadeMasculino == 0){

        porcentagemNaoMasculino = 0.0;

    }
    else{

        porcentagemNaoMasculino = ((float)quantidadeNaoMasculino/(float)quantidadeMasculino)*100;

    }

    if(quantidadeFeminino == 0){

        porcentagemSimFeminino = 0.0;

    }
    else{

        porcentagemSimFeminino = ((float)quantidadeSimFeminino/(float)quantidadeFeminino)*100;

    }

    printf("\nQuantidade Masculino: %d\n", quantidadeMasculino);
    printf("Quantidde Feminino: %d\n", quantidadeFeminino);
    printf("Quantidade de pessoas que responderam sim: %d\n", quantidadeSim);
    printf("Quantidade de pessoas que responderam nao: %d\n", quantidadeNao);
    printf("Porcentagem de mulheres que responderam sim: %f%%\n", porcentagemSimFeminino);
    printf("Porcentagem de homens que responderam nao: %f%%\n", porcentagemNaoMasculino);

    return 0;

}