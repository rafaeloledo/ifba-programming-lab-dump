#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 40
#define TAM2 40
#define TAM3 20


struct dados{
        char nome[TAM2],sexo[TAM3],dataNascimento[TAM3],cpf[TAM3];
        int matricula;
}aluno[TAM],professor[TAM];
struct disc{
    char nome[TAM2],semestre[TAM3],professor[TAM2],alunos[TAM2][TAM2],codigo[TAM3];
}disciplina[TAM];

int counta1,countp1,countd1;
int countd11;

void CadastroAluno(char nome[TAM2],char sexo[TAM3],char dataNascimento[TAM3],char cpf[TAM3], int matricula){
    setlocale(LC_ALL,"Portuguese");
    int i=0,cont=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,dia,mes,ano,contcpf=0;
    int h=11,result=0,result2,aux=0,z=1,a=12,b=1,resultado=0,resultado2,e=1;
    do{
    if(cont==0){
        printf("Digite uma das opções do menu secundário do aluno %d:\n1- Inserir ou modificar nome\n2- Inserir ou modificar Sexo\n3- Inserir ou modificar Data de Nascimento\n4- Inserir ou modificar Cpf\n"
        "5- Gerar Matrícula\n6- Exluir cadastro do aluno atual\n7- Listar dados cadastrados\n0- Finalizar cadastro do aluno\n", counta1);
        cont++;
    }
    else{
        printf("Digite uma das opções do menu secundário: ");
    }
    scanf("%d", &i);
    switch(i){
        case 1:{
            cont1=0;
            setbuf(stdin,NULL);
            printf("Digite o nome do aluno %d: ", counta1);
            fgets(nome,39,stdin);
            if(((nome[0]-'0')>=0 && (nome[0]-'0')<=9) || ((nome[0]-'0')>=-9 && (nome[0]-'0')<=0 ) || (strlen(nome)>TAM3)){
                printf("\nNome inválido.");
            }
            cont1++;
        break;}
        case 2:{
            cont2=0;
            setbuf(stdin,NULL);
            printf("Digite o sexo; m,f ou o para masculino, feminino ou outro: ");
            scanf("%[A-Z a-z]", sexo);
            if(strlen(sexo)==1){
            switch(sexo[0]){
                case 'm':
                case 'M':
                cont2++;
                break;
                case 'f':
                case 'F':
                cont2++;
                break;
                case 'o':
                case 'O':
                cont2++;
                break;
                default:{
                    printf("\nSexo inválido\n.");
                    sexo[0]=' ';
                break;}
            }
            }
            else{
                printf("Erro\n");
                sexo[0]=' ';
            }
            cont2++;
        
        break;}
        case 3:{
            cont3=0;
            printf("Digite a data de nascimento com barras: ");
            setbuf(stdin,NULL);
            fgets(dataNascimento,13,stdin);
            dia=(dataNascimento[0]-'0')*10;
            dia+=dataNascimento[1]-'0';
            mes=(dataNascimento[3]-'0')*10;
            mes+=dataNascimento[4]-'0';
            ano=(dataNascimento[6]-'0')*1000;
            ano+=(dataNascimento[7]-'0')*100;
            ano+=(dataNascimento[8]-'0')*10;
            ano+=dataNascimento[9]-'0';
            if(dia<1 || dia>31){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes<1 || mes>12){
                printf("Data de nascimento inválida.\n");
            }
            else if(ano<1900 || ano>2100){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes == 4 || mes == 6 || mes==9 || mes==11){
                if(dia>30){
                    printf("Data de nascimento inválida.\n");
                }
            }
            else if((ano%4==0 && ano%100>0 )|| (ano%4==00 && ano%100==0 && ano%400==0)){
                if(mes==2){
                    if(dia>29){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            else{
                if(mes==2){
                    if(dia>28){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            cont3++;
        
        break;}
        case 4:{
            contcpf=0,cont4=0,h=11,result=0,aux=0,z=1,a=12,b=1,resultado=0,e=1;
            printf("Digite o cpf com ponto e hífen: ");
            setbuf(stdin,NULL);
            scanf("%[0-9.-]", cpf);
            for(int l=0;l<=9;l++){
                if(aux==11){
                    printf("\nCpf inválido.");
                    contcpf++;
                }
                aux=0;
                for(int k=0;k<=13;k++){
                    if((cpf[k]-'0')==l){
                        aux++;
                    }
                }
            }
            for(int j=0;j<=10;j++){
                if((cpf[j])!='.'){
                    result+=(cpf[j]-'0')*(h-z);
                }
                else{
                    z--;
                }
                z++;
            }
            if((result*10)%11==10){
                result2=0;
            }
            if((result*10)%11==cpf[12]-'0' || result2==cpf[12]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            for(b=0;b<=12;b++){
                if((cpf[b])!='.' && (cpf[b])!= '-'){
                    resultado+=(cpf[b]-'0')*(a-e);
                }
                else{
                    e--;
                }
                e++;
            }
            if((resultado*10)%11==10){
                resultado2=0;
            }
            if((resultado*10)%11==cpf[13]-'0' || resultado2==cpf[13]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            if(contcpf==0){
                cont4++;
            }
            cont4++;
        
        break;}
        case 5:{
            cont5=0;
            if(cont1>0 && cont2>0 && cont3>0 && cont4>0){
                matricula=counta1;
                printf("Matrícula do aluno %d: %d\n", counta1,matricula);
                cont5++;
                break;
            }
            else{
                printf("Erro ao gerar Matrícula.\n");
                break;
            }
        }
        case 6:{
        for(int t=0;t<20;t++){
            nome[t]='.';
            }
        sexo[0]='.';
        for(int t=0;t<12;t++){
            dataNascimento[t]='.';
        } 
        for(int t=0;t<16;t++){
            cpf[t]='.';
        }
        matricula=0;
        break;}
        case 7:{
        printf("Nome: %s\n",nome);
        printf("Sexo: %c\n",sexo[0]);
        printf("Data de Nascimento: %s\n",dataNascimento);
        printf("Cpf: %s\n",cpf);
        printf("Matricula: %d\n",matricula);
        break;}
        default:
        break;
    }
    }
    while(i);
    
    if (cont1==0 || cont2==0 || cont3==0 || cont4==0 || cont5==0){
        for(int t=0;t<TAM2;t++){
            nome[t]=' ';
        }
        sexo[0]=' ';
        for(int t=0;t<TAM3;t++){
            dataNascimento[t]=' ';
        }
        for(int t=0;t<TAM3;t++){
            cpf[t]=' ';
        }
        matricula=0;
    }
}
void CadastroProfessor(char nome[TAM2],char sexo[TAM3],char dataNascimento[TAM3],char cpf[TAM3], int matricula){
    setlocale(LC_ALL,"Portuguese");
    int dia,mes,ano;
    int i=0;
    int cont=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,contcpf=0;
    int h=11,result=0,result2,aux=0,z=1,a=12,b=1,resultado=0,resultado2,e=1;
    do{
    if(cont==0){
        printf("Digite uma das opções do menu secundário do professor %d:\n1- Inserir ou modificar nome\n2- Inserir ou modificar Sexo\n3- Inserir ou modificar Data de Nascimento\n4- Inserir ou modificar Cpf\n"
        "5- Gerar Matrícula\n6- Excluir cadastro do professor atual\n7- Listar dados cadastrados\n0- Finalizar cadastro do professor\n", countp1);
        cont++;
    }
    else{
        printf("Digite uma das opções do menu secundário: ");
    }
    scanf("%d", &i);
    switch(i){
        case 1:{
            cont1=0;
            setbuf(stdin,NULL);
            printf("Digite o nome do professor %d: ", countp1);
            fgets(nome,39,stdin);
            if(((nome[0]-'0')>=0 && (nome[0]-'0')<=9) || ((nome[0]-'0')>=-9 && (nome[0]-'0')<=0 ) || (strlen(nome)>TAM3)){
                printf("\nNome inválido.");
            }
            else{
                cont1++; 
            }   
        break;}
        case 2:{
            cont2=0;
            printf("Digite o sexo; m,f ou o para masculino, feminino ou outro: ");
            setbuf(stdin,NULL);
            scanf("%[A-Z a-z]", sexo);
            if(strlen(sexo)==1){
            switch(sexo[0]){
                case 'm':
                case 'M':
                cont2++;
                break;
                case 'f':
                case 'F':
                cont2++;
                break;
                case 'o':
                case 'O':
                cont2++;
                break;
                default:{
                    sexo[0]=' ';
                    printf("Sexo inválido\n.");
                break;}
            }
            }
            else{
                printf("Erro\n");
                sexo[0]=' ';
            }
        break;}
        case 3:{
            cont3=0;
            printf("Digite a data de nascimento com barras: ");
            setbuf(stdin,NULL);
            fgets(dataNascimento,13,stdin);
            dia=(dataNascimento[0]-'0')*10;
            dia+=dataNascimento[1]-'0';
            mes=(dataNascimento[3]-'0')*10;
            mes+=dataNascimento[4]-'0';
            ano=(dataNascimento[6]-'0')*1000;
            ano+=(dataNascimento[7]-'0')*100;
            ano+=(dataNascimento[8]-'0')*10;
            ano+=dataNascimento[9]-'0';
            if(dia<1 || dia>31){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes<1 || mes>12){
                printf("Data de nascimento inválida.\n");
            }
            else if(ano<1900 || ano>2100){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes == 4 || mes == 6 || mes==9 || mes==11){
                if(dia>30){
                    printf("Data de nascimento inválida.\n");
                }
            }
            else if((ano%4==0 && ano%100>0 )|| (ano%4==00 && ano%100==0 && ano%400==0)){
                if(mes==2){
                    if(dia>29){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            else{
                if(mes==2){
                    if(dia>28){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            cont3++;
        
        break;}
        case 4:{
            contcpf=0,cont4=0,h=11,result=0,aux=0,z=1,a=12,b=1,resultado=0,e=1;
            printf("Digite o cpf com ponto e hífen: ");
            setbuf(stdin,NULL);
            scanf("%[0-9.-]", cpf);
            for(int l=0;l<=9;l++){
                if(aux==11){
                    printf("\nCpf inválido.");
                    contcpf++;
                }
                aux=0;
                for(int k=0;k<=13;k++){
                    if((cpf[k]-'0')==l){
                        aux++;
                    }
                }
            }
            for(int j=0;j<=10;j++){
                if((cpf[j])!='.'){
                    result+=(cpf[j]-'0')*(h-z);
                }
                else{
                    z--;
                }
                z++;
            }
            if((result*10)%11==10){
                result2=0;
            }
            if((result*10)%11==cpf[12]-'0' || result2==cpf[12]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            for(b=0;b<=12;b++){
                if((cpf[b])!='.' && (cpf[b])!= '-'){
                    resultado+=(cpf[b]-'0')*(a-e);
                }
                else{
                    e--;
                }
                e++;
            }
            if((resultado*10)%11==10){
                resultado2=0;
            }
            if((resultado*10)%11==cpf[13]-'0' || resultado2==cpf[13]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            if(contcpf==0){
                cont4++;
            }
        
        break;}
        case 5:{
            cont5=0;
            if(cont1>0 && cont2>0 && cont3>0 && cont4>0){
                matricula = countp1;
                printf("Matrícula do professor %d: %d\n", countp1,matricula);
                cont5++;
                break;
            }
            else{
                printf("Erro ao gerar Matrícula.\n");
                break;
            }
        }
        case 6:{
        for(int t=0;t<20;t++){
            nome[t]=' ';
        }
        sexo[0]=' ';
        for(int t=0;t<12;t++){
            dataNascimento[t]=' ';
        }
        for(int t=0;t<14;t++){ 
            cpf[t]=' ';
        }
        matricula=0;
        break;}
        case 7:{
        printf("Nome: %s\n",nome);
        printf("Sexo: %c\n",sexo[0]);
        printf("Data de Nascimento: %s\n",dataNascimento);
        printf("Cpf: %s\n",cpf);
        printf("Matricula: %d\n",matricula);
        break;}
        default:
        break;
    }
    }
    while(i);
    if (cont1==0 || cont2==0 || cont3==0 || cont4==0 || cont5==0){
        printf("Não foram cadastrados todos os dados.\n");
        for(int t=0;t<20;t++){
            nome[t]=' ';
        }
        sexo[0]=' ';
        for(int t=0;t<10;t++){
            dataNascimento[t]=' ';
        }
        for(int t=0;t<15;t++){
            cpf[t]=' ';
        }
        matricula=0;
    }
}
void CadastroDisciplina(char nome[TAM2],char semestre[TAM3],char professor[TAM2],char alunos[TAM2][TAM2],char codigo[TAM3]){
    setlocale(LC_ALL, "Portuguese");
    int cont=0,i=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0;
    do{
        if(cont==0){
        printf("Digite uma das opções do menu secundário da disciplina %d:\n1- Inserir ou modificar nome\n2- Inserir ou modificar Semestre\n3- Inserir ou modificar Professor\n4- Inserir ou modificar Alunos\n"
        "5- Inserir ou modificar Código da disciplina\n6- Excluir cadastro feito\n7- Listar dados cadastrados\n0- Finalizar cadastro da disciplina\n", countd1);
        cont++;
        }
        else{
            printf("Digite uma das opções do menu secundário: ");
        }
        scanf("%d", &i);
        switch(i){
            case 1:{
            cont1=0;
            printf("Digite o nome de uma disciplina: ");
            setbuf(stdin,NULL);
            fgets(nome,22,stdin);
            if(((nome[0]-'0')>=0 && (nome[0]-'0')<=9) || ((nome[0]-'0')>=-9 && (nome[0]-'0')<=0 ) || (strlen(nome)>TAM3)){
                printf("\nDisciplina inválida.");
            }
            cont1++;
            break;}
            case 2:{
            cont2=0;
            printf("Digite o semestre da disciplina %d (ex: 2019.1): ", countd1);
            setbuf(stdin,NULL);
            fgets(semestre,7,stdin); 
            if( semestre[4]!='.' ||  semestre[5]-'0'>2 ||semestre[5]-'0'<1 ){
                printf("Semestre Inválido.\n");
            }
            cont2++;
            break;}
            case 3:{
            cont3=0;
            printf("Digite o professor da disciplina %d: ", countd1);
            setbuf(stdin,NULL);
            fgets(professor,22,stdin);
            if(((professor[0]-'0')>=0 && (professor[0]-'0')<=9) || ((professor[0]-'0')>=-9 && (professor[0]-'0')<=0 ) || (strlen(professor)>TAM3)){
                printf("\nDisciplina inválida.");
            }
            cont3++;
            break;}
            case 4:{
            cont4=0;
            printf("Digite qual o numero do aluno a se cadastrar: ");
            setbuf(stdin,NULL);
            scanf("%d", &countd11);
            printf("Digite o nome do aluno %d da disciplina %s: ", countd11, nome);
            setbuf(stdin,NULL);
            fgets(alunos[countd11-1],22,stdin);
            if(((alunos[countd11-1][0]-'0')>=0 && (alunos[countd11-1][0]-'0')<=9) || ((alunos[countd11-1][0]-'0')>=-9 && (alunos[countd11-1][0]-'0')<=0 ) || (strlen(alunos[countd11-1])>TAM3)){
                printf("\nAluno inválido.");
            }
            cont4++;
            break;}
            case 5:{
            cont5=0;
            printf("Digite o código da disciplina %s (ex: INF.029): ", nome);
            setbuf(stdin,NULL);
            fgets(codigo,9,stdin);
            if(codigo[3]!='.' || (((codigo[0]-'0')>=0 && (codigo[0]-'0')<=9) || ((codigo[0]-'0')>=-9 && (codigo[0]-'0')<=-1))){
                printf("Código inválido\n.");
            }
            cont5++;
            break;}
            case 6:{
            for(int t=0;t<TAM2-1;t++){
                nome[t]=' ';
            }
            for(int t=0;t<TAM3-1;t++){
                semestre[t]=' ';
            }
            for(int t=0;t<TAM3-1;t++){
                professor[t]=' ';
            }
            for(int t=0;t<TAM2-1;t++){
                alunos[countd11-1][t]=' ';
            }
            for(int t=0;t<7;t++){
                codigo[t]=' ';
            }
            break;}
            case 7:{
            printf("Nome da disciplina: %s\n", nome);
            printf("Semestre: %s\n", semestre);
            printf("Professor da disciplina: %s\n", professor);                                                                                                                 
            printf("Aluno %d da disciplina: %s\n", countd11, alunos[countd11-1]);
            printf("Codigo da disciplina: %s\n", codigo);
            break;}
            default:
            break;
        }
    }
    while(i);
    if (cont1==0 || cont2==0 || cont3==0 || cont4==0 || cont5==0){
        printf("Não foram cadastrados todos os dados.\n");
        for(int t=0;t<TAM2;t++){
            nome[t]=' ';
        }
        
        for(int t=0;t<TAM3;t++){
            semestre[t]=' ';
        }
        
        for(int t=0;t<TAM3;t++){
            professor[t]=' ';
        }
        
        for(int t=0;t<TAM2;t++){
            alunos[countd11-1][t]=' ';
            printf("%c", alunos[countd11-1][t]);
        }
        for(int t=0;t<7;t++){
            codigo[t]=' ';
        }
    }
}


