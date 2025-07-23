#include <stdlib.h>

char    *ft_strdup(char *src){
    char *save;
    int i = 0;
    
    while(src[i])
        i++;
    save = malloc(sizeof(char) * i + 1);
    if(!save)
        return NULL;
    i = 0;
    while(src[i]){
        save[i] = src[i];
        i++;
    }
    save[i] = '\0';
    return save;
}