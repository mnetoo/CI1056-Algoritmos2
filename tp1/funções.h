#ifndef FUNCOES_H
#define FUNCOES_H


#include <stdio.h>
#include <stdlib.h>


#define TAM 1024    // Tamanho do vetor
#define MAX_VAL 2048 // Valor máximo para os números aleatórios


extern int contagemTrocas;      // Variáveis globais
extern int contagemComparacoes;

/*================================================================================================================*/


// Função que preenche um vetor de inteiros com valores aleatórios entre 0 e 2048
void geraVetor(int vetor[]);

// Função que exibe o menu de opções
void menu();

// Função que imprime um vetor de inteiros
void imprimeVetor(int vetor[], int n);

// Função que troca o conteúdo de duas variáveis
void trocar(int *a, int *b);


/*================================================================================================================*/


                    /* QUICK SORT UTILIZANDO O ÚLTIMO ELEMENTO DO VETOR COMO PIVÔ */


int particionarUltimo(int vetor[], int inicio, int fim);

void quickSortUltimo(int vetor[], int inicio, int fim);


/*================================================================================================================*/


                    /* QUICK SORT UTILIZANDO A MEDIANA DE TRÊS ELEMENTOS DO VETOR */

int particionarMedianaDeTres(int vetor[], int inicio, int fim);

int medianaDeTres(int vetor[], int inicio, int fim);

void quickSortMedianaDeTres(int vetor[], int inicio, int fim);


/*================================================================================================================*/


                    /* SHELL SORT UTILIZANDO A SEQUÊNCIA DE HIBBARD */ 

void shellSortHibbard(int vetor[], int n);


/*================================================================================================================*/


                    /* SHELL SORT UTILIZANDO A SEQUÊNCIA DE KNUTH */

void shellSortKnuth(int vetor[], int n);


/*================================================================================================================*/

#endif