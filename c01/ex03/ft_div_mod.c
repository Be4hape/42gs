#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
    // a / b = div
    // a % b = mod
    *div = a / b;
    *mod = a % b;
}

int main()
{
    int a = 60;
    int b = 30;
    int div, mod;

    ft_div_mod(a, b, &div, &mod);
    printf("%d %d", div, mod);

    return 0;
}