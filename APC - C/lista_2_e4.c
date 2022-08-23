#include <stdio.h>
//S�ntese
    //Objetivo: Descobrir se o n�mero � perfeito ou n�o;
    //Entrada:  N testes que ser�o feitos e o n�mero de cada teste;
    //Sa�da:    Para cada n�mero a resposta se ele � perfeito ou n�o;

int perfeito(int X);

int perfeito(int X) {
    int divisor, contador, soma;
    float resto;
    soma = 0;

    for(contador = 1; contador < X; contador++){
        if(X % contador == 0) {
            divisor = contador;
            soma = soma + divisor;
        }
    }

    if(soma == X){
        return 1;
    } else if (soma != X) {
        return 0;
    }
}

int main() {
    int N, X;
    scanf("%d", &N);

    for(N = N; N > 0; N--){
        scanf("%d", &X);
        if(perfeito(X) == 1){
            printf("%d eh perfeito\n", X);
        } else if(perfeito(X) == 0) {
            printf("%d nao eh perfeito\n", X);
        }

    }

    return 0;
}
