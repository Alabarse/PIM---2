#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include<stdbool.h>

_Bool StringsIguais(const char s1 [], const char s2 [], const char s3[], const char s4[]) {
     int i = 0;
     while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && s3[i] == s4[i] && s3[i] != '\0' && s4[i] != '\0') {
            ++i;
     }

     if (s1[i] == '\0' && s2[i] == '\0' && s3[i] == '\0' && s4[i] == '\0') {
        printf("Certo");
        return true;
     }else {
         printf("Errado");
         return false;
     }

}

void agendar() {
    FILE * agendamentos;
    agendamentos = fopen("D:\\Mateus\\EstudoC\\agendamentos.txt", "w");
    fprintf(agendamentos, "========== Agendametos ==========");
}

void cadastroPacientes() {
    system("cls");
    printf("========== Cadastrando Paciente ========== \n");
    int escolha;
    int idade;
    char nome[30];
    char cpf[13];
    char cep[9];
    printf("Nome:");
    scanf("%s", nome);
    printf("Idade:");
    scanf("%i", &idade);
    printf("CPF:");
    scanf("%s", cpf);
    printf("CEP:");
    scanf("%s", cep);
    printf("========== Cadastrando Paciente ========== \n");

    FILE * cadastrosDePacientes;
    cadastrosDePacientes = fopen("D:\\Mateus\\EstudoC\\cadastrosDePacientes.txt", "a");
    fprintf(cadastrosDePacientes, "Nome: %s \n", &nome);
    fprintf(cadastrosDePacientes, "Idade: %d \n", idade);
    fprintf(cadastrosDePacientes, "CPF: %s \n", &cpf);
    fprintf(cadastrosDePacientes, "CEP: %s \n \n", &cep);
    fclose(cadastrosDePacientes);

    printf("\n");
    printf("1-Voltar\n");
    printf("2-Sair\n");
    printf("Escolha:");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
        cadastrar();
        break;
        case 2:
        exit(0);
        break;
        default:
        printf("Opção inválida!");
        cadastroPacientes();
    }
}

void mostrarPacientes() {

    int escolha;

    system("cls");
    FILE *cadastroDePacientes;
        cadastroDePacientes = fopen("D:\\Mateus\\EstudoC\\cadastrosDePacientes.txt", "r");

        if (cadastroDePacientes == NULL) {
            printf("Não foi possivel abrir o arquivo");
            getchar();
            exit(0);
        }else {
            char login[30];
            while(fgets(login, 30, cadastroDePacientes) != NULL) {
            printf("%s", login);
    }

        fclose(cadastroDePacientes);
}

printf("1-Voltar \n");
printf("Escolha:");
scanf("%d", &escolha);
if(escolha == 1) {
    cadastros();
}else {
    exit(0);
}

}

void mostrarMedicos() {
    system("cls");
    int escolha;
    FILE *cadastroDeMedicos;
        cadastroDeMedicos = fopen("D:\\Mateus\\EstudoC\\cadastrosDeMedicos.txt", "r");

        if (cadastroDeMedicos == NULL) {
            printf("Não foi possivel abrir o arquivo");
            getchar();
            exit(0);
        }else {
            char login[30];
            while(fgets(login, 30, cadastroDeMedicos) != NULL) {
            printf("%s", login);
    }

        fclose(cadastroDeMedicos);
}

printf("1-Voltar \n");
printf("Escolha:");
scanf("%d", &escolha);
if(escolha == 1) {
    cadastros();
}else {
    exit(0);
}
}

void telaDeAgendamentos () {
    system("cls");
    printf("1-Novo agendamento\n");
    printf("2-Consultar Agendamento\n");
    printf("3-Listar todos Agendamentos\n");
    printf("4-Voltar\n");
    printf("Escolha:");
    int escolha;
    scanf("%d", &escolha);
    switch(escolha) {
    case 1:
        menuPrincipal();
        break;
    }
}

void cadastrar() {
    system("cls");
    printf("1-Paciente\n");
    printf("2-Medicos\n");
    printf("3-Voltar\n");
    printf("Escolha:");
    int escolha;
    scanf("%d", &escolha);
    switch(escolha) {
    case 1:
        cadastroPacientes();
        break;
    case 2:
        cadastroMedicos();
    case 3:
        menuPrincipal();
    default:
        printf("Opção inválida!");
        cadastrar();
    }
}

void cadastros() {
    system("cls");
    int escolha;
    printf("1-Pacientes\n");
    printf("2-Médicos\n");
    printf("3-Voltar\n");
    printf("Escolha:");
    scanf("%d", &escolha);
    switch(escolha){
    case 1:
        mostrarPacientes();
        break;
    case 2:
        mostrarMedicos();
        break;
    case 3:
        menuPrincipal();
    default:
        printf("Opção inválida");
    }

}

void menuPrincipal() {



    system("cls");
    int escolha;
    printf("1-Visualizar Relatórios\n");
    printf("2-Cadastrar\n");
    printf("3-Cadastros\n");
    printf("4-Agendamentos\n");
    printf("5-Sair\n");
    printf("Escolha: ");
    scanf("%d",&escolha);
switch(escolha) {
case 1:
    telaDeRelatorio();
    break;
case 2:
    cadastrar();
    break;
case 3:
    cadastros();
    break;
case 4:
    telaDeAgendamentos();
    break;
case 5:
    telaInicial();
default:
    printf("Digite uma opção válida!");
    menuPrincipal();
}

}
void telaInicial() {



    system("cls");
    printf("Digite sua escolha\n");
    printf("1-Login\n");
    printf("2-Cadastro\n");
    printf("Escolha:");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha) {
      case 1:
       telaDeLogin();
       break;
      case 2:
       telaDeCadastro();
       break;
      default:
        printf("\nPor favor digite uma opção válida  \n \n");
        getchar();
        printf("Digite ENTER para continuar....");
        getchar();

        telaInicial();
    }

}
void cadastroMedicos() {



    system("cls");
    printf("========== Cadastrando Médico ========== \n");
    int idade;
    char nome[20], nacionalidade[15];
    printf("Nome:");
    scanf("%s", &nome);
    printf("Idade:");
    scanf("%d", &idade);
    printf("Nacionalidade:");
    scanf("%s", &nacionalidade);
    printf("========== Cadastrando Médico ========== \n");

    FILE *cadastroDeMedicos;
    cadastroDeMedicos = fopen("D:\\Mateus\\EstudoC\\cadastrosDeMedicos.txt", "a");
    fprintf(cadastroDeMedicos, "Nome:%s \n", &nome);
    fprintf(cadastroDeMedicos, "Idade: %d \n", idade);
    fprintf(cadastroDeMedicos, "Nacionalidade:%s \n \n", &nacionalidade);
    fclose(cadastroDeMedicos);
    int escolha;

    printf("\n");
    printf("1-Voltar\n");
    printf("2-Sair\n");
    printf("Escolha:");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
        cadastrar();
        break;
        case 2:
        exit(0);
        break;
        default:
        printf("Opção inválida!");
        cadastrar();
    }

}
void telaDeLogin() {

    system("cls");
    char usuario[30];
    char senha[30];
    bool contaExistente = false;
 printf("=========LOGIN=========\n");
    printf(" Login:");
    scanf("%s", usuario);
    printf(" Senha:");
    scanf("%s", senha);
printf("=========LOGIN=========\n");

system("cls");

// Manipulação arquivo TXT

FILE *logSenha;
logSenha = fopen("D:\\Mateus\\EstudoC\\LogSenha.txt", "r");

FILE *logLogin;
logLogin = fopen("D:\\Mateus\\EstudoC\\LogLogin.txt", "r");
if (logLogin == NULL) {
    printf("Não foi possivel abrir o arquivo");
    getchar();
    exit(0);
}else {
    char login[30];
    int i= 0;
    while(fscanf(logLogin,"%s", &login) != usuario) {
            while (login[i] == usuario [i] && login[i] != '\0' && usuario[i] != '\0') {
                printf("%s \n", login);
                ++i;

                 if (login[i] == '\0' && usuario[i] == '\0') {
                    printf("Logado com sucesso \n");
                    system("pause");
                    menuPrincipal();
            }else {
                printf("erro \n");
            }
            }
        }
        if (login[i] == '\0' && usuario[i] == '\0') {
                    printf("Logado com sucesso \n");
            }else {
                printf("erro \n");
            }

           /* if (login[i] == '\0' && usuario[i] == '\0') {
                    printf("Logado com sucesso\n");
                    printf("Usuario:%s \n", usuario);
                    printf("Login:%s \n", login);
                    printf("Senha:%s \n", senha);
                    printf("PalavraP:%s \n", palavraP);
                    i = 0;
                    jumper = true;
                }else {
                    printf("Erro no login\n");
                    printf("Usuario:%s \n", usuario);
                    printf("Login:%s \n", login);
                    printf("Senha:%s \n", senha);
                    printf("PalavraP:%s \n", palavraP);
                    i = 0;
                } */

    fclose(logLogin);
}

}

void telaDeCadastro() {
    system("cls");
    char usuario[30], senha[30];
    printf("=========Cadastro=========\n");
    printf(" Login:");
    scanf("%s", usuario);
    printf(" Senha:");
    scanf("%s", senha);
printf("=========Cadastro=========\n");

// Manipulação arquivo TXT
FILE *logLogin;

logLogin = fopen ("D:\\Mateus\\EstudoC\\LogLogin.txt", "a");
fprintf(logLogin, "%s\n", &usuario);
fclose(logLogin);

FILE *logSenha;
logSenha = fopen("D:\\Mateus\\EstudoC\\LogSenha.txt", "a");
fprintf(logSenha, "%s\n", &senha);
fclose(logSenha);

    system("cls");
    getchar();
    telaDeLogin();


}

void telaDeRelatorio() {


    system("cls");
    int Escolharede;
    printf("Deseja solicitar relatorio de qual rede: \n");
    printf("1 - Curitiba\n");
    printf("2 - São Paulo\n" );
    printf("3 - Rio de janeiro\n");
    printf("4 - Voltar\n");
    printf("Escolha:");
    scanf("%d", &Escolharede);

    switch(Escolharede) {
    case 1:
        system("cls");
        printf("============ CURITIBA ============\n");
        break;
    case 2:
        system("cls");
        printf("============ SÃO PAULO ============\n");
        break;
    case 3:
        system("cls");
        printf("============ RIO DE JANEIRO ============\n");
        break;
    case 4:
        menuPrincipal();
        break;
    default:
        printf("Valor inválido");
    }


}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    telaInicial();

}
