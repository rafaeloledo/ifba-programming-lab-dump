/*2) Crie um programa que tenha uma fun��o subtrai e a fun��o main. A fun��o
main deve ler tr�s valores, enviar para a fun��o subtrai. A fun��o subtrai deve
realizar a subtra��o dos tr�s valores (primeiro menos o segundo menos o
terceiro) e retornar o valor. A Fun��o main deve imprimir o resultado da
subtra��o.*/

#include <cwchar>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

float funcao_subtrair(float, float, float);

int main() {
  float n1, n2, n3;

  setlocale(LC_ALL, "Portuguese");

  printf("Digite tr�s valores: \n");
  scanf("%f%f%f", &n1, &n2, &n3);

  funcao_subtrair(n1, n2, n3);

  printf("O resultado da subtra��o �: %.2f\n", (n1 - n2) - n3);

  system("PAUSE");
}

float funcao_subtrair(float n1, float n2, float n3) { return (n1 - n2) - n3; }
