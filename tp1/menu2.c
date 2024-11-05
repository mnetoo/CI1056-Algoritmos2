#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1024    // Tamanho do vetor
#define MAX_VAL 2048 // Valor máximo para os números aleatórios no vetor


#define MAX_NUM 100000 // Valor máximo para os números aleatórios

// Função que gera um número aleatório entre 0 e 100.000
int geraAleatorio() {
    return rand() % (MAX_VAL + 1);
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











































// Função para exibir o menu e retornar a opção escolhida
int menu() 
{
    int opcao;

    printf("\n");
    printf("                                    Bem-vindo ao Trabalho Prático da disciplina de Algoritmos II!\n");
    printf("                                    Aqui você verá a implementação de algoritmos de ordenação e busca.\n");
    printf("\n");
    printf("Selecione a operação desejada:\n");
    printf("\n");

    printf("0. Sair\n");
    printf("1. QuickSort - Pivô Último\n");
    printf("2. QuickSort - Pivô Mediana de Três\n");
    printf("3. ShellSort - Sequência de Knuth\n");
    printf("4. ShellSort - Sequência de Hibbard\n");
    printf("5. SelectionSort - Quadrático\n");
    printf("6. Busca Sequencial\n");
    printf("7. Busca Binária\n");
    printf("\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    return opcao;
}


// Função para executar a operação com base na opção escolhida
void programa(int opcao) 
{
    switch (opcao) 
    {
        case 0:
            printf("Saindo do programa...\n");
            break;


        case 1:
            printf("QuickSort com Pivô Último...\n");
            // Chame a função para o QuickSort com pivô último aqui
            break;












        case 2:
            printf("Executando QuickSort com Pivô Mediana de Três...\n");
            // Chame a função para o QuickSort com pivô mediana de três aqui
            break;











        case 3:
            printf("Executando ShellSort com Sequência de Knuth...\n");
            // Chame a função para o ShellSort com sequência de Knuth aqui
            break;










        case 4:
            printf("Executando ShellSort com Sequência de Hibbard...\n");
            // Chame a função para o ShellSort com sequência de Hibbard aqui
            break;











        case 5:
            printf("Executando SelectionSort...\n");
            // Chame a função para o SelectionSort aqui
            break;














        case 6:
            printf("Executando Busca Sequencial...\n");
            // Chame a função para a busca sequencial aqui
            break;











        case 7:
            printf("Executando Busca Binária...\n");
            // Chame a função para a busca binária aqui
            break;











        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
}
















int main() {
    int opcao;

    // Executa o menu e a função correspondente até o usuário escolher sair
    do {
        opcao = menu();
        programa(opcao);
    } while (opcao != 0);

    return 0;
}