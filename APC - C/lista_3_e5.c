#include <stdio.h>
#include <string.h>

//S�ntese
    //Objetivo: Pegar uma certa data e adapt�-la para outros modos de dispor ela;
    //Entrada:  A data;
    //Sa�da:    Os formatos diversos de escrev�-la;

int main() {
    int data[4];

    scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
    printf("%02d/%02d/%02d\n", data[1], data[0], data[2]);
    printf("%02d/%02d/%02d\n", data[2], data[1], data[0]);
    printf("%02d-%02d-%02d\n", data[0], data[1], data[2]);

    return 0;
}
