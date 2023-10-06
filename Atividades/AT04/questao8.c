/*8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve
ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do
cliente. A função main deve imprimir os dados do cliente.*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct dados {
  char nome[30], sexo[13];
  double cpf[13], dataNascimento[11];
} cliente;
struct dados cadastrarCliente(char nome[], double dataNascimento[],
                              double cpf[], char sexo[]);
int main() {
  setbuf(stdin, NULL);
  setlocale(LC_ALL, "Portuguese");
  cadastrarCliente(cliente.nome, cliente.dataNascimento, cliente.cpf,
                   cliente.sexo);
  printf("Nome do cliente: %s", cliente.nome);
  printf("Sexo do cliente: %s", cliente.sexo);
  if (cliente.dataNascimento[1] == 0) {
    printf("Data de nascimento do cliente: 0%.lf\n",
           cliente.dataNascimento[11]);
  } else {
    printf("Data de nascimento do cliente: %.lf\n", cliente.dataNascimento[11]);
  }
  if (cliente.cpf[1] == 0) {
    printf("Cpf do cliente: 0%.f", cliente.cpf[13]);
  } else {
    printf("Cpf do cliente: %.f", cliente.cpf[13]);
  }
  return 0;
}

struct dados cadastrarCliente(char nome[], double dataNascimento[],
                              double cpf[], char sexo[]) {
  printf("Digite o nome e o sexo do cliente: ");
  fgets(cliente.nome, 40, stdin);
  fgets(cliente.sexo, 40, stdin);
  printf("Digite a data de nascimento e o cpf do cliente: ");
  scanf("%lf%lf", &cliente.dataNascimento[11], &cliente.cpf[13]);
  return cliente;
}
