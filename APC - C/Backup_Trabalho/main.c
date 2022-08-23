/*#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 9999

//S�ntese
    //Objetivo: Produzir um algotimo que cadastre voos e reservas, sendo poss�vel cancelar ou excluir os mesmos;
    //Entrada:  N�mero da reserva, n�mero do voo, CPF do passageiro, nome completo do passageiro, sexo, data de nascimento, status da reserva (ativa ou cancelada);
    //Sa�da:    Qualquer informa��o cadastrada;

void flush_in();

void Cadastrar_voo(int i);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int i = 0; //Vai identificar qual o voo cadastrado;

    //Desenvolvendo a apar�ncia do menu de op��es;
    printf("===============================================================\n");
    printf("========== Bem-vindo � reserva de viagens especiais! ==========\n");
    printf("===============================================================\n");
    printf("\n");

    printf("Escolha uma das op��es abaixo:\n");
    printf("\n");

    printf("1) Cadastrar voo\n2) Cadastrar reserva\n3) Consultar voo\n4) Consultar reserva\n5) Consultar passageiro\n6) Cancelar voo\n7) Cancelar reserva\n8) Excluir voo\n9) Sair do programa\n");
    printf("\n");

    //Habilitando as op��es e suas respectivas a��es;
    int opcao;
    char verificador = 'S'; //Ser� usado para repetir o programa caso a op��o escolhida seja inv�lida;

    do{
    scanf("%d", &opcao);
    flush_in();

    switch (opcao){
        case 1: //Cadastro do voo por meio de um procedimento;
            Cadastrar_voo(i);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Essa escolha n�o � v�lida, tente novamente!\n");
    }
        printf("\nGostaria de fazer outra a��o? (S/N)\n");
        scanf("%c", &verificador);
        if (verificador != 'N' || verificador != 'n'){
            printf("\nEscolha uma das op��es:\n");
        }

    } while (verificador != 'N' && verificador != 'n');

    return 0;
        }

    void flush_in(){
        int ch;
        while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void Cadastrar_voo (int i) {
    //Declarando as vari�veis para o cadastramento;
    int contador = 0;

    struct registro_voo{
        int numeroVoo[MAX];
        int qntdMaxPassageiros[MAX];
        int data[3][MAX];
        int hora[2][MAX];
        char statusVoo[MAX];
    };

    struct registro_voo voo;
    //Menu do cadastramento;
    printf("\n");
    printf("==========================================\n");
    printf("========== Cadastramento de Voo ==========\n");
    printf("==========================================\n");
    printf("\n");

    //Entrada dos dados necess�rios;
    printf("Qual o n�mero do voo?\n");
    scanf("%d", &voo.numeroVoo[contador]);
    i = voo.numeroVoo[contador];
    printf("Qual o m�ximo de passageiros no voo?\n");
    scanf("%d", &voo.qntdMaxPassageiros[i]);
    printf("Qual a data do voo?\n");
    scanf("%d/%d/%d", &voo.data[0][i], &voo.data[1][i], &voo.data[2][i]);
    printf("Qual a hora de partida do voo?\n");
    scanf("%d:%d", &voo.hora[0][i], &voo.hora[1][i]);


}

*/
