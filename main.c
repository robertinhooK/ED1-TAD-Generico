// TAD Generico 'Garotas'
// Trabalho de Estrutura de Dados 2023.2
// Feito por Rôberth Kaua
// Programa criado e executado no IDE 'Replit'
// link: https://replit.com/@ROBERTHKAUA/TAD-Generico-Roberth-Kaua

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gCofo.h"

int main(void) {

  int escolha, escolha2;
  int num_garotas, num_garotas_now = 0;
  int cofoCriado = FALSE;

  char nome[20];
  int ano;
  float intensidade;

  Desilusoes *cofo = NULL;
  Garota *grta = NULL;

  do {

  // limpa a tela
  printf("\033[H\033[J");

  // menu
  printf("\nOla! Escolha uma das opcoes abaixo:\n\n");

  printf("1. Criar uma colecao de Desilusoes\n");
  printf("2. Inserir uma garota na colecao\n");
  printf("3. Remover uma garota da colecao\n");
  printf("4. Consultar uma garota na colecao\n");
  printf("5. Listar as garotas da colecao\n");
  printf("6. Esvaziar a colecao\n");
  printf("7. Destruir a colecao\n");
  printf("0. Sair\n");

  printf("\nSua escolha: ");
  scanf("%d", &escolha);

  switch (escolha) {

//-------------------------------------------------------------------------------

  case 1:
    if(cofoCriado != TRUE) {
      printf("\nCerto! Agora informe quantas garotas pretende inserir na colecao: ");
      scanf("%d", &num_garotas);
      cofo = criarGCofo(num_garotas);
      if (cofo != NULL) {
        cofoCriado = TRUE;
        printf("\ncolecao de Desilusoes criada!\n");
      }
      else {
        printf("\nErro ao criar a colecao!\n");
      }
    }
    else {
      printf("\nA colecao de Desilusoes já foi criada!\n");
    }
    break;

//-------------------------------------------------------------------------------

  case 2:

    if(cofoCriado == TRUE) {
      if(num_garotas_now < num_garotas) {
        printf("\nCerto! Agora informe:\n");
        printf("\nO nome dela: ");
        scanf("%s", nome);
        printf("O ano em que aconteceu: ");
        scanf("%d", &ano);
        printf("A intensidade da desilusao: ");
        scanf("%f", &intensidade);

        grta = criarGarota(ano, intensidade);

        for(int i = 0; i < strlen(nome); i++) {
          inserirNome(grta, i, nome[i]); 
        }

        if(inserirNoGCofo(cofo, grta) == TRUE) {
          printf("\nGarota inserida!\n");
          num_garotas_now++;
        }
        else {
          printf("\nErro! A garota nao foi inserida!\n");
        }
      }
      else {
        printf("\nA colecao esta cheia!\n");
      }
    }
    else {
      printf("\nCrie primeiro a colecao de Desilusoes!\n");
    }
    break;

//-------------------------------------------------------------------------------

  case 3:

    if(cofoCriado == TRUE) {
      if(num_garotas_now > 0) {
        printf("\nCerto! Agora informe pelo que deseja consultar a garota:\n");
        printf("\n1. Pelo nome");
        printf("\n2. Pelo ano");
        printf("\n3. Pela intensidade");

        printf("\n\nSua escolha: ");
        scanf("%d", &escolha2);

        if(escolha2 == 1) {
          printf("\nOk! Agora informe o nome da garota: ");
          scanf("%s", nome);
        }
        else if(escolha2 == 2) {
          printf("\nOk! Agora informe o ano da desilusao dela: ");
          scanf("%d", &ano);
        }
        else if(escolha2 == 3) {
          printf("\nOk! Agora informe a intensidade da desilusao: ");
          scanf("%f", &intensidade);
        }
        else {
          printf("\nOpcao invalida...");
          break;
        }

        int posicao = consultarGarota(cofo, nome, ano, intensidade, escolha2);
        if(posicao != -1) {
          printf("\nEssa garota esta presente na colecao!\n");
          printf("\nNome: ");
          for(int i = 0; i < tamanhoNome(cofo, posicao); i++) {
            printf("%c", imprimeNome(cofo, posicao, i));
          }
          printf("\nAno do ocorrido: %d", imprimeAno(cofo, posicao));
          printf("\nIntensidade da desilusao: %.2f\n", imprimeIntensidade(cofo, posicao));

          if(removerGarota(cofo, nome, ano, intensidade, escolha2) == TRUE) {
            printf("\nA garota foi removida da colecao!\n");
            num_garotas_now--;
          }
          else {
            printf("\nEssa garota nao esta na colecao!\n");
          }
        }
        else {
          printf("\nEssa garota nao esta na colecao!\n");
        }
      }
      else {
        printf("\nA colecao nao possui nenhuma garota para ser removida!\n");
      }
    }
    else {
      printf("\nCrie primeiro a colecao de Desilusoes!\n");
    }
    break;

//-------------------------------------------------------------------------------

  case 4:
    if(cofoCriado == TRUE) {
      if(num_garotas_now > 0) {
        printf("\nCerto! Agora informe pelo que deseja consultar a garota:\n");
        printf("\n1. Pelo nome");
        printf("\n2. Pelo ano");
        printf("\n3. Pela intensidade");

        printf("\n\nSua escolha: ");
        scanf("%d", &escolha2);

        if(escolha2 == 1) {
          printf("\nOk! Agora informe o nome da garota: ");
          scanf("%s", nome);
        }
        else if(escolha2 == 2) {
          printf("\nOk! Agora informe o ano da desilusao dela: ");
          scanf("%d", &ano);
        }
        else if(escolha2 == 3) {
          printf("\nOk! Agora informe a intensidade da desilusao: ");
          scanf("%f", &intensidade);
        }
        else {
          printf("\nOpcao invalida...");
          break;
        }

        int posicao = consultarGarota(cofo, nome, ano, intensidade, escolha2);
        if(posicao != -1) {
          printf("\nEssa garota esta presente na colecao!\n");
          printf("\nNome: ");
          for(int i = 0; i < tamanhoNome(cofo, posicao); i++) {
            printf("%c", imprimeNome(cofo, posicao, i));
          }
          printf("\nAno do ocorrido: %d", imprimeAno(cofo, posicao));
          printf("\nIntensidade da desilusao: %.2f\n", imprimeIntensidade(cofo, posicao));
        }
        else {
          printf("\nEssa garota nao esta na colecao!\n");
        }
      }
      else {
        printf("\nA colecao nao possui nenhuma garota para ser consultada!\n");
      }
    }
    else {
      printf("\nCrie primeiro a colecao de Desilusoes!\n");
    }
    break;

//-------------------------------------------------------------------------------

  case 5:

    if (cofoCriado == TRUE) {
      if(num_garotas_now > 0) {
        for(int i = 0; i < num_garotas_now; i++) {
          printf("\nGarota %d:", i+1);
          printf("\nNome: ");
          for(int j = 0; j < tamanhoNome(cofo, i); j++) {
            printf("%c", imprimeNome(cofo, i, j));
          }
          printf("\nAno do ocorrido: %d", imprimeAno(cofo, i));
          printf("\nIntensidade da desilusao: %.2f\n", imprimeIntensidade(cofo, i));
        }
      }
      else {
        printf("\nA colecao nao possui nenhuma garota ainda!\n");
      }
    }
    else {
      printf("\nCrie primeiro a colecao de Desilusoes!\n");
    }
    break;

//-------------------------------------------------------------------------------

  case 6:

    if(cofoCriado == TRUE) {
      if(num_garotas_now > 0) {
        if(esvaziaTudo(cofo) == TRUE) {
          printf("\nCerto! colecao esvaziada!\n");
          num_garotas_now = 0;
        }
      }
      else {
        printf("\nA colecao ja esta vazia!\n");
      }
    }
    else {
      printf("\nCrie primeiro a colecao de Desilusoes!\n");
    }
    break;

//-------------------------------------------------------------------------------

  case 7:
    if(cofoCriado == TRUE) {
      if(destruirGCofo(cofo) == TRUE) {
        printf("\nA colecao de Desilusoes foi destruida!\n");
        cofoCriado = FALSE;
      }
      else if(destruirGCofo(cofo) == -1) {
        printf("\nA colecao de Desilusoes precisa estar vazia!\n");
      }
    }
    else {
      printf("\nA colecao de Desilusoes nem existe ainda!\n");
    }
    break;

//-------------------------------------------------------------------------------    

  case 0:
    printf("\nSaindo do programa... Adeus!\n");
    if(cofoCriado == TRUE) {
      esvaziaTudo(cofo);
      destruirGCofo(cofo);
    }
    break;

//-------------------------------------------------------------------------------

  default:
    printf("\nOpcao invalida... Tente novamente!\n");
    break;

//-------------------------------------------------------------------------------
  }

  printf("\nPressione Enter para continuar...");
  getchar(); // Captura o Enter anterior
  getchar(); // Aguarda o Enter do usuário

  } while (escolha != 0); // Repete até a opcao 'sair' ser escolhida

  return 0;
}