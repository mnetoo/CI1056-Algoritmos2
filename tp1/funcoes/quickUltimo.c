/*================================================ [QUICK SORT] ===========================================================*/

//                                UTILIZANDO O ÚLTIMO ELEMENTO DO VETOR COMO PIVÔ


// Particiona o vetor de forma que os elementos menores que o pivô fiquem à esquerda e os maiores à direita
int particionarUltimo(int vetor[], int inicio, int fim) 
{
    int pivo = vetor[fim];  // Escolhe o último elemento como pivô
    int indiceMenor = inicio - 1;

    for (int i = inicio; i < fim; i++) 
    {   
        //contagemComparacoes++;
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