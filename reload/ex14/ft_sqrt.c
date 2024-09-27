#include <stdio.h>
#include <unistd.h>

int ft_sqrt(int nb)
{
    // nb의 제곱근을 반환하는 함수
    int i = 1;

    if (nb <= 0)
        return 0;
    if (nb == 1)
        return 1;

    while (i * i <= nb)
    {
        if (i * i == nb)
            return i;
        i++;
    }
    return 0;
}

int main()
{
    int ans = ft_sqrt(1);
    printf("%d", ans);

    return 0;
}