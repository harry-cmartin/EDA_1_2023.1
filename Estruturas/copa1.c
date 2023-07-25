#include <stdio.h>

int main(){
    int f = 8;
    int t = 0, teste = 0;

    char equipes[100] = {'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    for (int i = 1; i <= 4; i++){
        for (int i = 1; i <= f; i++){
            int t1 = 0;
            int t2 = 0;

    scanf("%d %d", &t1, &t2);

    if (t1 > t2){
        equipes[teste] = equipes[t];
        teste = teste + 1;
        t = t + 2;
    }
    else{
        equipes[teste] = equipes[t + 1];
            teste = teste + 1;
            t = t + 2;
    }
    if (teste == f){
        teste = 0;
        t = 0;
    }
}
    f = f / 2;
  }
    printf("%c\n", equipes[teste]);
}
