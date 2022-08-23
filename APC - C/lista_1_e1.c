#include <stdio.h>
    //S�ntese
    //Objetivo: Calcular o salario de um cidadao;
    //Entrada:  O numero correspondente ao funcionario, as horas trabalhadas e o valor da hora;
    //Sa�da:    O numero correspondente ao funcionario e o valor de seu salario;

int main() {
    int n_func, horas;
    float valor_horas, salario;

    scanf("%d" , &n_func);
    scanf("%d" , &horas);
    scanf("%f" , &valor_horas);

    salario = horas * valor_horas;

    printf("NUMBER = %d\n" , n_func);
    printf("SALARY = U$ %.2f\n" , salario);

    return 0;
}
