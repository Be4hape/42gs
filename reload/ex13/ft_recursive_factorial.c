#include <stdio.h>
#include <unistd.h>

int ft_recursive_factorial(int nb)
{
    // nb!를 구해라, 재귀 사용
    if (nb < 0)
        return 0;
    if (nb == 0)
        return 1;

    return nb * ft_recursive_factorial(nb - 1);
}

int main()
{
    int nb = ft_recursive_factorial(5);

    printf("%d", nb);
    return 0;
}