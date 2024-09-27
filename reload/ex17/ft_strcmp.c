#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    // strcmp > 두 문자열 비교, 문자열이 같은경우 = 0, 값이 다른 경우 = 차이 반환
    int i = 0;
    while (s1[i] != 0 || s2[i] != 0)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

int main()
{
    int diff = ft_strcmp("Apple", "apple");

    printf("%d", diff);

    return 0;
}