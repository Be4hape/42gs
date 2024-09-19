#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
    // a / b = a
    // a % b = b;
    int swap1, swap2;

    swap1 = *a / *b;
    swap2 = *a % *b;

    *a = swap1;
    *b = swap2;
}

int main()
{
    int a = 90;
    int b = 30;

    ft_ultimate_div_mod(&a, &b);
    printf("%d %d", a, b);

    return 0;
}