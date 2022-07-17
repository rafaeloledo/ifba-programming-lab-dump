#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define TAM 5
struct dados{
    char nome[40],sexo,dataNascimento[20],dataNascimento1[20],cpf[20], matricula[20];
}aluno[TAM];
int main(){
    int i=0,cont=0,o=1;
    setlocale(LC_ALL,"Portuguese");
    do{
    if(cont==0){
        printf("Menu:\n 1-Inserir o nome do aluno na lista de alunos\n 2-Listar Alunos\n 0-Terminar\n ");
        cont++;
    }
    else{
        printf("Digite uma das opções do menu: ");
    }
    scanf("%d", &i);
    switch(i){
        case 1:{
        printf("Numero máximo de nomes possíveis na lista atual: %d\n", TAM);
        for(int l=0;l<TAM;l++){
            if(o==1){
                setbuf(stdin,NULL);
                printf("Digite um nome: ");
                fgets(aluno[l].nome,39,stdin);
                if(l<TAM-1){
                    printf("Deseja continuar? 1- sim 0- não: ");
                    scanf("%d", &o);
                }
            }
            if(o==0){
                break;
            }
        }
        break;
        }
        case 2:{
        printf("Lista de alunos atual:\n");
        for(int b=0;b<TAM;b++){
            printf("%s", aluno[b].nome);
        }
        break;
        }
        default:
        break;
        }

    }
    while(i);
    return 0;
}
