#include <stdio.h>
#include <stdlib.h>
#include "funções.h"


#define TAM 1024    // Tamanho do vetor
#define MAX_VAL 2048 // Valor máximo para os números aleatórios

int contagemTrocas = 0;      // Variável global para contar trocas
int contagemComparacoes = 0; // Variável global para contar comparações


/*===========================================================================================================*/


// Preenche um vetor de inteiros com valores aleatórios entre 0 e 2048
void geraVetor(int vetor[]) 
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % (MAX_VAL + 1); // Gera números aleatórios entre 0 e 2048
    }
}


/*===========================================================================================================*/



// Função para imprimir uma linha de separação
void linhaSeparacao() {
    printf("\n");
    printf("______________________________________________________________________________________");
    printf("\n");
    printf("\n");
}



/*===========================================================================================================*/




// Imprime um vetor de inteiros
void imprimeVetor(int vetor[], int n) 
{
    if (n > TAM)
        n = TAM;  // Limita a impressão ao tamanho máximo do vetor

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("\n");
}


/*===========================================================================================================*/

// Exibe o menu de opções
void menu() {
    printf("\n--- Menu de Opções ---\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}


/*===========================================================================================================*/


// Troca o conteúdo de duas variáveis
void trocar(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
    contagemTrocas++;
}


/*==========================================================================================================================*/


void exibirContagens(char *metodo) {
    printf("\n[%s] Contagem de trocas: %d\n", metodo, contagemTrocas);
    printf("[%s] Contagem de comparações: %d\n", metodo, contagemComparacoes);
}


/*================================================ [QUICK SORT] ===========================================================*/

//                                UTILIZANDO O ÚLTIMO ELEMENTO DO VETOR COMO PIVÔ


// Particiona o vetor de forma que os elementos menores que o pivô fiquem à esquerda e os maiores à direita
int particionarUltimo(int vetor[], int inicio, int fim) 
{
    int pivo = vetor[fim];  // Escolhe o último elemento como pivô
    int indiceMenor = inicio - 1;

    for (int i = inicio; i < fim; i++) 
    {   
        contagemComparacoes++;
        if (vetor[i] < pivo) {
            indiceMenor++;
            trocar(&vetor[indiceMenor], &vetor[i]);
        }
    }
    trocar(&vetor[indiceMenor + 1], &vetor[fim]);
    return indiceMenor + 1;
}


// Ordena o vetor utilizando o método quicksort com o último elemento como pivô
void quickSortUltimo(int vetor[], int inicio, int fim) 
{
    if (inicio < fim) {
        int indicePivo = particionarUltimo(vetor, inicio, fim);
        quickSortUltimo(vetor, inicio, indicePivo - 1);
        quickSortUltimo(vetor, indicePivo + 1, fim);
    }
}
/*===========================================================================================================*/
/*===========================================================================================================*/

//                              UTILIZANDO A MEDIANA DE TRÊS ELEMENTOS DO VETOR

// Escolhe o pivô como a mediana de três (primeiro, meio e último elementos)
int medianaDeTres(int vetor[], int inicio, int fim) 
{
    int meio = (inicio + fim) / 2;

    // Ordena inicio, meio e fim para obter a mediana
    if (vetor[inicio] > vetor[meio]) trocar(&vetor[inicio], &vetor[meio]);
    if (vetor[inicio] > vetor[fim]) trocar(&vetor[inicio], &vetor[fim]);
    if (vetor[meio] > vetor[fim]) trocar(&vetor[meio], &vetor[fim]);

    // Coloca a mediana no final, onde será usada como pivô
    trocar(&vetor[meio], &vetor[fim]);
    return vetor[fim];
}


//  Particiona o vetor de forma que os elementos menores que o pivô fiquem à esquerda e os maiores à direita
int particionarMedianaDeTres(int vetor[], int inicio, int fim) 
{
    int pivo = medianaDeTres(vetor, inicio, fim);  // Escolhe o pivô como a mediana de três
    int indiceMenor = inicio - 1;

    for (int i = inicio; i < fim; i++) 
    {
        contagemComparacoes++;
        if (vetor[i] < pivo) 
        {
            indiceMenor++;
            trocar(&vetor[indiceMenor], &vetor[i]);
        }
    }
    trocar(&vetor[indiceMenor + 1], &vetor[fim]);
    return indiceMenor + 1;
}


// Ordena o vetor utilizando o método quicksort com a mediana de três como pivô
void quickSortMedianaDeTres(int vetor[], int inicio, int fim) 
{
    if (inicio < fim) {
        int indicePivo = particionarMedianaDeTres(vetor, inicio, fim);
        quickSortMedianaDeTres(vetor, inicio, indicePivo - 1);
        quickSortMedianaDeTres(vetor, indicePivo + 1, fim);
    }
}



/*================================================ [SHELL SORT] ===========================================================*/


//                                      UTILIZANDO A SEQUÊNCIA DE KNUTH


//Ordena o vetor utilizando o método shellsort com a sequência de Knuth
void shellSortKnuth(int vetor[], int n) 
{
    int gap = 1;
    // Calcula o maior gap de Knuth que seja menor que o tamanho do vetor
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    for (; gap > 0; gap = (gap - 1) / 3) {
        // Ordenação com o gap atual
        for (int i = gap; i < n; i++) {
            int temp = vetor[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                contagemComparacoes++; // Incrementa a contagem de comparações
                if (vetor[j - gap] > temp) {
                    vetor[j] = vetor[j - gap];
                } else {
                    break; // Se não for maior, sai do loop
                }
            }
            if (j != i) { // Se houve troca
                vetor[j] = temp;
                contagemTrocas++; // Incrementa a contagem de trocas
            }
        }
    }
}


/*===========================================================================================================*/


//                                      UTILIZANDO A SEQUÊNCIA DE HIBBARD


// Ordena o vetor utilizando o método shellsort com a sequência de Hibbard
void shellSortHibbard(int vetor[], int n) 
{
    int k = 1;
    // Calcula o maior gap de Hibbard que seja menor que o tamanho do vetor
    while ((1 << k) - 1 < n) {
        k++;
    }
    k--;

    for (int gap = (1 << k) - 1; gap > 0; k--, gap = (1 << k) - 1) {
        // Ordenação com o gap atual
        for (int i = gap; i < n; i++) {
            int temp = vetor[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                contagemComparacoes++; // Incrementa a contagem de comparações
                if (vetor[j - gap] > temp) {
                    vetor[j] = vetor[j - gap];
                } else {
                    break; // Se não for maior, sai do loop
                }
            }
            vetor[j] = temp; // Move o elemento para a posição correta
            contagemTrocas++; // Incrementa a contagem de trocas
        }
    }
}



/*===========================================================================================================*/


//                                      UTILIZANDO O SELECTION SORT


// Ordena o vetor utilizando o método Selection Sort
void selectionSort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;  // Assume que o primeiro elemento não ordenado é o menor
        for (int j = i + 1; j < n; j++) {
            contagemComparacoes++;  // Incrementa a contagem de comparações
            // Atualiza o índice do menor elemento encontrado
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (indiceMenor != i) {
            trocar(&vetor[i], &vetor[indiceMenor]);  // Chama a função de troca
        }
    }
}



/*====================================== [ALGORITMOS DE PESQUISA] =================================================*/


//                                    ALGORITMO DE BUSCA SEQUENCIAL


// Função para buscar um elemento sequencialmente no vetor e contar as comparações
int buscaSequencial(int vetor[], int tamanho, int elemento, int *contagemComparacoes) {
    *contagemComparacoes = 0; // Zera a contagem no início da busca

    for (int i = 0; i < tamanho; i++) {
        (*contagemComparacoes)++; // Incrementa a contagem a cada comparação
        if (vetor[i] == elemento) {
            return i; // Retorna o índice onde o elemento foi encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}



// Escolhe entre um número digitado pelo usuário ou gerado aleatoriamente para busca
void realizarBuscaSequencial(int vetor[], int tamanho) {
    int opcao, elemento, posicao;
    int comparacoes;

    // Pergunta ao usuário se ele quer inserir um valor ou gerar um número aleatório
    do {
        printf("Escolha uma opção:\n");
        printf("1. Digitar um número para buscar\n");
        printf("2. Gerar um número aleatório para buscar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao != 1 && opcao != 2) {
            printf("Opção inválida! Por favor, escolha 1 ou 2.\n");
        }
    } while (opcao != 1 && opcao != 2);

    if (opcao == 1) {
        printf("Digite o número a ser buscado: ");
        scanf("%d", &elemento);
    } else {
        elemento = rand() % (MAX_VAL + 1); // Gera número aleatório entre 0 e MAX_VAL
        printf("Número gerado aleatoriamente para busca: %d\n", elemento);
    }

    // Realiza a busca sequencial no vetor original
    posicao = buscaSequencial(vetor, tamanho, elemento, &comparacoes);

    // Exibe o resultado da busca
    if (posicao != -1) {
        printf("Elemento %d encontrado na posição %d após %d comparações.\n", elemento, posicao, comparacoes);
    } else {
        printf("Elemento %d não encontrado no vetor após %d comparações.\n", elemento, comparacoes);
    }
}



/*===========================================================================================================*/


//                                       ALGORITMO DE BUSCA BINÁRIA


// Função de busca binária no vetor ordenado
int buscaBinaria(int vetor[], int tamanho, int elemento, int *contagemComparacoes) {
    int inicio = 0, fim = tamanho - 1;
    *contagemComparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*contagemComparacoes)++;

        if (vetor[meio] == elemento) {
            return meio;  // Retorna o índice onde o elemento foi encontrado
        }
        else if (vetor[meio] < elemento) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;  // Retorna -1 se o elemento não for encontrado
}

// Função para permitir consulta de elemento no vetor, com entrada ou número aleatório
void realizarBuscaBinaria(int vetor[], int tamanho) {
    int elemento, contagemComparacoes = 0, opcao;

    // Loop para garantir que o usuário escolha uma opção válida
    do {
        printf("Escolha uma opção para a busca binária:\n");
        printf("1 - Digitar o elemento a ser buscado\n");
        printf("2 - Gerar aleatoriamente o elemento a ser buscado\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao != 1 && opcao != 2) {
            printf("Opção inválida! Por favor, escolha 1 ou 2.\n");
        }
    } while (opcao != 1 && opcao != 2);

    if (opcao == 1) {
        printf("Digite o elemento a ser buscado: ");
        scanf("%d", &elemento);
    } else {
        elemento = rand() % (MAX_VAL + 1); // Gera número aleatório entre 0 e MAX_VAL
        printf("Elemento gerado aleatoriamente: %d\n", elemento);
    }

    // Realiza a busca binária no vetor ordenado
    int posicao = buscaBinaria(vetor, tamanho, elemento, &contagemComparacoes);

    // Exibe o resultado da busca
    if (posicao != -1) {
        printf("Elemento encontrado na posição: %d\n", posicao);
    } else {
        printf("Elemento não encontrado no vetor.\n");
    }
    printf("Número de comparações realizadas: %d\n", contagemComparacoes);
}


/*===========================================================================================================*/