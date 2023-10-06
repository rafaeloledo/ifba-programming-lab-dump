/*3) Fa�a um programa que tenha uma fun��o que recebe um n�mero inteiro e
retorna o fatorial deste n�mero. Esta fun��o deve ainda verificar se � poss�vel
calcular o fatorial, se n�o for, ela deve de alguma forma retornar para a main
que deu algum erro. A fun��o main deve solicitar o valor do usu�rio e imprimir o
fatorial dele, ou se n�o � poss�vel calcular o fatorial.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

double func_fatorial(int);

int num, cont, result, seguir;

int main() {
  setlocale(LC_ALL, "Portuguese");

  do {
    printf("Digite um n�mero para se calcular o fatorial:\n");

    scanf("%d", &num);

    func_fatorial(num);

    printf("\nDeseja continuar a calcular o fatorial? 1- Sim 0- N�o\n");

    scanf("%d", &seguir);
  } while (seguir);

  system("PAUSE");
}

double func_fatorial(int num1) {
  int cont;

  if (num1 != 0 && num1 != 1 && num1 > 0)
    printf("O fatorial de %d � = %d x", num1, num1);

  cont = num1 - 1;

  result = num1;

  if (num1 == 0 || num1 == 1) {
    printf("Fatorial de %d = 1\n", num1);
  } else {
    if (num1 > 0) {
      for (; cont >= 2; cont--) {
        printf(" %d x", cont);
        result *= cont;
      }
    }
  }
  if (num1 != 0 && num1 != 1 && num1 > 0)
    printf(" %d = %d \n ", cont, result);
  if (num1 < 0)
    printf("O fatoral de %d � inexistente", num1);
}
