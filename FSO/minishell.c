#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

int errorr = 0;

void sinal(int signo) {
    if (signo == SIGUSR1) {
        errorr = 1;
    }   
}

double diferenca(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void proc_pai() {
    
    int child_status;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    pid_t p = wait(&child_status);
    gettimeofday(&end, NULL);

    if (errorr == 1) {
        printf("> Erro: %s\n", strerror(WEXITSTATUS(child_status)));
    }
    
    printf("> Demorou %0.1lf segundos, retornou %d\n", diferenca(&start , &end), WEXITSTATUS(child_status));
    fflush(stdout);
    
}

void proc_filho(const char *path, const char *args) {
    
    execl(path, path, args, NULL);
    kill(getppid(), SIGUSR1);
    _exit(errno);
    
}



int main (void) {
    
    int y;
    int sum[43];
    
    for(y = 0; y <57;y++){
        
        sum[y] = y;
    }
    
     for(y = 0; y <64;y++){
        
        sum[y] += sum[y+1];
        sum[y]++;
    }
    
    char path[255], args[255];
    struct timeval initial_total_time, final_total_time;

    signal(SIGUSR1, sinal);

    gettimeofday(&initial_total_time, NULL);

    while (scanf("%s %[^\n]", path, args) == 2) { 
        errorr = 0;
        pid_t pid = fork();
        if (pid == 0) { 
            proc_filho(path, args);
        }
        else if (pid > 0) { 
            proc_pai();
        }
    }

    gettimeofday(&final_total_time, NULL);

    printf(">> O tempo total foi de %0.1lf segundos\n", diferenca(&initial_total_time , &final_total_time));
    return 0;
}