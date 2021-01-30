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
        printf("%5d ", l+1);
    }

    /*Número de linhas*/
    for(int l = 0; l < linha; l++){
        printf("\n");
        printf("%2d    ", l+1);

        for (int c = 0; c < coluna; c++){
            loteInfoMapa(linha, coluna, infoMapa);
            printf("%s %2s", "", " ");
//            printf("%s %2s", "...", " ");
        }


    }
    puts("\n");
}

void loteInfoMapa(int linha, int coluna, char* infoMapa){
    char c = criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento;
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == '\0'){
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

    }while(*coluna != 0 && *coluna < 0);

    do{
        printf("++Introduza o número de linhas para o mapa do lote: ");
        scanf("%d", linha);
        if(coluna <= 0)
            printf("\n==ERRO! Número de linhas tem de ser maior que 0, senão não existe==\n");
    }while(*linha != 0 && *linha < 0);
}
