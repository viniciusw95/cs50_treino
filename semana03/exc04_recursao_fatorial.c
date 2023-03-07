/* Algoritmo que exemplifica a recursão usando fatorial de um número n. */

#include <stdio.h>

int fatorial(int n);

int main(void)
{
    printf("Digite um número: ");
    int n;
    scanf("%d", &n);
    int fat = fatorial(n);
    printf("%i! = %i", n, fat);
}

int fatorial(int n)
{
    if (n <= 1) 
    {
        return 1;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}

