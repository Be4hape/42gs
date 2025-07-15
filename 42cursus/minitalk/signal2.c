#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler_usr1(int sig){
    (void)sig;
    printf("Received SIGUSR1\n");
}

void handler_usr2(int sig){
    (void)sig;
    printf("Received SIGUSR2\n");
}


int main(){
    struct sigaction sa1 = {0}, sa2 = {0};

    sa1.sa_handler = handler_usr1;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa1, NULL);

    sa2.sa_handler = handler_usr2;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = SA_RESTART;
    sigaction(SIGUSR2, &sa2, NULL);

    printf("PID %d : waiting for SIGUSR1 or SIGUSR2\n", getpid());
    while(1) pause();

    return 0;
}