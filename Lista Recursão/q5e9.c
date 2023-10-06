#include <stdio.h>
#include <stdlib.h>

// v
/*Crie uma função recursiva que receba um número inteiro positivo N e calcule o
somatório dos números de 1 a N. */

long int somatorio(int n) {
  static long int cont1 = 10, cont2 = 1, result = 0;

  if (n % cont1 / cont2 == 0) {
    int retorno = result;
    cont1 = 10, cont2 = 1, result = 0;
    return retorno;
  }
  result += n % cont1 / cont2;
  cont1 *= 10;
  cont2 *= 10;

  return somatorio(n);
}

int main() {
  int n = 0, c;
  
  printf("Digite um número para calcular o somatório dos seus números: \n");
  do {
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("%ld\n", somatorio(n));
    printf("Deseja continuar? Sim(1) Não(2)\n");
    scanf("%d", &c);
  } while (c);
}
