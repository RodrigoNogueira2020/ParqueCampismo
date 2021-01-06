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
#define

typedef struct{
    char tipoAlojamento; // T - tenda, C - caravana ou A - autocaravana
    char redeEletrica; // e - Se tem rede eletrica, x - Se não tem rede eletrica
} reserva;

typedef struct{
    char tipoAlojamento; // T - tenda, C - caravana ou A - autocaravana
    char redeEletrica; // e - Se tem rede eletrica, x - Se não tem rede eletrica
} lote;

#endif // LOTES_H_INCLUDED
