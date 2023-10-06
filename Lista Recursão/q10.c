#include <stdio.h>
#include <stdlib.h>

// v 07:18 12/06/2021
/* Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192 */

long int contar(long int n, long int k) {
  static long int cont1 = 10, cont2 = 1, repeticoes = 0;

  if ((n % cont1) / cont2 == 0) {
    long int retorno = repeticoes;
    cont1 = 10, cont2 = 1;
    repeticoes = 0;
    return retorno;
  }
  if ((n % cont1) / cont2 == k) {
    repeticoes++;
  }

  cont1 *= 10;
  cont2 *= 10;
  contar(n, k);
}

int main() {
  long int c, n = 0, k = 0;

  do {
    printf("Digite um número e outro para checar quantas vezes este se repete "
           "no primeiro: ");
    scanf("%ld%ld", &n, &k);
    printf("%ld\n", contar(n, k));
    printf("Deseja continuar? Sim (1) Não (0)\n");
    scanf("%ld", &c);
  } while (c);
}
