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

//void registaDadosParque(){//regista os dados do lote na reservaAtual
//
//    if (parque[pedeLinha][pedeColuna].reservaAtual.tipo != NULL){
//        parque[pedeLinha][pedeColuna].ultimasReservas[0] = parque[pedeLinha][pedeColuna].reservaAtual;
//    }
//
//    if (lerDadosEletricidade()){//se a eletricidade for true regista na reservaAtual como true
//        parque[pedeLinha-1][pedeColuna-1].reservaAtual.eletricidade = true;
//    }else{//caso contrario regista como false
//        parque[pedeLinha-1][pedeColuna-1].reservaAtual.eletricidade = false;
//    }
//    //regista os dados do lote na reservaAtual
//    parque[pedeLinha-1][pedeColuna-1].reservaAtual.tipo = criarLote.tipo;
//    parque[pedeLinha-1][pedeColuna-1].reservaAtual.custoTotal = criarLote.custoTotal;
//    parque[pedeLinha-1][pedeColuna-1].reservaAtual.numCampista = criarLote.numCampista;
//
//    for (int i = 0; i < parque[pedeLinha-1][pedeColuna-1].reservaAtual.numCampista; ++i){//regista os dados do utilizador na reservaAtual
//        strcpy(parque[pedeLinha-1][pedeColuna-1].reservaAtual.dados[i].nome, criarLote.dados[i].nome);
//        parque[pedeLinha-1][pedeColuna-1].reservaAtual.dados[i].idade = criarLote.dados[i].idade;
//    }
//}

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

}

void libertarReserva(int linha, int coluna){
    if(criarLote[linha][coluna].ultimasReservas[i] != NULL)
        criarLote[linha][coluna].ultimasReservas[i] = criarLote[linha][coluna].reservaAtual;
    }
    printf("-- Reserva de lote libertada com sucesso! --")
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

