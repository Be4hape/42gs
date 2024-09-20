#include <unistd.h>
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    int i = 0;
    while (size > i)
    {
        size--;
        printf("%d", tab[size]);
    }
}

int main()
{
    int itr[] = {1, 2, 3, 4, 5};
    ft_rev_int_tab(itr, 5);

    return 0;
}