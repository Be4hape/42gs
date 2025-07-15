#include <stdio.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    int i = 0;
    pid_t server_pid;
    
    //argv[][]
    if(argc == 3)
    {
        while(argv[i]){
            if(argv[i] == 1){
               kill(server_pid, SIGUSR1);
            }
            i++;
        }
    }
}
