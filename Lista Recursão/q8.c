#include <stdio.h>
#include <stdlib.h>

// v 07:15 12/06/2021
/* O máximo divisor comum dos inteiros x e y é o maior inteiro que divide x e y.
Escreva uma função recursiva mdc em C, que retorna o máximo divisor comum de x
e y. O mdc de x e y é definido como segue: se y é igual a 0, então mdc(x,y) é x;
caso contrário, mdc(x,y) é mdc (y, x%y), onde % é o operador resto. */

int mdc1(int n, int num) {
  static int divisor = 2, mdc = 1, cont = 0;

  if ((n >= 1 && num >= 1) && (divisor <= num && divisor <= n)) {
    if (n % divisor == 0 && num % divisor == 0) {
      mdc *= divisor;
      cont++;
      n /= divisor;
      num /= divisor;
    } else {
      divisor++;
    }
  } else {
    int retorno = mdc;
    divisor = 2, mdc = 1, cont = 0;
    return retorno;
  }

  mdc1(n, num);
}
int main() {
  int c, n, n1;

  do {
    printf("Digite n e n1 para achar o máximo divisor comum (mdc): ");
    scanf("%d%d", &n, &n1);
    printf("Máximo Divisor Comum: %d\n", mdc1(n, n1));
    printf("Deseja Continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
