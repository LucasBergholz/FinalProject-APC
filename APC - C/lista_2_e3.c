#include <stdio.h>
//S�ntese
    //Objetivo: A partir de certo n�mero, a sa�da ser� uma sequ�ncia l�gica;
    //Entrada:  Certo n�mero N;
    //Sa�da:    A sequ�ncia l�gica;

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
