/*
|| Projeto Gest�o de Reservas de Parque de Campismo
||============================================================================
|| Autores : +Rodrigo Nogueira - 200262002 - 200262002@estudantes.ips.pt
||           +Ricardo Reis     - 200262024 - 200262024@estudantes.ips.pt
||============================================================================
|| 2� Fase de Entrega
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campista.h"
#include "lotes.h"

campista criarCampista(char *nome, int idade){
    campista campista;
    strcpy(campista.nome, nome);
	campista.idade = idade;
    return campista;
}

void imprimirCampista(campista c){
    printf("Nome: %s\n", c.nome);
    printf("Idade: %d\n", c.idade);
}
