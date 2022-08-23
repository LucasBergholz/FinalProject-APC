#include <stdio.h>
//Síntese
    //Objetivo: Descobrir quem achou o maior valor definida pelas funções de cada aluno;
    //Entrada:  Um número N de testes e os inteiros X e Y de cada teste;
    //Saída:    Quem ganhou entre o s três alunos;

    int f_rafael(int X, int Y);
    int f_beto(int X, int Y);
    int f_carlos(int X, int Y);

    int f_rafael(int X, int Y) {
        float resultado;

        resultado = (3*X*3*X) + (Y*Y);

        return resultado;
    }

    int f_beto(int X, int Y) {
        float result;

        result = (2*X*X)+(5*Y*5*Y);

        return result;
    }

        int f_carlos(int X, int Y) {
        float res;

        res = (-100*X) + (Y*Y*Y);

        return res;
    }

int main() {
    int N, X, Y, contador;

    scanf("%d", &N);

    for(contador = 0; contador < N; contador++){
        scanf("%d %d", &X, &Y);
        if(f_rafael(X, Y) > f_beto(X, Y) && f_rafael(X, Y) > f_carlos(X, Y)){
                printf("Rafael ganhou\n");
   }
        else if(f_beto(X, Y) > f_rafael(X, Y) && f_beto(X, Y) > f_carlos(X, Y)){
                printf("Beto ganhou\n");
        }
        else if(f_carlos(X, Y) > f_rafael(X, Y) && f_carlos(X, Y) > f_beto(X, Y)){
                printf("Carlos ganhou\n");
   }
    }


    return 0;
}
