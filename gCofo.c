// TAD Generico 'Garotas'
// Trabalho de Estrutura de Dados 2023.2
// Feito por Rôberth Kaua
// Programa criado e executado no IDE 'Replit'
// link: https://replit.com/@ROBERTHKAUA/TAD-Generico-Roberth-Kaua

#ifndef GCOFO_C
#define GCOFO_C

#include "gCofo.h"
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------------------------------------

struct garota {
  char *nome;
  int ano;
  float intensidade;
};

//--------------------------------------------------------------------------------

struct desilusoes {
  int quant_max;
  int quant_atual;
  void **garotas;
};

//--------------------------------------------------------------------------------

Desilusoes *criarGCofo(int n) {
  Desilusoes *cofo;
  if(n>0) {
    cofo = (Desilusoes*) malloc(sizeof(Desilusoes));
    if(cofo != NULL) {
      cofo->garotas = (void**) malloc (sizeof(void*) * n);
      if(cofo->garotas != NULL) {
        cofo->quant_atual = 0;
        cofo->quant_max = n;
        return cofo;
      }
      free(cofo);
    }
  }
  return NULL;
}

//--------------------------------------------------------------------------------

Garota *criarGarota(int ano, float intensidade) {
  Garota *grt = (Garota*)malloc(sizeof(Garota));
    if (grt != NULL) {
      grt->ano = ano;
      grt->intensidade = intensidade;
      grt->nome = (char*)malloc(sizeof(char) * 20);
      if (grt->nome != NULL) {
        return grt;
      }
      free(grt);
    }
  return NULL;
}

//--------------------------------------------------------------------------------

int inserirNome(Garota *garota, int i, char letra) {
  if (garota != NULL) {
    garota->nome[i] = letra;
    return TRUE;
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int inserirNoGCofo(Desilusoes *cofo, void *garota) {
  if(cofo != NULL) {
    if(cofo->quant_atual < cofo->quant_max) {
      cofo->garotas[cofo->quant_atual] = garota;
      cofo->quant_atual++;
      return TRUE;
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int removerGarota(Desilusoes *cofo, char *nome, int ano, float intensidade, int escolha) {
  if(cofo != NULL) {
    if(cofo->quant_atual > 0) {
      if(escolha == 1) {
        if(nome != NULL) {
          for (int i = 0; i < cofo->quant_atual; i++) {
            Garota *aux = cofo->garotas[i];
            if (strcmp(aux->nome, nome) == 0) {
              if(cofo->quant_atual > 1 && i != cofo->quant_atual - 1) {
                for (int j = i; j < (cofo->quant_atual - 1); j++) {
                  cofo->garotas[j] = cofo->garotas[j + 1];
                }
              }
              cofo->quant_atual--;
              if(destruirGarota(aux) == TRUE) {
                return TRUE;
              }
            }
          }
        }
      }
      else if(escolha == 2) {
        for (int i = 0; i < cofo->quant_atual; i++) {
          Garota *aux = cofo->garotas[i];
          if (aux->ano == ano) {
            if(cofo->quant_atual > 1 && i != cofo->quant_atual - 1) {
              for (int j = i; j < (cofo->quant_atual - 1); j++) {
                cofo->garotas[j] = cofo->garotas[j + 1];
              }
            }
            cofo->quant_atual--;
            if(destruirGarota(aux) == TRUE) {
              return TRUE;
            }
          }
        }
      }
      else if(escolha == 3) {
        for (int i = 0; i < cofo->quant_atual; i++) {
          Garota *aux = cofo->garotas[i];
          if (aux->intensidade == intensidade) {
            if(cofo->quant_atual > 1 && i != cofo->quant_atual - 1) {
              for (int j = i; j < (cofo->quant_atual - 1); j++) {
                cofo->garotas[j] = cofo->garotas[j + 1];
              }
            }
            cofo->quant_atual--;
            if(destruirGarota(aux) == TRUE) {
              return TRUE;
            }
          }
        }
      }
    }
  }
  return -1;
}

//--------------------------------------------------------------------------------

int esvaziaTudo(Desilusoes *cofo) {
  if(cofo->quant_atual > 0) {
    for (int i = 0; i < cofo->quant_atual; i++) {
      if(destruirGarota(cofo->garotas[i]) == FALSE) {
        return FALSE;
      }
    }
    cofo->quant_atual = 0;
    return TRUE;
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int destruirGarota(Garota *garota) {
  if(garota != NULL) {
    free(garota->nome);
    free(garota);
    return TRUE;
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int consultarGarota(Desilusoes *cofo, char *nome, int ano, float intensidade, int escolha) {
  if(cofo != NULL) {
    if(escolha == 1) {
      if(nome != NULL) {
        for (int i = 0; i < cofo->quant_atual; i++) {
          Garota *aux = cofo->garotas[i];
          if (strcmp(aux->nome, nome) == 0) {
            return i;
          }
        }
      }
    }
    else if(escolha == 2) {
      for (int i = 0; i < cofo->quant_atual; i++) {
        Garota *aux = cofo->garotas[i];
        if (aux->ano == ano) {
          return i;
        }
      }
    }
    else if(escolha == 3) {
      for (int i = 0; i < cofo->quant_atual; i++) {
        Garota *aux = cofo->garotas[i];
        if (aux->intensidade == intensidade) {
          return i;
        }
      }
    }
  }
  return -1;
}

//--------------------------------------------------------------------------------

char imprimeNome(Desilusoes *cofo, int i, int j) {

  if (cofo != NULL) {
    if (i >= 0) {
      Garota *aux = cofo->garotas[i];
      return aux->nome[j];
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int tamanhoNome(Desilusoes *cofo, int i) {

  if (cofo != NULL) {
    if (i >= 0) {
      Garota *aux = cofo->garotas[i];
      return strlen(aux->nome);
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int imprimeAno(Desilusoes *cofo, int i) {

  if (cofo != NULL) {
    if (i >= 0) {
      Garota *aux = cofo->garotas[i];
      return aux->ano;
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

float imprimeIntensidade(Desilusoes *cofo, int i) {

  if (cofo != NULL) {
    if (i >= 0) {
      Garota *aux = cofo->garotas[i];
      return aux->intensidade;
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

int destruirGCofo (Desilusoes *cofo) {
  if(cofo != NULL) {
    if(cofo->quant_atual == 0) {
      free(cofo->garotas);
      free(cofo);
      return TRUE;
    }
    return -1;
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

#endif

//--------------------------------------------------------------------------------