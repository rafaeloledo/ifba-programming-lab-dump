#include <stdio.h>
#include <stdlib.h>
#define TAM 100

// v 07:13 12/06/2021

/*Crie um programa em C que receba um vetor de números reais com 100 elementos.
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.
*/

float inverte(float *vet, int tam) {
  static int aux = 0, cont = 0;
  aux = vet[tam - 1];
  vet[tam - 1] = vet[cont];
  vet[cont] = aux;
  cont++;

  if (cont == tam + 1) {
    aux = 0, cont = 0;
    return 0;
  }

  inverte(vet, tam - 1);
}

int main() {
  float vet[TAM];
  int c;

  // preeche o vetor com valores de 1 a 100 (i+1)
  for (int i = 0; i < TAM; i++) {
    vet[i] = i + 1;
  }

  do {
    inverte(vet, TAM);
    for (int i = 0; i < TAM; i++) {
      printf("%.2f\n", vet[i]);
    }
    printf("Deseja continuar? Sim (1) Não (0)\n");
    scanf("%d", &c);
  } while (c);
}
