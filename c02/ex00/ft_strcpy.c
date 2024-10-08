#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

int main()
{
    // src의 문자열을 dest에 복사
    char src[] = "hello world";
    char dest[] = "ll";

    char *test = ft_strcpy(dest, src);

    printf("%s", test);
    return 0;
}