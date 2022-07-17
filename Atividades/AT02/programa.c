#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    float n=0,n1,n2,cont=0;
    
    while(n>=0){
        if (cont==0){
            printf("Digite um numero dentre a lista: \n 0- Sair\n 1- Somar\n 2- Subtrair\n 3- Multiplicar\n 4- Dividir\n ");
            scanf("%f", &n);
            cont++;
        }
        if(n==0)
            break;
        if(n<0){
            printf("Digitou um valor negativo, por favor digite somente entre as opcoes acima.");
            continue;}
        if(n==1){
            printf("Digite dois numeros para serem somados:\n");
            scanf("%f%f", &n1,&n2);
            printf("A soma dos  dois numeros eh: %.2f\n", n1+n2);}
        if(n==2){
            printf("Digite dois numeros para serem subtraidos:\n");
            scanf("%f%f", &n1,&n2);
            printf("A subtracao dos  dois numeros eh: %.2f\n", n1-n2);}
        if(n==3){
            printf("Digite dois numeros para serem multiplicados:\n");
            scanf("%f%f", &n1,&n2);
            printf("A multiplicacao dos  dois numeros eh: %.2f\n", n1*n2);}
        if(n==4){
            printf("Digite dois numeros para serem divididos:\n");
            scanf("%f%f", &n1,&n2);
            printf("A divisao dos  dois numeros eh: %.2f\n", n1/n2);}
        if(n>4){
            printf("Valor maior que 4.\n");
            break;
        }
        cont--;
    }
    
    printf("O programa terminou.");
    
    return 0;
}