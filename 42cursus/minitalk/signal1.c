#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig){
    if(sig == SIGUSR1){
        printf("SIGUSR1 is received\n");
    }
}

int main(){
    signal(SIGUSR1, handler);
    printf("PID : %d, waiting for SIGUSR1...\n", getpid());
    while(1)
        pause();

    return 0;
}