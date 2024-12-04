// TAD Generico 'Garotas'
// Trabalho de Estrutura de Dados 2023.2
// Feito por Rôberth Kaua
// Programa criado e executado no IDE 'Replit'
// link: https://replit.com/@ROBERTHKAUA/TAD-Generico-Roberth-Kaua


#define TRUE 1
#define FALSE 0
#ifndef GCOFO_H
#define GCOFO_H

typedef struct garota Garota;
typedef struct desilusoes Desilusoes;

Desilusoes *criarGCofo(int n);
Garota *criarGarota(int ano, float intensidade);

int inserirNoGCofo(Desilusoes *cofo, void *garota);
int inserirNome(Garota *garota, int i, char letra);

int removerGarota(Desilusoes *cofo, char *nome, int ano, float intensidade, int escolha);
int destruirGarota(Garota *garota);

int consultarGarota(Desilusoes *cofo, char *nome, int ano, float intensidade, int escolha);

char imprimeNome(Desilusoes *cofo, int i, int j);
int imprimeAno(Desilusoes *cofo, int i);
float imprimeIntensidade(Desilusoes *cofo, int i);
int tamanhoNome(Desilusoes *cofo, int i);

int esvaziaTudo(Desilusoes *cofo);
int destruirGCofo (Desilusoes *cofo);

#endif