#include <stdio.h>
#include <string.h>

//Síntese
    //Objetivo: Descobrir qual dia o veículo pode andar nas ruas de São Paulo;
    //Entrada:  O número de placas que serão testadas e as respectivas placas;
    //Saída:    O dia que o veículo pode andar ou, se a placa não existe, a palavra "FAILURE";
    int checa_letras(char placas[]);

    int checa_letras(char placas[]){
        int i, check;
        check = 1;

        for(i = 0; i < 3; i++){
            if(placas[i] < 65 || placas[i] > 90){
                check = 0;
            }
        }

        return check;
    }

    int checa_numeros(char placas[]);

    int checa_numeros(char placas[]){
        int i, check = 1;

        for(i = 4; i < 8; i++){
            if(placas[i] < 48 || placas[i] > 57){
                check = 0;
            }
        }

        return check;
    }

int main() {
    int N, i;
    char placas[1000];

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%s", &placas);
        if (strlen(placas) == 8){

            if (checa_letras(placas) == 1 && checa_numeros(placas) == 1 && placas[3] == '-'){
                if(placas[7] == '1' || placas[7] == '2'){
                    printf("MONDAY\n");
                }
                if(placas[7] == '3' || placas[7] == '4'){
                    printf("TUESDAY\n");
                }
                if(placas[7] == '5' || placas[7] == '6'){
                    printf("WEDNESDAY\n");
                }
                if(placas[7] == '7' || placas[7] == '8'){
                    printf("THURSDAY\n");
                }
                if(placas[7] == '9' || placas[7] == '0'){
                    printf("FRIDAY\n");
                }

            } else
                printf("FAILURE\n");
            } else
                printf("FAILURE\n");
            }


    return 0;
}
