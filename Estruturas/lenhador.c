

#include <stdio.h>

#define MAXLINHA 1000
#define MAXCOLUNAS 11



char matrix[MAXLINHA][MAXCOLUNAS];

void InicioMatriz(int Linhas);
void Tela(int Linhas);
void Arvore(char Ladogalho, int Galho);

char Muda_lado(char Lado1lenhador, int Linhas);
int NewTronco(char Lado1lenhador, int Linhas);

void Atualizacao(char Lado1lenhador, int Linhas);
void PersLenhador(char Lado1lenhador);


int main(int argc, char const *argv[]){


    int Linhas, X, Galho;
    int i = 0, quebrado = 0 ;
    
    char instrucoes[2000], Ladogalho, Lado1lenhador;



    scanf("%d", &Linhas);
    getchar();

    InicioMatriz(Linhas);


    scanf("%d", &X);
    getchar();



    for(int i = 0 ; i < X ; i++){

        scanf("%c %d", &Ladogalho, &Galho);
        
        getchar();

        Arvore(Ladogalho,Galho);

    }

    scanf("%c", &Lado1lenhador);
    
    getchar();



    PersLenhador(Lado1lenhador);
    Tela(Linhas);


    scanf("%s", instrucoes);

    while(instrucoes[i]!='\0'){

        if(instrucoes[i] == 'T') Lado1lenhador = Muda_lado(Lado1lenhador, Linhas);
        if( instrucoes[i] == 'B' ) quebrado = NewTronco(Lado1lenhador, Linhas);
        if(quebrado == 1 ){


            printf("*morreu*\n");
            return 0;

        }

        i++;

    }


    return 0;
}

//---------------------------------------

void InicioMatriz(int Linhas){

    for(int i = 0 ; i < MAXLINHA ; i++){

        for(int j = 0 ; j < MAXCOLUNAS ; j++){

            if( j >= 4 && j <=6 && i >= MAXLINHA - Linhas) matrix[i][j] = '|';


            else matrix[i][j] = ' ';

        }

    }

}



void Tela(int Linhas){

    printf("~~~~~~~~~~~\n");


    for(int i = MAXLINHA - 5  ; i < MAXLINHA ; i++){


        for(int j = 0 ; j < MAXCOLUNAS ; j++){

            printf("%c", matrix[i][j]);



        }

        printf("\n");

    }


    printf("~~~~~~~~~~~\n");

}



void Arvore (char Ladogalho, int Galho) {

    if ( Ladogalho == 'D'){

        matrix[MAXLINHA-Galho][8] = '-';
        matrix[MAXLINHA-Galho][9] = '-';
        matrix[MAXLINHA-Galho][10] = '-';



    } else if ( Ladogalho == 'E' ){
        

        matrix[MAXLINHA-Galho][0] = '-';
        matrix[MAXLINHA-Galho][1] = '-';
        matrix[MAXLINHA-Galho][2] = '-';



    }


}

void PersLenhador(char Lado1lenhador){


    if ( Lado1lenhador == 'D' ) {

        matrix[MAXLINHA-2][8] = 'L';
        matrix[MAXLINHA-1][8] = 'L';



    } else if ( Lado1lenhador == 'E' ) {

        matrix[MAXLINHA-2][2] = 'L';
        matrix[MAXLINHA-1][2] = 'L';



    }

}


char Muda_lado(char Lado1lenhador, int Linhas){

        if( Lado1lenhador == 'D'){
            

            if( matrix[MAXLINHA-2][2] == '-' || matrix[MAXLINHA-1][2] == '-' ){

                printf("*beep*\n");
                return Lado1lenhador;

            } else {
                

                matrix[MAXLINHA-2][2] = 'L';
                matrix[MAXLINHA-1][2] = 'L';
                matrix[MAXLINHA-1][8] = ' ';
                matrix[MAXLINHA-2][8] = ' ';
                Lado1lenhador = 'E';
                Tela(Linhas);
                return Lado1lenhador;

            }

        } else if( Lado1lenhador == 'E'){


            if( matrix[MAXLINHA-2][8] == '-' || matrix[MAXLINHA-1][8] == '-' ){

                printf("*beep*\n");
                return Lado1lenhador;

            } else {

                matrix[MAXLINHA-2][8] = 'L';
                matrix[MAXLINHA-1][8] = 'L';
                matrix[MAXLINHA-1][2] = ' ';
                matrix[MAXLINHA-2][2] = ' ';
                Lado1lenhador = 'D';
                Tela(Linhas);
                return Lado1lenhador;


            }
        }

}



int NewTronco(char Lado1lenhador, int Linhas){

        if(Lado1lenhador == 'D' && matrix[MAXLINHA-1][6] == '|') matrix[MAXLINHA-1][6] = '<';

        else if(Lado1lenhador == 'E' && matrix[MAXLINHA-1][4] == '|') matrix[MAXLINHA-1][4] = '>';

        else if(Lado1lenhador == 'D' && matrix[MAXLINHA-1][6] == ' ') return 0;

        else if(Lado1lenhador == 'E' && matrix[MAXLINHA-1][4] == ' ') return 0;

        else if(Lado1lenhador == 'D' && matrix[MAXLINHA-1][6] == '<' && matrix[MAXLINHA-3][10]!='-') Atualizacao(Lado1lenhador, Linhas);

        else if(Lado1lenhador == 'E' && matrix[MAXLINHA-1][4] == '>' && matrix[MAXLINHA-3][1]!='-') Atualizacao(Lado1lenhador, Linhas);

        else return 1;


        Tela(Linhas);

    return 0;

}

void Atualizacao(char Lado1lenhador, int Linhas){

    for(int i = MAXLINHA ; i > MAXLINHA - Linhas -1; i--) {

        for(int j = 0 ; j < MAXCOLUNAS ; j++){
            
            
            matrix[i][j] = matrix[i-1][j];


        }

    }


    PersLenhador(Lado1lenhador);

}
