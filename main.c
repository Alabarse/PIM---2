#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menuPrincipal() {
    system("cls");
int escolha;
printf("1-Visualizar Relatórios\n");
printf("2-Cadastrar Médicos\n");
printf("3-Cadastrar Pacientes\n");
printf("4-Cadastrar Funcionarios\n");
printf("Escolha: ");
scanf("%d",&escolha);
switch(escolha) {
case 1:
    telaDeRelatorio();
    break;
case 2:
    printf("Em breve..");
    break;
case 3:
    printf("Em breve..");
    break;
case 4:
    printf("Em breve..");
    break;
default:
    printf("Digite uma opção válida!");
    menuPrincipal();
}

}

int telaDeLogin() {
    system("cls");
    char usuario, senha;
 printf("==================\n");
    printf(" Login:");
    scanf("%s", &usuario);
    printf(" Senha:");
    scanf("%s", &senha);
printf("==================\n");
}

int telaDeCadastro() {
    system("cls");
    char usuario, senha, nacionalidade,funciOuPaciente;
    printf("==================\n");
    printf(" Nacionalidade:");
    scanf("%s", &nacionalidade);
    printf(" Funcionario ou paciente?");
    scanf("%s", &funciOuPaciente);
    printf(" Login:");
    scanf("%s", &usuario);
    printf(" Senha:");
    scanf("%s", &senha);
printf("==================\n");

// Manipulação arquivo TXT
FILE *logLogin;
logLogin = fopen ("D:\\Mateus\\EstudoC\\LogLogin.txt", "w");
fprintf(logLogin, "Usuario: %c \n", &usuario);
fprintf(logLogin, "Senha: %c \n", &senha);
fprintf(logLogin, "Nacionalidade: %c \n", &nacionalidade);
fclose(logLogin);

}

int telaDeRelatorio() {

    system("cls");
    int Escolharede;
    printf("Deseja solicitar relatorio de qual rede: \n");
    printf("1 - Curitiba\n");
    printf("2 - São Paulo\n" );
    printf("3 - Rio de janeiro\n");
    printf("4 - voltar\n");
    printf("Rede:");
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
        printf("Por favor digite uma opção válida");
    }
    menuPrincipal();
}
