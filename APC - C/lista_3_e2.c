#include <stdio.h>
#include <string.h>

//Síntese
    //Objetivo: Checar quantos estudantes de uma classe estão acima da média dessa turma;
    //Entrada:  Os C casos, os N alunos e as suas respectivas notas;
    //Saída:    A porcentagem de alunos com notas acima da média da turma;

int main() {
    int i, contador, C, N;
    float media, aadm;

        scanf("%d", &C);

        for(i = 0; i < C; i++){
            aadm = 0;
            media = 0;
            scanf("%d", &N);
            int notas[N];
            for(contador = 0; contador < N; contador++){
                scanf("%d", &notas[contador]);
            }
            for(contador = 0; contador < N; contador++){
                media = media + notas[contador];
            }
            media = media/N;
            for(contador = 0; contador < N; contador++){
                if(notas[contador] > media){
                    aadm++;
                }
            }
            aadm = (aadm*100)/N;
            printf("%.3f%%\n", aadm);
        }

    return 0;
}
