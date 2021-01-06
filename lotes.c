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
#include "campista.h"
#include "lotes.h"

void pedirCoordenadasLote(int *linha, int *coluna){
    printf("Introduza a coluna: ");
    scanf("%d", linha);

    printf("\nIntroduza a linha onde se encontra o lote: ");
    scanf("%d", coluna);
    fflush(stdin);

}

void pedirDadosLotes(lote *reservaLote){
    char eletricidade;

    do{
        printf("Tipo de alojamento [Tenda (T) // Caravana (C) // Autocaravana (A)]: ");
        scanf("%c", &reservaLote->tipoAlojamento);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 't': case 'c': case 'a':
                break;

            default:
                printf("==ERRO! Caractér inválido!==\n");
        }

    }while(tolower(reservaLote->tipoAlojamento) !='t' && tolower(reservaLote->tipoAlojamento) !='c' && tolower(reservaLote->tipoAlojamento) !='a');

    do{
        printf("Tem ligação à rede eletrica(S/N): ");
        scanf("%c", &eletricidade/*reservaLote->redeEletrica*/);
        fflush(stdin);

        switch(tolower(eletricidade)){
            case 's':
                reservaLote->redeEletrica='e';
                break;

            case 'n':
                reservaLote->redeEletrica ='x';
                break;

            default:
                printf("==ERRO! Caractér inválido!==\n");        }

    }while(tolower(eletricidade) !='s' && tolower(eletricidade) !='n');

//    printf("===== Dados dos campistas =====");
//    printf("Nome do campista: ");
//    gets(reservaLote->pessoaCampista.nome);
//    printf("Idade do campista :");
//    scanf("%d", &reservaLote->pessoaCampista.idade);
}
