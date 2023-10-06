#include <stdio.h>
#include <stdlib.h>

// v 06:57 12/06/2021

/*Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
55, 89... */

int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 2) + fib(n - 1);
}

int main() {
  int n = 0, fib1 = 0, c;
  do {
    printf("Digite o termo 'n' da sequência de fibonacci para imprimir: ");
    scanf("%d", &n);
    fib1 = fib(n - 1);
    printf("%d\n", fib1);
    printf("Deseja continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
