
#include <stdio.h>
#include <string.h>

int main() {
    
    char string[1000];
    
    scanf("%s", string);
    
    int i = strlen(string) - 1;
    
    for(int x = i; x >= 0; x--){
        
        printf("%c", string[x]);
    
    }
    return 0;
}