#include <stdio.h>

void troca(char *str){
    if(*str == '\0'){
        return;
    }
    else if(*str == 'x'){
        printf("y");
        return troca(str + 1); 
    }
    else{
        printf("%c", *str);
        return troca(str + 1);
    }
}
int main(void){
    char str[81];
    scanf("%s", str);
    troca(str);
    return 0;
}