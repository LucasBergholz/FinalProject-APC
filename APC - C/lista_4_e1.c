#include <stdio.h>
#include <string.h>

#define TAM 12

//S�ntese
    //Objetivo: Calcular a soma ou a m�dia dos valores de certa coluna de uma matriz;
    //Entrada:  A coluna C que ser� calculada a soma ou m�dia, os 144 valores que comp�em a matriz e o caracter S ou M que indicar� o c�lculo a ser feito;
    //Sa�da:    A soma ou m�dia da coluna C;

int main() {
    int L, i, j;
    char T;
    float matriz[TAM][TAM], soma, resultado = 0;
    soma = 0;

    scanf("%d", &L);
    scanf("%s", &T);

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            scanf("%f", &matriz[i][j]);
            soma = soma + matriz[L][j];
        }
    }

    switch(T) {
    case 'S':
        for(j = 0; j < TAM; j++){
            resultado = resultado + matriz[L][j];
        }
        break;

    case 'M':
        for(j = 0; j < TAM; j++){
            resultado = resultado + matriz[L][j];
        }
        resultado = resultado / TAM;
        break;
    }

    printf("%.1f\n", resultado);


    return 0;
}
