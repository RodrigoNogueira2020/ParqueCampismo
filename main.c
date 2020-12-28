#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu(int *matriz[][]){

    int opcao;
    char opcao2;

    do{
        printf("1 - Visualizar o mapa do parque\n");
        printf("2 - Reservar lote\n");
        printf("3 - Consultar informação de lote\n");
        printf("4 - Pesquisar lote do nome de campista\n");
        printf("5 - Editar a reserva de um lote\n");
        printf("6 - Libertar reserva\n");
        printf("0 - Sair\n\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 0:
                do{
                    printf("Deseja sair da aplicação? (S/N):\n");
                    scanf("%c", &opcao2);
                    fflush(stdin);

                    switch(opcao2){
                        case 's': case 'S':
                            printf("Adeus!\n");
                            return 0;
                            break;
                        case 'n': case 'N':
                            opcao=1;
                            puts("");
                            break;
                        default:
                            printf("Erro. Insira uma opção válida!\n");
                    }
                }while(opcao!=1);
                break;

            case 1:
                printf("1ª opção escolhida");
                mapa(&matriz);
                break;
            case 2:
                printf("2ª opção escolhida");
                break;
            case 3:
                printf("3ª opção escolhida");
                break;
            case 4:
                printf("4ª opção escolhida");
                break;
            default:
                printf("Erro. Insira uma opção válida!\n");
        }
    }while(opcao!=0);
}

void mapa(int *matriz[][]){
    int i, j;
    for(i=0;i<3;i++){
        for (j=0;j<3;j++){
             scanf("%d", &matriz[i][j]);
        }
    }
}

int main(void){
    setlocale(LC_ALL, "");
    //int matriz[5][5];
    menu();
    //mapa();
}


