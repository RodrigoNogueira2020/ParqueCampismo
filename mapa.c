/*
|| Projeto Gestão de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 2ª Fase de Entrega
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "campista.h"
#include "lotes.h"
#include "menu.h"
#include "mapa.h"

void apresentarMapa(int linha, int coluna){
    char infoMapa[3] = "";
    float lotesLivres = 0, lotesOcupados = 0, lotesOcupadosPercentagem = 0;
    printf("\nMapa dos lotes:\n\n");

    /*Formação das colunas*/
    printf("%3s", ""); // Espaço esquerdo inicial da coluna da tabela
    for(int l = 0; l < coluna; l++){
        printf(" %-3d", l+1);
    }

    /*Número de linhas*/
    for(int l = 0; l < linha; l++){
        printf("\n");
        printf("%2d ", l+1);

        for (int c = 0; c < coluna; c++){

            printf(" ");
            if(criarLote[l][c].reservaAtual.tipoAlojamento == NULL){
                printf("...");
                lotesLivres++;
            }
            else{
                printf("%c%c%d", criarLote[l][c].reservaAtual.tipoAlojamento, criarLote[l][c].reservaAtual.redeEletrica, criarLote[l][l].reservaAtual.numeroCampistas);
                lotesOcupados++;
            }
        }

    }

    lotesOcupadosPercentagem = (lotesOcupados / (Mapa.linha*Mapa.coluna)) * 100;
    printf("\nLotes livres: %.0f", lotesLivres);
    printf("\nTaxa de ocupação: %.2f%%", lotesOcupadosPercentagem );


    puts("\n");
}

void definirDimensoesLote(int *linha, int *coluna){

    printf("\n== A dimensão do lote ainda não está definida ==\n");
    do{
        printf("++Introduza o número de colunas para o mapa do lote: ");
        scanf("%d", coluna);

        if(coluna <= 0)
            printf("\n==ERRO! Número de coluna tem de ser maior que 0, senão não existe==\n");
        else if(*coluna > MAX_COLUNAS)
            printf("\n==ERRO! Número de colunas não pode exceder o máximo de %d colunas==\n", MAX_COLUNAS);

    }while(*coluna != 0 && *coluna < 0 || *coluna > MAX_COLUNAS);

    do{
        printf("++Introduza o número de linhas para o mapa do lote: ");
        scanf("%d", linha);

        if(linha <= 0)
            printf("\n==ERRO! Número de linhas tem de ser maior que 0, senão não existe==\n");
        else if(*linha > MAX_LINHAS)
            printf("\n==ERRO! Número de linhas não pode exceder o máximo de %d linhas==\n", MAX_LINHAS);

    }while(*linha != 0 && *linha < 0 || *linha > MAX_LINHAS);
}
