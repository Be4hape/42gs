#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;

    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

int main()
{
    char src[] = "hello world";
    char dest[] = "ll";

    char *test = ft_strncpy(dest, src, 4);
    printf("%s", test);

    return 0;
}