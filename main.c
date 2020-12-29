/*
* Projeto Gest�o de Reservas de Parque de Campismo
* Autores: +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
*          +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
* 1� Fase de Entrega
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void apresentarMapa(){
    int l, c; // Linha e coluna respetivamente
    const int DIMLIN = 3, DIMCOL = 2; // Dimens�o do parque de campismo

    /* Prototipo do mapa
    printf("\n");
    printf("%8s %5s %5s %5s %5s\n", "1", "2", "3", "4", "5");

    printf("%2s %6s %5s %5s %5s %5s\n", "1", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n", "2", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n", "3", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n", "4", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n\n", "5", "...", "...", "...", "...", "...");

    /*
     |                                  |
     |       1     2     3     4     5  |
     | 1    ...   ...   ...   ...   ... |
     |                                  |
     */

    printf("\n\nMapa dos lotes:\n\n");

    /*N�mero de colunas*/

    printf("%3s", ""); // Espa�o esquerdo inicial da coluna da tabela
    for(l=0;l<DIMCOL;l++)
        printf("%5d ", l+1);

    /*N�mero de linhas*/
    for(l=0;l<DIMLIN;l++){
        printf("\n");
        printf("%2d    ", l+1);

        for (c=0;c<DIMCOL;c++)
            printf("%s %2s", "...", " ");
    }
    puts("\n");
}

void menu(){
    int opcao; // Utilizado para verficar a op��o escolhida do menu principal
    char opcaoSair; // Utilizado para verficar a op��o escolhida na confirma��o se o utilizador deseja mesmo sair.

    do{
        printf("1 - Visualizar o mapa do parque\n");
        printf("2 - Reservar lote\n");
        printf("3 - Consultar informa��o de lote\n");
        printf("4 - Pesquisar lote do nome de campista\n");
        printf("5 - Editar a reserva de um lote\n");
        printf("6 - Libertar reserva\n");
        printf("0 - Sair\n\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 0:
                do{
                    printf("Deseja sair da aplica��o? (s/n): ");
                    scanf("%c", &opcaoSair);
                    fflush(stdin);

                    switch(tolower(opcaoSair)){
                        case 's':
                            printf("Adeus!\n");
                            break;
                        case 'n':
                            opcao=1;
                            puts("");
                            break;
                        default:
                            printf("Erro: Insira uma op��o v�lida!\n");
                    }
                }while(opcao!=1 && (tolower(opcaoSair)!='s'));

                break;

            // Visualizar o mapa do parque
            case 1:
                apresentarMapa();
                break;
            case 2:
                printf("2� op��o escolhida");
                break;
            case 3:
                printf("3� op��o escolhida");
                break;
            case 4:
                printf("4� op��o escolhida");
                break;
            case 7:
                system("cls"); // Limpar o ecr�
                break;
            default:
                printf("Erro: Insira uma op��o v�lida!\n");
        }
    }while(opcao!=0);
}

int main(void){
    setlocale(LC_ALL, "");
    //int matriz[5][5];
    menu();
}

