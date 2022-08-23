#include <stdio.h>
#include <string.h>

//Síntese
    //Objetivo: Pegar uma certa data e adaptá-la para outros modos de dispor ela;
    //Entrada:  A data;
    //Saída:    Os formatos diversos de escrevê-la;

int main() {
    int data[4];

    scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
    printf("%02d/%02d/%02d\n", data[1], data[0], data[2]);
    printf("%02d/%02d/%02d\n", data[2], data[1], data[0]);
    printf("%02d-%02d-%02d\n", data[0], data[1], data[2]);

    return 0;
}
