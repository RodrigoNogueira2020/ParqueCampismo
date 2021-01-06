/*
|| Projeto Gestão de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1ª Fase de Entrega
*/
#include "campista.h"
#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED

typedef struct{
    campista pessoaCampista;
    char tipoAlojamento; // T - tenda, C - caravana ou A - autocaravana
    char redeEletrica; // e - Se tem rede eletrica, x - Se não tem rede eletrica
    float preco;
    /* Tenda - 4,50€
     * Caravana - 6,00€
     * Autocaravana - 14,90€
     * Eletricidade - 3,00€
     * Campista - 3,50€
     */
} lote;

void pedirCoordenadasLote(int *linha, int *coluna);
void pedirDadosLotes(lote *reservaLote);

#endif // LOTES_H_INCLUDED
