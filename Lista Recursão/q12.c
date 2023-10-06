#include <stdio.h>
#include <stdlib.h>

#define tipo1 int
#define c1 "%d"

// v 07:59 12/06/2021
/*12) Faça uma função recursiva que receba um número inteiro positivo N e
imprima todos os números naturais de 0 até N em ordem crescente. */

// retorna o numero de digitos
tipo1 funcao1(tipo1 n) {
  static tipo1 cont1 = 10, cont2 = 1;
  tipo1 tam = 0;

  while ((n % cont1) / cont2 != 0) {
    tam++;
    cont1 *= 10;
    cont2 *= 10;
  }
  cont1 = 10;
  cont2 = 1;

  return tam;
}
// retorna um vetor com os valores
tipo1 *arm(tipo1 n, tipo1 tam) {
  tipo1 *p = malloc(tam * sizeof(tipo1));
  static tipo1 cont1 = 10, cont2 = 1;

  for (int i = 0; (n % cont1) / cont2 != 0; i++) {
    p[i] = (n % cont1) / cont2;
    cont1 *= 10;
    cont2 *= 10;
  }
  cont1 = 10;
  cont2 = 1;

  return p;
}
// ordena o vetor
tipo1 *funcao2(int n, int tam) {
  tipo1 *p = arm(n, tam);
  tipo1 aux;

  for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - 1; j++) {
      if (p[j] > p[j + 1]) {
        aux = p[j + 1];
        p[j + 1] = p[j];
        p[j] = aux;
      }
    }
  }

  return p;
}
// imprime em ordem crescente
int funcao3(int *p, int tam) {
  if (tam < 1) {
    return 0;
  }
  funcao3(p, tam - 1);
  printf("%d", p[tam - 1]);
}

tipo1 main() {
  tipo1 n = 0, tam = 0, num = 0, c;

  do {
    printf("Digite um número inteiro n para imprimí-lo em ordem crescente: ");
    scanf(c1, &n);
    tam = funcao1(n);
    int *num1 = funcao2(n, tam);
    printf("Número em ordem crescente: \n");
    funcao3(num1, tam);
    printf("\n");
    n = 0, tam = 0, num = 0;
    printf("Deseja continuar? Sim (1) Não (2)\n");
    scanf("%d", &c);
  } while (c);
}
