#include <stdio.h>
#include <string.h>

//S�ntese
    //Objetivo: Separar os 4 n�meros presentes em um CPF;
    //Entrada:  O CPF;
    //Sa�da:    Os 4 n�meros em sequ�ncia;

int main() {
    int cpf[4];

    scanf("%d.%d.%d-%d" , &cpf[0], &cpf[1], &cpf[2], &cpf[3]);
    printf("%03d\n" , cpf[0]);
    printf("%03d\n" , cpf[1]);
    printf("%03d\n" , cpf[2]);
    printf("%02d\n" , cpf[3]);

    return 0;
}
