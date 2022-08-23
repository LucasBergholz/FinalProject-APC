#include <stdio.h>
    //Síntese
    //Objetivo: Definir a partir de 3 números se existe um triângulo;
    //Entrada:  3 números reais;
    //Saída:    Se houver o triângulo, o perímetro é a saída. Caso não haja o triângulo, a saída é a área de um trapézio;

int main() {
    float A, B, C;
    float teste;

    scanf("%f %f %f" , &A, &B, &C);

    if (A < (B + C) && B < (A + C) && C < (B + A)){
        teste = A + B + C;
        printf("Perimetro = %.1f\n" , teste);

    } else {
        teste = ((A+B)*C)/2;
        printf("Area = %.1f\n" , teste);
    }


    return 0;
}
