/*7) Crie um programa que tenha uma fun��o ler3Palavras. Essa fun��o deve ler
tr�s palavras do usu�rio e retornar as tr�s palavras. A fun��o main deve
imprimir essas tr�s palavras*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ler3Palavras(char[3][30]);

char matriz[3][30];
int i, j;

int main() {
  setlocale(LC_ALL, "Portuguese");

  ler3Palavras(matriz);

  for (j = 0; j < 3; j++) {
    printf("Palavra %d: %s\n", j + 1, matriz[j]);
  }

  return 0;
}

char ler3Palavras(char matriz[3][30]) {
  for (i = 0; i < 3; i++) {
    printf("Digite uma palavra: ");
    scanf(" %s", matriz[i]);
  }

  return matriz[3][30];
}
