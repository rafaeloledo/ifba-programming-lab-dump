#include <stdio.h>
#include <stdlib.h>

// v 07:00 12/06/2021
// Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 -
// 321

int inverter(int n) {
  static int cont1 = 10, cont2 = 1;

  if ((n % cont1) / cont2 == 0) {
    cont1 = 10;
    cont2 = 1;
    return 1;
  }
  printf("%d", (n % cont1) / cont2);
  cont1 *= 10;
  cont2 *= 10;

  return inverter(n);
}
int main() {
  int n = 0, c;

  do {
    printf("Digite um número para ser invertido: ");
    scanf("%d", &n);
    inverter(n);
    printf("\nDeseja continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
