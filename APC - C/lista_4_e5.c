#include <stdio.h>
#include <string.h>

//Síntese
    //Objetivo: Desenvolver um algoritmo que decodifica matrings;
    //Entrada:  Uma matring;
    //Saída:    A string decodificada;

int main() {
    int i, j, tam;
    char N[82];

    scanf("%s", N);

    tam = strlen(N);

    int matriz[4][tam];

    for(i = 0; i < 4; i++){
        for(j = 0; j < tam; j++){
            if(i == 0){
                matriz[i][j] = (int)N[j]%48;
            } else {
                scanf("%1d", &matriz[i][j]);
        }
    }
    }

    int colunas[tam];
    i = 0;

    for(j = 0; j < tam; j++){
        colunas[j] = (1000 * matriz[i][j]) + (100 * matriz[i+1][j]) + (10 * matriz[i+2][j]) + (matriz[i+3][j]);
    }

    for(j = 1; j < tam-1; j++){
        printf("%c", (char)((colunas[0] * colunas[j] + colunas[tam-1])% 257));
    }

    printf("\n");

    return 0;
}
