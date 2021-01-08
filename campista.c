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

campista criarCampista(char *nome, int idade){
    campista campista;
    strcpy(campista.nome, nome);
	campista.idade = idade;
    return campista;
}

//void imprimirDadosCampista(Campista criarCampista){
//    printf("Nome: %s\n", criarCampista.nome);
//    printf("Idade: %d\n", criarCampista.idade);
//}
