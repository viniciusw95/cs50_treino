// Algoritmo que implementa a ordenação por mistura (merge sort).

#include <stdio.h>
#include <stdlib.h>

int *merge_sort(int vetor[], int tamanho);
void mostrar(int vetor[], int tamanho);
int *juntar(int *e, int *d, int tam_e, int tam_d);

// usado para confirmar a complexidade de merge sort = O(n * log n).
int cont = 0;

int main(void)
{
    int a[] = {6, 100, 5};
    int tam =  sizeof(a) / sizeof(int);
    printf("Vetor a (original): ");
    mostrar(a, tam);

    printf("\n");
    printf("Ordenando..:\n");
    int *b = merge_sort(a, tam);

    printf("\nVetor b (ordenado): ");
    mostrar(b, tam);
    printf("Total de iterações: %i", cont);
}

int *merge_sort(int vetor[], int tamanho)
{
    if (tamanho == 1)
    {
        int *a = (int *)malloc(1 * sizeof(int));
        *a = vetor[0];
        return a;
    }
    int tam_esquerda = tamanho / 2;
    int tam_direita = tamanho - tam_esquerda;
    int *e = merge_sort(vetor, tam_esquerda);
    int *d = merge_sort(&vetor[tam_esquerda], tam_direita);
   
    int *aux = juntar(e, d, tam_esquerda, tam_direita);
    free(e);
    free(d);
    return aux;
  
}

void mostrar(int vetor[], int tamanho)
{
    printf("[");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%i -> ", vetor[i]);
    }
    printf("]\n");
}

int *juntar(int *e, int *d, int tam_e, int tam_d) 
{
    printf("esq: ");
    mostrar(e, tam_e);

    printf("dir: ");
    mostrar(d, tam_d);

    int *dest = (int*)malloc((tam_e + tam_d) * sizeof(int));
    if (dest == NULL) 
    {
        printf("sem memória\n");
        exit(1);
    }
    int c = 0, i = 0, j = 0;
    // juntar as partes ordenadas
    while (i < tam_e && j < tam_d)
    {
        if (e[i] <= d[j])
        {
            dest[c] = e[i];
            i++;
        }
        else
        {
            dest[c] = d[j];
            j++;
        }
        c++;
        cont++;
    }
    // copiar o restante
    while (i < tam_e)
    {
        dest[c] = e[i];
        i++;
        c++;
        cont++;
    }
    while (j < tam_d)
    {
        dest[c] = d[j];
        j++;
        c++;
        cont++;
    }
    printf("dest: ");
    mostrar(dest, tam_e + tam_d);
    return dest;
}