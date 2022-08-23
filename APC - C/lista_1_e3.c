#include <stdio.h>
    //Síntese
    //Objetivo: Calcular o horário a partir de um número "bruto";
    //Entrada:  Um número N;
    //Saída:    O horário;

int main() {
    int N, hora, minuto, segundo;

    hora = 0;
    minuto = 0;
    segundo = 0;

    scanf("%d", &N);

    if (N < 60) {
        segundo = N;

    }else if (N < 3600 && N >= 60){
        minuto = N/60;
        segundo = N%60;

    }
     else if (N >= 3600) {
        hora = N/3600;
        N = N%3600;
        minuto = N/60;
        N = N%60;
        segundo = N;
    }

    printf("%d:%d:%d\n" , hora, minuto, segundo);


    return 0;
}
