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

lote criarLote(campista pessoaCampista, char tipoAlojamento, char redeEletrica, int numeroCampistas, float preco, int coordenadasLin, int coordenadasCol){
    lote criarLote;
    campista criarCampista;
    criarLote.pessoaCampista->nome = pessoaCampista.nome;

    criarLote.tipoAlojamento = tipoAlojamento;
    criarLote.redeEletrica = redeEletrica;
    criarLote.numeroCampistas = numeroCampistas;
    criarLote.preco = preco;
    criarLote.coordenadasLin = coordenadasLin;
    criarLote.coordenadasCol = coordenadasCol;

    return criarLote;
}

void pedirDadosLotes(int linha, int coluna){
    lote criarLote[linha][coluna];
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
        scanf("%c", criarLote[linha][coluna].tipoAlojamento);
        fflush(stdin);

        switch(tolower(criarLote[linha][coluna].tipoAlojamento)){
            case 't':
                criarLote[linha][coluna].tipoAlojamento = 'T';
                break;
            case 'c':
                criarLote[linha][coluna].tipoAlojamento = 'C';
                break;
            case 'a':
                criarLote[linha][coluna].tipoAlojamento = 'A';
                break;
            default:
                printf("==ERRO! Caractér inválido!==\n");
        }

    }while(tolower(criarLote[linha][coluna].tipoAlojamento) !='t' &&
           tolower(criarLote[linha][coluna].tipoAlojamento) !='c' &&
           tolower(criarLote[linha][coluna].tipoAlojamento) !='a');

    do{
        printf("Tem ligação à rede eletrica(S/N): ");
        scanf("%c", &eletricidade/*reservaLote->redeEletrica*/);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                criarLote[linha][coluna].redeEletrica='e';
                break;

            case 'n':
                criarLote[linha][coluna].redeEletrica ='x';
                break;

            default:
                printf("==ERRO! Caractér inválido!==\n");
        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

    printf("===== Dados do(s) campista(s) =====");
    printf("Número de campistas: ");
    scanf("%d", &criarLote[linha][coluna].numeroCampistas);
    fflush(stdin);
    for(int i=0;i<criarLote[linha][coluna].numeroCampistas;i++){

        printf("Nome do campista: ");
        gets(criarLote[linha][coluna]->pessoaCampista.nome);

        printf("Idade do campista :");
        scanf("%d", &criarLote[linha][coluna].pessoaCampista.idade);
        fflush(stdin);
    }

    //Preços com eletricidade
    if(tolower(eletricidade='e')){
        if(tolower(criarLote[linha][coluna].tipoAlojamento)=='t'){
            criarLote[linha][coluna].preco=3.00 /*Preço da eletricidade*/ + (3.50*(criarLote[linha][coluna].numeroCampistas)) /*Preço por número de campistas*/ + 4.50; // Preço da tenta
            printf("Preço a pagar: %.2f", criarLote[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(criarLote[linha][coluna].tipoAlojamento)=='c'){
            criarLote[linha][coluna].preco=3.00 /*Preço da eletricidade*/ + (3.50*(criarLote[linha][coluna].numeroCampistas)) /*Preço por número de campistas*/ + 6.00; // Preço da caravana
            printf("Preço a pagar: %.2f", criarLote[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='e')){
        if(tolower(criarLote[linha][coluna].tipoAlojamento=='a')){
            criarLote[linha][coluna].preco=3.00 /*Preço da eletricidade*/ + (3.50*(criarLote[linha][coluna].numeroCampistas)) /*Preço por número de campistas*/ + 14.90; // Preço da autocaravana
            printf("Preço a pagar: %.2f", criarLote[linha][coluna].preco);
        }
    }

    //Preços sem eletricidade
    if(tolower(eletricidade='x')){
        if(tolower(criarLote[linha][coluna].tipoAlojamento=='t')){
            criarLote[linha][coluna].preco=(3.50*(criarLote[linha][coluna].numeroCampistas)) /*Preço por número de campistas*/ + 4.50; // Preço da tenta
            printf("Preço a pagar: %.2f", criarLote[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(criarLote[linha][coluna].tipoAlojamento=='c')){
            criarLote[linha][coluna].preco=(3.50*(criarLote[linha][coluna].numeroCampistas)) /*Preço por número de campistas*/ + 6.00; // Preço da caravana
            printf("Preço a pagar: %.2f", criarLote[linha][coluna].preco);
        }
    }

    if(tolower(eletricidade='x')){
        if(tolower(criarLote[linha][coluna].tipoAlojamento=='a')){
            criarLote[linha][coluna].preco=(3.50*(criarLote[linha][coluna].numeroCampistas)) /*Preço por número de campistas*/ + 14.90; // Preço da autocaravana
            printf("Preço a pagar: %.2f", criarLote[linha][coluna].preco);
        }
    }
}

// Registar lote | linhasDoLote
void pedirCoordenadasLote(int *pedirLinha, int *pedirColuna, int linhasDoLote, int colunasDoLote){
    do{
        printf("Introduza a coluna onde se encontra o lote: ");
        scanf("%d", pedirColuna);

        if(*pedirColuna > colunasDoLote)
            printf("\n==ERRO! Número da coluna inserido excede o número máximo de colunas do mapa==\n");
        else if(*pedirColuna < 0)
            printf("\n==ERRO! Número da coluna inserido não pode ser menor que 0 ==\n");
        else if(*pedirColuna == 0)
            printf("\n==ERRO! Número da coluna não pode ser 0==\n");

    }while(*pedirColuna > colunasDoLote || *pedirColuna < 1);
    // PARA FAZER: Em vez de 5, deve ir buscar o valor das colunas no mapa dos lotes,
    //talvez numa struct propria para se poder mudar isso? mapaLote->Coluna?

    do{
        printf("\nIntroduza a linha onde se encontra o lote: ");
        scanf("%d", pedirLinha);

        if(*pedirLinha > linhasDoLote)
            printf("\n==ERRO! Número da linha inserido excede o número máximo de linhas do mapa==\n");
        else if(*pedirLinha < 0)
            printf("\n==ERRO! Número da linha inserido não pode ser menor que 0==\n");
        else if(*pedirLinha == 0)
            printf("\n==ERRO! Número da linha não pode ser 0==\n");

    }while(*pedirLinha > linhasDoLote || *pedirLinha < 1);
}
