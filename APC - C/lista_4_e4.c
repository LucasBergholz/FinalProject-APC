#include <stdio.h>
#include <string.h>

//S�ntese
    //Objetivo: Imprimir matrizes por meio de um padr�o, onde apenas 1, 2 e 3 seriam usados;
    //Entrada:  O n�mero de linhas e colunas;
    //Sa�da:    A matriz j� montada;

int main() {
    int N, i, j;

    int matriz[70][70];

    while(scanf("%d", &N) != EOF){
       for(i = 0; i < N; i++){
           for(j = 0; j < N; j++){
               if((i+j) == (N-1)){
                   matriz[i][j] = 2;
               } else if(i == j) {
                   matriz[i][j] = 1;
                } else if (i != j && (i+j) != (N - 1)) {
                   matriz[i][j] = 3;
               }
       }
       }
        for(i = 0; i < N; i++){
           for(j = 0; j < N; j++){
               printf("%d", matriz[i][j]);
       }
           printf("\n");
       }
   }


    return 0;
}
