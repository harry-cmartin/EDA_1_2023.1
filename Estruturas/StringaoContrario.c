#include <stdio.h>

void aocontrario(char *str){
    if(*str == '\0'){
        return;
    }
    else{
        aocontrario(str + 1);
        printf("%c", *str);
    }
}
int main(void){
    char str[501];
    scanf("%s", str);
    aocontrario(str);
    return 0;
}