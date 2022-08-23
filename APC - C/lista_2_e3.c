#include <stdio.h>
//Síntese
    //Objetivo: A partir de certo número, a saída será uma sequência lógica;
    //Entrada:  Certo número N;
    //Saída:    A sequência lógica;

void seq_logica(unsigned int N);

void seq_logica(unsigned int N) {
    int contador, i;
    i = 1;

     for (contador = 0; contador < N; contador++){
        printf("%d %d %d\n", i, (i*i), (i*i*i));
        printf("%d %d %d\n", i, (i*i)+1, (i*i*i)+1);
        i = i + 1;

    }

}

int main() {
    int N;
    scanf("%d", &N);

    seq_logica(N);

    return 0;
}
