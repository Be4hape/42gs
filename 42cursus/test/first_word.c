#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){    
    unsigned int i = 0;
    if(argc == 2 && argv[1]){
        while(argv[1][i] == 32 || argv[1][i] == 9)
            i++;
        while(argv[1][i] && !(argv[1][i] == 32 || argv[1][i] == 9)){
            write(1, &argv[1][i], 1);
            i++;
        }
        write(1, "\n", 1);
        return 0;
    }
    write(1, "\n", 1);
    return 0;
}