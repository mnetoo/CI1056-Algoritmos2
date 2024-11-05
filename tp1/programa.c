#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "funções.h"


int contagemTrocas = 0;      
int contagemComparacoes = 0;



int main() 
{
    int opcao = 0;
    srand(time(NULL));


    do {
        opcao = menu();
        program(opcao);
    } while (opcao != 0);

    
    return 0;
}