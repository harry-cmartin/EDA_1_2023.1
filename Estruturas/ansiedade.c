

#include <stdio.h>
#include <string.h>


int main(){
    
    char sins[3];
    int verificador = 0, TRIAGENS = 0;
    int leitor,i;

   for(i = 0; i < 10; i++){
       
       
       
       leitor = scanf("%s", sins);

       if(leitor == 1){
           
            if((tolower (sins[0]) == 's' && tolower(sins[1]) == 'i' && tolower (sins[2]) == 'm')
            || (tolower (sins[0]) == 'n' && tolower (sins[1]) == 'a' && tolower (sins[2]) == 'o')){
            if((tolower (sins[0]) == 's' && tolower(sins[1]) == 'i' && tolower (sins[2]) == 'm')){
                verificador++;
            }}
            
        else
        
            i--;
            
        if(i == 9 && verificador >= 2){
            
            TRIAGENS++;
            verificador = 0;
            
            i = -1;
        }
        else if(i == 9){
            
            verificador = 0;
            i = -1;
            
        }}
       else if(leitor == - 1 && i != 0)
       
            i --;
            
       else
       
            break;
       }
       
 
    printf("%d\n", TRIAGENS);
}
