#include <stdio.h>
//Síntese
    //Objetivo: Descobrir se o número é perfeito ou não;
    //Entrada:  N testes que serão feitos e o número de cada teste;
    //Saída:    Para cada número a resposta se ele é perfeito ou não;

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
