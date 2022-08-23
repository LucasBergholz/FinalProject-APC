#include <stdio.h>
#include <string.h>

//S�ntese
    //Objetivo: Escrever uma sequ�ncia de n�meros e dizer qual o menor dele e sua posi��o;
    //Entrada:  A quantidade N de n�meros e os N n�meros;
    //Sa�da:    O menor valor e a posi��o dele;

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
