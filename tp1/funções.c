#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "funções.h" 



/*===========================================================================================================*/


// Preenche um vetor de inteiros com valores aleatórios entre 0 e 2048
void geraVetor(int vetor[]) 
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % (MAX_VAL + 1); // Gera números aleatórios entre 0 e 2048
    }
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


// Função auxiliar para calcular a média
double calcularMedia(int valores[], int numExecucoes) {
    int soma = 0;
    for (int i = 0; i < numExecucoes; i++) {
        soma += valores[i];
    }
    return (double)soma / numExecucoes;
}


// Função auxiliar para calcular o desvio padrão
double calcularDesvioPadrao(int valores[], int numExecucoes, double media) {
    double somaDesvios = 0;
    for (int i = 0; i < numExecucoes; i++) {
        somaDesvios += pow(valores[i] - media, 2);
    }
    return sqrt(somaDesvios / numExecucoes);
}


// Função auxiliar para calcular o total de comparações
int calcularTotalComparacoes(int valores[], int numExecucoes) {
    int total = 0;
    for (int i = 0; i < numExecucoes; i++) {
        total += valores[i];
    }
    return total;
}



/*===========================================================================================================*/


//                                              MENU INTERATIVO


// Função para exibir o menu e retornar a opção escolhida
int menu() 
{
    int opcao;
    static bool primeiraExecucao = true;


    if (primeiraExecucao) 
    {
        printf("\n");
        printf("                                    Bem-vindo ao Trabalho Prático da disciplina de Algoritmos II!\n");
        printf("                                    Aqui você verá a implementação de algoritmos de ordenação e busca.\n");
        printf("\n");
        printf("Selecione a operação desejada:\n");
        printf("\n");
        primeiraExecucao = false;
    }

    printf("\n");
    printf("0. Sair\n");
    printf("1. Gerar Vetor\n");
    printf("2. QuickSort - Pivô Último\n");
    printf("3. QuickSort - Pivô Mediana de Três\n");
    printf("4. ShellSort - Sequência de Knuth\n");
    printf("5. ShellSort - Sequência de Hibbard\n");
    printf("6. SelectionSort - Quadrático\n");
    printf("7. Busca Sequencial\n");
    printf("8. Busca Binária\n");
    printf("9. Executar todos os algoritmos 1000 vezes\n");
    printf("\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    return opcao;
}



// Função para executar a operação com base na opção escolhida
void program(int opcao) 
{
    switch (opcao) 
    {
        case 0:
            printf("Saindo do programa...\n");
            break;


        case 1:
            int v[TAM];
            int v1[TAM];

            printf("Vetor gerado com sucesso...\n");
            geraVetor(v);

            for(int i = 0; i < TAM; i++)
                v1[i] = v[i];

            printf("Digite o tamanho do vetor que deseja visualizar: ");
            int tamanho;
            scanf("%d", &tamanho);
            imprimeVetor(v, tamanho);
            break;

        case 2:
            int escolha;
            
            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v);
                printf("\n");
                printf("Deseja visualizar o vetor gerado? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v, tamanho);
                }
            }
            else
                geraVetor(v);

            printf("\n");
            printf("Executando QuickSort com Pivô Último...\n");
            quickSortUltimo(v, 0, TAM - 1);
            exibirContagens("QuickSort - Pivô Último");

            printf("\n");
            printf("Deseja imprimir o vetor ordenado? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                printf("\n");
                printf("Digite o tamanho do vetor que deseja visualizar: ");
                int tamanho;
                scanf("%d", &tamanho);
                imprimeVetor(v, tamanho);
            }

            break;


        case 3:
            contagemComparacoes = 0;
            contagemTrocas = 0;

            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v);
                printf("\n");
                printf("Deseja visualizar o vetor gerado? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v, tamanho);
                }
            }
            else
                geraVetor(v);

            printf("\n");
            printf("Executando QuickSort com Mediana de Três...\n");
            quickSortMedianaDeTres(v, 0, TAM - 1);
            exibirContagens("QuickSort - Pivô Mediana de Três");

            printf("\n");
            printf("Deseja imprimir o vetor ordenado? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                printf("\n");
                printf("Digite o tamanho do vetor que deseja visualizar: ");
                int tamanho;
                scanf("%d", &tamanho);
                imprimeVetor(v, tamanho);
            }

            break;


        case 4:
            contagemComparacoes = 0;
            contagemTrocas = 0;

            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v);
                printf("\n");
                printf("Deseja visualizar o vetor gerado? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v, tamanho);
                }
            }
            else
                geraVetor(v);

            printf("\n");
            printf("Executando ShellSort com Sequência de Knuth...\n");
            shellSortKnuth(v, TAM);
            exibirContagens("ShellSort - Sequência de Knuth");

            printf("\n");
            printf("Deseja imprimir o vetor ordenado? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                printf("\n");
                printf("Digite o tamanho do vetor que deseja visualizar: ");
                int tamanho;
                scanf("%d", &tamanho);
                imprimeVetor(v, tamanho);
            }

            break;


        case 5:
            contagemComparacoes = 0;
            contagemTrocas = 0;

            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v);
                printf("\n");
                printf("Deseja visualizar o vetor gerado? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v, tamanho);
                }
            }
            else
                geraVetor(v);

            printf("\n");
            printf("Executando ShellSort com Sequência de Hibbard...\n");
            shellSortHibbard(v, TAM);
            exibirContagens("ShellSort - Sequência de Hibbard");

            printf("\n");
            printf("Deseja imprimir o vetor ordenado? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                printf("\n");
                printf("Digite o tamanho do vetor que deseja visualizar: ");
                int tamanho;
                scanf("%d", &tamanho);
                imprimeVetor(v, tamanho);
            }

            break;


        case 6:
            contagemComparacoes = 0;
            contagemTrocas = 0;

            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v);
                printf("\n");
                printf("Deseja visualizar o vetor gerado? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v, tamanho);
                }
            }
            else
                geraVetor(v);

            printf("\n");
            printf("Executando SelectionSort...\n");
            selectionSort(v, TAM);
            exibirContagens("SelectionSort");

            printf("\n");
            printf("Deseja imprimir o vetor ordenado? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                printf("\n");
                printf("Digite o tamanho do vetor que deseja visualizar: ");
                int tamanho;
                scanf("%d", &tamanho);
                imprimeVetor(v, tamanho);
            }

            break;


        case 7:
            contagemComparacoes = 0;

            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v1);
                printf("\n");
                printf("Deseja visualizar o vetor gerado? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v1, tamanho);
                }
            }
            else
                geraVetor(v1);

            printf("\n");
            printf("Executando Busca Sequencial...\n");
            realizarBuscaSequencial(v1, TAM);
            break;


        case 8:
            contagemComparacoes = 0;

            printf("Gerar Vetor? (1. Sim / 2. Não):\n");
            scanf("%d", &escolha);

            if (escolha == 1) 
            {
                geraVetor(v);
                quickSortMedianaDeTres(v, 0, TAM - 1);
                printf("\n");
                printf("Deseja visualizar o vetor gerado (Ordenado)? (1. Sim / 2. Não):\n");
                scanf("%d", &escolha);

                if (escolha == 1) 
                {
                    printf("\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    int tamanho;
                    scanf("%d", &tamanho);
                    imprimeVetor(v, tamanho);
                }
            }
            else
            {
                geraVetor(v);
                quickSortMedianaDeTres(v, 0, TAM - 1);
            }

            printf("\n");
            printf("Executando Busca Binária...\n");
            realizarBuscaBinaria(v, TAM);
            break;

        case 9: 
        {
            const int numExecucoes = 1000;
            int comparacoesQuickSortUltimo[numExecucoes];
            int comparacoesQuickSortMediana[numExecucoes];
            int comparacoesShellSortKnuth[numExecucoes];
            int comparacoesShellSortHibbard[numExecucoes];
            int comparacoesSelectionSort[numExecucoes];
            int comparacoesBuscaSequencial[numExecucoes];
            int comparacoesBuscaBinaria[numExecucoes];

            printf("\n");
            printf("Executando TODOS os algoritmos 1000 vezes...\n");

            // Execução e contagem para cada algoritmo
            for (int i = 0; i < numExecucoes; i++) 
            {
                int v[TAM];
                int v1[TAM];

                // QuickSort com Pivô Último
                geraVetor(v);
                contagemComparacoes = 0;
                quickSortUltimo(v, 0, TAM - 1);
                comparacoesQuickSortUltimo[i] = contagemComparacoes;

                // QuickSort com Pivô Mediana de Três
                geraVetor(v);
                contagemComparacoes = 0;
                quickSortMedianaDeTres(v, 0, TAM - 1);
                comparacoesQuickSortMediana[i] = contagemComparacoes;

                // ShellSort com Sequência de Knuth
                geraVetor(v);
                contagemComparacoes = 0;
                shellSortKnuth(v, TAM);
                comparacoesShellSortKnuth[i] = contagemComparacoes;

                // ShellSort com Sequência de Hibbard
                geraVetor(v);
                contagemComparacoes = 0;
                shellSortHibbard(v, TAM);
                comparacoesShellSortHibbard[i] = contagemComparacoes;

                // SelectionSort
                geraVetor(v);
                contagemComparacoes = 0;
                selectionSort(v, TAM);
                comparacoesSelectionSort[i] = contagemComparacoes;

                // Busca Sequencial
                geraVetor(v1);  // Usa v1 para não alterar o vetor ordenado em busca binária
                contagemComparacoes = 0;
                BuscaSequencialAleat(v1, TAM, &contagemComparacoes);
                comparacoesBuscaSequencial[i] = contagemComparacoes;

                // Busca Binária
                contagemComparacoes = 0;
                BuscaBinariaAleat(v, TAM, &contagemComparacoes);
                comparacoesBuscaBinaria[i] = contagemComparacoes;
            }

            // Cálculo da média, desvio padrão e total de comparações para cada algoritmo
            double mediaQuickUltimo = calcularMedia(comparacoesQuickSortUltimo, numExecucoes);
            double desvioQuickUltimo = calcularDesvioPadrao(comparacoesQuickSortUltimo, numExecucoes, mediaQuickUltimo);
            int totalQuickUltimo = calcularTotalComparacoes(comparacoesQuickSortUltimo, numExecucoes);

            double mediaQuickMediana = calcularMedia(comparacoesQuickSortMediana, numExecucoes);
            double desvioQuickMediana = calcularDesvioPadrao(comparacoesQuickSortMediana, numExecucoes, mediaQuickMediana);
            int totalQuickMediana = calcularTotalComparacoes(comparacoesQuickSortMediana, numExecucoes);

            double mediaShellKnuth = calcularMedia(comparacoesShellSortKnuth, numExecucoes);
            double desvioShellKnuth = calcularDesvioPadrao(comparacoesShellSortKnuth, numExecucoes, mediaShellKnuth);
            int totalShellKnuth = calcularTotalComparacoes(comparacoesShellSortKnuth, numExecucoes);

            double mediaShellHibbard = calcularMedia(comparacoesShellSortHibbard, numExecucoes);
            double desvioShellHibbard = calcularDesvioPadrao(comparacoesShellSortHibbard, numExecucoes, mediaShellHibbard);
            int totalShellHibbard = calcularTotalComparacoes(comparacoesShellSortHibbard, numExecucoes);

            double mediaSelection = calcularMedia(comparacoesSelectionSort, numExecucoes);
            double desvioSelection = calcularDesvioPadrao(comparacoesSelectionSort, numExecucoes, mediaSelection);
            int totalSelection = calcularTotalComparacoes(comparacoesSelectionSort, numExecucoes);

            double mediaBuscaSequencial = calcularMedia(comparacoesBuscaSequencial, numExecucoes);
            double desvioBuscaSequencial = calcularDesvioPadrao(comparacoesBuscaSequencial, numExecucoes, mediaBuscaSequencial);
            int totalBuscaSequencial = calcularTotalComparacoes(comparacoesBuscaSequencial, numExecucoes);

            double mediaBuscaBinaria = calcularMedia(comparacoesBuscaBinaria, numExecucoes);
            double desvioBuscaBinaria = calcularDesvioPadrao(comparacoesBuscaBinaria, numExecucoes, mediaBuscaBinaria);
            int totalBuscaBinaria = calcularTotalComparacoes(comparacoesBuscaBinaria, numExecucoes);


            // Exibição dos resultados
            printf("\n");
            printf("Resultados das Comparações após 1000 execuções:\n");

            printf("\n");
            printf("QuickSort (Pivô Último): Média = %.2f\n", mediaQuickUltimo);
            printf("QuickSort (Pivô Último): Desvio Padrão = %.2f\n", desvioQuickUltimo);
            printf("QuickSort (Pivô Último): Total = %d\n", totalQuickUltimo);
            printf("____________________________________________________________________________\n");



            printf("\n");
            printf("QuickSort (Pivô Mediana de Três): Média = %.2f, \n", mediaQuickMediana);
            printf("QuickSort (Pivô Mediana de Três): Desvio Padrão = %.2f\n", desvioQuickMediana);
            printf("QuickSort (Pivô Mediana de Três): Total = %d\n", totalQuickMediana);
            printf("____________________________________________________________________________\n");



            printf("\n");
            printf("ShellSort (Sequência de Knuth): Média = %.2f\n", mediaShellKnuth);
            printf("ShellSort (Sequência de Knuth): Desvio Padrão = %.2f\n", desvioShellKnuth);
            printf("ShellSort (Sequência de Knuth): Total = %d\n", totalShellKnuth);
            printf("____________________________________________________________________________\n");



            printf("\n");
            printf("ShellSort (Sequência de Hibbard): Média = %.2f\n", mediaShellHibbard);
            printf("ShellSort (Sequência de Hibbard): Desvio Padrão = %.2f\n", desvioShellHibbard);
            printf("ShellSort (Sequência de Hibbard): Total = %d\n", totalShellHibbard);
            printf("____________________________________________________________________________\n");
            
            
            
            printf("\n");
            printf("SelectionSort: Média = %.2f\n", mediaSelection);
            printf("SelectionSort: Desvio Padrão = %.2f\n", desvioSelection);
            printf("SelectionSort: Total = %d\n", totalSelection);
            printf("____________________________________________________________________________\n");
            


            printf("\n");
            printf("Busca Sequencial: Média = %.2f\n", mediaBuscaSequencial);
            printf("Busca Sequencial: Desvio Padrão = %.2f\n", desvioBuscaSequencial);
            printf("Busca Sequencial: Total = %d\n", totalBuscaSequencial);
            printf("____________________________________________________________________________\n");
            

            
            printf("\n");
            printf("Busca Binária: Média = %.2f\n", mediaBuscaBinaria);
            printf("Busca Binária: Desvio Padrão = %.2f\n",desvioBuscaBinaria);
            printf("Busca Binária: Total = %d\n", totalBuscaBinaria);
            printf("____________________________________________________________________________\n");


            break;
        }

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
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
        printf("\n");
        printf("Escolha uma opção:\n");
        printf("1. Digitar um número para buscar\n");
        printf("2. Gerar um número aleatório para buscar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao != 1 && opcao != 2) {
            printf("Opção inválida! Por favor, escolha 1 ou 2.\n");
        }
    } while (opcao != 1 && opcao != 2);

    if (opcao == 1) 
    {
        printf("\n");
        printf("Digite o número a ser buscado: ");
        scanf("%d", &elemento);
    } 
    else 
    {
        elemento = rand() % (MAX_VAL + 1); // Gera número aleatório entre 0 e MAX_VAL
        printf("Número gerado aleatoriamente para busca: %d\n", elemento);
    }

    // Realiza a busca sequencial no vetor original
    posicao = buscaSequencial(vetor, tamanho, elemento, &comparacoes);

    // Exibe o resultado da busca
    if (posicao != -1) 
    {
        printf("\n");
        printf("Elemento %d encontrado na posição %d após %d comparações.\n", elemento, posicao, comparacoes);
    } 
    else 
        printf("Elemento %d não encontrado no vetor após %d comparações.\n", elemento, comparacoes);
    
}



// Função para realizar a busca sequencial com número aleatório
void BuscaSequencialAleat(int vetor[], int tamanho, int *comparacoes) {
    int elemento = rand() % (MAX_VAL + 1); // Gera número aleatório entre 0 e MAX_VAL
    buscaSequencial(vetor, tamanho, elemento, comparacoes);
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
void realizarBuscaBinaria(int vetor[], int tamanho) 
{
    int elemento, contagemComparacoes = 0, opcao;

    // Loop para garantir que o usuário escolha uma opção válida
    do {
        printf("\n");
        printf("Escolha uma opção para a busca binária:\n");
        printf("1 - Digitar o elemento a ser buscado\n");
        printf("2 - Gerar aleatoriamente o elemento a ser buscado\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao != 1 && opcao != 2) {
            printf("Opção inválida! Por favor, escolha 1 ou 2.\n");
        }
    } while (opcao != 1 && opcao != 2);

    if (opcao == 1) 
    {
        printf("Digite o elemento a ser buscado: ");
        scanf("%d", &elemento);
    } 
    else 
    {
        elemento = rand() % (MAX_VAL + 1); // Gera número aleatório entre 0 e MAX_VAL
        printf("Elemento gerado aleatoriamente: %d\n", elemento);
    }

    // Realiza a busca binária no vetor ordenado
    int posicao = buscaBinaria(vetor, tamanho, elemento, &contagemComparacoes);

    // Exibe o resultado da busca
    if (posicao != -1) 
    {
        printf("\n");
        printf("Elemento encontrado na posição: %d\n", posicao);
    } 
    else 
        printf("Elemento não encontrado no vetor.\n");
    printf("Número de comparações realizadas: %d\n", contagemComparacoes);
}



// Função para realizar a busca binária com número aleatório
void BuscaBinariaAleat(int vetor[], int tamanho, int *comparacoes) {
    int elemento = rand() % (MAX_VAL + 1); // Gera número aleatório entre 0 e MAX_VAL
    buscaBinaria(vetor, tamanho, elemento, comparacoes);
}


/*===========================================================================================================*/