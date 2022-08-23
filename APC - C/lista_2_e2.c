#include <stdio.h>
//Síntese
    //Objetivo: Descobrir qual quadrante pertence certo ponto;
    //Entrada:  As coordenadas do ponto;
    //Saída:    Qual quadrante ele pertence;

void quadrante(int X, int Y);

void quadrante(int X, int Y) {
    int resultado[100], contador, limite;
    contador = 0;

    do{
    scanf("%d %d", &X, &Y);

        if( X > 0 && Y > 0){
            resultado[contador] = 1;
            contador = contador + 1;
   }
        if( X < 0 && Y > 0){
            resultado[contador] = 2;
            contador = contador + 1;
   }
        if( X < 0 && Y < 0){
            resultado[contador] = 3;
            contador = contador + 1;
   }
        if(X > 0 && Y < 0){
            resultado[contador] = 4;
            contador = contador + 1;
   }

    }while (X != 0 && Y != 0);

    limite = contador;

    for (contador = 0; contador <= limite; contador++){
        if(resultado[contador] == 1){
            printf("primeiro\n");
   }
        if(resultado[contador] == 2){
            printf("segundo\n");
   }
        if(resultado[contador] == 3){
            printf("terceiro\n");
   }
        if(resultado[contador] == 4){
            printf("quarto\n");
   }

    }

}

int main() {
    int X, Y;

    quadrante(X, Y);

    return 0;
}
