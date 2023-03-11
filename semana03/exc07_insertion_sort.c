// a ideia do insertion sort (ordenação por inserção) é ordenar deslocando os valores
// maiores para direita, abrindo espaço para o elemento menor. Irá inserir o elemento menor 
// logo antes do próximo maior que ele.

#include <stdio.h>

int insertion_sort(int vetor[], int tamanho);
void mostrar(int vetor[], int tamanho);

int main(void)
{
    int vetor[] = {100, 1, 99, 101, 98, 2, 97, -3};

    int tam = sizeof(vetor) / sizeof(int);

    insertion_sort(vetor, tam);
    mostrar(vetor, tam);
}

int insertion_sort(int vetor[], int tamanho)
{
    int atual;
    int j;
    int i = 1;
    while (i < tamanho)
    {     
        atual = vetor[i];
        j = i - 1;
        while (j >= 0 && atual <= vetor[j])
        {         
            vetor[j+1] = vetor[j];
            vetor[j] = atual;
            j--;     
            mostrar(vetor, tamanho);
        }
        i++;    
    }
}

void mostrar(int vetor[], int tamanho)
{
    int i = 0;
    printf("[");
    while (i < tamanho)
    {
        printf("-> %d ", vetor[i]);
        i++;
    }
    printf("]\n");
}