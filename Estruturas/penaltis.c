#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int i;
    int lance = 1, fim = 0;
    int chutes1 = n, chutes2 = n;
    int gol1 = 0, gol2= 0;
    char timeA[n + 1], timeB[n + 1];
    scanf(" %s %s", timeA, timeB);

    for(i = 0; i < n; i++){
        if(timeA[i] == 'o'){
            gol1++;
        }
        chutes1--;
        if(gol1 > gol2 + chutes2 || gol2 > gol1 + chutes1){
            fim = lance;
            break;
        }
        lance++;
        if(timeB[i] == 'o'){
            gol2++;
        }
        chutes2--;
        if(gol1 > gol2 + chutes2 || gol2 > gol1 + chutes1){
            fim = lance;
            break;
        }
        lance++;
    }
    if(fim == 0){
        printf("Empate\n");
    }
    else{
        printf("%d\n", fim);
    }
    return 0;
}