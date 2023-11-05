#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int saida = 0;


void represent(int a ) {
    saida = a;
}

int main (void){
    
    signal (SIGUSR1, represent);
    signal (SIGUSR2, represent);

    pause ();
    
    if(fork() == 0)
       exit(0);
       
    pause();
    
    wait(NULL);
    pause();
    
    exit(0);

}