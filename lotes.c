/*
|| Projeto Gestão de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1ª Fase de Entrega
*/

#include "campista.h"
#include "lotes.h"
#include <ctype.h>

void pedirDadosLotes(lote *reservaLote){
    char eletricidade;

    do{
        printf("Tipo de alojamento [Tenda (T) // Caravana (C) // Autocaravana (A)]: ");
        scanf("%c", &reservaLote->tipoAlojamento);
        fflush(stdin);
        if(tolower(reservaLote->tipoAlojamento!='t') || tolower(reservaLote->tipoAlojamento!='c' tolower(reservaLote->tipoAlojamento!='a'))){
            printf("ERRO! Caractér inválido!");
        }
    }while(tolower(reservaLote->tipoAlojamento!='t') || tolower(reservaLote->tipoAlojamento!='c' tolower(reservaLote->tipoAlojamento!='a')));

    do{
        printf("Tem ligação à rede eletrica(S/N): ");
        scanf("%c", &eletricidade/*reservaLote->redeEletrica*/);
        fflush(stdin);

        if(tolower(eletricidade=='s')){
            &reservaLote->redeEletrica='e';
        }else if(tolower(eletricidade=='n')){
            &reservaLote->redeEletrica='x';
        }else{
            printf("ERRO! Caractér inválido!");
        }

    }while(tolower(eletricidade!='s') || tolower(eletricidade!='n'));

    printf("===== Dados dos campistas =====");
    printf("Nome do campista: ");
    gets(reservaLote->pessoaCampista.nome);
    printf("Idade do campista :");
    gets(reservaLote->pessoaCampista.idade);
}


