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
//            loteInfoMapa(linha, coluna, infoMapa);
//            printf(" %2s", " ");
//            printf("%s ", "...", "");

            printf(" ");
            if(criarLote[l][c].reservaAtual.tipoAlojamento == NULL)
                printf("...");
            else
                printf("%c%c%d", criarLote[l][c].reservaAtual.tipoAlojamento, criarLote[l][c].reservaAtual.redeEletrica, criarLote[l][l].reservaAtual.numeroCampistas);
        }

    }
    puts("\n");

//    if(criarLote[i][j].reservaAtual.tipo == NULL){
//        printf("\t---\t\t");
//        contaLivres++;//conta os lotes livres
//    }
//    else{//caso contrario mostra informacao do lote
//        if (criarLote[i][j].reservaAtual.redeEletrica){
//            printf("\t%ce%d\t\t", criarLote[i][j].reservaAtual.tipo, criarLote[i][j].reservaAtual.numCampista);
//        }else{
//            printf("\t%cx%d\t\t", criarLote[i][j].reservaAtual.tipo, criarLote[i][j].reservaAtual.numCampista);
//        }
//    }
}

void loteInfoMapa(int linha, int coluna, char* infoMapa){

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL){
        printf("%s", "...");
        printf("%c", criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento);
    }
    else{
        switch(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento){
            case 'T':
                strcat(infoMapa, "T");
                break;
            case 'C':
                strcat(infoMapa, "C");
                break;
            case 'A':
                strcat(infoMapa, "A");
                break;
        }

        switch(criarLote[linha-1][coluna-1].reservaAtual.redeEletrica){
            case 'e':
                strcat(infoMapa, "e");
                break;
            case 'x':
                break;
                strcat(infoMapa, "x");
        }
        char c = criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas + '0';
        strcat(infoMapa, c);
    }
//
//        if(criarLote[linha][coluna].reservaAtual.tipoAlojamento == NULL){
//            printf("...");
//        }
//        else{
//            printf("%c", criarLote[linha][coluna].reservaAtual.tipoAlojamento);
//            printf("%c", criarLote[linha][coluna].reservaAtual.redeEletrica);
//            printf("%d", criarLote[linha][coluna].reservaAtual.numeroCampistas);
//        }
//        printf("%s", infoMapa);

//        if(toupper(parque[i][j].reservaAtual.tipo) == NULL){//se a reserva atual não tiver nenhum registo do tipo de alojamento irá mostrar na tabela o lote com o respetivo numero
//            printf("\t---\t\t");
//            contaLivres++;//conta os lotes livres
//        }
//        else{//caso contrario mostra informacao do lote
//            if (parque[i][j].reservaAtual.eletricidade){
//                printf("\t%ce%d\t\t", toupper(parque[i][j].reservaAtual.tipo), parque[i][j].reservaAtual.numCampista);
//            }else{
//                printf("\t%cx%d\t\t", toupper(parque[i][j].reservaAtual.tipo),parque[i][j].reservaAtual.numCampista);
//            }
//        }

//    }

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
