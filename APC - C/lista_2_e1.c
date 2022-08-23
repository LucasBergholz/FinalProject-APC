#include <stdio.h>
    //Síntese
    //Objetivo: Ajudar Maria a calcular e organizar seu experimento;
    //Entrada:  N casos, a quantia de cada caso e o tipo de cobaia;
    //Saída:    Total de cobaias e de cada um dos tipos e o percentual de cada tipo usado;

void porcentagem(int C, int R, int S, int total);

void porcentagem(int C, int R, int S, int total) {
    float pCoelho, pRato, pSapo;

    pCoelho =(float) C/total;
    pRato = (float) R/total;
    pSapo =(float) S/total;

    printf("Percentual de coelhos: %.2f %%\n", pCoelho*100);
    printf("Percentual de ratos: %.2f %%\n", pRato*100);
    printf("Percentual de sapos: %.2f %%\n", pSapo*100);
}

int main() {
    int N, quantia, C, R, S, total;
    char tipo;

    C = 0;
    R = 0;
    S = 0;

    scanf("%d", &N);
    for(N = N; N > 0; N--) {
        scanf("%d %c", &quantia, &tipo);
        switch (tipo) {
            case 'C':
            C = C + quantia;
                break;
            case 'R':
            R = R + quantia;
                break;
            case 'S':
            S = S + quantia;
                break;
        }
    }

    total = C + R + S;
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", C);
    printf("Total de ratos: %d\n", R);
    printf("Total de sapos: %d\n", S);
    porcentagem(C, R, S, total);

    return 0;
}
