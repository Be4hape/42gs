#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2){
    //s2를 s1에 복사하고, null을 포함하여 s1을 반환
    int i = 0;
    while(s2[i]){
        s1[i] = s2[i];
        s2++;
    }
    s1[i] = 0;
    return s1;
}
