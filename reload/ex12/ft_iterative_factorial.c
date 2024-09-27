#include <stdio.h>
#include <unistd.h>

int ft_iterative_factorial(int nb)
{
    // nb! 를 구해라, 반복문 이용
    int i = 0;
    int mul = 1;
    while (i < nb)
    {
        mul = mul * (nb - i);

        i++;
    }
    return mul;
}

int main()
{
    int nb = 5;
    nb = ft_iterative_factorial(nb);
    printf("%d", nb);

    return 0;
}