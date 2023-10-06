/*4) Crie um programa que tenha uma função ler3Numeros. Essa função deve ler
três números do usuário e retornar os três números. A função main deve imprimir
esses três números. Utilize vetor para fazer o retorno.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

float ler3Numeros(float[3]);

float n[3];

int main() {

  int k;
  setlocale(LC_ALL, "Portuguese");

  ler3Numeros(n);

  for (k = 0; k < 3; k++)
    printf("Valor númerico da posição %d é: %.2f\n", k + 1, n[k]);
}

float ler3Numeros(float n[3]) {
  int i;

  printf("Digite 3 números:\n");

  for (i = 0; i < 3; i++)
    scanf("%f", &n[i]);

  return n[3];
}
