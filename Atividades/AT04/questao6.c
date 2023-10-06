/* 6) Crie um programa que tenha uma fun??o ler3Letras. Essa fun??o deve ler
tr?s letras do usu‡rio e retornar as tr?s letras. A fun??o main deve imprimir
essas tr?s letras */

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

char ler3Letras(char[3]);
char letras[3];

int main() {
  setlocale(LC_ALL, "Portuguese");
  int k;

  ler3Letras(letras);

  for (k = 0; k < 3; k++) {
    printf("Letra na posicao %d eh: %c\n", k + 1, letras[k]);
  }

  system("PAUSE");
}

char ler3Letras(char letras[3]) {
  int i;

  printf("Digite 3 letras: \n");

  for (i = 0; i < 3; i++)
    scanf(" %c", &letras[i]);

  return letras[3];
}
