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

void apresentarMapa(int linha, int coluna){
    printf("\nMapa dos lotes:\n\n");

    /*Formação das colunas*/
    printf("%3s", ""); // Espaço esquerdo inicial da coluna da tabela
    for(int l=0; l<coluna; l++){
        printf("%5d ", l+1);
    }

    /*Número de linhas*/
    for(int l=0; l<linha; l++){
        printf("\n");
        printf("%2d    ", l+1);

        for (int c=0; c<coluna; c++)
            printf("%s %2s", "...", " ");
    }
    puts("\n");
}

void definirDimensoesLote(int *linha, int *coluna){

    printf("\n== A dimensão do lote ainda não está definida ==\n");
    do{
        printf("++Introduza o número de colunas para o mapa do lote: ");
        scanf("%d", coluna);

        if(coluna <= 0)
            printf("\n==ERRO! Número de coluna tem de ser maior que 0, senão não existe==\n");
    }while(*coluna != 0 && *coluna < 0);

    do{
        printf("++Introduza o número de linhas para o mapa do lote: ");
        scanf("%d", linha);
        if(coluna <= 0)
            printf("\n==ERRO! Número de linhas tem de ser maior que 0, senão não existe==\n");
    }while(*linha != 0 && *linha < 0);
}
