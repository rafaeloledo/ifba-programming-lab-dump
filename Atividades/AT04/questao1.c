/*1) Crie um programa que tenha uma função soma e a função main. A função main
deve ler dois valores, enviar para a função soma. A função soma deve realizar a
soma e retornar o valor. A Função main deve imprimir o resultado da soma.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

float soma;

float funcao_soma(float, float);

int main() {
  float n1, n2;

  setlocale(LC_ALL, "Portuguese");

  printf("Digite dois valores: \n");
  scanf("%f %f", &n1, &n2);

  funcao_soma(n1, n2);
  printf("O resultado da soma é: %.2f\n", soma);

  system("PAUSE");
}

float funcao_soma(float n1, float n2) {
  soma = n1 + n2;

  return soma;
}
