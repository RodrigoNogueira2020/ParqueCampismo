#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

typedef struct{
    int linha;
    int coluna;
} mapa;
mapa Mapa;

void definirDimensoesLote(int *linha, int *coluna);
void apresentarMapa(int linha, int coluna);

void loteInfoMapa(int linha, int coluna);

#endif // MAPA_H_INCLUDED
