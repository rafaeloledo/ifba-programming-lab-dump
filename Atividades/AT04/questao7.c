/*7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler
três palavras do usuário e retornar as três palavras. A função main deve
imprimir essas três palavras*/

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
