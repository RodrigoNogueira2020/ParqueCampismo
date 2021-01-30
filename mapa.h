#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#define MAX_LINHAS 15
#define MAX_COLUNAS 15
typedef struct{
    int linha;
    int coluna;
} mapa;
mapa Mapa;

typedef struct{
  struct reserva *r;
}reservaMapa;

void definirDimensoesLote(int *linha, int *coluna);
void apresentarMapa(int linha, int coluna);

void loteInfoMapa(int linha, int coluna, char* infoMapa);

#endif // MAPA_H_INCLUDED
