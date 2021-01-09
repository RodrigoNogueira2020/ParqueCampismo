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
#include "menu.h"
#include "mapa.h"

void menu(){
    char opcao; // Opção escolhida do menu principal
    char opcaoSair; // Utilizado na confirmação se o utilizador deseja mesmo sair. (opcao == 0)
    int linha=0, coluna=0;
    int pedirLinha=0, pedirColuna=0;

    do{
        fflush(stdin);
        printf("1 - Visualizar o mapa do parque\n");
        printf("2 - Reservar lote\n");
        printf("3 - Consultar informação de lote\n");
        printf("4 - Pesquisar lote do nome de campista\n");
        printf("5 - Editar a reserva de um lote\n");
        printf("6 - Libertar reserva\n");
        printf("\n0 - Sair\n\n");
        scanf("%c", &opcao);
        fflush(stdin);

        // Algumas letras introduzidas são recebidas como opções no menu, isto previne isso
        if (opcao < '0' || opcao > '7')
            opcao = '9';

        switch(opcao){
            case '0':
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
                            printf("==ERRO! Insira uma opção válida!==\n");
                    }
                }while(opcao!=1 && (tolower(opcaoSair)!='s'));
                break;

            // Visualizar o mapa do parque
            case '1':
                // Se coluna é zero é porque o mapa dos lotes ainda não existe
                switch(coluna){
                    case 0:
                        definirDimensoesLote(&linha, &coluna);
                    default:
                        apresentarMapa(linha, coluna);
                }
                break;
            // Reservar lote
            case '2':
                switch(coluna){
                    // Se coluna é zero é porque o mapa dos lotes ainda não existe
                    case 0:
                        definirDimensoesLote(&linha, &coluna);
                    default:
                        system("cls");
                        apresentarMapa(linha, coluna);
                        pedirCoordenadasLote(&pedirLinha, &pedirColuna);
                        //pedirDadosLotes(pedirLinha, pedirColuna);
                }
                break;
            // Consultar informação de lote
            case '3':
                printf("3ª opção escolhida");
                break;
            // Pesquisar lote do nome de campista
            case '4':
                printf("4ª opção escolhida");
                break;
            case '7':
                system("cls"); // Limpar o ecrã
                break;
            default:
                printf("\n==ERRO! Escolha uma opção correspondente às do menu!==\n");
        }
    }while(opcao!='0');
}
