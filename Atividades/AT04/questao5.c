/*5) Crie um programa que tenha uma fun��o ler4Numeros. Essa fun��o deve ler
quatro n�meros do usu�rio e retornar os quatro n�meros. A fun��o main deve
imprimir esses quatro n�meros. Utilize struct para fazer o retorno*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

float ler4Numeros(float[4]);

struct numeros {
  float num[4];
} usuario;

int main() {
  int k;
  setlocale(LC_ALL, "Portuguese");

  ler4Numeros(usuario.num);

  for (k = 0; k < 4; k++)
    printf("N�mero do usu�rio na posicao %d �: %.2f\n", k + 1, usuario.num[k]);
}

float ler4Numeros(float num[4]) {
  int i;

  printf("Digite 4 n�meros: \n");

  for (i = 0; i < 4; i++) {
    scanf("%f", &usuario.num[i]);
  }

  return usuario.num[4];
}
