#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2){
    int i = 0;
    while (s2[i]){
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}
