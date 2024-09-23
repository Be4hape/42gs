#include <stdio.h>

int ft_str_is_alpha(char *str)
{
    // 알파벳만 있는 경우 > return 1
    // 아닌 경우 > return 0

    int i = 0;

    while (str[i] != 0)
    {
        if (!((str[i] > 64) && (str[i] < 91) || (str[i] > 96) && (str[i] < 123)))
            return 0;

        i++;
    }
    return 1;
}

int main()
{
    char str[] = "asdads";

    int a = ft_str_is_alpha(str);
    printf("%d", a);

    return 0;
}