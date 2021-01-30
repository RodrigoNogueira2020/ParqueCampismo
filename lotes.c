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
#include <ctype.h>
#include "campista.h"
#include "lotes.h"
#include "Mapa.h"

/*
 * =>*pedirLinha e *pedirColuna
 * São as coordenadas do lote que o utilizador pretende reservar.
 * NOTA: esta função NÃO verifica se o lote está ocupado,
 *isso estará para o "pedirDadosLotes()"
 *
*/

void consultarLotes(int linha, int coluna);

void pedirCoordenadasLote(int *pedirLinha, int *pedirColuna){
    mapa Mapa;
    /* Impede que os valores sejam nulos ou excedam dimensões do Mapa lotes */
    do{
        printf("Introduza a coluna onde se encontra o lote: ");
        scanf("%d", pedirColuna);

        if(*pedirColuna > Mapa.coluna)
            printf("\n==ERRO! Número da coluna inserido excede o número máximo de colunas do mapa==\n");
        else if(*pedirColuna < 0)
            printf("\n==ERRO! Número da coluna inserido não pode ser menor que 0 ==\n");
        else if(*pedirColuna == 0)
            printf("\n==ERRO! Número da coluna não pode ser 0==\n");

    }while(*pedirColuna > Mapa.coluna || *pedirColuna < 1);

    do{
        printf("Introduza a linha onde se encontra o lote: ");
        scanf("%d", pedirLinha);
        fflush(stdin);

        if(*pedirLinha > Mapa.linha)
            printf("\n==ERRO! Número da linha inserido excede o número máximo de linhas do Mapa==\n");
        else if(*pedirLinha < 0)
            printf("\n==ERRO! Número da linha inserido não pode ser menor que 0==\n");
        else if(*pedirLinha == 0)
            printf("\n==ERRO! Número da linha não pode ser 0==\n");

    }while(*pedirLinha > Mapa.linha || *pedirLinha < 1);
}

void menuReservaLote(){
    printf("===   MENU DE RESERVA DO LOTE   ===\n");
    printf(":: Tenda              4,50 Euros ::\n");
    printf(":: Caravana           6,00 Euros ::\n");
    printf(":: Autocaravana      14,50 Euros ::\n");
    printf(":: ----------------------------- ::\n");
    printf(":: +Eletricidade      3,00 Euros ::\n");
    printf(":: Cada campista      3,50 Euros ::\n");
    printf("===================================\n");
}

void pedirDadosLotes(int linha, int coluna){
    char eletricidade, tipoAloj;
    int numCampistas = 0;

    //temporario
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento != NULL){
        printf("\n==ERRO! Lote já está reservado!==\n");
        return;
    }

    criarLote[linha-1][coluna-1].reservaAtual.coordenadasLin = linha;
    criarLote[linha-1][coluna-1].reservaAtual.coordenadasCol = coluna;
    criarLote[linha-1][coluna-1].reservaAtual.preco = 0;

    do{
        menuReservaLote();
        printf("Tipo de alojamento [ (T)enda // (C)aravana // (A)utocaravana ]: ");
        scanf("%c", &tipoAloj);
        fflush(stdin);

        switch(tolower(tipoAloj)){
            case 't':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'T';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 4.50;
                break;
            case 'c':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'C';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 6.00;
                break;
            case 'a':
                criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = 'A';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 14.90;
                break;
            default:
                printf("\n==ERRO! Caractér inválido!==\n\n");
        }

    }while(tolower(tipoAloj) !='t' && tolower(tipoAloj) !='c' && tolower(tipoAloj) !='a');

    do{
        printf("Tem ligação à rede eletrica (S/N): ");
        scanf("%c", &eletricidade);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = 'e';
                criarLote[linha-1][coluna-1].reservaAtual.preco += 3.00;
                break;

            case 'n':
                criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = 'x';
                break;

            default:
                printf("\n==ERRO! Caractér inválido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

    do{
        printf("===== Dados do(s) campista(s) =====");
        printf("\nNúmero de campistas: ");
        scanf("%d", &numCampistas);
        fflush(stdin);

        if(numCampistas > 6)
            printf("\n==ERRO! Número máximo campistas é 6!==\n");
        else if(numCampistas <= 0)
            printf("\n==ERRO! Valor inserido não pode ser menor ou igual a zero!==\n");
        else if(isalpha(numCampistas) != 0)
            printf("\n==ERRO! Valor inserido não é um número!==\n");
        else{
            criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = numCampistas;
            criarLote[linha-1][coluna-1].reservaAtual.preco += numCampistas * 3.50;
        }

    }while(numCampistas <= 0 && numCampistas > 6 && isalpha(numCampistas) == 0 );

    for(int i = 0 ; i < numCampistas; i++){
        printf("Nome do %dº campista: ", i+1);
        gets(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome);

        do{
            printf("Idade do %dº campista: ", i+1);
            scanf("%d", &criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade);
            fflush(stdin);
        }while(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade <= 0);
    }

    consultarLotes(linha, coluna);

}

void consultarLotes(int linha, int coluna){

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL){
        printf("\n==ERRO! Este lote não está reservado!==\n");
        return;
    }

    printf("\n\n===   INFORMAÇÃO DO LOTE   ===");
    printf("\n::Tipo de alojamento: ");
    printf("%c", criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento);
    switch(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento){
        case 'T':
            printf("Tenda");
            break;
        case 'C':
            printf("Caravana");
            break;
        default:
            printf("Autocaravana");
    }

    printf("\n::Rede eletrica: ");
    switch(criarLote[linha-1][coluna-1].reservaAtual.redeEletrica){
        case 'e':
            printf("Sim");
            break;
        default:
            printf("Não");
    }

    printf("\n::Número de campistas: %d", criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas);
    for(int i = 0; i < criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i++){
        printf("\n::Campista nº%d: %s", i+1, criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome);
        printf("\n::Idade%9s%d", ": ", criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade);
    }

    printf("\n::Preço: %.2f Euro(s)\n", criarLote[linha-1][coluna-1].reservaAtual.preco);

    printf("==============================\n\n");

}

void editarReservaLote(int linha, int coluna){
    int info;
    do{
        consultarLotes(linha, coluna);
        printf("\n====================================\n");
        printf("\n||Qual é o detalhe que deseja alterar?||\n");
        printf("\n====================================\n");
        printf("1 - Tipo de alojamento\n");
        printf("2 - Rede eletrica\n");
        printf("3 - Adicionar campista\n");
        printf("4 - Remover campista\n");
        printf("0 - Sair\n");
        scanf("%d", &info);
    }while(isalpha(info) == 0 && info != 0);
}

void anularInfo(int linha, int coluna){
    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento != NULL){
        criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.redeEletrica = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.preco = 0;
        criarLote[linha-1][coluna-1].reservaAtual.coordenadasCol = NULL;
        criarLote[linha-1][coluna-1].reservaAtual.coordenadasLin = NULL;

        for(int i=0; i<criarLote[linha-1][coluna-1].reservaAtual.numeroCampistas; i+1){
            strcpy(criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].nome, NULL);
            criarLote[linha-1][coluna-1].reservaAtual.pessoaCampista[i].idade = NULL;
        }
    }
}

void libertarReserva(int linha, int coluna){

    if(criarLote[linha-1][coluna-1].reservaAtual.tipoAlojamento == NULL){
        printf("\n==ERRO! Este lote não está reservado!==\n");
        return;
    }

    if(criarLote[linha-1][coluna-1].ultimasReservas[0].tipoAlojamento == NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }
    else if (criarLote[linha-1][coluna-1].ultimasReservas[1].tipoAlojamento == NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[1] = criarLote[linha-1][coluna-1].ultimasReservas[0];
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }
    else if(criarLote[linha-1][coluna-1].ultimasReservas[2].tipoAlojamento == NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[2] = criarLote[linha-1][coluna-1].ultimasReservas[1];
        criarLote[linha-1][coluna-1].ultimasReservas[1] = criarLote[linha-1][coluna-1].ultimasReservas[0];
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }
    else if(criarLote[linha-1][coluna-1].ultimasReservas[2].tipoAlojamento != NULL)
    {
        criarLote[linha-1][coluna-1].ultimasReservas[2] = criarLote[linha-1][coluna-1].ultimasReservas[1];
        criarLote[linha-1][coluna-1].ultimasReservas[1] = criarLote[linha-1][coluna-1].ultimasReservas[0];
        criarLote[linha-1][coluna-1].ultimasReservas[0] = criarLote[linha][coluna].reservaAtual;
        anularInfo(linha, coluna);
    }

    printf("\n-- Reserva de lote libertada com sucesso! --\n");
}


void escreverDadosFicheirosLotes(){
    FILE *f;
    f = fopen("reservaLote.bin", "wb");

    if(f == NULL){
        printf("\n==ERRO! Ficheiro não existe.==\n");
        return;
    }

    fwrite(&criarLote, sizeof(reserva), MAX_LINHAS*MAX_COLUNAS, f);
    fwrite(&Mapa, sizeof(mapa), MAX_LINHAS*MAX_COLUNAS, f);
    fclose(f);
}

void lerDadosFicheiroLotes(){
    FILE *f;
    f = fopen("reservaLote.bin", "rb");

    if(f == NULL){
        printf("\n==ERRO! Ficheiro não existe.==\n");
        return;
    }

    fread(&criarLote, sizeof(reserva), MAX_LINHAS*MAX_COLUNAS, f);
    fread(&Mapa, sizeof(mapa), MAX_LINHAS*MAX_COLUNAS, f);
    fclose(f);
}

