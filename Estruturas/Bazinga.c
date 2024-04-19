
#include <stdio.h>
#include <string.h>

int main()
{
    
    char sheldon[50], raj[50];
    
    scanf("%s %s", sheldon, raj);
    
    if(strcmp(sheldon,raj) == 0){
        printf("De novo!\n");
        
    }else if(strcmp(sheldon, "pedra") == 0 && (strcmp(raj, "lagarto") == 0 ||  strcmp(raj, "tesoura") == 0 )){
        printf("Bazinga!\n");
    }else if(strcmp(sheldon, "pedra") == 0 && !(strcmp(raj, "lagarto") == 0 ||  strcmp(raj, "tesoura") == 0 )){
         printf("Raj trapaceou!\n");
    }else if(strcmp(sheldon, "papel") == 0 && (strcmp(raj, "pedra") == 0 ||  strcmp(raj, "Spock") == 0 )){
        printf("Bazinga!\n");
    }else if(strcmp(sheldon, "papel") == 0 && !(strcmp(raj, "pedra") == 0 ||  strcmp(raj, "Spock") == 0 )){
         printf("Raj trapaceou!\n");
    }else if(strcmp(sheldon, "tesoura") == 0 && (strcmp(raj, "papel") == 0 ||  strcmp(raj, "lagarto") == 0)){
        printf("Bazinga!\n");
    }else if(strcmp(sheldon, "tesoura") == 0 && !(strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0 )){
         printf("Raj trapaceou!\n");
    }else if(strcmp(sheldon, "Spock") == 0 && (strcmp(raj, "tesoura") == 0 ||  strcmp(raj, "pedra") == 0 )){
        printf("Bazinga!\n");
    }else if(strcmp(sheldon, "Spock") == 0 && !(strcmp(raj, "tesoura") == 0 ||  strcmp(raj, "pedra") == 0 )){
         printf("Raj trapaceou!\n");
    }else if(strcmp(sheldon, "lagarto") == 0 && (strcmp(raj, "Spock") == 0 ||  strcmp(raj, "papel") == 0 )){
        printf("Bazinga!\n");
    }else if(strcmp(sheldon, "lagarto") == 0 && !(strcmp(raj, "Spock") == 0 ||  strcmp(raj, "papel") == 0 )){
         printf("Raj trapaceou!\n");
    }
    
    
    return 0;
}
