/*5) Crie um programa que tenha uma função ler4Numeros. Essa função deve ler
quatro números do usuário e retornar os quatro números. A função main deve
imprimir esses quatro números. Utilize struct para fazer o retorno*/

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
    printf("Número do usuário na posicao %d é: %.2f\n", k + 1, usuario.num[k]);
}

float ler4Numeros(float num[4]) {
  int i;

  printf("Digite 4 números: \n");

  for (i = 0; i < 4; i++) {
    scanf("%f", &usuario.num[i]);
  }

  return usuario.num[4];
}
