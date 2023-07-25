#include <stdio.h>
int pares(char *str){
    if(str[2] == '\0'){
        return 0;
    }
    else if(*str == str[2]){
        return pares(str + 1) + 1;  
    }
    else{
        return pares(str + 1);
    }  
}
int main(){
    char str [201];
    scanf("%s", str);
    printf("%d\n", pares(str));
    return 0;
}