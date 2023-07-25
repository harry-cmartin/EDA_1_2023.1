
#include <stdio.h>

int Func_de_9s (int n , int * De9s){
	
	int soma = 0;
	
	if (n < 10){
		    
		if (n % 9 == 0) return 1;
		else return 0;
	
	}else{
		
	    while (n > 0){
			soma += n % 10;
		    n /=10;				 		 		 
		}
		   
		(*De9s)++;
		
		return Func_de_9s(soma,De9s);
	}
	
	
	
}



int main (){
    
	char String[10000];
	
	int Somador = 0, i;
	
	int De9s = 0;
	
	while (1){
	    
	    
	scanf ("%s",String);
		
	if (String[0] == '0')
	break;			
			
		for (i = 0; String[i]!='\0'; i++){
			Somador += String[i] - 48;		
		}
			
		if (Func_de_9s(Somador,&De9s)){
		    
		printf ("%s is a multiple of 9 and has 9-degree %d.\n", String,  De9s+1);
			
		}else{
		    
		printf ("%s is not a multiple of 9.\n", String);
		
		}

	De9s  = 0;
	Somador = 0;
		
	}
	

	return 0;
}
