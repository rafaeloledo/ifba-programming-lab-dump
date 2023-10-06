#include <stdio.h>
#include <stdlib.h>

// v 07:43 12/06/2021
/*11) A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros.
*/

int multiplicaPorSoma(int n, int k) {
  if (k == 1) {
    return n;
  }
  return n + multiplicaPorSoma(n, k - 1);
}

int main() {
  int c, n = 0, k = 0;

  do {
    printf("Digite um número e quantas vezes quer multiplicá-lo: ");
    scanf("%d%d", &n, &k);
    printf("%d\n", multiplicaPorSoma(n, k));
    printf("Deseja continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
