#include <stdio.h>
#include <stdlib.h>

typedef struct // horario
{
  int hora, minuto, segundo;
} horario;

typedef struct // data
{
  int dia;
  int mes;
  int ano;
} data;

typedef struct // info consulta
{
  int codconsulta, codpaciente;
  data data_consulta;
  horario horario_consulta;
} consulta;

typedef struct // info paciente
{
  int codpaciente, tel;
  int contConsulta;
  char nome[30];
  consulta c[26];
} Paciente;

int i;
int cont = 0;
Paciente paciente[4];
consulta consu;

void cadastrar() {
  //system("cls");
  int verificacao = 0;
  if (cont > 3) {
    printf("Limite de clientes já cadastrados!");
  }
  printf("\nCadastrar um novo Cliente.\n");
  setbuf(stdin, NULL);
  printf("Insira o nome: ");
  fgets(paciente[cont].nome, 29, stdin);

  int codigo;
  int codigoDisponivel = 0;

  //primeiro paciente cadastrado
  if(cont == 0){
    printf("Insira o codigo do paciente: ");
    scanf("%d", &paciente[cont].codpaciente);
    codigoDisponivel = 1;
  }

  while(codigoDisponivel == 0){
    printf("Insira o codigo do paciente: ");
    scanf("%d", &codigo);
    for(i = 0; i < cont; i++){
    if(codigo == paciente[i].codpaciente){
      printf("Já existe um paciente com esse codigo! Digite outro codigo:\n");
    }
      else{
        codigoDisponivel = 1;
        paciente[cont].codpaciente = codigo;
      }
  }
}

  printf("Insira o telefone do paciente: ");
  scanf("%d", &paciente[cont].tel);
  paciente[cont].contConsulta = 0;
  cont++;
  printf("Paciente cadastrado com suceso!\n");
  // system("pause");
}

void Cadastrar_Consulta() {
  //system("cls");
  int codigo;
  int dia, mes, ano;
  int indice = 99;
  // VERIFICACAO DE PACIENTE
  printf("\nInsira o codigo do Paciente: ");
  scanf("%d", &codigo);

  for (i = 0; i < 4; i++) {
    if (codigo == paciente[i].codpaciente) {
      printf("Paciente cadastrado!\n");
      indice = i;
      i = 5;
    }
  }

  if (indice == 99) {
    printf("Paciente com esse código não cadastrado");
    printf("\nCadastre agora!\n");
    cadastrar();
  }

  // system("pause");
  int diaDisponivel = 0;
  do {
    // system("cls");
    printf("Digite o dia para a consulta: ");
    scanf("%d", &dia);
    printf("Digite o mes para a consulta: ");
    scanf("%d", &mes);
    printf("Digite o ano para a consulta: ");
    scanf("%d", &ano);
    if (dia == paciente[indice]
                   .c[paciente[indice].contConsulta]
                   .data_consulta.dia &&
        mes == paciente[indice]
                   .c[paciente[indice].contConsulta]
                   .data_consulta.mes &&
        ano == paciente[indice]
                   .c[paciente[indice].contConsulta]
                   .data_consulta.ano) {
      printf("\nEsta data ja foi solicitada por este mesmo paciente, tente "
             "outra data!\n");
      // system("pause");
    } else {
      diaDisponivel = 1;
      paciente[indice].c[paciente[indice].contConsulta].data_consulta.dia = dia;
      paciente[indice].c[paciente[indice].contConsulta].data_consulta.mes = mes;
      paciente[indice].c[paciente[indice].contConsulta].data_consulta.ano = ano;
      printf("Digite o codigo da consulta: ");
      scanf("%d",
            &paciente[indice].c[paciente[indice].contConsulta].codconsulta);
      printf("Digite a hora para a consulta: ");
      scanf("%d", &paciente[indice]
                       .c[paciente[indice].contConsulta]
                       .horario_consulta.hora);
      printf("Digite o minutos para a consulta: ");
      scanf("%d", &paciente[indice]
                       .c[paciente[indice].contConsulta]
                       .horario_consulta.minuto);
      printf("Digite o segundo para a consulta: ");
      scanf("%d", &paciente[indice]
                       .c[paciente[indice].contConsulta]
                       .horario_consulta.segundo);
      paciente[indice].contConsulta++;
    }
  } while (diaDisponivel == 0);
  printf("\nConsulta agendada com suceso!\n");
}
    //system("pause");

void consultar_agendamento() {
    //system("cls");
  int codigo;
  int indice = 99;
  printf("\nDigite o codigo do paciente: ");
  scanf("%d", &codigo);
  for (i = 0; i < 4; i++) {
    if (codigo == paciente[i].codpaciente) {
      printf("Paciente cadastrado!\n");
      indice = i;
      i = 5;
    }
  }

  if (indice == 99) {
    printf("Paciente com esse código não cadastrado");
    printf("\nCadastre agora!\n");
    cadastrar();
  }

  printf("\nConsultas do Paciente %s", paciente[indice].nome);
  for (int j = 0; j < paciente[indice].contConsulta; j++) {

    printf("\n%d / %d / %d - %d:%d:%d \n",
           paciente[indice].c[j].data_consulta.dia,
           paciente[indice].c[j].data_consulta.mes,
           paciente[indice].c[j].data_consulta.ano,
           paciente[indice].c[j].horario_consulta.hora,
           paciente[indice].c[j].horario_consulta.minuto,
           paciente[indice].c[j].horario_consulta.segundo);
  }
  //system("pause");
}

void alterar_horarioConsulta() {
  //system("cls");
  int codigo, codigo_consulta;
  int indice = 99, indice_consulta;
  printf("\nDigite o codigo do paciente: ");
  scanf("%d", &codigo);
  for (i = 0; i < 4; i++) {
    if (codigo == paciente[i].codpaciente) {
      printf("Paciente cadastrado!\n");
      indice = i;
      i = 5;
    }
  }

  if (indice == 99) {
    printf("Paciente com esse código não cadastrado");
    printf("\nCadastre agora!\n");
    cadastrar();
  }

  printf("\nDigite o codigo da consulta que terá o horário alterado: ");
  scanf("%d", &codigo_consulta);
  for (i = 0; i < 26; i++) {
    if (codigo_consulta == paciente[indice].c[i].codconsulta) {
      printf("Consulta cadastrada!\n");
      indice_consulta = i;
      i = 27;
    }
  }

  printf("Digite a nova hora para a consulta: ");
  scanf("%d", &paciente[indice].c[indice_consulta].horario_consulta.hora);
  printf("Digite o novo minuto para a consulta: ");
  scanf("%d", &paciente[indice].c[indice_consulta].horario_consulta.minuto);
  printf("Digite o novo segundo para a consulta: ");
  scanf("%d", &paciente[indice].c[indice_consulta].horario_consulta.segundo);

  //system("pause");
}

int main() {
  int option;
  do {
    //system("cls");
    printf("\n1 - Cadastrar cliente.\n2 - Fazer consulta.\n3 - "
           "Consultar agendamentos.\n4 - Alterar horario de uma consulta.\n5 - "
           "Para sair do Programa.\nInsira uma opcao: ");
    scanf("%d", &option);
    switch (option) {
    case 1:
      cadastrar();
      break;
    case 2:
      Cadastrar_Consulta();
      break;
    case 3:
      consultar_agendamento();
      break;
    case 4:
      alterar_horarioConsulta();
      break;
    default:
      if (option != 5) {
        printf("\nPrograma encerrado, insira uma opcao valida!\n");
      }
      break;
    }
  } while (option != 5);
  return 0;
}
