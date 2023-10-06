#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "escola.h"
#include <string.h>
#define TAM 50
#define TAM2 40
#define TAM3 20
#define DISC 10
int counta1=0,countp1=0,countd1=0;
int countd11;

int main (){
    int n=0,p=0;
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("\nDigite uma das opções do menu principal:\n1- Cadastrar aluno\n2- Cadastrar Professor\n3- Cadastrar Disciplina\n4- Menu de Relatórios\n0- Encerrar o programa\n");

    scanf("%d", &n);
    switch(n){
        case 1:{
            do{
            printf("Qual o número do aluno que deseja cadastrar? Digite um valor de 1 a %d\n", TAM);
            scanf("%d",&counta1);
            if(counta1>=1 && counta1<=TAM){
                CadastroAluno(aluno[counta1-1].nome,aluno[counta1-1].sexo,aluno[counta1-1].dataNascimento,aluno[counta1-1].cpf,aluno[counta1-1].matricula);
            }
            else{
                printf("Erro.\n");
            }
            printf("Deseja continuar o cadastro de alunos? 1- sim 0- não: ");
            scanf("%d", &p);
            }
            while(p);
        break;}
        case 2:{
           do{
            printf("Qual o número do professor que deseja cadastrar? Digite um valor de 1 a %d\n", TAM);
            scanf("%d",&countp1);
            if(countp1>=1 && countp1<=TAM){
                CadastroProfessor(professor[countp1-1].nome,professor[countp1-1].sexo,professor[countp1-1].dataNascimento,professor[countp1-1].cpf,professor[countp1-1].matricula);
            }
            else{
                printf("Erro.\n");
            }
            printf("Deseja continuar o cadastro de professores? 1- sim 0-não: ");
            scanf("%d", &p);
            }
            while(p);
        break;}
        case 3:{
            do{
            printf("Qual o número da disciplina que deseja cadastrar? Digite um valor de 1 a %d\n", DISC);
            scanf("%d",&countd1);
            if(countd1>=1 && countd1<=DISC){
                CadastroDisciplina(disciplina[countd1-1].nome,disciplina[countd1-1].semestre,disciplina[countd1-1].professor,disciplina[countd1-1].alunos,disciplina[countd1-1].codigo);
            }
            else{
                printf("Erro.\n");
            }
            printf("Deseja continuar o cadastro de disciplinas? 1- sim 0-não: ");
            scanf("%d", &p);
            }
            while(p);
        break;}
        case 4:{
        Relatorio(aluno,professor,disciplina);
        break;}
        default:{
        break;}
    }
    }
    while(n);
    return 0;
}
