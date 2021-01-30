/*
|| Projeto Gestão de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 1ª Fase de Entrega
*/
#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED
#include "campista.h"
#include "mapa.h"
#include "menu.h"
#define MAX_LINHAS 15
#define MAX_COLUNAS 15

typedef struct{
    campista pessoaCampista[6];
    char tipoAlojamento;   // T - tenda, C - caravana ou A - autocaravana
    char redeEletrica;    // e - Se tem rede eletrica, x - Se não tem rede eletrica
    int numeroCampistas; // Número de campistas por lote
    float preco;

    int coordenadasLin;
    int coordenadasCol;

    /*
     * Tenda - 4,50€
     * Caravana - 6,00€
     * Autocaravana - 14,90€
     * Eletricidade - 3,00€
     * Campista - 3,50€
     */
}lote;

typedef struct{
    lote reservaAtual;
    lote ultimasReservas[3];
}reserva;

reserva criarLote[MAX_LINHAS][MAX_COLUNAS];
/*
    imprimir reserva(reserva r);
    char getTipoAlojamento(reserva r);
    char get eletricidade(reserva r);
*/

/*Para definir as dimensões do lote*/
void pedirCoordenadasLote(int *pedirLinha, int *pedirColuna);

//reserva criarLote(campista pessoaCampista[], char tipoAlojamento, char redeEletrica, int numeroCampistas, float preco, int coordenadasLin, int coordenadasCol);

/*Para definir as dimensões do lote*/
void pedirDadosLotes(int linha, int coluna);

/*float calcularTarifa() -> Em recurso, calcula baseado nos dias tambem*/
void escreverDadosFicheirosLotes();
void lerDadosFicheiroLotes();


#endif // LOTES_H_INCLUDED
