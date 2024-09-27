#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;

    return i;
}

int main()
{
    int length = ft_strlen("hello world");
    printf("%d", length);

    return 0;
}