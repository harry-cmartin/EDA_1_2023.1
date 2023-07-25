
#include <stdio.h>
#include <string.h>

int main() {
    
    char string[1000];
    
    scanf("%s", string);
    
    int i = strlen(string);
    
    printf("%d", i);
    return 0;
}