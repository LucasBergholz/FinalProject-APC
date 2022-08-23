#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define MAX 999

//Síntese
    //Objetivo: Produzir um algotimo que cadastre voos e reservas, sendo possível cancelar ou excluir os mesmos;
    //Entrada:  Número da reserva, número do voo, CPF do passageiro, nome completo do passageiro, sexo, data de nascimento, status da reserva (ativa ou cancelada);
    //Saída:    Qualquer informação cadastrada;

int numeroDeVoos = 0;

int numeroDeReservas = 0;

int validarCancelamento = 0;

void flush_in();

struct voo{ //Struct com as informações que serão guardadas;
        char idVoo[9];
        int capacidade, ocupacao;
        int dia, mes, ano;
        int hora, minuto;
        char statusVoo;
    };

struct voo leituraVoos[MAX];

struct reserva{ //Struct com as informações que serão guardadas;
    char idReserva[10];
    char idVooReserva[9];
    char cpf[12];
    char nomePassageiro[MAX];
    char sexo;
    int ddnDia, ddnMes, ddnAno; //ddn = data de nascimento, separei ela em 3 partes para facilitar a checagem da mesma;
    char statusReserva;
};

struct reserva leituraReservas[MAX];

char verifica_reserva_voo[9]; //É usado para verificar se um passageiro está repetindo seu cadastro em um voo;

char verifica_cpf_voo[12]; //É usado para verificar se um passageiro está usando um CPF igual para pessoas diferentes;

void Cadastrar_voo(FILE *DadosDoVoo); //Função de cadastro de voos;

void Ler_voos(FILE *DadosDoVoo); //Função de leitura do arquivo onde estão armazenados os voos;

void Cadastrar_reserva(FILE *DadosDaReserva); //Função de cadastro de reservas;

void Ler_reservas(FILE *DadosDaReserva); //Função de leitura do arquivo onde estão armazenadas as reservas;

void Consultar_voo(FILE *DadosDoVoo, FILE *DadosDaReserva);

void Consultar_reserva(FILE *DadosDoVoo, FILE *DadosDaReserva);

void Consultar_passageiro(FILE *DadosDoVoo, FILE *DadosDaReserva);

void Cancelar_voo(FILE *DadosDoVoo, FILE *DadosDaReserva, FILE *FileAuxiliarVoo, FILE *FileAuxiliarReserva);

void Cancelar_reserva(FILE *DadosDoVoo, FILE *DadosDaReserva, FILE *FileAuxiliarVoo, FILE *FileAuxiliarReserva);

void Excluir_voo(FILE *DadosDoVoo, FILE *DadosDaReserva, FILE *FileAuxiliarVoo, FILE *FileAuxiliarReserva);

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *DadosDoVoo; //Criando ponteiro que guardará as informações do voo;

    DadosDoVoo = fopen("dadosdovoo.txt", "a+"); //Abrindo o arquivo para uso ao longo do código;

    FILE *DadosDaReserva; //Criando ponteiro que guardará as informações da reserva;

    DadosDaReserva = fopen("dadosdareserva.txt", "a+"); //Abrindo o arquivo para uso ao longo do código;

    FILE *FileAuxiliarVoo; //Criando ponteiro que será usado para ajudar no cancelamento e exclusão de voos;

    FileAuxiliarVoo = fopen("fileauxiliarvoo.txt", "a+");

    FILE *FileAuxiliarReserva; //Criando ponteiro que será usado para ajudar no cancelamento e exclusão de reservas;

    FileAuxiliarReserva = fopen("fileauxiliarreserva.txt", "a+");

    fclose(DadosDoVoo);
    fclose(DadosDaReserva);
    fclose(FileAuxiliarVoo);
    fclose(FileAuxiliarReserva);

    //Desenvolvendo a aparência do menu de opções;
    printf("===============================================================\n");
    printf("========== Bem-vindo à reserva de viagens especiais! ==========\n");
    printf("===============================================================\n");
    printf("\n");

    printf("Escolha uma das opções abaixo:\n");
    printf("\n");

    printf("1) Cadastrar voo\n2) Cadastrar reserva\n3) Consultar voo\n4) Consultar reserva\n5) Consultar passageiro\n6) Cancelar voo\n7) Cancelar reserva\n8) Excluir voo\n9) Sair do programa\n");
    printf("\n");

    //Habilitando as opções e suas respectivas ações;
    int opcao;
    char verificador = 'S'; //Será usado para repetir o programa caso a opção escolhida seja inválida;

    do{
    DadosDoVoo = fopen("dadosdovoo.txt", "a+"); //Abrindo o arquivo para uso ao longo do código;
    DadosDaReserva = fopen("dadosdareserva.txt", "a+"); //Abrindo o arquivo para uso ao longo do código;
    validarCancelamento = 0;
    numeroDeVoos = 0;
    numeroDeReservas = 0;
    Ler_voos(DadosDoVoo); //Tirando os dados dos voos do arquivo;
    Ler_reservas(DadosDaReserva); //Tirando os dados das reservas do arquivo;
    fseek(DadosDoVoo, 0, SEEK_END); //Colocando o ponteiro no final do arquivo;
    fseek(DadosDaReserva, 0, SEEK_END); //Colocando o ponteiro no final do arquivo;
    scanf("%d", &opcao);
    flush_in();

    switch (opcao){
        case 1: //Cadastro do voo por meio de um procedimento;
            system("cls || clear");
            Cadastrar_voo(DadosDoVoo);
            break;
        case 2:
            system("cls || clear");
            Cadastrar_reserva(DadosDaReserva);
            break;
        case 3:
            system("cls || clear");
            Consultar_voo(DadosDoVoo, DadosDaReserva);
            break;
        case 4:
            system("cls || clear");
            Consultar_reserva(DadosDoVoo, DadosDaReserva);
            break;
        case 5:
            system("cls || clear");
            Consultar_passageiro(DadosDoVoo, DadosDaReserva);
            break;
        case 6:
            system("cls || clear");
            Cancelar_voo(DadosDoVoo,DadosDaReserva, FileAuxiliarVoo, FileAuxiliarReserva);
            break;
        case 7:
            system("cls || clear");
            Cancelar_reserva(DadosDoVoo,DadosDaReserva, FileAuxiliarVoo, FileAuxiliarReserva);
            break;
        case 8:
            system("cls || clear");
            Excluir_voo(DadosDoVoo,DadosDaReserva, FileAuxiliarVoo, FileAuxiliarReserva);
            break;
        case 9:
            verificador = 'n';
            break;
        default:
            printf("\nEssa escolha não é válida, tente novamente!\n");
    }
        if (verificador != 'n'){
            printf("\nGostaria de fazer outra ação? (S/N)\n");
            scanf("%c", &verificador);
            flush_in();

            if (verificador != 'N' && verificador != 'n'){ //Vai repetir o processo de mostrar o menu e pedir que o usuário escolha uma das opções;
                system("cls || clear");
                printf("Escolha uma das opções abaixo:\n\n");
                printf("1) Cadastrar voo\n2) Cadastrar reserva\n3) Consultar voo\n4) Consultar reserva\n5) Consultar passageiro\n6) Cancelar voo\n7) Cancelar reserva\n8) Excluir voo\n9) Sair do programa\n\n");
            }
        }

    fclose(DadosDoVoo);
    fclose(DadosDaReserva);

    //Se validarCancelamento = 1, então o passo 6 ocorreu, e houve um cancelamento de voo, exigindo uma atualização dos arquivos;
    if(validarCancelamento == 1){
        remove("dadosdovoo.txt");
        remove("dadosdareserva.txt");
        rename("fileauxiliarvoo.txt", "dadosdovoo.txt");
        rename("fileauxiliarreserva.txt", "dadosdareserva.txt");
    }

    //Se validarCancelamento = 2, então o passo 7 ocorreu, e houve um cancelamento de reserva, exigindo uma atualização dos arquivos;
    if(validarCancelamento == 2){
        remove("dadosdareserva.txt");
        rename("fileauxiliarreserva.txt", "dadosdareserva.txt");
    }

    } while (verificador != 'N' && verificador != 'n');

    return 0;
        }

void flush_in(){ //Usada pra parar alguns bugs do código;
       int ch;
       while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void Cadastrar_voo (FILE *DadosDoVoo) {
    struct voo registro; //Criando a rede de variáveis para o cadastramento do voo;
    int repetidor = 0;

    //Menu do cadastramento;
    printf("==========================================\n");
    printf("========== Cadastramento de Voo ==========\n");
    printf("==========================================\n");
    printf("\n");

    //Entrada dos dados necessários;
    numero_voo(registro, DadosDoVoo);

    //Garantindo que a capacidade seja válida (número positivo);
    do{
        printf("Qual o máximo de passageiros no voo?\n");
        scanf("%d", &registro.capacidade);
        flush_in();
        repetidor = 1;

        if(registro.capacidade <= 0){
            printf("\nEssa capacidade não é válida, tente novamente.\n\n");
            repetidor = 0;
        }

    } while (repetidor == 0);

    data_voo(registro, DadosDoVoo);
    hora_voo(registro, DadosDoVoo);

    fseek(DadosDoVoo, 0, SEEK_END); //Destinando o ponteiro no final do arquivo;

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDoVoo, "%d,", registro.capacidade);
    fprintf(DadosDoVoo, "A\n");

    printf("\nO cadastro do voo foi um sucesso!\n");
}

void numero_voo(struct voo registro, FILE *DadosDoVoo);

void numero_voo(struct voo registro, FILE *DadosDoVoo){ //Verificar a validade do dado do número de voo;
    int repetidor = 0, i; //Manter um loop até que o usuário digite um valor correto de id de voo;

    do{
        printf("Qual o número do voo? (JEB-XXXX)\n");
        scanf("%s", registro.idVoo);

        if(registro.idVoo[0] != 74 || registro.idVoo[1] != 69 || registro.idVoo[2] != 66 || registro.idVoo[3] != 45){ //Checando se a id do voo tem o "JEB-";
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[4] < 48 || registro.idVoo[4] > 57){ //Checando os últimos 4 caracteres, garantindo que são números;
            printf("\nNúmero não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[5] < 48 || registro.idVoo[5] > 57){
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[6] < 48 || registro.idVoo[6] > 57){
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[7] < 48 || registro.idVoo[7] > 57){
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else {
            repetidor = 1;

            for(i = 0; i < numeroDeVoos; i++){ //Checando se já foi registrado um voo de mesma id;
                if(strncmp(registro.idVoo, leituraVoos[i].idVoo, 9) == 0){
                    repetidor = 0;
                    printf("\nEsse voo já está cadastrado, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);

        //Destinando o ponteiro no final do arquivo;
        fseek(DadosDoVoo, 0, SEEK_END);

        //Escrevendo no arquivo os dados do voo;
        fprintf(DadosDoVoo, "%s,", registro.idVoo);
    }

void data_voo(struct voo registro, FILE *DadosDoVoo);

void data_voo(struct voo registro, FILE *DadosDoVoo){ //Verificar a validade da data do voo;
    time_t mytime; //Inicializando as variáveis da biblioteca time.h;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
    int repetidor = 0; //Manter um loop até que o usuário digite um valor correto de data;

    do{
        printf("Qual a data do voo? (XX/YY/ZZZZ)\n"); //Leitura da data;
        scanf("%d/%d/%d", &registro.dia, &registro.mes, &registro.ano);

        if(registro.ano < (tm.tm_year + 1900)){ //Garantindo que não seja registrado um voo no passado;
            printf("\nEssa data não é válida, tente novamente.\n\n");

        } else if(registro.ano == (tm.tm_year + 1900) && registro.mes < (tm.tm_mon + 1)){
            printf("\nEssa data não é válida, tente novamente.\n\n");

        } else if(registro.ano == (tm.tm_year + 1900) && registro.mes == (tm.tm_mon + 1) && registro.dia <= tm.tm_mday){ //Desse if até o primeiro if, está se garantindo que não agende um voo para o passado;
            printf("\nEssa data não é válida, tente novamente.\n\n");

        } else {
            if(( registro.ano % 4 == 0 && registro.ano % 100 != 0) || registro.ano % 400 == 0) {
                if (registro.mes >= 1 && registro.mes <= 12) {
                if ((registro.dia < 1 || registro.dia > 31) && (registro.mes == 1 || registro.mes == 3 || registro.mes == 5 || registro.mes == 7 || registro.mes == 8 || registro.mes == 10 || registro.mes == 12)) {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                } else if ((registro.dia < 1 || registro.dia > 30) && (registro.mes == 4 || registro.mes == 6 || registro.mes == 9 || registro.mes == 11)) {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                } else if ((registro.dia < 1 || registro.dia > 29) && (registro.mes == 2)) {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                } else {
                    repetidor = 1;
                }
                } else {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                }

            } else {
                if (registro.mes >= 1 && registro.mes <= 12) {
                    if ((registro.dia < 1 || registro.dia > 31) && (registro.mes == 1 || registro.mes == 3 || registro.mes == 5 || registro.mes == 7 || registro.mes == 8 || registro.mes == 10 || registro.mes == 12)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else if ((registro.dia < 1 || registro.dia > 30) && (registro.mes == 4 || registro.mes == 6 || registro.mes == 9 || registro.mes == 11)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else if ((registro.dia < 1 || registro.dia > 28) && (registro.mes == 2)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else {
                        repetidor = 1;
                    }
                } else {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDoVoo, "%d,%d,%d,", registro.dia, registro.mes, registro.ano);
}

void hora_voo(struct voo registro, FILE *DadosDoVoo);

void hora_voo(struct voo registro, FILE *DadosDoVoo){ //Verificar a validade da hora do voo;

    int repetidor = 0; //Manter um loop até que o usuário digite um valor correto de horário;

    do{
        printf("Qual a hora de partida do voo? (XX:YY)\n");
        scanf("%d:%d", &registro.hora, &registro.minuto);

        if(registro.minuto > 59 || registro.minuto < 0 || registro.hora > 23 || registro.hora < 0){ //Garantindo que o horário seja válido;
            printf("\nEsse horário não é válido, tente novamente.\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDoVoo, "%d,%d,", registro.hora, registro.minuto);
}

/*void status_voo(struct voo registro);

void status_voo(struct voo registro){ //Verificar o status do voo;
    int repetidor = 0; //Vai manter um loop até que o usuário digite um status correto;

    do{
        printf("Esse voo está ativo ou cancelado? (A/C)\n");
        scanf("%c", &registro.statusVoo);
        flush_in();

        if(registro.statusVoo != 65 && registro.statusVoo != 67){ //Garantindo que o caracter seja: A ou C;
            printf("\nEsse status de voo não é válido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}*/

void Ler_voos(FILE *DadosDoVoo){
    int i;
    char cabecalho[MAX];

    rewind(DadosDoVoo);

    while(fgets(cabecalho, MAX - 1, DadosDoVoo)){ //Calculando a partir do número de linhas do documento, o número de voos;
        numeroDeVoos++;
    }
    numeroDeVoos = numeroDeVoos - 1;

    rewind(DadosDoVoo);
    fgets(cabecalho, MAX - 1, DadosDoVoo); //Tirando o cabeçalho da parte da leitura;

    for(i = 0; i < numeroDeVoos; i++){
        fscanf(DadosDoVoo, "%[^,],%d,%d,%d,%d,%d,%d,%c\n",  leituraVoos[i].idVoo,
                                                            &leituraVoos[i].dia,
                                                            &leituraVoos[i].mes,
                                                            &leituraVoos[i].ano,
                                                            &leituraVoos[i].hora,
                                                            &leituraVoos[i].minuto,
                                                            &leituraVoos[i].capacidade,
                                                            &leituraVoos[i].statusVoo);
    }
}

void Cadastrar_reserva(FILE *DadosDaReserva) {
    struct reserva registrar; //Criando a rede de variáveis para o cadastramento do registro;
    struct voo registro;

    //Menu do cadastramento;
    printf("==============================================\n");
    printf("========== Cadastramento de Reserva ==========\n");
    printf("==============================================\n");
    printf("\n");

    //Entrada dos dados necessários;
    id_reserva(registrar, DadosDaReserva);
    numero_voo_reserva(registro, DadosDaReserva);
    cpf_passageiro(registrar, DadosDaReserva);
    nome_passageiro(registro, registrar, DadosDaReserva);
    sexo_passageiro(registrar, DadosDaReserva);
    data_nascimento(registrar, DadosDaReserva);

    fseek(DadosDaReserva, 0, SEEK_END); //Destinando o ponteiro no final do arquivo;

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "A\n");

    printf("\nO cadastro da reserva foi um sucesso!\n");

}

void id_reserva(struct reserva registrar, FILE *DadosDaReserva);

void id_reserva(struct reserva registrar, FILE *DadosDaReserva){ //Verificar se a id da reserva é válida;
    int i;
    int repetidor = 0; //Manter um loop até que o usuário digite um valor correto da id da reserva;

    do{
        printf("Qual o número da reserva? (GB-XXXXXX)\n");
        scanf("%s", registrar.idReserva);
        flush_in();

        if(registrar.idReserva[0] != 71 || registrar.idReserva[1] != 66 || registrar.idReserva[2] != 45){ //Checando se a id da reserva tem o "GB-";
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else if(registrar.idReserva[3] < 48 || registrar.idReserva[3] > 57){
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else if(registrar.idReserva[4] < 48 || registrar.idReserva[4] > 57){ //Checando os últimos 4 caracteres, garantindo que são números;
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else if(registrar.idReserva[5] < 48 || registrar.idReserva[5] > 57){
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else if(registrar.idReserva[6] < 48 || registrar.idReserva[6] > 57){
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else if(registrar.idReserva[7] < 48 || registrar.idReserva[7] > 57){
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else if(registrar.idReserva[8] < 48 || registrar.idReserva[8] > 57){
            printf("\nNúmero de reserva não é válido, tente novamente.\n\n");

        } else {
            repetidor = 1;

            for(i = 0; i < numeroDeReservas; i++){ //Checando se já foi registrado uma reserva de mesma id;
                if(strncmp(registrar.idReserva, leituraReservas[i].idReserva, 10) == 0){
                    repetidor = 0;
                    printf("\nEssa reserva já está cadastrada, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "%s,", registrar.idReserva);
}

void numero_voo_reserva(struct voo registro, FILE *DadosDaReserva);

void numero_voo_reserva(struct voo registro, FILE *DadosDaReserva){ //Verificar a validade do dado do número de voo;
    int repetidor = 0, i; //Manter um loop até que o usuário digite um valor correto de id de voo;
    int num_passageiros; //Vai ser usado pra checar a ocupação do voo escolhido;
    float capacidadeDoVoo; //Vai ser usado pra checar a ocupação do voo escolhido;

    do{
        printf("Qual o número do voo? (JEB-XXXX)\n");
        scanf("%s", registro.idVoo);

        if(registro.idVoo[0] != 74 || registro.idVoo[1] != 69 || registro.idVoo[2] != 66 || registro.idVoo[3] != 45){ //Checando se a id do voo tem o "JEB-";
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[4] < 48 || registro.idVoo[4] > 57){ //Checando os últimos 4 caracteres, garantindo que são números;
            printf("\nNúmero não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[5] < 48 || registro.idVoo[5] > 57){
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[6] < 48 || registro.idVoo[6] > 57){
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else if(registro.idVoo[7] < 48 || registro.idVoo[7] > 57){
            printf("\nNúmero do voo não é válido, tente novamente.\n\n");

        } else {
            for(i = 0; i < numeroDeVoos; i++){
                if(strncmp(registro.idVoo, leituraVoos[i].idVoo, 9) == 0){
                    repetidor = 1;
                    capacidadeDoVoo = leituraVoos[i].capacidade;
                }
            }

            if(repetidor == 0){
                printf("\nEsse voo ainda não está cadastrado, tente novamente.\n\n");
            }
        }

        //Checando a lotação do voo escolhido
        num_passageiros = 0;
        for(int j = 0; j < numeroDeReservas; j++){
            if(strncmp(leituraReservas[j].idVooReserva, registro.idVoo, 9) == 0){
                num_passageiros++;
            }
        }

        float ocupacaoDoVoo = 100*(num_passageiros/capacidadeDoVoo);

        if(ocupacaoDoVoo == 100){
            printf("\nEsse voo está lotado, tente novamente.\n\n");
            repetidor = 0;
        }

        //Checando se o voo está ativo;
        for(int k = 0; k < numeroDeVoos; k++){
            if(strncmp(leituraVoos[k].idVoo, registro.idVoo, 9) == 0 && leituraVoos[k].statusVoo == 'C'){
                repetidor = 0;
                printf("\nEsse voo está cancelado, tente novamente.\n\n");
            }
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "%s,", registro.idVoo);
    strcpy(verifica_reserva_voo, registro.idVoo);
    flush_in();
}

void cpf_passageiro(struct reserva registrar, FILE *DadosDaReserva);

void cpf_passageiro(struct reserva registrar, FILE *DadosDaReserva){ //Verificar a validade do CPF;
    int repetidor = 0, i, id = 0;
    int validar; //Se validar = 0 o CPF foi escrito com algum caracter sem ser número;

    do{
        validar = 1;
        printf("Qual o CPF do passageiro? (Escreva apenas os números)\n");
        scanf("%s", registrar.cpf);
        flush_in();

        for(i = 0; i < 11; i++){
            if(registrar.cpf[i] < 48 || registrar.cpf[i] > 57){ //Garantindo ser número;
                validar = 0;
            }
        }

        //CPF's de números todos iguais não são válidos;
        if(registrar.cpf[0] == registrar.cpf[1] &&
           registrar.cpf[1] == registrar.cpf[2] &&
           registrar.cpf[2] == registrar.cpf[3] &&
           registrar.cpf[3] == registrar.cpf[4] &&
           registrar.cpf[4] == registrar.cpf[5] &&
           registrar.cpf[5] == registrar.cpf[6] &&
           registrar.cpf[6] == registrar.cpf[7] &&
           registrar.cpf[7] == registrar.cpf[8] &&
           registrar.cpf[8] == registrar.cpf[9] &&
           registrar.cpf[9] == registrar.cpf[10]){
            validar = 0;
        }

        if(validar == 0){
            printf("\nO CPF é inválido, tente novamente.\n\n");
        } else {
            repetidor = 1; //Retira o algoritmo do loop após uma entrada válida dos dados pedidos;
        }

        validar = 1;

        for(int j = 0; j < numeroDeReservas; j++){ //Verificando se o CPF já está no histórico do sistema;
            if(strncmp(registrar.cpf, leituraReservas[j].cpf, 12) == 0){
               id = j;
               validar = 2;
            }
        }

        if(validar == 2){ //Informando os dados da pessoa com esse CPF, de acordo com o sistema;
            printf("\nJá existe um passageiro com esse CPF no sistema:\n");
            printf("- Nome: %s\n- Sexo: %c\n- Data de Nascimento: %d/%d/%d\n\n", leituraReservas[id].nomePassageiro, leituraReservas[id].sexo, leituraReservas[id].ddnDia, leituraReservas[id].ddnMes, leituraReservas[id].ddnAno);
        }

        for(int k = 0; k < numeroDeReservas; k++){ //Verificando se esse CPF já está cadastrado no voo digitado anteriormente;
            if(strncmp(registrar.cpf, leituraReservas[k].cpf, 12) == 0 && strncmp(verifica_reserva_voo, leituraReservas[k].idVooReserva, 9) == 0){
                validar = 3;
            }
        }

        if(validar == 3){
            printf("\nO passageiro já está cadastrado nesse voo, tente novamente.\n\n");
            repetidor = 0;
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "%s,", registrar.cpf);
    strcpy(verifica_cpf_voo, registrar.cpf);
}

void nome_passageiro(struct voo registro, struct reserva registrar, FILE *DadosDaReserva);

void nome_passageiro(struct voo registro, struct reserva registrar, FILE *DadosDaReserva){ //Validar o nome do passageiro;
    int tamanho, repetidor = 0, verificador, i;

    do{
        verificador = 1;
        printf("Digite o nome do passageiro:\n");
        scanf(" %[^\n]", registrar.nomePassageiro);
        flush_in();
        tamanho = strlen(registrar.nomePassageiro);

        for(int i = 0; i < tamanho; i++){
            if(registrar.nomePassageiro[i] < 65 && registrar.nomePassageiro[i] != 32){
               printf("\nO nome do passageiro é inválido, tente novamente.\n\n");
               verificador = 0;

            } else if(registrar.nomePassageiro[i] > 90){
                if(registrar.nomePassageiro[i] < 97 || registrar.nomePassageiro[i] > 122){
                    printf("\nO nome do passageiro é inválido, tntne novamente.\n\n");
                    verificador = 0;
                }
            }
        }

        if(verificador == 1){
            repetidor = 1;
        }

        for(i = 0; i < numeroDeReservas; i++){ //Checando se o usuário está cadastrando o mesmo CPF para duas pessoas diferentes;
            if (strncmp(registrar.nomePassageiro, leituraReservas[i].nomePassageiro, MAX) == 0){
                if(strncmp(verifica_cpf_voo, leituraReservas[i].cpf, 12) != 0){
                    repetidor = 0;
                    printf("\nEsse passageiro foi anteriormente registrado com outro CPF, tente novamente.\n\n");
                }
            } else if(strncmp(registrar.nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0){
                if(strncmp(verifica_cpf_voo, leituraReservas[i].cpf, 12) == 0){
                    repetidor = 0;
                    printf("\nO CPF digitado anteriormente está registrado para outra pessoa no sistema, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "%s,", registrar.nomePassageiro);
}

void sexo_passageiro(struct reserva registrar, FILE *DadosDaReserva);

void sexo_passageiro(struct reserva registrar, FILE *DadosDaReserva){
    int repetidor = 0; //Vai manter um loop até que o usuário digite um sexo correto;

    do{
        printf("Qual o sexo do passageiro? (M/F)\n");
        scanf("%c", &registrar.sexo);
        flush_in();

        if(registrar.sexo != 77 && registrar.sexo != 70){ //Garantindo que o caracter seja: A ou C;
            printf("\nEsse sexo não é válido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

        for(int i = 0; i < numeroDeReservas; i++){ //Checando se o usuário está cadastrando o mesmo CPF para duas pessoas diferentes;
            if(strncmp(verifica_cpf_voo, leituraReservas[i].cpf, 12) == 0){
                if(registrar.sexo != leituraReservas[i].sexo){
                    repetidor = 0;
                    printf("\nA pessoa registrada no cpf acima não é desse sexo, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "%c,", registrar.sexo);
}

void data_nascimento(struct reserva registrar, FILE *DadosDaReserva);

void data_nascimento(struct reserva registrar, FILE *DadosDaReserva){
    time_t mytime; //Inicializando as variáveis da biblioteca time.h;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
    int repetidor = 0; //Manter em um loop até o usuário digitar uma data de nascimento válida;

    do{
        printf("Qual a data de nascimento do passageiro? (XX/YY/ZZZZ)\n"); //Leitura da data;
        scanf(" %d/%d/%d", &registrar.ddnDia, &registrar.ddnMes, &registrar.ddnAno);

        if(registrar.ddnAno < 1931){ //Pessoas velhas demais não são adequadas para esse voo;
            printf("\nO passageiro não tem idade adequada para um voo desse porte, tente novamente.\n\n");

        } else if(registrar.ddnAno > (tm.tm_year + 1900)){ //Garantindo que não ocorra um registro no futuro;
            printf("\nEssa data não é válida, tente novamente.\n\n");

        } else if(registrar.ddnAno == (tm.tm_year + 1900) && registrar.ddnMes > (tm.tm_mon + 1)){
            printf("\nEssa data não é válida, tente novamente.\n\n");

        } else if(registrar.ddnAno == (tm.tm_year + 1900) && registrar.ddnMes == (tm.tm_mon + 1) && registrar.ddnDia > tm.tm_mday){ //Desse if até o primeiro if, está se garantindo que não agende um voo para o passado;
            printf("\nEssa data não é válida, tente novamente.\n\n");

        } else {
            if(( registrar.ddnAno % 4 == 0 && registrar.ddnAno % 100 != 0) || registrar.ddnAno % 400 == 0) { //Checagem se o ano é bissexto;
                if (registrar.ddnMes >= 1 && registrar.ddnMes <= 12) { //Garantindo que o mês é válido;
                    //Garantindo que o dia está certo para o respectivo mês;
                    if ((registrar.ddnDia < 1 || registrar.ddnDia > 31) && (registrar.ddnMes == 1 || registrar.ddnMes == 3 || registrar.ddnMes == 5 || registrar.ddnMes == 7 || registrar.ddnMes == 8 || registrar.ddnMes == 10 || registrar.ddnMes == 12)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 30) && (registrar.ddnMes == 4 || registrar.ddnMes == 6 || registrar.ddnMes == 9 || registrar.ddnMes == 11)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 29) && (registrar.ddnMes == 2)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else {
                        repetidor = 1;
                    }
                } else {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                }

            } else {
                if (registrar.ddnMes >= 1 && registrar.ddnMes <= 12) { //Garantindo que o mês é válido;
                    if ((registrar.ddnDia < 1 || registrar.ddnDia > 31) && (registrar.ddnMes == 1 || registrar.ddnMes == 3 || registrar.ddnMes == 5 || registrar.ddnMes == 7 || registrar.ddnMes == 8 || registrar.ddnMes == 10 || registrar.ddnMes == 12)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 30) && (registrar.ddnMes == 4 || registrar.ddnMes == 6 || registrar.ddnMes == 9 || registrar.ddnMes == 11)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else if ((registrar.ddnDia < 1 || registrar.ddnDia > 28) && (registrar.ddnMes == 2)) {
                        printf("\nEssa data não é válida, tente novamente.\n\n");
                    } else {
                        repetidor = 1;
                    }
                } else {
                    printf("\nEssa data não é válida, tente novamente.\n\n");
                }
            }
        }

        for(int i = 0; i < numeroDeReservas; i++){ //Checando se o usuário está cadastrando o mesmo CPF para duas pessoas diferentes;
            if(strncmp(verifica_cpf_voo, leituraReservas[i].cpf, 12) == 0){
                if(registrar.ddnDia != leituraReservas[i].ddnDia || registrar.ddnMes != leituraReservas[i].ddnMes || registrar.ddnAno != leituraReservas[i].ddnAno){
                    repetidor = 0;
                    printf("\nA pessoa registrada no cpf acima não possui essa data de nascimento, tente novamente.\n\n");
                }
            }
        }

    } while(repetidor == 0);

    //Escrevendo no arquivo os dados do voo;
    fprintf(DadosDaReserva, "%d,%d,%d,", registrar.ddnDia, registrar.ddnMes, registrar.ddnAno);
}

void Ler_reservas(FILE *DadosDaReserva){
    int i;
    char cabecalho[MAX];

    rewind(DadosDaReserva);

    while(fgets(cabecalho, MAX - 1, DadosDaReserva)){ //Calculando a partir do número de linhas do documento, o número de reservas;
        numeroDeReservas++;
    }
    numeroDeReservas = numeroDeReservas - 1;

    rewind(DadosDaReserva);
    fgets(cabecalho, MAX - 1, DadosDaReserva); //Tirando o cabeçalho da parte da leitura;

    for(i = 0; i < numeroDeReservas; i++){
        fscanf(DadosDaReserva, "%[^,],%[^,],%[^,],%[^,],%c,%d,%d,%d,%c\n",
                                                                    leituraReservas[i].idReserva,
                                                                    leituraReservas[i].idVooReserva,
                                                                    leituraReservas[i].cpf,
                                                                    leituraReservas[i].nomePassageiro,
                                                                    &leituraReservas[i].sexo,
                                                                    &leituraReservas[i].ddnDia,
                                                                    &leituraReservas[i].ddnMes,
                                                                    &leituraReservas[i].ddnAno,
                                                                    &leituraReservas[i].statusReserva);
    }
}

/*void status_reserva(struct reserva registrar);

void status_reserva(struct reserva registrar){ //Verificar o status do voo;
    int repetidor = 0; //Vai manter um loop até que o usuário digite um status correto;

    do{
        printf("Essa reserva está ativa ou cancelada? (A/C)\n");
        scanf("%c", &registrar.statusReserva);
        flush_in();

        if(registrar.statusReserva != 65 && registrar.statusReserva != 67){ //Garantindo que o caracter seja: A ou C;
            printf("\nEsse status de reserva não é válido, tente novamente.\n\n");

        } else {
            repetidor = 1;
        }

    } while(repetidor == 0);
}
*/

void Consultar_voo(FILE *DadosDoVoo, FILE *DadosDaReserva){
    int num_passageiros;

    //Menu da consulta;
    printf("==========================================\n");
    printf("============ Consulta de Voos ============\n");
    printf("==========================================\n");
    printf("\n");

    for(int i = 0; i < numeroDeVoos; i++){ //Printando na tela os dados de cada voo;
        num_passageiros = 0;
        printf("\n%dº Voo\n", i+1);
        printf("=> iD do voo: %s\n", leituraVoos[i].idVoo);
        printf("=> Data do voo: %d/%d/%d às %d:%d\n", leituraVoos[i].dia, leituraVoos[i].mes, leituraVoos[i].ano, leituraVoos[i].hora, leituraVoos[i].minuto);

        if(leituraVoos[i].statusVoo == 'A'){
            printf("=> Status do voo: Ativo\n");
        } else {
            printf("=> Status do voo: Cancelado\n");
        }

        //Colocando a ocupação e lista de passageiros;
        printf("=> Lista de passageiros:\n");
        for(int j = 0; j < numeroDeReservas; j++){
            if(strncmp(leituraReservas[j].idVooReserva, leituraVoos[i].idVoo, 9) == 0 && leituraReservas[j].statusReserva != 'C'){
                printf("- %s\n", leituraReservas[j].nomePassageiro);
                num_passageiros++;
            }
        }

        if(num_passageiros == 0){
            printf("- Nenhum passageiro cadastrado.\n");
        }

        float capacidadeDoVoo = leituraVoos[i].capacidade;
        float ocupacaoDoVoo = 100*(num_passageiros/capacidadeDoVoo);

        printf("=> Taxa de ocupação: %.1f%% (%d de %d)\n", ocupacaoDoVoo, num_passageiros, leituraVoos[i].capacidade);
    }
}

void Consultar_reserva(FILE *DadosDoVoo, FILE *DadosDaReserva){

    //Menu da consulta;
    printf("==============================================\n");
    printf("============ Consulta de Reservas ============\n");
    printf("==============================================\n");
    printf("\n");

    for(int i = 0; i < numeroDeReservas; i++){ //Printando na tela os dados de cada voo;
        printf("\n%dª Reserva\n", i+1);
        printf("=> iD da reserva: %s\n", leituraReservas[i].idReserva);
        printf("=> iD do voo: %s\n", leituraReservas[i].idVooReserva);
        printf("=> Passageiro: %s\n", leituraReservas[i].nomePassageiro);

        if(leituraReservas[i].sexo == 'M'){
            printf("=> Sexo do passageiro: Masculino\n");
        } else {
            printf("=> Sexo do passageiro: Feminino\n");
        }

        printf("=> Data de Nascimento do passageiro: %d/%d/%d\n", leituraReservas[i].ddnDia, leituraReservas[i].ddnMes, leituraReservas[i].ddnAno);

        if(leituraReservas[i].statusReserva == 'A'){
            printf("=> Status da reserva: Ativo\n");
        } else {
            printf("=> Status da reserva: Cancelado\n");
        }
    }
}

void Consultar_passageiro(FILE *DadosDoVoo, FILE *DadosDaReserva){
    char passageiro_checado[MAX];
    char lista_passageiros[MAX][MAX];
    int k = 0;

    //Menu da consulta;
    printf("=================================================\n");
    printf("============ Consulta de Passageiros ============\n");
    printf("=================================================\n");
    printf("\n");

    printf("\n=> Lista de passageiros:\n");

    //Printando na tela todos os passageiros;
    for(int i = 0; i < numeroDeReservas; i++){
        if(strncmp(leituraReservas[i+1].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+2].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+3].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+4].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+5].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+6].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+7].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+8].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+9].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+10].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0 &&
           strncmp(leituraReservas[i+11].nomePassageiro, leituraReservas[i].nomePassageiro, MAX) != 0){
                printf("- %s\n", leituraReservas[i].nomePassageiro);
            }
    }

    //Recebendo do usuário qual passageiro quer consultar;
    printf("\nQual passageiro gostaria de consultar?\n");
    scanf("%[^\n]", passageiro_checado);
    flush_in();

    //Printando na tela todas as reservas do passageiro escolhido;
    for(int j = 0; j < numeroDeReservas; j++){
        if(strncmp(passageiro_checado, leituraReservas[j].nomePassageiro, MAX) == 0){
            printf("\n%dª Reserva\n", k+1);
            k++;
            printf("=> iD da reserva: %s\n", leituraReservas[j].idReserva);
            printf("=> iD do voo: %s\n", leituraReservas[j].idVooReserva);
            if(leituraReservas[j].statusReserva == 'A'){
                printf("=> Status da reserva: Ativo\n");
            } else {
                printf("=> Status da reserva: Cancelado\n");
            }
        }
    }
}

void Cancelar_voo(FILE *DadosDoVoo, FILE *DadosDaReserva, FILE *FileAuxiliarVoo, FILE *FileAuxiliarReserva){
    char voo_cancelado[9], line[MAX];
    int repetidor = 0, i, k, id;

    //Menu da consulta;
    printf("==================================================\n");
    printf("============== Cancelamento de Voos ==============\n");
    printf("==================================================\n");
    printf("\n");

    //Printando todos os voos disponíveis;
    printf("\n=> Lista de voos:\n");
    for(i = 0; i < numeroDeVoos; i++){
        printf("- %s\n", leituraVoos[i].idVoo);
    }

    //Garantindo a leitura de um voo que está cadastradado no sistema;
    do{
        //Leitura do voo a ser cancelado;
        printf("\nQual voo gostaria de cancelar?\n");
        scanf("%s", voo_cancelado);
        flush_in();

        repetidor = 1;
        for(int j = 0; j < numeroDeVoos; j++){
            if(strncmp(voo_cancelado, leituraVoos[j].idVoo, 9) == 0){ //Se o voo digitado coincidir com um voo do sistema o repetidor é = 0 e sai do loop;
                repetidor = 0;
            }
        }

        if(repetidor == 1){ //Caso o repetidor continue com o valor de 1 quer dizer que o voo digitado não coincidiu com nenhum dos voos do sistema;
            printf("\nEsse voo não foi encontrado no sistema, tente novamente.\n");
        }

    }while(repetidor != 0);

    //Abrindo o arquivo auxiliar para escrever nele os dados dos voos;
    FileAuxiliarVoo = fopen("fileauxiliarvoo.txt", "a+");
    fseek(FileAuxiliarVoo, 0, SEEK_SET);
    fprintf(FileAuxiliarVoo, "iD,Data,Hora,Passageiros,Status\n"); //Printando o cabeçalho do arquivo;

    //Abrindo o arquivo auxiliar para escrever nele os dados das reservas;
    FileAuxiliarReserva = fopen("fileauxiliarreserva.txt", "a+");
    fseek(FileAuxiliarReserva, 0, SEEK_SET);
    fprintf(FileAuxiliarReserva, "iD,Voo,CPF,Nome,Sexo,Dia,Mes,Ano,Status\n"); //Printando o cabeçalho do arquivo;

    for(i = 0; i < numeroDeVoos; i++){
        //Printando primeiramente no arquivo auxiliar de voos;
        if(strncmp(voo_cancelado, leituraVoos[i].idVoo, 9) == 0){ //Caso o voo digitado coincida com o voo da leituraVoos[i], ele printa o voo com o status cancelado no arquivo auxiliar;
            fprintf(FileAuxiliarVoo, "%s,%d,%d,%d,%d,%d,%d,C\n", leituraVoos[i].idVoo,
                                                                 leituraVoos[i].dia,
                                                                 leituraVoos[i].mes,
                                                                 leituraVoos[i].ano,
                                                                 leituraVoos[i].hora,
                                                                 leituraVoos[i].minuto,
                                                                 leituraVoos[i].capacidade);
        } else {
            fprintf(FileAuxiliarVoo, "%s,%d,%d,%d,%d,%d,%d,%c\n",leituraVoos[i].idVoo,
                                                                 leituraVoos[i].dia,
                                                                 leituraVoos[i].mes,
                                                                 leituraVoos[i].ano,
                                                                 leituraVoos[i].hora,
                                                                 leituraVoos[i].minuto,
                                                                 leituraVoos[i].capacidade,
                                                                 leituraVoos[i].statusVoo);
        }
    }

    for(i = 0; i < numeroDeReservas; i++){
        //Printando agora no arquivo auxiliar de reservas;
        if(strncmp(voo_cancelado, leituraReservas[i].idVooReserva, 9) == 0){ //Caso o voo digitado coincida com o voo da leituraReservas[i], ele printa a reserva com o status cancelado no arquivo auxiliar;
            fprintf(FileAuxiliarReserva, "%s,%s,%s,%s,%c,%d,%d,%d,C\n", leituraReservas[i].idReserva,
                                                                        leituraReservas[i].idVooReserva,
                                                                        leituraReservas[i].cpf,
                                                                        leituraReservas[i].nomePassageiro,
                                                                        leituraReservas[i].sexo,
                                                                        leituraReservas[i].ddnDia,
                                                                        leituraReservas[i].ddnMes,
                                                                        leituraReservas[i].ddnAno);
        } else {
            fprintf(FileAuxiliarReserva, "%s,%s,%s,%s,%c,%d,%d,%d,%c\n", leituraReservas[i].idReserva,
                                                                         leituraReservas[i].idVooReserva,
                                                                         leituraReservas[i].cpf,
                                                                         leituraReservas[i].nomePassageiro,
                                                                         leituraReservas[i].sexo,
                                                                         leituraReservas[i].ddnDia,
                                                                         leituraReservas[i].ddnMes,
                                                                         leituraReservas[i].ddnAno,
                                                                         leituraReservas[i].statusReserva);
        }
    }

    fclose(FileAuxiliarVoo);
    fclose(FileAuxiliarReserva);

    validarCancelamento = 1; //Será usado esse int para mudar o nome dos arquivos, deletando o dadosdovoo.txt e transformando o arquivo auxiliar no principal;

    printf("\nVoo cancelado com sucesso!\n");
}

void Cancelar_reserva(FILE *DadosDoVoo, FILE *DadosDaReserva, FILE *FileAuxiliarVoo, FILE *FileAuxiliarReserva){
    char reserva_cancelada[10], line[MAX];
    int repetidor = 0, i;

    //Menu da consulta;
    printf("======================================================\n");
    printf("============== Cancelamento de Reservas ==============\n");
    printf("======================================================\n");
    printf("\n");

    //Printando todas as reservas disponíveis;
    printf("\n=> Lista de reservas:\n");
    for(i = 0; i < numeroDeReservas; i++){
        printf("- %s: %s, %s;\n", leituraReservas[i].idReserva, leituraReservas[i].idVooReserva, leituraReservas[i].nomePassageiro);
    }

    //Garantindo a leitura de uma reserva que está cadastradado no sistema;
    do{
        //Leitura da reserva a ser cancelado;
        printf("\nQual reserva gostaria de cancelar?\n");
        scanf("%s", reserva_cancelada);
        flush_in();

        repetidor = 1;
        for(int j = 0; j < numeroDeReservas; j++){
            if(strncmp(reserva_cancelada, leituraReservas[j].idReserva, 9) == 0){ //Se a reserva digitada coincidir com uma reserva do sistema o repetidor é = 0 e sai do loop;
                repetidor = 0;
            }
        }

        if(repetidor == 1){ //Caso o repetidor continue com o valor de 1 quer dizer que o voo digitado não coincidiu com nenhum dos voos do sistema;
            printf("\nEssa reserva não foi encontrada no sistema, tente novamente.\n");
        }

    }while(repetidor != 0);

    //Abrindo o arquivo auxiliar para escrever nele os dados das reservas;
    FileAuxiliarReserva = fopen("fileauxiliarreserva.txt", "a+");
    fseek(FileAuxiliarReserva, 0, SEEK_SET);
    fprintf(FileAuxiliarReserva, "iD,Voo,CPF,Nome,Sexo,Dia,Mes,Ano,Status\n"); //Printando o cabeçalho do arquivo;

    for(i = 0; i < numeroDeReservas; i++){
        //Printando no arquivo auxiliar de reservas;
        if(strncmp(reserva_cancelada, leituraReservas[i].idReserva, 9) == 0){ //Caso a reserva digitada coincida com a reserva da leituraReservas[i], ele printa a reserva com o status cancelado no arquivo auxiliar;
            fprintf(FileAuxiliarReserva, "%s,%s,%s,%s,%c,%d,%d,%d,C\n", leituraReservas[i].idReserva,
                                                                        leituraReservas[i].idVooReserva,
                                                                        leituraReservas[i].cpf,
                                                                        leituraReservas[i].nomePassageiro,
                                                                        leituraReservas[i].sexo,
                                                                        leituraReservas[i].ddnDia,
                                                                        leituraReservas[i].ddnMes,
                                                                        leituraReservas[i].ddnAno);
        } else {
            fprintf(FileAuxiliarReserva, "%s,%s,%s,%s,%c,%d,%d,%d,%c\n", leituraReservas[i].idReserva,
                                                                         leituraReservas[i].idVooReserva,
                                                                         leituraReservas[i].cpf,
                                                                         leituraReservas[i].nomePassageiro,
                                                                         leituraReservas[i].sexo,
                                                                         leituraReservas[i].ddnDia,
                                                                         leituraReservas[i].ddnMes,
                                                                         leituraReservas[i].ddnAno,
                                                                         leituraReservas[i].statusReserva);
        }
    }

    fclose(FileAuxiliarReserva);

    validarCancelamento = 2; //Será usado esse int para mudar o nome dos arquivos, deletando o dadosdovoo.txt e transformando o arquivo auxiliar no principal;

    printf("\nReserva cancelada com sucesso!\n");
}

void Excluir_voo(FILE *DadosDoVoo, FILE *DadosDaReserva, FILE *FileAuxiliarVoo, FILE *FileAuxiliarReserva){
    char voo_excluido[9], line[MAX];
    int repetidor = 0, i;

    //Menu da consulta;
    printf("==============================================\n");
    printf("============== Exclusão de Voos ==============\n");
    printf("==============================================\n");
    printf("\n");

    //Printando todos os voos disponíveis;
    printf("\n=> Lista de voos:\n");
    for(i = 0; i < numeroDeVoos; i++){
        printf("- %s\n", leituraVoos[i].idVoo);
    }

    //Garantindo a leitura de um voo que está cadastradado no sistema;
    do{
        //Leitura do voo a ser excluido;
        printf("\nQual voo gostaria de excluir?\n");
        scanf("%s", voo_excluido);
        flush_in();

        repetidor = 1;
        for(int j = 0; j < numeroDeVoos; j++){
            if(strncmp(voo_excluido, leituraVoos[j].idVoo, 9) == 0){ //Se o voo digitado coincidir com um voo do sistema o repetidor é = 0 e sai do loop;
                repetidor = 0;
            }
        }

        if(repetidor == 1){ //Caso o repetidor continue com o valor de 1 quer dizer que o voo digitado não coincidiu com nenhum dos voos do sistema;
            printf("\nEsse voo não foi encontrado no sistema, tente novamente.\n");
        }

    }while(repetidor != 0);

    //Abrindo o arquivo auxiliar para escrever nele os dados dos voos;
    FileAuxiliarVoo = fopen("fileauxiliarvoo.txt", "a+");
    fseek(FileAuxiliarVoo, 0, SEEK_SET);
    fprintf(FileAuxiliarVoo, "iD,Data,Hora,Passageiros,Status\n"); //Printando o cabeçalho do arquivo;

    //Abrindo o arquivo auxiliar para escrever nele os dados das reservas;
    FileAuxiliarReserva = fopen("fileauxiliarreserva.txt", "a+");
    fseek(FileAuxiliarReserva, 0, SEEK_SET);
    fprintf(FileAuxiliarReserva, "iD,Voo,CPF,Nome,Sexo,Dia,Mes,Ano,Status\n"); //Printando o cabeçalho do arquivo;

    for(int k = 0; k < numeroDeVoos; k++){
        //Printando primeiramente no arquivo auxiliar de voos;
        if(strncmp(voo_excluido, leituraVoos[k].idVoo, 9) == 0){ //Caso o voo digitado coincida com o voo da leituraVoos[i], ele não printará nada no arquivo;

        } else {
            fprintf(FileAuxiliarVoo, "%s,%d,%d,%d,%d,%d,%d,%c\n",leituraVoos[k].idVoo,
                                                                 leituraVoos[k].dia,
                                                                 leituraVoos[k].mes,
                                                                 leituraVoos[k].ano,
                                                                 leituraVoos[k].hora,
                                                                 leituraVoos[k].minuto,
                                                                 leituraVoos[k].capacidade,
                                                                 leituraVoos[k].statusVoo);
        }
    }

    for(i = 0; i < numeroDeReservas; i++){
        //Printando agora no arquivo auxiliar de reservas;
        if(strncmp(voo_excluido, leituraReservas[i].idVooReserva, 9) == 0){ //Caso o voo digitado coincida com o voo da leituraReservas[i], ele printa a reserva com o status cancelado no arquivo auxiliar;

        } else {
            fprintf(FileAuxiliarReserva, "%s,%s,%s,%s,%c,%d,%d,%d,%c\n", leituraReservas[i].idReserva,
                                                                         leituraReservas[i].idVooReserva,
                                                                         leituraReservas[i].cpf,
                                                                         leituraReservas[i].nomePassageiro,
                                                                         leituraReservas[i].sexo,
                                                                         leituraReservas[i].ddnDia,
                                                                         leituraReservas[i].ddnMes,
                                                                         leituraReservas[i].ddnAno,
                                                                         leituraReservas[i].statusReserva);
        }
    }

    fclose(FileAuxiliarVoo);
    fclose(FileAuxiliarReserva);

    validarCancelamento = 1; //Será usado esse int para mudar o nome dos arquivos, deletando o dadosdovoo.txt e transformando o arquivo auxiliar no principal;

    printf("\nVoo cancelado com sucesso!\n");
}
