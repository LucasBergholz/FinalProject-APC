#include <stdio.h>
#include <math.h>
    //Síntese
    //Objetivo: Calcular a distância entre dois pontos;
    //Entrada:  As coordenadas dos dois pontos;
    //Saída:    A distância entre esses pontos;

int main() {
    float x1, y1, x2, y2;
    float resultado;

    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    resultado = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));

    printf("%.4f\n" , resultado);

    return 0;
}
