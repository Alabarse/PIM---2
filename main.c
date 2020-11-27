#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

FILE * agendamentos;
FILE * logSenha;
FILE *logLogin;
FILE * cadastrosDePacientes;
FILE * cadastroDePacientes;
FILE * cadastroDeMedicos;
FILE * RelatorioSP;
FILE * RelatorioRJ;
FILE * RelatorioCURITIBA;

bool logado = false;
int unidadePR = 0;
int unidadeSP = 0;
int unidadeRJ = 0;
char senha[30];

void novoRelatorioSP();

void porPadraoRelatorios();

void novoRelatorioRJ();

void novoRelatorioPR();

void removerAgendamento();

void novoRelatorio();

void verificarSenhaLogin();

void listarAgendamentos();

void agendar();

void cadastroPacientes();

void mostrarPacientes();

void mostrarMedicos();

void telaDeAgendamentos();

void cadastrar();

void cadastros();

void menuPrincipal();

void telaInicial();

void cadastroMedicos();

void telaDeLogin();

void telaDeCadastro();

void telaDeRelatorio();

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    telaInicial();
}

void listarAgendamentos() {

    system("cls");
    agendamentos = fopen("agendamentos.txt", "r");

    if (agendamentos == NULL) {
        printf("Não foi possivel abrir o arquivo");
        getchar();
        exit(0);
    }else {
        char nome[25];
        int dia;
        int mes;
        while(fgets(nome, 25, agendamentos) != NULL) {
            printf("%s", nome);
        }
        printf("\n");
        fclose(agendamentos);
    }

    getchar();
    printf("\nDigite ENTER para voltar.");
    getchar();
    telaDeAgendamentos();

}

void verificarSenhaLogin() {
    bool deBounce = true;

logSenha = fopen("LogSenha.txt", "r");

if (logSenha == NULL){
    printf("Impossivel abrir o log de senhas!");
    getchar();
    exit(0);
}
    char palavraPasse[30];
    while(fscanf(logSenha, "%s", palavraPasse) != senha || palavraPasse != NULL) {
        if (strcmp (palavraPasse,senha) == 0) {
            printf("Logado com sucesso...");
            deBounce = true;
            logado = true;
            getchar();
            menuPrincipal();
            break;
            }
    }
    deBounce = false;
    if (strcmp(palavraPasse,senha) != 0 && deBounce == false) {
            printf("Senha incorreta! Pressione ENTER para continuar...");
            getchar();
            telaInicial();
      }
}

void agendar() {
    system("cls");
    char nomePaciente[50];
    int diaConsulta;
    int mesConsulta;
    printf("Digite o nome do Paciente:");
    scanf("%s", &nomePaciente);
    printf("Digite o dia da consulta:");
    scanf("%i", &diaConsulta);
    printf("Digite o mês da consulta:");
    scanf("%i", &mesConsulta);
    system("cls");

    if (diaConsulta <= 31 && mesConsulta <= 12) {
    agendamentos = fopen("agendamentos.txt", "a");
    fprintf(agendamentos, "\n\n%s\n%i/%i", nomePaciente, diaConsulta, mesConsulta);
    fclose(agendamentos);
    telaDeAgendamentos();
    }else {
        printf("Dia ou mês fora do calendario convencional!\n");
        system("pause");
        agendar();
    }
}

void cadastroPacientes() {
    system("cls");
    printf("========== Cadastrando Paciente ========== \n");
    int escolhaCP;
    int idade;
    char nome[30];
    char sobrenome[30];
    char cpf[11];
    char cep[9];
    printf("Nome:");
    scanf("%s", nome);
    printf("Sobrenome:");
    scanf("%s", &sobrenome);
    printf("Idade:");
    scanf("%i", &idade);
    printf("CPF:");
    scanf("%s", cpf);
    if (cpf[13] != '\0') {
        printf("digite o cpf novamente!");
        scanf("%s", &cpf);
    }
    printf("CEP:");
    scanf("%s", cep);
    printf("========== Cadastrando Paciente ========== \n");


    cadastrosDePacientes = fopen("cadastrosDePacientes.txt", "a");
    fprintf(cadastrosDePacientes, "Nome: %s \n", &nome);
    fprintf(cadastrosDePacientes, "Idade: %d \n", idade);
    fprintf(cadastrosDePacientes, "CPF: %s \n", &cpf);
    fprintf(cadastrosDePacientes, "CEP: %s \n \n", &cep);
    fclose(cadastrosDePacientes);

    printf("\n");
    printf("1-Voltar\n");
    printf("2-Continuar Cadastrando\n");
    printf("Escolha:");
    scanf("%d", &escolhaCP);

    switch (escolhaCP) {
        case 1:
            cadastrar();
        break;
        case 2:
            cadastroPacientes();
        break;
        default:
        printf("Opção inválida! Aperte ENTER para continuar..");
        system("pause");
        cadastroPacientes();
    }
}

void mostrarPacientes() {

    int escolha;

    system("cls");

        cadastroDePacientes = fopen("cadastrosDePacientes.txt", "r");

        if (cadastroDePacientes == NULL) {
            printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
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

void telaDeAgendamentos () {
    system("cls");
    printf("1-Novo agendamento\n");
    printf("2-Listar todos Agendamentos\n");
    printf("3-Voltar\n");
    printf("Escolha:");
    int escolhaOpAgendamento;
    scanf("%i", &escolhaOpAgendamento);
    switch(escolhaOpAgendamento) {
    case 1:
        agendar();
    break;
    case 2:
        listarAgendamentos();
    break;
    case 3:
        menuPrincipal();
    break;
    default:
        printf("Opção inválida! Digite ENTER para continuar!");
        getchar();
        telaDeAgendamentos();
    break;
    }
}

void mostrarMedicos(){
    system("cls");
    int escolha;
        cadastroDeMedicos = fopen("cadastrosDeMedicos.txt", "r");

        if (cadastroDeMedicos == NULL) {
            printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
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
    int escolhaMenu;
    printf("1-Visualizar Relatórios\n");
    printf("2-Cadastrar\n");
    printf("3-Cadastros\n");
    printf("4-Agendamentos\n");
    printf("5-Sair\n");
    printf("Escolha: ");
    scanf("%d",&escolhaMenu);
switch(escolhaMenu) {
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
    int escolha;
    do {
    system("cls");
    printf("Digite sua escolha\n");
    printf("1-Login\n");
    printf("2-Cadastro\n");
    printf("Escolha:");
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
    } while(logado == false);
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

    cadastroDeMedicos = fopen("cadastrosDeMedicos.txt", "a");
    fprintf(cadastroDeMedicos, "Nome:%s \n", &nome);
    fprintf(cadastroDeMedicos, "Idade: %d \n", idade);
    fprintf(cadastroDeMedicos, "Nacionalidade:%s \n \n", &nacionalidade);
    fclose(cadastroDeMedicos);
    int escolha;

    printf("\n");
    printf("1-Voltar\n");
    printf("2-Continuar Cadastrando\n");
    printf("Escolha:");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            cadastrar();
        break;
        case 2:
            cadastroMedicos();
        break;
        default:
        printf("Opção inválida!");
        cadastroMedicos();
    }
}

void telaDeLogin() {

    system("cls");
    char usuario[30];
    bool contaExistente = false;
 printf("=========LOGIN=========\n");
    printf(" Login:");
    scanf("%s", usuario);
    printf(" Senha:");
    scanf("%s", senha);
printf("=========LOGIN=========\n");

system("cls");

// Manipulação arquivo TXT


logSenha = fopen("LogSenha.txt", "r");

logLogin = fopen("LogLogin.txt", "r");

if (logLogin == NULL) {
    printf("ARQUIVO VAZIO, FAVOR CRIAR CADASTROS A SER ACESSADOS!");
    getchar();
    exit(0);
}else {
    char login[30];
    int i= 0;
    while(fscanf(logLogin,"%s", &login) != usuario) {
        if(strcmp(login,usuario) == 0) {
            printf("Verificando senha... \n");
            verificarSenhaLogin();
            break;
        }else if (strcmp(login,usuario) != 0 && i == 30) {
            printf("Usuario incorreto! Pressione ENTER para continuar...");
            getchar();
            telaInicial();
            break;
        }
        i++;
    }
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

logLogin = fopen ("LogLogin.txt", "a");
fprintf(logLogin, "%s\n", &usuario);
fclose(logLogin);

FILE *logSenha;
logSenha = fopen("LogSenha.txt", "a");
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
    printf("4 - Novo Relatorio\n");
    printf("5 - Voltar\n");
    printf("Escolha:");
    scanf("%d", &Escolharede);

    switch(Escolharede) {
    case 1:
        system("cls");
        printf("============ CURITIBA ============\n");
        listarRelatorioPR();
    break;
    case 2:
        system("cls");
        printf("============ SÃO PAULO ============\n");
        listarRelatorioSP();
    break;
    case 3:
        system("cls");
        printf("============ RIO DE JANEIRO ============\n");
        listarRelatorioRJ();
        break;
    case 4:
        novoRelatorio();
    break;
    break;
    case 5:
        menuPrincipal();
    break;
    default:
        printf("Valor inválido");
    }
}

void novoRelatorio() {
    system("cls");
    int escolhaRelatorio;
    printf("Escolha a rede que se enquadra no relatorio: \n");
    printf("1 - Curitiba\n");
    printf("2 - São Paulo\n" );
    printf("3 - Rio de janeiro\n");
    printf("4 - voltar\n");
    printf("Escolha:");
    scanf("%i", &escolhaRelatorio);
    switch (escolhaRelatorio) {
        case 1:
            novoRelatorioPR();
        break;
        case 2:
            novoRelatorioSP();
        break;
        case 3:
            novoRelatorioRJ();
        break;
        case 4:
            telaDeRelatorio();
        break;
        default:
            printf("Escolha inválida! aperte ENTER para continuar.");
            getchar();
            novoRelatorio();
        break;
    }

}

void novoRelatorioPR() {

system("cls");
 int avaliacaoPR;
 char feedbackPR[150];
 int linhaPR = 0;
 char caracterePR;

 RelatorioCURITIBA = fopen("RelatorioCuritiba.txt", "a");
 if (RelatorioCURITIBA == NULL) {
    printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
 }else {
    printf("Avalie de 0 a 10!\n");
    scanf("%i", &avaliacaoPR);
    while (avaliacaoPR < 0 || avaliacaoPR > 10) {
        printf("Valor inválido digite novamente de 0 a 10!\n");
        scanf("%i", &avaliacaoPR);
    }
    getchar();
    printf("Dê seu feedback! lim. 150 caracteres:");
    do {
        caracterePR = getchar();
        feedbackPR[linhaPR] = caracterePR;
        ++linhaPR;
    }while(caracterePR != '\n');

    feedbackPR[linhaPR - 1] = '\0';

    fprintf(RelatorioCURITIBA, "\nnota:%i\n", avaliacaoPR);
    fprintf(RelatorioCURITIBA, "feedback: %s\n", feedbackPR);
    fclose(RelatorioCURITIBA);
    novoRelatorio();
 }

}

void novoRelatorioRJ() {

system("cls");

int avaliacaoRJ;
char feedbackRJ[150];
int linhaRJ = 0;
char caractereRJ;

RelatorioRJ = fopen("RelatorioRio.txt", "a");

if (RelatorioRJ == NULL) {
    printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
 }else {
    printf("Avalie de 0 a 10!\n");
    scanf("%i", &avaliacaoRJ);
    while (avaliacaoRJ < 0 || avaliacaoRJ > 10) {
        printf("Valor inválido digite novamente de 0 a 10!\n");
        scanf("%i", &avaliacaoRJ);
    }
    getchar();
    printf("Dê seu feedback! lim. 150 caracteres:");
    do {
        caractereRJ = getchar();
        feedbackRJ[linhaRJ] = caractereRJ;
        ++linhaRJ;
    }while(caractereRJ != '\n');

    feedbackRJ[linhaRJ - 1] = '\0';

    fprintf(RelatorioRJ, "\nnota:%i\n", avaliacaoRJ);
    fprintf(RelatorioRJ, "feedback: %s\n", feedbackRJ);
    fclose(RelatorioRJ);
    novoRelatorio();
 }
}


void novoRelatorioSP() {

system("cls");
int avaliacaoSP;
char feedbackSP[150];
char caractereSP;
int linhaSP = 0;

RelatorioSP = fopen("RelatorioSP.txt", "a");

if (RelatorioSP == NULL) {
    printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
 }else {
    printf("Avalie de 0 a 10!\n");
    scanf("%i", &avaliacaoSP);
    while (avaliacaoSP < 0 || avaliacaoSP > 10) {
        printf("Valor inválido digite novamente de 0 a 10!\n");
        scanf("%i", &avaliacaoSP);
    }
    getchar();
    printf("Dê seu feedback! lim. 150 caracteres:");
    do {
        caractereSP = getchar();
        feedbackSP[linhaSP] = caractereSP;
        ++linhaSP;
    }while(caractereSP != '\n');

    feedbackSP[linhaSP - 1] = '\0';

    fprintf(RelatorioSP, "\nnota:%i\n", avaliacaoSP);
    fprintf(RelatorioSP, "feedback: %s\n", feedbackSP);
    fclose(RelatorioSP);
    novoRelatorio();
}

}


/*void porPadraoRelatorios() {
    if (RelatorioCURITIBA == NULL) {
    RelatorioCURITIBA = fopen("RelatorioNoCuritiba.txt", "w");
    fprintf(RelatorioCURITIBA, "%i", unidadePR);
    }

    if (RelatorioSP == NULL) {
    RelatorioSP = fopen("RelatorioSP.txt", "w");
    fprintf(RelatorioSP, "%i", unidadeSP);
    }

    if (RelatorioRJ == NULL) {
    RelatorioRJ = fopen("RelatorioRJ.txt", "w");
    fprintf(RelatorioRJ, "%i", unidadeRJ);
    }
}


void qntdAtendidoEmPR() {

FILE * qntdAtendidoPR;

    qntdAtendidoPR = fopen("qntdAtendidoNoPR.txt", "w");

if (qntdAtendidoPR == NULL) {
        printf("Impossivel abrir o arquivo");
}else {


    fprintf(qntdAtendidoPR, "%i", unidadePR);
    fclose(qntdAtendidoPR);

    qntdAtendidoPR = fopen("qntdAtendidoNoPR.txt", "r");
    fscanf(qntdAtendidoPR, "%i", unidadePR);
    fclose(qntdAtendidoPR);

    unidadePR++;

}

}


void qntdAtendidoEmSP() {

FILE * qntdAtendidoSP;

qntdAtendidoSP = fopen("qntdAtendidoNoSP.txt", "r");
fscanf(qntdAtendidoSP, "%i", unidadeSP);
unidadeSP++;
fclose(qntdAtendidoSP);

qntdAtendidoSP = fopen("qntdAtendidoNoSP.txt", "w");
fprintf(qntdAtendidoSP, "%i", unidadeSP);
fclose(qntdAtendidoSP);

}


void qntdAtendidoEmRJ() {

FILE * qntdAtendidoRJ;

qntdAtendidoRJ = fopen("qntdAtendidoNoRJ.txt", "r");
fscanf(qntdAtendidoRJ, "%i", unidadeSP);
unidadeRJ++;
fclose(qntdAtendidoRJ);

qntdAtendidoRJ = fopen("qntdAtendidoNoRJ.txt", "w");
fprintf(qntdAtendidoRJ, "%i", unidadeRJ);
fclose(qntdAtendidoRJ);

}
*/

void listarRelatorioPR() {

RelatorioCURITIBA = fopen("RelatorioCuritiba.txt", "r");

        if (RelatorioCURITIBA == NULL) {
            printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
            getchar();
            exit(0);
        }else {
            char informacoesPR[200];
            while(fgets(informacoesPR, 200, RelatorioCURITIBA) != NULL) {
            printf("%s", informacoesPR);
    }

        fclose(RelatorioCURITIBA);

}
    getchar();
    printf("\nDigite ENTER para voltar.");
    getchar();
    getchar();
    telaDeRelatorio();
}

void listarRelatorioSP() {

RelatorioSP = fopen("RelatorioSP.txt", "r");

        if (RelatorioSP == NULL) {
            printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
            getchar();
            exit(0);
        }else {
            char informacoesSP[200];
            while(fgets(informacoesSP, 200, RelatorioSP) != NULL) {
            printf("%s", informacoesSP);
    }

        fclose(RelatorioSP);

}
    getchar();
    printf("\nDigite ENTER para voltar.");
    getchar();
    telaDeRelatorio();

}


void listarRelatorioRJ() {


RelatorioRJ = fopen("RelatorioRio.txt", "r");

        if (RelatorioRJ == NULL) {
            printf("ARQUIVO VAZIO, FAVOR CRIAR INFORMAÇOES A SER ACESSADAS!");
            getchar();
            exit(0);
        }else {
            char informacoesRJ[200];
            while(fgets(informacoesRJ, 200, RelatorioRJ) != NULL) {
            printf("%s", informacoesRJ);
    }

        fclose(RelatorioRJ);
}
    getchar();
    printf("\nDigite ENTER para voltar.");
    getchar();
    telaDeRelatorio();

}
