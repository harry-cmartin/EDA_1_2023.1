

#include <stdio.h>


void isc(char *copiar){
    
    if(copiar[0] == '\0'){
        
        return;
    }
    
    if(copiar[0] != 'x'){
        
        printf("%c", copiar[0]);
    }
    
    
    
   isc(&copiar[1]);
   
   if(copiar[0] == 'x'){
       
      printf("%c", copiar[0]);
       
   }
  

}

int main()
{
   
   char v[100];
   
   scanf("%s\n", v);
   
   isc(v);

    return 0;
}

