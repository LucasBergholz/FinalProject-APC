#include <stdio.h>
    //Síntese
    //Objetivo: Calcular o imposto de renda de um cidadão de Lisarb;
    //Entrada:  Sua renda;
    //Saída:    Valor do imposto de renda;

int main() {
    float renda;
    float imposto;

    scanf("&f" , &renda);

    if (renda > 4500){
        imposto = (1000*1.08) + (1500*1.18) + ((renda-4500)*1.28);

    } else if (renda > 3000 && renda <= 4500){
        imposto = (1000*1.08) + ((renda-3000)*1.18);

     } else if (renda > 2000 && renda <= 3000) {
        imposto = (renda-2000)*1.08;

     } else {
      imposto = 0;
    }

    if (imposto == 0) {
        printf("Isento\n");

    } else {
        printf("R$ %f" , imposto);

    }


    return 0;
}
