#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

typedef struct{
    int linha;
    int coluna;
} mapa;

void definirDimensoesLote(int *linha, int *coluna);
void apresentarMapa(int linha, int coluna);


#endif // MAPA_H_INCLUDED
