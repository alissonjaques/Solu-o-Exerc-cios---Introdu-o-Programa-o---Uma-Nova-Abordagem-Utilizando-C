#include<stdio.h>

int main(){

    int numeroDaConta, contaAnterior, idCorrentistaMaiorSaldo, idCorrentistaSegundoMaiorSaldo;
    float saldoDaConta, valorDaOperacao, saldoTotalDasOperacoes, valorCorrentistaComMaiorSaldo, valorCorrentistaComSegundoMaiorSaldo;

    printf("Informe os dados da lista (primeiro informe o numero da conta, depois a operacao), caso deseje sair informe o numero da conta como 0):\n");
    printf("Conta: ");
    scanf("%d", &numeroDaConta);

    if(numeroDaConta==0){

        printf("Sem lista para extracao de dados.\n"); 

    }
    else{

        contaAnterior = numeroDaConta;
        saldoDaConta = 0;
        saldoTotalDasOperacoes = 0;
        valorCorrentistaComMaiorSaldo = -9000000;
        valorCorrentistaComSegundoMaiorSaldo = -9000000;

        do{

            printf("Valor Operacao: ");
            scanf("%f", &valorDaOperacao);

            if(valorDaOperacao>20000){

                printf("Operacao suspeita encontrada | conta : %d | R$%f\n", numeroDaConta,valorDaOperacao);

            }

            if(contaAnterior == numeroDaConta){

                saldoDaConta = saldoDaConta + valorDaOperacao;

            }
            else{

                printf("Saldo das Operacoes | conta: %d | saldo: R$%f\n", contaAnterior, saldoDaConta);

                if(saldoDaConta > valorCorrentistaComMaiorSaldo){

                    idCorrentistaSegundoMaiorSaldo = idCorrentistaMaiorSaldo;
                    idCorrentistaMaiorSaldo = contaAnterior;
                    valorCorrentistaComSegundoMaiorSaldo = valorCorrentistaComMaiorSaldo;
                    valorCorrentistaComMaiorSaldo = saldoDaConta;

                }
                else{

                    if(saldoDaConta > valorCorrentistaComSegundoMaiorSaldo){

                        idCorrentistaSegundoMaiorSaldo = contaAnterior;
                        valorCorrentistaComSegundoMaiorSaldo = saldoDaConta;

                    }

                }

                saldoDaConta = valorDaOperacao;

            }

            saldoTotalDasOperacoes = saldoTotalDasOperacoes + valorDaOperacao;

            contaAnterior = numeroDaConta;

            printf("Conta: ");
            scanf("%d", &numeroDaConta);

        }while(numeroDaConta != 0);

        valorDaOperacao = 0;
        if(contaAnterior == numeroDaConta){

            saldoDaConta = saldoDaConta + valorDaOperacao;

        }
        else{

            printf("Saldo das Operacoes | conta: %d | saldo: R$%f\n", contaAnterior, saldoDaConta);

            if(saldoDaConta > valorCorrentistaComMaiorSaldo){

                idCorrentistaSegundoMaiorSaldo = idCorrentistaMaiorSaldo;
                idCorrentistaMaiorSaldo = contaAnterior;                
                valorCorrentistaComSegundoMaiorSaldo = valorCorrentistaComMaiorSaldo;
                valorCorrentistaComMaiorSaldo = saldoDaConta;

            }
            else{

                
                if(saldoDaConta > valorCorrentistaComSegundoMaiorSaldo){

                    idCorrentistaSegundoMaiorSaldo = contaAnterior;
                    valorCorrentistaComSegundoMaiorSaldo = saldoDaConta;

                }

            }

        }

        if(valorCorrentistaComMaiorSaldo == -9000000){
            
            idCorrentistaMaiorSaldo = 0;
            valorCorrentistaComMaiorSaldo =0;
        
        }
        if(valorCorrentistaComSegundoMaiorSaldo == -9000000){

            idCorrentistaSegundoMaiorSaldo = 0;
            valorCorrentistaComSegundoMaiorSaldo = 0;

        }
        
        printf("Correntistas que produziram o maior saldo nas suas operacoes:\n");
        printf("Conta: %d | Saldo: R$%f\n", idCorrentistaMaiorSaldo, valorCorrentistaComMaiorSaldo);
        printf("Conta: %d | Saldo: R$%f\n", idCorrentistaSegundoMaiorSaldo, valorCorrentistaComSegundoMaiorSaldo);
        printf("Saldo Total das Operacoes: R$%f\n", saldoTotalDasOperacoes);

    }

    return 0;

}
