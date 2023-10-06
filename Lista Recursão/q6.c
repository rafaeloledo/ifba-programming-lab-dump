#include <stdio.h>
#include <stdlib.h>

// v 07:06 12/06/2021
/* Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule k^n . Utilize apenas multiplicações. O
programa principal deve solicitar ao usuário os valores de k e n e imprimir o
resultado da chamada da função. */

int potencia(int n, int k) {
  static int cont = 0, result = 1;

  if (cont == k) {
    int retorno = result;
    cont = 0, result = 1;
    return retorno;
  }
  result *= n;
  cont++;
  potencia(n, k);
}
int main() {
  int n = 0, k = 0, c;

  do {
    printf("Digite um número n e depois sua potencia k: ");
    scanf("%d%d", &n, &k);
    printf("%d\n", potencia(n, k));
    printf("Deseja continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
