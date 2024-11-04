#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 1024    // Tamanho do vetor
#define MAX_VAL 2048 // Valor máximo para os números aleatórios
#define MAX_NUM 100000 // Valor máximo para os números aleatórios




int contagemTrocas = 0;      // Variável global para contar trocas
int contagemComparacoes = 0; // Variável global para contar comparações


// Função que gera um número aleatório entre 0 e 100.000
int geraAleatorio() {
    return rand() % (MAX_VAL + 1);
}


// Inicializa a semente com o tempo atual
void inicializaAleatorio() {
    srand(time(NULL));
}


// Preenche um vetor de inteiros com valores aleatórios entre 0 e 2048
void geraVetor(int vetor[]) 
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % (MAX_VAL + 1); // Gera números aleatórios entre 0 e 2048
    }
}


// Imprime um vetor de inteiros
void imprimeVetor(int vetor[], int n) 
{
    if (n > TAM)
        n = TAM;  // Limita a impressão ao tamanho máximo do vetor

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("\n");
}


// Troca o conteúdo de duas variáveis
void trocar(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
    contagemTrocas++;
}


void exibirContagens(char *metodo) 
{
    printf("\n[%s] Contagem de trocas: %d\n", metodo, contagemTrocas);
    printf("[%s] Contagem de comparações: %d\n", metodo, contagemComparacoes);
    printf("\n");
}



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







// Função para imprimir uma linha de separação
void linhaSeparacao() {
    printf("\n");
    printf("______________________________________________________________________________________");
    printf("\n");
    printf("\n");
}







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


void menu (int v[], int opcao, char []) 
{
    int subOpcao;
    char resposta[1];

    printf("\n");
    printf("Bem vindo ao Trabalho Prático da disciplina de Algoritmos II!\n");
    printf("Aqui você verá a implementação de algoritmos de ordenação e busca.\n");
    printf("\n");
    printf("Logo abaixo, selecione a operação desejada:\n");
    printf("\n");

    printf("0. Sair\n");
    printf("1. Ordenação\n");
    printf("2. Busca\n");
    printf("\n");

    scanf("%d", &opcao);

    while (opcao != 0)
    {
        if (opcao == 1)
        {
            printf("Você escolheu a opção de ordenação.\n");
            printf("Aqui você poderá escolher entre os algoritmos de ordenação disponíveis:\n");
            printf("\n");
            printf("1. QuickSort - Pivô Último Elemento\n");
            printf("2. QuickSort - Pivô Mediana de Três\n");
            printf("3. Shell Sort - Espaçamento com Sequência de Hibbard\n");
            printf("4. Shell Sort - Espaçamento com Sequência de Knuth\n");
            printf("5. Selection Sort\n");
            printf("6. Voltar\n");
            scanf("%d", &subOpcao);

            if (subOpcao == 1)
            {
                printf("Você escolheu o QuickSort com o último elemento como pivô.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Ordenar o vetor 1 vez.\n");
                    printf("2. Ordenar o vetor 1000 vezes.\n");
                    printf("3. Ordenar o vetor N vezes.\n");
                    printf("4. Voltar\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        printf("Ordenando o vetor 1 vez...\n");
                        quickSortUltimo(v, 0, TAM - 1);
                        exibirContagens("QuickSort - Último Elemento Pivô");
                        printf("Vetor após a ordenação com último elemento como pivô\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 2)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        printf("Ordenando o vetor 1000 vezes...\n");

                        int i = 0;
                        while (i < 1000)
                        {
                            quickSortUltimo(v, 0, TAM - 1);
                            exibirContagens("QuickSort - Último Elemento Pivô");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com último elemento como pivô\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 3)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        int i = 0;
                        printf("Digite o número de vezes que deseja ordenar o vetor: ");
                        scanf("%d", &subOpcao);
                        printf("Ordenando o vetor %d vezes...\n", subOpcao);

                        while (i < subOpcao)
                        {   
                            quickSortUltimo(v, 0, TAM - 1);
                            exibirContagens("QuickSort - Último Elemento Pivô");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com último elemento como pivô\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 4)
                    {
                        printf("Voltando...\n");
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                }
            }
            
            else if(subOpcao == 2)
            {
                printf("Você escolheu o QuickSort com a mediana de três como pivô.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Ordenar o vetor 1 vez.\n");
                    printf("2. Ordenar o vetor 1000 vezes.\n");
                    printf("3. Ordenar o vetor N vezes.\n");
                    printf("4. Voltar\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        printf("Ordenando o vetor 1 vez...\n");
                        quickSortMedianaDeTres(v, 0, TAM - 1);
                        exibirContagens("QuickSort - Pivô Mediana de Três");
                        printf("Vetor após a ordenação com mediana de três\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 2)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        printf("Ordenando o vetor 1000 vezes...\n");

                        int i = 0;
                        while (i < 1000)
                        {
                            quickSortMedianaDeTres(v, 0, TAM - 1);
                            exibirContagens("QuickSort - Pivô Mediana de Três");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com mediana de três\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 3)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        int i = 0;
                        printf("Digite o número de vezes que deseja ordenar o vetor: ");
                        scanf("%d", &subOpcao);
                        printf("Ordenando o vetor %d vezes...\n", subOpcao);

                        while (i < subOpcao)
                        {
                            quickSortMedianaDeTres(v, 0, TAM - 1);
                            exibirContagens("QuickSort - Pivô Mediana de Três");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com mediana de três\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 4)
                    {
                        printf("Voltando...\n");
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                }
            }

            else if(subOpcao == 3)
            {
                printf("Você escolheu o Shell Sort com a sequência de Hibbard.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Ordenar o vetor 1 vez.\n");
                    printf("2. Ordenar o vetor 1000 vezes.\n");
                    printf("3. Ordenar o vetor N vezes.\n");
                    printf("4. Voltar\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        printf("Ordenando o vetor 1 vez...\n");
                        shellSortHibbard(v, TAM);
                        exibirContagens("ShellSort - Sequência de Hibbard");
                        printf("Vetor após a ordenação com sequência de Hibbard\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 2)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        printf("Ordenando o vetor 1000 vezes...\n");

                        int i = 0;
                        while (i < 1000)
                        {
                            shellSortHibbard(v, TAM);
                            exibirContagens("ShellSort - Sequência de Hibbard");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com sequência de Hibbard\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 3)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        
                        printf("Digite o número de vezes que deseja ordenar o vetor: ");
                        scanf("%d", &subOpcao);
                        printf("Ordenando o vetor %d vezes...\n", subOpcao);

                        int i = 0;
                        while (i < subOpcao)
                        {
                            shellSortHibbard(v, TAM);
                            exibirContagens("ShellSort - Sequência de Hibbard");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com sequência de Hibbard\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 4)
                    {
                        printf("Voltando...\n");
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                }
            }

            else if(subOpcao == 4)
            {
                printf("Você escolheu o Shell Sort com a sequência de Knuth.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Ordenar o vetor 1 vez.\n");
                    printf("2. Ordenar o vetor 1000 vezes.\n");
                    printf("3. Ordenar o vetor N vezes.\n");
                    printf("4. Voltar\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        printf("Ordenando o vetor 1 vez...\n");
                        shellSortKnuth(v, TAM);
                        exibirContagens("ShellSort - Sequência de Knuth");
                        printf("Vetor após a ordenação com sequência de Knuth\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 2)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        printf("Ordenando o vetor 1000 vezes...\n");

                        int i = 0;
                        while (i < 1000)
                        {
                            shellSortKnuth(v, TAM);
                            exibirContagens("ShellSort - Sequência de Knuth");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com sequência de Knuth\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 3)
                    {
                        contagemComparacoes = 0;
                        contagemTrocas = 0;
                        
                        printf("Digite o número de vezes que deseja ordenar o vetor: ");
                        scanf("%d", &subOpcao);
                        printf("Ordenando o vetor %d vezes...\n", subOpcao);

                        int i = 0;
                        while (i < subOpcao)
                        {
                            shellSortKnuth(v, TAM);
                            exibirContagens("ShellSort - Sequência de Knuth");
                            int v[TAM];
                            geraVetor(v);
                            i++;
                        }
                        printf("Vetor após a ordenação com sequência de Knuth\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 4)
                    {
                        printf("Voltando...\n");
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                    
                }
            }

            else if(subOpcao == 5)
            {
                printf("Você escolheu o Selection Sort.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Ordenar o vetor 1 vez.\n");
                    printf("2. Ordenar o vetor 1000 vezes.\n");
                    printf("3. Ordenar o vetor N vezes.\n");
                    printf("4. Voltar\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        printf("Ordenando o vetor 1 vez...\n");
                        printf("Vetor após a ordenação com selection sort\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 2)
                    {
                        printf("Ordenando o vetor 1000 vezes...\n");

                        while (subOpcao < 1000)
                        {
                            //selectionSort();
                            subOpcao++;
                        }
                        printf("Vetor após a ordenação com selection sort\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 3)
                    {
                        int i = 0;
                        printf("Digite o número de vezes que deseja ordenar o vetor: ");
                        scanf("%d", &subOpcao);
                        printf("Ordenando o vetor %d vezes...\n", subOpcao);

                        while (i < subOpcao)
                        {
                            //selectionSort();
                            i++;
                        }
                        printf("Vetor após a ordenação com selection sort\n");
                        printf("Digite o tamanho do vetor que deseja visualizar: ");
                        scanf("%d", &subOpcao);
                        imprimeVetor(v, subOpcao);
                    }

                    else if(subOpcao == 4)
                    {
                        printf("Voltando...\n");
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                    
                }
            }

            else if(subOpcao == 6)
            {
                printf("Voltando ao menu principal...\n");
            }

            else
            {
                printf("Opção inválida!\n");
            }
        }


        else if(opcao == 2)
        {
            printf("Você escolheu a opção de busca.\n");
            printf("Aqui você poderá escolher entre os algoritmos de busca disponíveis:\n");
            printf("\n");
            printf("1. Busca Sequencial\n");
            printf("2. Busca Binária\n");
            printf("3. Voltar\n");

            scanf("%d", &subOpcao);

            if(subOpcao == 1)
            {
                printf("Você escolheu a busca sequencial.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Digitar um número para busca\n");
                    printf("2. Gerar um número aleatório para busca\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        printf("Selecione a opção desejada:\n");
                        printf("1. Buscar pelo número 1 vez.\n");
                        printf("2. Buscar pelo número 1000 vezes.\n");
                        printf("3. Buscar pelo número N vezes.\n");
                        printf("4. Voltar\n");

                        scanf("%d", &subOpcao);

                        if(subOpcao == 1)
                        {
                            printf("Digite o número que deseja buscar: ");
                            scanf("%d", &subOpcao);
                            printf("Realizando a busca sequencial...\n");
                            printf("Elemento encontrado na posição: %d\n", subOpcao);
                        }

                        else if(subOpcao == 2)
                        {
                            printf("Buscando pelo número 1000 vezes...\n");
                            printf("Digite o número que deseja buscar: ");
                            scanf("%d", &subOpcao);
                            printf("Realizando a busca sequencial...\n");

                            while (subOpcao < 1000)
                            {
                                //buscaSequencial();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                subOpcao++;
                            }
                        }

                        else if(subOpcao == 3)
                        {
                            int i = 0;
                            printf("Digite o número de vezes que deseja buscar pelo número: ");
                            scanf("%d", &subOpcao);
                            printf("Buscando pelo número %d vezes...\n", subOpcao);

                            while (i < subOpcao)
                            {
                                //buscaSequencial();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                i++;
                            }
                        }

                        else if(subOpcao == 4)
                        {
                            printf("Voltando...\n");
                        }
                        
                        else
                        {
                            printf("Opção inválida!\n");
                        }
                    }

                    else if(subOpcao == 2)
                    {
                        printf("Selecione a opção desejada:\n");
                        printf("1. Buscar pelo número 1 vez.\n");
                        printf("2. Buscar pelo número 1000 vezes.\n");
                        printf("3. Buscar pelo número N vezes.\n");
                        printf("4. Voltar\n");

                        scanf("%d", &subOpcao);

                        if(subOpcao == 1)
                        {
                            subOpcao = geraAleatorio();
                            printf("Número gerado aleatoriamente para busca: %d\n", subOpcao);
                            printf("Realizando a busca sequencial 1 vez...\n");
                            printf("Elemento encontrado na posição: %d\n", subOpcao);
                        }

                        else if(subOpcao == 2)
                        {
                            printf("Buscando pelo número 1000 vezes...\n");
                            subOpcao = geraAleatorio();
                            printf("Número gerado aleatoriamente para busca: %d\n", subOpcao);
                            printf("Realizando a busca sequencial...\n");

                            while (subOpcao < 1000)
                            {
                                //buscaSequencial();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                subOpcao++;
                            }
                        }

                        else if(subOpcao == 3)
                        {
                            int i = 0;
                            subOpcao = geraAleatorio();
                            printf("Número gerado aleatoriamente para busca: %d\n", subOpcao);
                            printf("Buscando pelo número %d vezes...\n", subOpcao);

                            while (i < subOpcao)
                            {
                                //buscaSequencial();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                i++;
                            }
                        }

                        else if(subOpcao == 4)
                        {
                            printf("Voltando...\n");
                        }
                        
                        else
                        {
                            printf("Opção inválida!\n");
                        }
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                }
            }

            else if(subOpcao == 2)
            {
                printf("Você escolheu a busca binária.\n");
                printf("Deseja gerar um vetor? (s/n) \n");
                printf("\n");
                scanf("%1s", resposta);
                if (strcmp(resposta, "s") == 0)
                {
                    int v[TAM];
                    geraVetor(v);
                    printf("Vetor gerado com sucesso!\n");
                    printf("Digite o tamanho do vetor que deseja visualizar: ");
                    scanf("%d", &subOpcao);
                    imprimeVetor(v, subOpcao);
                    printf("\n");

                    printf("Selecione a opção desejada:\n");
                    printf("1. Digitar um número para busca\n");
                    printf("2. Gerar um número aleatório para busca\n");

                    scanf("%d", &subOpcao);

                    if(subOpcao == 1)
                    {
                        printf("Selecione a opção desejada:\n");
                        printf("1. Buscar pelo número 1 vez.\n");
                        printf("2. Buscar pelo número 1000 vezes.\n");
                        printf("3. Buscar pelo número N vezes.\n");
                        printf("4. Voltar\n");

                        scanf("%d", &subOpcao);

                        if(subOpcao == 1)
                        {
                            printf("Digite o número que deseja buscar: ");
                            scanf("%d", &subOpcao);
                            printf("Realizando a busca binária...\n");
                            printf("Elemento encontrado na posição: %d\n", subOpcao);
                        }

                        else if(subOpcao == 2)
                        {
                            printf("Buscando pelo número 1000 vezes...\n");
                            printf("Digite o número que deseja buscar: ");
                            scanf("%d", &subOpcao);
                            printf("Realizando a busca binária...\n");

                            while (subOpcao < 1000)
                            {
                                //buscaBinaria();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                subOpcao++;
                            }
                        }

                        else if(subOpcao == 3)
                        {
                            int i = 0;
                            printf("Digite o número de vezes que deseja buscar pelo número: ");
                            scanf("%d", &subOpcao);
                            printf("Buscando pelo número %d vezes...\n", subOpcao);

                            while (i < subOpcao)
                            {
                                //buscaBinaria();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                i++;
                            }
                        }

                        else if(subOpcao == 4)
                        {
                            printf("Voltando...\n");
                        }
                        
                        else
                        {
                            printf("Opção inválida!\n");
                        }
                    }

                    else if(subOpcao == 2)
                    {
                        printf("Selecione a opção desejada:\n");
                        printf("1. Buscar pelo número 1 vez.\n");
                        printf("2. Buscar pelo número 1000 vezes.\n");
                        printf("3. Buscar pelo número N vezes.\n");
                        printf("4. Voltar\n");

                        scanf("%d", &subOpcao);

                        if(subOpcao == 1)
                        {
                            subOpcao = geraAleatorio();
                            printf("Número gerado aleatoriamente para busca: %d\n", subOpcao);
                            printf("Realizando a busca binária 1 vez...\n");
                            printf("Elemento encontrado na posição: %d\n", subOpcao);
                        }

                        else if(subOpcao == 2)
                        {
                            printf("Buscando pelo número 1000 vezes...\n");
                            subOpcao = geraAleatorio();
                            printf("Número gerado aleatoriamente para busca: %d\n", subOpcao);
                            printf("Realizando a busca binária...\n");

                            while (subOpcao < 1000)
                            {
                                //buscaBinaria();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                subOpcao++;
                            }
                        }

                        else if(subOpcao == 3)
                        {
                            int i = 0;
                            subOpcao = geraAleatorio();
                            printf("Número gerado aleatoriamente para busca: %d\n", subOpcao);
                            printf("Buscando pelo número %d vezes...\n", subOpcao);

                            while (i < subOpcao)
                            {
                                //buscaBinaria();
                                printf("Elemento encontrado na posição: %d\n", subOpcao);
                                i++;
                            }
                        }

                        else if(subOpcao == 4)
                        {
                            printf("Voltando...\n");
                        }
                        
                        else
                        {
                            printf("Opção inválida!\n");
                        }
                    }

                    else if(subOpcao == 3)
                    {
                        printf("Voltando ao menu principal...\n");
                    }

                    else
                    {
                        printf("Opção inválida!\n");
                    }
                }
            }
        }


        else
        {
            printf("Opção inválida!\n");
        }

        printf("\n");
        printf("Selecione alguma opção:\n");
        printf("0. Sair\n");
        printf("1. Ordenação\n");
        printf("2. Busca\n");
        scanf("%d", &opcao);
    }
}








int main() 
{
    int v[TAM];
    char resposta [1];
    int opcao = 0;
    
    // Gera um vetor com valores aleatórios
    //geraVetor(v);

    inicializaAleatorio();
    menu (v, opcao, resposta);



    return 0;
}