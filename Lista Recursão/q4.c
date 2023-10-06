#include <stdio.h>
#include <stdlib.h>
#define TAM 5

// v 07:02 12/06/2021
// Faça uma função recursiva que permita somar os elementos de um vetor de
// inteiros

int somaElementos(int *p) {
  static int cont = 0, soma = 0;

  if (cont == TAM) {
    int retorno = soma;
    cont = 0, soma = 0;
    return retorno;
  }
  soma += p[cont];
  cont++;

  return somaElementos(p);
}

int main() {
  int *vet = malloc(TAM * sizeof(int));
  int c;

  do {
    printf("Digite %d elementos para serem somados: \n", TAM);
    for (int i = 0; i < TAM; i++) {
      printf("Digite o elemento %d: ", i + 1);
      printf("\n");
      scanf("%d", &vet[i]);
    }
    int result = 0;
    result = somaElementos(vet);
    printf("Soma: %d", result);
    free(vet);
    printf("\nDeseja continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
