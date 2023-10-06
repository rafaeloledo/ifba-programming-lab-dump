/*2) Crie um programa que tenha uma função subtrai e a função main. A função
main deve ler três valores, enviar para a função subtrai. A função subtrai deve
realizar a subtração dos três valores (primeiro menos o segundo menos o
terceiro) e retornar o valor. A Função main deve imprimir o resultado da
subtração.*/

#include <cwchar>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

float funcao_subtrair(float, float, float);

int main() {
  float n1, n2, n3;

  setlocale(LC_ALL, "Portuguese");

  printf("Digite três valores: \n");
  scanf("%f%f%f", &n1, &n2, &n3);

  funcao_subtrair(n1, n2, n3);

  printf("O resultado da subtração é: %.2f\n", (n1 - n2) - n3);

  system("PAUSE");
}

float funcao_subtrair(float n1, float n2, float n3) { return (n1 - n2) - n3; }
