/*
Implementa o algoritmo de ordenação por seleção (selection sort):
Consiste em varrer sucessivamente a área não ordenada do vetor, até que a área não ordenada 
fique com apenas 1 elemento.
Sendo que para cada uma das varreduras, irá:
1º) procurar o menor elemento. Depois disso, 
2º) trocar a posição do menor elemento com o elemento do início da parte não ordenada.
*/

#include <stdio.h>

void selection_sort(int vetor[], int tamanho);
void imprimir_vetor(int vetor[], int tamanho);

int main(void)
{
    int numeros[] = {1, 2, 3, 5, 4};

    int tamanho = sizeof(numeros) / sizeof(int);

    if (tamanho > 0)
    {
        selection_sort(numeros, tamanho);
    }
    imprimir_vetor(numeros, tamanho);
}

void selection_sort(int vetor[], int tamanho)
{
    int qtd_nao_ordenada = tamanho;

    for (int i = 0; i < qtd_nao_ordenada - 1; i++)
    {
        int *pMenor = &vetor[i];
        for (int j = i + 1; j < qtd_nao_ordenada; j++)
        {
            if (vetor[j] < *pMenor)
            {
                pMenor = &vetor[j];
            }    
        }
        int aux = vetor[i];
        vetor[i] = *pMenor;
        *pMenor = aux;                
    }
}

void imprimir_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%i -> ", vetor[i]);
    }
}