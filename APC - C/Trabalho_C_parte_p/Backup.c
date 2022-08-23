#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define MAX 9999

//S�ntese
    //Objetivo: Produzir um algotimo que cadastre voos e reservas, sendo poss�vel cancelar ou excluir os mesmos;
    //Entrada:  N�mero da reserva, n�mero do voo, CPF do passageiro, nome completo do passageiro, sexo, data de nascimento, status da reserva (ativa ou cancelada);
    //Sa�da:    Qualquer informa��o cadastrada;

void flush_in();

void Cadastrar_voo();

void Cadastrar_reserva();

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *pont_DadosDoVoo; //Criando ponteiro que guardar� as informa��es do voo;

    pont_DadosDoVoo = fopen("dadosdovoo.txt", "a"); //Abrindo o arquivo para uso ao longo do c�digo;

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
            system("cls || clear");
            Cadastrar_voo();
            break;
        case 2:
            system("cls || clear");
            Cadastrar_reserva();
            break;
        case 3:
            system("cls || clear");
            break;
        case 9:
            verificador = 'n';
            break;
        default:
            printf("\nEssa escolha n�o � v�lida, tente novamente!\n");
    }
        if (verificador != 'n'){
            printf("\nGostaria de fazer outra a��o? (S/N)\n");
            scanf("%c", &verificador);
            flush_in();

            if (verificador != 'N' && verificador != 'n'){ //Vai repetir o processo de mostrar o menu e pedir que o usu�rio escolha uma das op��es;
                system("cls || clear");
                printf("Escolha uma das op��es abaixo:\n\n");
                printf("1) Cadastrar voo\n2) Cadastrar reserva\n3) Consultar voo\n4) Consultar reserva\n5) Consultar passageiro\n6) Cancelar voo\n7) Cancelar reserva\n8) Excluir voo\n9) Sair do programa\n\n");
            }
        }

    } while (verificador != 'N' && verificador != 'n');

    fclose(pont_DadosDoVoo);

    return 0;
        }

void flush_in(){ //Usada pra parar alguns bugs do c�digo;
       int ch;
       while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

struct voo{ //Struct com as informa��es que ser�o guardadas;
        char idVoo[8];
        int capacidade, ocupacao;
        int dia, mes, ano;
        int hora, minuto;
        char statusVoo;
    };

void Cadastrar_voo () {
    struct voo registro; //Criando a rede de vari�veis para o cadastramento do voo;

    //Menu do cadastramento;
    printf("==========================================\n");
    printf("========== Cadastramento de Voo ==========\n");
    printf("==========================================\n");
    printf("\n");

    //Entrada dos dados necess�rios;
    numero_voo(registro);
    printf("Qual o m�ximo de passageiros no voo?\n");
    scanf("%d", &registro.capacidade);
    data_voo(registro);
    hora_voo(registro);
    status_voo(registro);
    printf("\nO cadastro do voo foi um sucesso!\n");
}

void numero_voo(struct voo registro);

void numero_voo(struct voo registro){ //Verificar a validade do dado do n�mero de voo;
    int repetidor = 0; //Manter um loop at� que o usu�rio digite um valor correto de id de voo;

    do{
        printf("Qual o n�mero do voo? (JEB-XXXX)\n");
        scanf("%s", &registro.idVoo);

        if(registro.idVoo[0] != 74 || registro.idVoo[1] != 69 || registro.idVoo[2] != 66 || registro.idVoo[3] != 45){ //Checando se a id do voo tem o "JEB-";
            printf("\nN�mero do voo n�o � v�lido, tente novamente.\n\n");

        } else if(registro.idVoo[4] < 48 || registro.idVoo[4] > 57){ //Checando os �ltimos 4 caracteres, garantindo que s�o n�meros;
            printf("\nN�mero n�o � v�lido, tente novamente.\n\n");

        } else if(registro.idVoo[5] < 48 || registro.idVoo[5] > 57){
            printf("\nN�mero do voo n�o � v�lido, tente novamente.\n\n");

        } else if(registro.idVoo[6] < 48 || registro.idVoo[6] > 57){
            printf("\nN�mero do voo n�o � v�lido, tente novamente.\n\n");

        } else if(registro.idVoo[7] < 48 || registro.idVoo[7] > 57){
            printf("\nN�mero do voo n�o � v�lido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}

void data_voo(struct voo registro);

void data_voo(struct voo registro){ //Verificar a validade da data do voo;
    time_t mytime; //Inicializando as vari�veis da biblioteca time.h;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
    int repetidor = 0; //Manter um loop at� que o usu�rio digite um valor correto de data;

    do{
        printf("Qual a data do voo? (XX/YY/ZZZZ)\n"); //Leitura da data;
        scanf(" %d/%d/%d", &registro.dia, &registro.mes, &registro.ano);

        if(registro.ano < (tm.tm_year + 1900)){ //Garantindo que n�o seja registrado um voo no passado;
            printf("\nEssa data n�o � v�lida, tente novamente.\n\n");

        } else if(registro.ano == (tm.tm_year + 1900) && registro.mes < (tm.tm_mon + 1)){
            printf("\nEssa data n�o � v�lida, tente novamente.\n\n");

        } else if(registro.ano == (tm.tm_year + 1900) && registro.mes == (tm.tm_mon + 1) && registro.dia <= tm.tm_mday){ //Desse if at� o primeiro if, est� se garantindo que n�o agende um voo para o passado;
            printf("\nEssa data n�o � v�lida, tente novamente.\n\n");

        } else {
            if(( registro.ano % 4 == 0 && registro.ano % 100 != 0) || registro.ano % 400 == 0) {
                if (registro.mes >= 1 && registro.mes <= 12) {
                if ((registro.dia < 1 || registro.dia > 31) && (registro.mes == 1 || registro.mes == 3 || registro.mes == 5 || registro.mes == 7 || registro.mes == 8 || registro.mes == 10 || registro.mes == 12)) {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                } else if ((registro.dia < 1 || registro.dia > 30) && (registro.mes == 4 || registro.mes == 6 || registro.mes == 9 || registro.mes == 11)) {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                } else if ((registro.dia < 1 || registro.dia > 29) && (registro.mes == 2)) {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                } else {
                    repetidor = 1;
                }
                } else {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                }

            } else {
                if (registro.mes >= 1 && registro.mes <= 12) {
                    if ((registro.dia < 1 || registro.dia > 31) && (registro.mes == 1 || registro.mes == 3 || registro.mes == 5 || registro.mes == 7 || registro.mes == 8 || registro.mes == 10 || registro.mes == 12)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else if ((registro.dia < 1 || registro.dia > 30) && (registro.mes == 4 || registro.mes == 6 || registro.mes == 9 || registro.mes == 11)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else if ((registro.dia < 1 || registro.dia > 28) && (registro.mes == 2)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else {
                        repetidor = 1;
                    }
                } else {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);
}


void hora_voo(struct voo registro);

void hora_voo(struct voo registro){ //Verificar a validade da hora do voo;

    int repetidor = 0; //Manter um loop at� que o usu�rio digite um valor correto de hor�rio;

    do{
        printf("Qual a hora de partida do voo? (XX:YY)\n");
        scanf("%d:%d", &registro.hora, &registro.minuto);

        if(registro.minuto > 59 || registro.minuto < 0 || registro.hora > 23 || registro.hora < 0){ //Garantindo que o hor�rio seja v�lido;
            printf("\nEsse hor�rio n�o � v�lido, tente novamente.\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}

void status_voo(struct voo registro);

void status_voo(struct voo registro){ //Verificar o status do voo;
    int repetidor = 0; //Vai manter um loop at� que o usu�rio digite um status correto;

    do{
        printf("Esse voo est� ativo ou cancelado? (A/C)\n");
        scanf("%c", &registro.statusVoo);
        flush_in();

        if(registro.statusVoo != 65 && registro.statusVoo != 67){ //Garantindo que o caracter seja: A ou C;
            printf("\nEsse status de voo n�o � v�lido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}

struct reserva{
    char idReserva[9];
    char cpf[11];
    char nomePassageiro[999];
    char sexo;
    int ddnDia, ddnMes, ddnAno; //ddn = data de nascimento, separei ela em 3 partes para facilitar a checagem da mesma;
    char statusReserva;
};

void Cadastrar_reserva() {
    struct reserva registrar; //Criando a rede de vari�veis para o cadastramento do registro;

    //Menu do cadastramento;
    printf("==============================================\n");
    printf("========== Cadastramento de Reserva ==========\n");
    printf("==============================================\n");
    printf("\n");

    //Entrada dos dados necess�rios;
    id_reserva(registrar);
    //numero_voo(registrar);
    cpf_passageiro(registrar);
    nome_passageiro(registrar);
    sexo_passageiro(registrar);
    data_nascimento(registrar);
    status_reserva(registrar);
    printf("\nO cadastro da reserva foi um sucesso!\n");



}

void id_reserva(struct reserva registrar);

void id_reserva(struct reserva registrar){
    int repetidor = 0; //Manter um loop at� que o usu�rio digite um valor correto da id da reserva;

    do{
        printf("Qual o n�mero da reserva? (GB-XXXXXX)\n");
        scanf("%s", &registrar.idReserva);

        if(registrar.idReserva[0] != 71 || registrar.idReserva[1] != 66 || registrar.idReserva[2] != 45){ //Checando se a id da reserva tem o "GB-";
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else if(registrar.idReserva[3] < 48 || registrar.idReserva[3] > 57){
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else if(registrar.idReserva[4] < 48 || registrar.idReserva[4] > 57){ //Checando os �ltimos 4 caracteres, garantindo que s�o n�meros;
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else if(registrar.idReserva[5] < 48 || registrar.idReserva[5] > 57){
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else if(registrar.idReserva[6] < 48 || registrar.idReserva[6] > 57){
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else if(registrar.idReserva[7] < 48 || registrar.idReserva[7] > 57){
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else if(registrar.idReserva[8] < 48 || registrar.idReserva[8] > 57){
            printf("\nN�mero de reserva n�o � v�lido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}

void cpf_passageiro(struct reserva registrar);

void cpf_passageiro(struct reserva registrar){
    int repetidor = 0, i;
    int validar; //Se validar = 0 o CPF foi escrito com algum caracter sem ser n�mero;

    do{
        validar = 1;
        printf("Qual o CPF do passageiro? (Escreva apenas os n�meros)\n");
        scanf("%s", &registrar.cpf);
        flush_in();

        for(i = 0; i < 11; i++){
            if(registrar.cpf[i] < 48 || registrar.cpf[i] > 57){ //Garantindo ser n�mero;
                validar = 0;
            }
        }

        if(validar == 0){
            printf("\nO CPF � inv�lido, tente novamente.\n\n");
        } else {
            repetidor = 1; //Retira o algoritmo do loop ap�s uma entrada v�lida dos dados pedidos;
        }

    } while(repetidor == 0);
}

void nome_passageiro(struct reserva registrar);

void nome_passageiro(struct reserva registrar){
    int tamanho, repetidor = 0, verificador;

    do{
        verificador = 1;
        printf("Digite o nome do passageiro:\n");
        scanf(" %[^\n]", registrar.nomePassageiro);
        flush_in();
        tamanho = strlen(registrar.nomePassageiro);

        for(int i = 0; i < tamanho; i++){
            if(registrar.nomePassageiro[i] < 65 && registrar.nomePassageiro[i] != 32){
               printf("\nO nome do passageiro � inv�lido, tente novamente.\n\n");
               verificador = 0;

            } else if(registrar.nomePassageiro[i] > 90){
                if(registrar.nomePassageiro[i] < 97 || registrar.nomePassageiro[i] > 122){
                    printf("\nO nome do passageiro � inv�lido, tntne novamente.\n\n");
                    verificador = 0;

                }
            }
        }

        if(verificador == 1){
            repetidor = 1;
        }

    } while(repetidor == 0);
}

void sexo_passageiro(struct reserva registrar);

void sexo_passageiro(struct reserva registrar){
    int repetidor = 0; //Vai manter um loop at� que o usu�rio digite um sexo correto;

    do{
        printf("Qual o sexo do passageiro? (M/F)\n");
        scanf("%c", &registrar.sexo);
        flush_in();

        if(registrar.sexo != 77 && registrar.sexo != 70){ //Garantindo que o caracter seja: A ou C;
            printf("\nEsse sexo n�o � v�lido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}


void data_nascimento(struct reserva registrar);

void data_nascimento(struct reserva registrar){
    time_t mytime; //Inicializando as vari�veis da biblioteca time.h;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
    int repetidor = 0; //Manter em um loop at� o usu�rio digitar uma data de nascimento v�lida;

    do{
        printf("Qual a data de nascimento do passageiro? (XX/YY/ZZZZ)\n"); //Leitura da data;
        scanf(" %d/%d/%d", &registrar.ddnDia, &registrar.ddnMes, &registrar.ddnAno);

        if(registrar.ddnAno > (tm.tm_year + 1900)){ //Garantindo que n�o ocorra um registro no futuro;
            printf("\nEssa data n�o � v�lida, tente novamente.\n\n");

        } else if(registrar.ddnAno == (tm.tm_year + 1900) && registrar.ddnMes > (tm.tm_mon + 1)){
            printf("\nEssa data n�o � v�lida, tente novamente.\n\n");

        } else if(registrar.ddnAno == (tm.tm_year + 1900) && registrar.ddnMes == (tm.tm_mon + 1) && registrar.ddnDia > tm.tm_mday){ //Desse if at� o primeiro if, est� se garantindo que n�o agende um voo para o passado;
            printf("\nEssa data n�o � v�lida, tente novamente.\n\n");

        } else {
            if(( registrar.ddnAno % 4 == 0 && registrar.ddnAno % 100 != 0) || registrar.ddnAno % 400 == 0) { //Checagem se o ano � bissexto;
                if (registrar.ddnMes >= 1 && registrar.ddnMes <= 12) { //Garantindo que o m�s � v�lido;
                    //Garantindo que o dia est� certo para o respectivo m�s;
                    if ((registrar.ddnDia < 1 || registrar.ddnDia > 31) && (registrar.ddnMes == 1 || registrar.ddnMes == 3 || registrar.ddnMes == 5 || registrar.ddnMes == 7 || registrar.ddnMes == 8 || registrar.ddnMes == 10 || registrar.ddnMes == 12)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 30) && (registrar.ddnMes == 4 || registrar.ddnMes == 6 || registrar.ddnMes == 9 || registrar.ddnMes == 11)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 29) && (registrar.ddnMes == 2)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else {
                        repetidor = 1;
                    }
                } else {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                }

            } else {
                if (registrar.ddnMes >= 1 && registrar.ddnMes <= 12) { //Garantindo que o m�s � v�lido;
                    if ((registrar.ddnDia < 1 || registrar.ddnDia > 31) && (registrar.ddnMes == 1 || registrar.ddnMes == 3 || registrar.ddnMes == 5 || registrar.ddnMes == 7 || registrar.ddnMes == 8 || registrar.ddnMes == 10 || registrar.ddnMes == 12)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 30) && (registrar.ddnMes == 4 || registrar.ddnMes == 6 || registrar.ddnMes == 9 || registrar.ddnMes == 11)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 28) && (registrar.ddnMes == 2)) {
                        printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                    } else {
                        repetidor = 1;
                    }
                } else {
                    printf("\nEssa data n�o � v�lida, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);
}


void status_reserva(struct reserva registrar);

void status_reserva(struct reserva registrar){ //Verificar o status do voo;
    int repetidor = 0; //Vai manter um loop at� que o usu�rio digite um status correto;

    do{
        printf("Essa reserva est� ativa ou cancelada? (A/C)\n");
        scanf("%c", &registrar.statusReserva);
        flush_in();

        if(registrar.statusReserva != 65 && registrar.statusReserva != 67){ //Garantindo que o caracter seja: A ou C;
            printf("\nEsse status de reserva n�o � v�lido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}
