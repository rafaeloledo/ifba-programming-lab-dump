/*4) Crie um programa que tenha uma fun��o ler3Numeros. Essa fun��o deve ler
tr�s n�meros do usu�rio e retornar os tr�s n�meros. A fun��o main deve imprimir
esses tr�s n�meros. Utilize vetor para fazer o retorno.*/

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
    printf("Valor n�merico da posi��o %d �: %.2f\n", k + 1, n[k]);
}

float ler3Numeros(float n[3]) {
  int i;

  printf("Digite 3 n�meros:\n");

  for (i = 0; i < 3; i++)
    scanf("%f", &n[i]);

  return n[3];
}
