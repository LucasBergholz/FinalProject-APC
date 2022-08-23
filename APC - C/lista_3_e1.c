#include <stdio.h>
#include <string.h>

//Síntese
    //Objetivo: Escrever uma sequência de números e dizer qual o menor dele e sua posição;
    //Entrada:  A quantidade N de números e os N números;
    //Saída:    O menor valor e a posição dele;

int main() {
    int N, X[1000], contador;
    int i, save_menor_valor, save_posicao;

    scanf("%d", &N);

    for(contador = 0; contador < N; contador++) {
        scanf("%d", &X[contador]);

    }
    save_menor_valor = X[0];

    for(i = 0; i < N; i++) {

        if(i == 0){
            save_menor_valor = save_menor_valor;

        }else if(X[i] < save_menor_valor) {
            save_menor_valor = X[i];
            save_posicao = i;
        }
    }


    printf("Menor valor: %d\n", save_menor_valor);
    printf("Posicao: %d\n", save_posicao);

    return 0;
}
