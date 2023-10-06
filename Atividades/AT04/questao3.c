/*3) Faça um programa que tenha uma função que recebe um número inteiro e
retorna o fatorial deste número. Esta função deve ainda verificar se é possível
calcular o fatorial, se não for, ela deve de alguma forma retornar para a main
que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o
fatorial dele, ou se não é possível calcular o fatorial.*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

double func_fatorial(int);

int num, cont, result, seguir;

int main() {
  setlocale(LC_ALL, "Portuguese");

  do {
    printf("Digite um número para se calcular o fatorial:\n");

    scanf("%d", &num);

    func_fatorial(num);

    printf("\nDeseja continuar a calcular o fatorial? 1- Sim 0- Não\n");

    scanf("%d", &seguir);
  } while (seguir);

  system("PAUSE");
}

double func_fatorial(int num1) {
  int cont;

  if (num1 != 0 && num1 != 1 && num1 > 0)
    printf("O fatorial de %d é = %d x", num1, num1);

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
    printf("O fatoral de %d é inexistente", num1);
}
