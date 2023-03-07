/*
Exemplifica recursão utilizando a conjecture de Collatz.
*/

#include <stdio.h>

int collatz(int n);

int main(void)
{
    printf("Um número positivo: ");
    int n;
    scanf("%d", &n);

    if (n > 0)
    {
        int steps = collatz(n);
        printf("Passos para chegar de %d até o 1: %d\n", n, steps);
    }

}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n / 2);
        // 16 -> 8 (steps = 2)
        // 8 -> 4 (steps = 3)
        // 4 -> 2 (steps = 4)
        // 2 -> 1 (steps = 5)
    }
    else if (n % 2 == 1)
    {
        return 1 + collatz(n * 3 + 1);
        // 5 -> 16 (steps = 1)

    }
}