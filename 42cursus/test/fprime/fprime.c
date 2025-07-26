#include <stdio.h>
#include <stdlib.h>
//printf, atoi

int main(int ac, char **av){
    int i = 2, num = 0;

    if(ac == 2){
        num = atoi(av[1]);
        if(num == 1) 
            printf("1");
        while(i <= num){
            if(num % i == 0){
                printf("%d", i);
                if(num != i) 
                    printf("*");
                num = num / i;
            }i++;            
        }
    }
    printf("\n");

    return 0;
}