#include <stdio.h>
#include <stdlib.h>

// v 06:55 12/06/2021

// Faça uma função recursiva que calcule e retorne o fatorial de um número
// inteiro N

int fat(int n) {
  if (n == 2) {
    return 2;
  }
  return n * fat(n - 1);
}

int main() {
  int n = 0, fat1 = 0, c;

  do {
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &n);
    printf("%d\n", fat(n));
    printf("Deseja continuar? Sim (1) Não (0)");
    scanf("%d", &c);
  } while (c);

  return 0;
}
