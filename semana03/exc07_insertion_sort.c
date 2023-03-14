// a ideia do insertion sort (ordenação por inserção) é ordenar deslocando os maiores valores do vetor v[]
// para direita, abrindo espaço para o elemento menor, chamado 'x'. Assim, irá inserir o elemento x
// na posição i, tal que v[i-1] <= v[i] <= v[i+1].

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *lista_aleatoria(int tamanho);
int insertion_sort(int vetor[], int tamanho);
void mostrar(int vetor[], int tamanho);

int main(void)
{

    int tam = 4;
    int *lista = lista_aleatoria(tam);

    printf("lista aleatória: ");
    mostrar(lista, tam);

    insertion_sort(lista, tam);
    printf("lista ordenada: ");
    mostrar(lista, tam);

    free(lista);
}

int insertion_sort(int vetor[], int tamanho)
{
    int atual, j;
    int i = 1;
    while (i < tamanho)
    {     
        atual = vetor[i];
        j = i - 1;
        while (j >= 0 && atual <= vetor[j])
        {         
            vetor[j+1] = vetor[j];
            j--;     
        }
        vetor[j+1] = atual;
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

int *lista_aleatoria(int tamanho)
{
    srand(time(NULL));
    int *lista = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        lista[i] = (rand() % 200) - 100;
    }
    return lista;
}