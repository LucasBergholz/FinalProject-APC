#include <stdio.h>
    //S�ntese
    //Objetivo: Definir a partir de 3 n�meros se existe um tri�ngulo;
    //Entrada:  3 n�meros reais;
    //Sa�da:    Se houver o tri�ngulo, o per�metro � a sa�da. Caso n�o haja o tri�ngulo, a sa�da � a �rea de um trap�zio;

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
