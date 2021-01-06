/*
|| Projeto Gestão de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1ª Fase de Entrega
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include "campista.h"
#include "lotes.h"

lote reservaLote;

void pedirDadosLotes(lote *reservaLote);

void apresentarMapa(){
    int l, c; // Linha e coluna respetivamente
    const int DIMLIN = 5, DIMCOL = 5; // Dimensão do parque de campismo
    //int DIMLIN, DIMCOL; //Variáveis para o utilizador escoher o tamanho do mapa do parque

    /* Prototipo do mapa
    printf("\n");
    printf("%8s %5s %5s %5s %5s\n", "1", "2", "3", "4", "5");

    printf("%2s %6s %5s %5s %5s %5s\n", "1", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n", "2", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n", "3", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n", "4", "...", "...", "...", "...", "...");
    printf("%2s %6s %5s %5s %5s %5s\n\n", "5", "...", "...", "...", "...", "...");


     |                                  |
     |       1     2     3     4     5  |
     | 1    ...   ...   ...   ...   ... |
     |                                  |
     */
    /*
    printf("\nInsira o número de linhas do mapa: ");
    scanf("%d", &DIMLIN);                               * Pedir ao utilizador o tamanho do mapa do parque
    printf("Insira o número de colunas do mapa: ");     *
    scanf("%d", &DIMCOL);
    */
    printf("\n\nMapa dos lotes:\n\n");

    /*Formação das colunas*/
    printf("%3s", ""); // Espaço esquerdo inicial da coluna da tabela
    for(l=0;l<DIMCOL;l++){
        printf("%5d ", l+1);
    }
    /*Número de linhas*/
    for(l=0;l<DIMLIN;l++){
        printf("\n");
        printf("%2d    ", l+1);

        for (c=0;c<DIMCOL;c++)
            printf("%s %2s", "...", " ");
    }
    puts("\n");
}

void menu(){
    int opcao; // Utilizado para verficar a opção escolhida do menu principal
    char opcaoSair; // Utilizado para verficar a opção escolhida na confirmação se o utilizador deseja mesmo sair.
    int l=0, c=0;

    do{
        printf("1 - Visualizar o mapa do parque\n");
        printf("2 - Reservar lote\n");
        printf("3 - Consultar informação de lote\n");
        printf("4 - Pesquisar lote do nome de campista\n");
        printf("5 - Editar a reserva de um lote\n");
        printf("6 - Libertar reserva\n");
        printf("\n0 - Sair\n\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 0:
                do{
                    printf("Deseja sair da aplicação? (s/n): ");
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
                            printf("Erro: Insira uma opção válida!\n");
                    }
                }while(opcao!=1 && (tolower(opcaoSair)!='s'));

                break;

            //Visualizar o mapa do parque
            case 1:
                apresentarMapa();
                break;
            case 2:

//                lote reservaLote;
//                pedirDadosLotes(&reservaLote);
                pedirDadosLotes(reservaLote);
                apresentarMapa();
                pedirCoordenadasLote(&l, &c);
                pedirDadosLotes(&lote[l][c]);
                break;
            case 3:
                printf("3ª opção escolhida");
                break;
            case 4:
                printf("4ª opção escolhida");
                break;
            case 7:
                system("cls"); // Limpar o ecrã
                break;
            default:
                printf("Erro: Insira uma opção válida!\n");
        }
    }while(opcao!=0);
}

int main(void){
    setlocale(LC_ALL, "");
    menu();
}
