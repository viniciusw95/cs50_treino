// programa que implementa busca binaria
#include <stdio.h>

void busca_binaria(int vetor[], int tamanho, int elemento_buscado);

// mudar de acordo com a quantiadade de elementos no vetor 'numeros'
int COMP = 12;

int main(void)
{
    int numeros[] = {1, 2, 3, 4, 5, 8, 12, 16, 18, 19, 23, 25};
    
    for (int i = 0; i < COMP; i++)
    {
        busca_binaria(numeros, COMP, numeros[i]);
    }
}

// imprime a posição do elemento do vetor (ordenado) passado como argumento.
void busca_binaria(int vetor[], int tamanho, int elemento_buscado)
{
    int area_busca = COMP;

    // início do vetor
    int i = 0;
    // fim o vetor
    int f = COMP - 1;
    
    while (i <= f)
    {
        int meio = (i + f) / 2; 
        if (vetor[meio] == elemento_buscado)
        {
            printf("Elemento %i na posição %i\n", vetor[meio], meio);
            break;
        }
        else if (vetor[meio] < elemento_buscado) 
        {
            i = meio + 1;
        }
        else
        {
            f = meio - 1;
        }
    }

}