/*
|| Projeto Gestão de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1ª Fase de Entrega
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "campista.h"
#include "lotes.h"
#include "mapa.h"
mapa mapaDimensoes;
void pedirDadosLotes(lote *reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]){
    char eletricidade;

    do{
        printf("=== MENU DE ALOJAMENTO ===\n");
        printf("++ Tenda ::: 4,50€\n");
        printf("++ Caravana ::: 6,00€\n");
        printf("++ Autocaravana ::: 14,50€\n");
        printf("++ Eletricidade ::: 3,00€\n");
        printf("++ Campista ::: 3,50€\n");
        printf("==========================\n");

        printf("Tipo de alojamento [Tenda (T) // Caravana (C) // Autocaravana (A)]: ");
        scanf("%c", &reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento);
        fflush(stdin);

        switch(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento)){
            case 't':
                reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento = 'T';
                break;
            case 'c':
                reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento = 'C';
                break;
            case 'a':
                reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento = 'A';
                break;
            default:
                printf("==ERRO! Caractér inválido!==\n");
        }

    }while(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento) !='t' &&
           tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento) !='c' &&
           tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento) !='a');

    do{
        printf("Tem ligação à rede eletrica(S/N): ");
        scanf("%c", &eletricidade/*reservaLote->redeEletrica*/);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->redeEletrica='e';
                break;

            case 'n':
                reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->redeEletrica ='x';
                break;

            default:
                printf("==ERRO! Caractér inválido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

    printf("===== Dados do(s) campista(s) =====");
    printf("Número de campistas: ");
    scanf("%d", &reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas);
    fflush(stdin);
    for(int i=0;i<reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas;i++){

        printf("Nome do campista: ");
        gets(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->pessoaCampista.nome);

        printf("Idade do campista :");
        scanf("%d", &reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->pessoaCampista.idade);
        fflush(stdin);
    }

    //Preços com eletricidade
    if(tolower(eletricidade='e')){
        if(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento)=='t'){
            reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco=3.00 /*Preço da eletricidade*/ + (3.50*(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas)) /*Preço por número de campistas*/ + 4.50; // Preço da tenta
            printf("Preço a pagar: %.2f", reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento)=='c'){
            reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco=3.00 /*Preço da eletricidade*/ + (3.50*(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas)) /*Preço por número de campistas*/ + 6.00; // Preço da caravana
            printf("Preço a pagar: %.2f", reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento=='a')){
            reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco=3.00 /*Preço da eletricidade*/ + (3.50*(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas)) /*Preço por número de campistas*/ + 14.90; // Preço da autocaravana
            printf("Preço a pagar: %.2f", reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco);
        }
    }

    //Preços sem eletricidade
    if(tolower(eletricidade='x')){
        if(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento=='t')){
            reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco=(3.50*(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas)) /*Preço por número de campistas*/ + 4.50; // Preço da tenta
            printf("Preço a pagar: %.2f", reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento=='c')){
            reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco=(3.50*(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas)) /*Preço por número de campistas*/ + 6.00; // Preço da caravana
            printf("Preço a pagar: %.2f", reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->tipoAlojamento=='a')){
            reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco=(3.50*(reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->numeroCampistas)) /*Preço por número de campistas*/ + 14.90; // Preço da autocaravana
            printf("Preço a pagar: %.2f", reservaLote[mapaDimensoes.linha][mapaDimensoes.coluna]->preco);
        }
    }
}

// Registar lote
void pedirCoordenadasLote(int *pedirLinha, int *pedirColuna, int linhaDoLote, int colunaDoLote){
    do{
        printf("Introduza a coluna onde se encontra o lote: ");
        scanf("%d", pedirColuna);

        if(pedirColuna > colunaDoLote)
            printf("\n==ERRO! Número de coluna inserido excede o número máximo de colunas do mapa==\n");
        else if(pedirColuna < 1)
            printf("\n==ERRO! Número de coluna inserido é menor que 0==\n");
    }while(*pedirColuna > colunaDoLote || *pedirColuna < 1);
    // PARA FAZER: Em vez de 5, deve ir buscar o valor das colunas no mapa dos lotes,
    //talvez numa struct propria para se poder mudar isso? mapaLote->Coluna?

    do{
        printf("\nIntroduza a linha onde se encontra o lote: ");
        scanf("%d", pedirLinha);
    }while(*pedirLinha > linhaDoLote || *pedirLinha < 1);
}
