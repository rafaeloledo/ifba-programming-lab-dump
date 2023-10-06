#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contN = 0, contS = 0, contC = 0, contNasc = 0, contador = 0, contador1;
char dataNascimento1[20];
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarNascimento(char dataNascimento[]);
int validarCPF(char cpf[]);

struct dados {
  char nome[40], sexo, dataNascimento[20], dataNascimento1[20], cpf[20];
} cliente;
struct dados cadastrarCliente(char nome[], char sexo, char dataNascimento[],
                              char cpf[]);
int main() {
  setbuf(stdin, NULL);
  setlocale(LC_ALL, "Portuguese");
  cadastrarCliente(cliente.nome, cliente.sexo, cliente.dataNascimento,
                   cliente.cpf);
  if (contN == 0) {
    printf("Nome validado com sucesso: %s", cliente.nome);
  } else {
    printf("Erro na validação.Nome é inválido.\n");
  }
  if (contS == 0) {
    printf("Sexo validado com sucesso: %c\n", cliente.sexo);
  } else {
    printf("Erro na validação.Sexo digitado é inválido.\n");
  }
  if (contNasc == 0) {
    printf("Data de nascimento validada com sucesso: %s\n",
           cliente.dataNascimento1);
  } else {
    printf("Erro na validação.Data de nascimento é inválida.\n");
  }
  if (contC == 0) {
    printf("Cpf validado com sucesso: %s\n", cliente.cpf);
  } else {
    printf("Erro na validação.Cpf digitado é invalido.");
  }
  return 0;
  system("PAUSE");
}
struct dados cadastrarCliente(char nome[], char sexo, char dataNascimento[],
                              char cpf[]) {
  printf("Digite o nome do cliente: ");
  fgets(cliente.nome, 40, stdin);
  printf("Digite o sexo do cliente. Opções: m e M para masculino, f e F para "
         "feminino, o e O para outro. Caso digite mais de um caractere o "
         "programa irá bugar.: ");
  scanf(" %c%*c", &cliente.sexo);
  printf("Digite a data de nascimento do cliente com barras: ");
  gets(cliente.dataNascimento);
  strcpy(cliente.dataNascimento1, cliente.dataNascimento);
  printf("Digite o cpf do cliente com . e -: ");
  fgets(cliente.cpf, 15, stdin);
  validarNome(cliente.nome);
  validarSexo(cliente.sexo);
  validarCPF(cliente.cpf);
  validarNascimento(cliente.dataNascimento);
  return cliente;
}

int validarNome(char nome[40]) {
  if ((cliente.nome[0] - '0') >= 0 && (cliente.nome[0] - '0') <= 9 ||
      (cliente.nome[0] - '0') >= -9 && (cliente.nome[0] - '0') <= 0) {
    return contN++;
  }
  printf("%s", cliente.nome);
  if (strlen(cliente.nome) > 20) {
    return contN++;
  }
}

int validarSexo(char sexo) {
  switch (cliente.sexo) {
  case 'm':
  case 'M':
    break;
  case 'f':
  case 'F':
    break;
  case 'o':
  case 'O':
    break;
  default:
    return contS++;
    break;
  }
}
int validarCPF(char cpf[20]) {
  int i = 11, j = 1, result = 0, result2, aux = 0, k, z = 1;
  int a = 12, b = 1, resultado = 0, resultado2, auxi = 0, c, d = 0, e = 1;
  int conversor;
  int l = 0;
  for (l = 0; l <= 9; l++) {
    if (aux == 11) {
      return contC++;
    }
    aux = 0;
    for (k = 0; k <= 13; k++) {
      if ((cliente.cpf[k] - '0') == l) {
        aux++;
      }
    }
  }

  for (j = 0; j <= 10; j++) {
    if ((cliente.cpf[j]) != '.') {
      result += (cliente.cpf[j] - '0') * (i - z);
    } else {
      z--;
    }
    z++;
  }

  if ((result * 10) % 11 == 10) {
    result2 = 0;
  }
  if ((result * 10) % 11 == cliente.cpf[12] - '0' ||
      result2 == cliente.cpf[12] - '0') {
    contador++;
  } else {
    return contC++;
  }

  for (b = 0; b <= 12; b++) {
    if ((cliente.cpf[b]) != '.' && (cliente.cpf[b]) != '-') {
      resultado += (cliente.cpf[b] - '0') * (a - e);

    } else {
      e--;
    }
    e++;
  }

  if ((resultado * 10) % 11 == 10) {
    resultado2 = 0;
  }
  if ((resultado * 10) % 11 == cliente.cpf[13] - '0' ||
      resultado2 == cliente.cpf[13] - '0') {
    contador++;
  } else {
    return contC++;
  }
  return 0;
}

int validarNascimento(char dataNascimento[20]) {
  int dia1, mes1, ano1, cont = 1, count = 0;
  char *sub;
  // variaveis dia1, mes1,ano1 são inicializadas
  dia1 = (dataNascimento[0] - '0') * 10;
  dia1 += dataNascimento[1] - '0';
  // posicao 3 da string é "/"
  mes1 = (dataNascimento[3] - '0') * 10;
  mes1 += dataNascimento[4] - '0';
  // posicao 5 da string é "/"
  ano1 = (dataNascimento[6] - '0') * 1000;
  ano1 += (dataNascimento[7] - '0') * 100;
  ano1 += (dataNascimento[8] - '0') * 10;
  ano1 += dataNascimento[9] - '0';

  // se o dia eh entre 1 e 31
  if (dia1 < 1 || dia1 > 31) {
    return contNasc++;
  }
  // se o mes eh entre 1 e 12
  if (mes1 < 1 || mes1 > 12) {
    return contNasc++;
  }
  // ano esta no intervalo de 1900 a 2100
  if (ano1 < 1900 || ano1 > 2100) {
    return contNasc++;
  }
  // se o mes for 04, 06, 09 ou 11, dia pode ser no maximo 30
  if (mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11) {
    if (dia1 > 30) {
      return contNasc++;
    }
  }
  // se o ano for bissexto, dia 02 pode ser no maximo 29
  // se o mes for 02, dia pode ser no maximo 28
  if (ano1 % 4 == 0 && ano1 % 100 > 0 ||
      ano1 % 4 == 00 && ano1 % 100 == 0 && ano1 % 400 == 0) {
    if (mes1 == 2) {
      if (dia1 > 29) {
        return contNasc++;
      }
    }

  } else {
    if (mes1 == 2) {
      if (dia1 > 28) {
        return contNasc++;
      }
    }
  }
  return 0;
}
