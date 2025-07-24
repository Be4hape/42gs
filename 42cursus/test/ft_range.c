#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end){
    int i = 0;
    int *p;
    if(start < 0){
        i = end - start + 1;
    }
    else{
        i = end + start + 1;
    }
    p = malloc(sizeof(int) * i + 1);
    if(!p){
        return NULL;
    }
    while(i--){
        p[i] = i;
    }
    return p;
}

int main(){
    int *p;
    p = ft_range(-10, 1);

    printf("%d", *p);
    return 0;
}