/*
Implementação do algoritmo Ordenação por flutuação (bubble sort).
Consiste em analisar repetidamente cada par de elementos adjacentes, da esquerda para direita, trocando-os
de posição caso seja necessário. Quando isso é feito, os elementos maiores vão se descolando para o final
da lista. O algoritmo só irá parará, portanto, quando não forem feitas nenhuma troca de posições na última
passagem pela lista, o que garante que o vetor já está ordenado.
*/

#include <stdio.h>

void bubble_sort(int lista[], int tamanho);
void trocar(int *p_num1, int *p_num2);
void imprimir_vetor(int lista[], int tamanho);

int main(void)
{
    printf("Algoritmo de ordenação por flutuação (bubble sort):");

    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tamanho = sizeof(numeros) / sizeof(int);

    bubble_sort(numeros, tamanho);

    imprimir_vetor(numeros, tamanho);

    return 0;
}

void bubble_sort(int lista[], int tamanho)
{
    // quantidade de comparações a serem feitas em cada passagem pela lista.
    int c = tamanho - 1; 
    int trocas = -1;

    int counter = 0;

    while (trocas != 0)
    {
        trocas = 0;
        for (int j = 1; j <= c; j++)
        {
            counter++;
            // para cada elemento adjante, vai comparar se estão fora de ordem.
            if (lista[j - 1] > lista[j])
            {
                trocar(&lista[j-1] , &lista[j]);
                trocas++;
            }
        }
        // pode-se tirar 1 da quantidade de comparações, pois no final da Yª passagem, o Yº maior elemento
        // já vai estar na sua posição definitiva.
        c--;
    }
    printf("Feitas %i comparações.", counter);
}

void trocar(int *p_num1, int *p_num2)
{
    printf("Trocando posição dos elementos %i e %i\n", *p_num1, *p_num2);
    int aux = *p_num1;
    *p_num1 = *p_num2;
    *p_num2 = aux;
    
}

void imprimir_vetor(int lista[], int tamanho)
{
    printf("[");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%i -> ", lista[i]);
    }
    printf("fim]");

}