// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Rafael Oliveira Ledo
//  email: rafaeloliveiraledo@gmail.com
//  Matrícula: 2019116039
//  Semestre: 2021.1
//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
/*
## função utilizada para testes  ##
    somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)

int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}*/

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}*/

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    int datavalida = 1;
    int iDia=0,iMes=0,iAno=0;
    int bissexto=0;
    int i,j;
    char sDia[3],sMes[3],sAno[5];
    setlocale(LC_ALL,"Portuguese");
    //quebrar a string data em strings sDia, sMes, sAno
    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    //criar as variáveis iDia, iMes, iAno
    //printf("%s\n", data);
    for(i=0;i<3;i++){
        sDia[i]='\0';
        sMes[i]='\0';
    }
    for(i=0;i<4;i++){
        sAno[i]='\0';
    }
    for(i=0;data[i]!='/';i++){
        sDia[i]=data[i];
    }
    for(i=i+1,j=0;data[i]!='/';i++,j++){
        sMes[j]=data[i];
    }
    for(i=i+1,j=0;j<4;i++,j++){
        sAno[j]=data[i];
    }
    if(strlen(sDia)>1){
        iDia=(sDia[0]-'0')*10;
        iDia+=(sDia[1]-'0');
    }
    else if(strlen(sDia)==1){
        iDia=sDia[0]-'0';
    }
    else{
        for(i=0;i<3;i++){
            sDia[i]='\0';
        }
        datavalida=0;
    }
    if(strlen(sMes)>1){
        iMes=(sMes[0]-'0')*10;
        iMes+=(sMes[1]-'0');
    }
    else if(strlen(sMes)==1){
        iMes=sMes[0]-'0';
    }
    else{
        for(i=0;i<3;i++){
            sMes[i]='\0';
        }
        datavalida=0;
    }
    if(strlen(sAno)>2){
        iAno=(sAno[0]-'0')*1000;
        iAno+=(sAno[1]-'0')*100;
        iAno+=(sAno[2]-'0')*10;
        iAno+=sAno[3]-'0';
    }
    else if(strlen(sAno)==2){
        iAno=(sAno[0]-'0')*10;
        iAno+=(sAno[1]-'0');
    }
    else{
        for(i=0;i<5;i++){
            sAno[i]='\0';
        }
        datavalida=0;
    }
    /*printf("Dia: %d\nMes: %d\nAno: %d\n", iDia,iMes,iAno);*/
    if(iAno<100){
        iAno+=2000;
        
    }
    if(iDia<1 || iDia>31){
        datavalida=0;
    }
    else if(iMes<1 || iMes>12){
        datavalida=0;
    }
    else if(iAno<1900 || iAno>3100){
        datavalida=0;
    }
    else if(iMes == 4 || iMes == 6 || iMes==9 || iMes==11){
        if(iDia>30){
            datavalida=0;
        }
    }
    else if((iAno%4==0 && iAno%100!=0 ) || (iAno%4==00 && iAno%100!=0 && iAno%400==0)){
        if(iMes==2){
            if(iDia>29){
                datavalida=0;
            }
        }
    }
    else{
        if(iMes==2){
            if(iDia>28){
                datavalida=0;
            }
        }
    }
    if (datavalida)
        return 1;   
    else
        return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias=0,nMeses=0,nAnos=0,inDia=0,inMes=0,inAno=0,finDia=0,finMes=0,finAno=0;
    char sDia[3],sMes[3],sAno[5],sDia1[3],sMes1[3],sAno1[5];
    int i,d,j;
    setlocale(LC_ALL,"Portuguese");
    if (q1(datainicial) == 0){
        return 2;}
    if (q1(datafinal) == 0){
        return 3;}
    for(i=0;i<3;i++){
        sDia[i]='\0';
        sMes[i]='\0';
    }
    for(i=0;i<4;i++){
        sAno[i]='\0';
    }
    for(i=0;datainicial[i]!='/';i++){
        sDia[i]=datainicial[i];
    }
    for(i=i+1,j=0;datainicial[i]!='/';i++,j++){
        sMes[j]=datainicial[i];
    }
    for(i=i+1,j=0;j<4;i++,j++){
        sAno[j]=datainicial[i];
    }
    if(strlen(sDia)>1){
        inDia=(sDia[0]-'0')*10;
        inDia+=(sDia[1]-'0');
    }
    else if(strlen(sDia)==1){
        inDia=sDia[0]-'0';
    }
    else{
        for(i=0;i<3;i++){
            sDia[i]='\0';
        }
    }
    if(strlen(sMes)>1){
        inMes=(sMes[0]-'0')*10;
        inMes+=(sMes[1]-'0');
    }
    else if(strlen(sMes)==1){
        inMes=sMes[0]-'0';
    }
    else{
        for(i=0;i<3;i++){
            sMes[i]='\0';
        }
    }
    if(strlen(sAno)>2){
        inAno=(sAno[0]-'0')*1000;
        inAno+=(sAno[1]-'0')*100;
        inAno+=(sAno[2]-'0')*10;
        inAno+=sAno[3]-'0';
    }
    else if(strlen(sAno)==2){
        inAno=(sAno[0]-'0')*10;
        inAno+=(sAno[1]-'0');
    }
    else{
        for(i=0;i<5;i++){
            sAno[i]='\0';
        }
    }
    for(i=0;i<3;i++){
        sDia1[i]='\0';
        sMes1[i]='\0';
    }
    for(i=0;i<4;i++){
        sAno1[i]='\0';
    }
    for(i=0;datafinal[i]!='/';i++){
        sDia1[i]=datafinal[i];
    }
    for(i=i+1,j=0;datafinal[i]!='/';i++,j++){
        sMes1[j]=datafinal[i];
    }
    for(i=i+1,j=0;j<4;i++,j++){
        sAno1[j]=datafinal[i];
    }
    if(strlen(sDia1)>1){
        finDia=(sDia1[0]-'0')*10;
        finDia+=(sDia1[1]-'0');
    }
    else if(strlen(sDia1)==1){
        finDia=sDia1[0]-'0';
    }
    else{
        for(i=0;i<3;i++){
            sDia1[i]='\0';
        }
    }
    if(strlen(sMes1)>1){
        finMes=(sMes1[0]-'0')*10;
        finMes+=(sMes1[1]-'0');
    }
    else if(strlen(sMes1)==1){
        finMes=sMes1[0]-'0';
    }
    else{
        for(i=0;i<3;i++){
            sMes1[i]='\0';
        }
    }
    if(strlen(sAno1)>2){
        finAno=(sAno1[0]-'0')*1000;
        finAno+=(sAno1[1]-'0')*100;
        finAno+=(sAno1[2]-'0')*10;
        finAno+=sAno1[3]-'0';
    }
    else if(strlen(sAno1)==2){
        finAno=(sAno1[0]-'0')*10;
        finAno+=(sAno1[1]-'0');
    }
    else{
        for(i=0;i<5;i++){
            sAno1[i]='\0';
        }
    }
    if (inAno>finAno || (inMes>finMes && inAno==finAno)){
        return 4;
    }
    if(inMes==1 || inMes==3 || inMes==5 || inMes==7 || inMes==8 || inMes==10 || inMes==12){
        nDias+=31-inDia; 
        nDias+=finDia;
    }
    if(inMes==4 || inMes==6 || inMes==9 || inMes==11){
        nDias+=30-inDia;
        nDias+=finDia;
    }
    if(inMes==2){
        if((inAno%4==0 && inAno%100!=0) || (inAno%4==0 && inAno%100!=0 && inAno%400==0)){
            nDias+=29-inDia;
            nDias+=finDia;
        }
        else{
            nDias+=28-inDia;
            nDias+=finDia;
        }
    }
    if(inAno<finAno){
        for(i=inMes+1,d=inAno;(i!=finMes || d!=finAno);i++){
            nMeses++;
            if(i==12){
                d++;
                i=0;
            }
            if(inMes==1 || inMes== 3 || inMes==5 || inMes== 7 || inMes==8 || inMes==10 || inMes== 12){
                    if(nDias==31){
                        nDias=0;
                        nMeses++;
                        
                    }
            }
            if(inMes==4 || inMes==6 || inMes==9 || inMes==11){
                    if(nDias==30){
                        nDias=0;
                        nMeses++;
                        
                    }
            }
            if(inMes==2){
                if((inAno%4==0 && inAno%100!=0) || (inAno%4==0 && inAno%100!=0 && inAno%400==0)){
                    if(nDias==29){
                        nDias=0;
                        nMeses++;
                    }
                }
                else{
                    if(nDias==28){
                        nDias=0;
                        nMeses++;
                    } 
                }
            }
            if(nMeses==12){
                nAnos++;
                nMeses=0;
            }
        }
    }
    if(inAno==finAno){
        for(i=inMes+1,d=inAno;i==finMes;i++){
            if(finMes-inMes>1){
                nMeses++;
            }
            if(inMes==1 || inMes== 3 || inMes==5 || inMes== 7 || inMes==8 || inMes==10 || inMes== 12){
                if(nDias>=31){
                    nDias-=31;
                    nMeses++; 
                }
            }
            if(inMes==4 || inMes==6 || inMes==9 || inMes==11){
                if(nDias>=30){
                    nDias-=30;
                    nMeses++;
                }
            }
            if(inMes==2){
                if((inAno%4==0 && inAno%100!=0) || (inAno%4==0 && inAno%100!=0 && inAno%400==0)){
                    if(nDias>=29){
                        nDias-=29;
                        nMeses++;
                    }
                }
                else{
                    if(nDias>=28){
                        nDias-=28;
                        nMeses++;
                    } 
                }
            } 
            if(nMeses==12){
                nAnos++;
                nMeses=0;
            }
        }
    }

    
    /*mantenha o código abaixo, para salvar os dados 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    //printf("Retornei 1\n");
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. 
    Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
    Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(wchar_t *texto, wchar_t c, int isCaseSensitive)
{
    int qtdOcorrencias = 0,i;

    for(i=0;i<=1;i++){
        switch(c){  
            case L'á':
            case L'â':
            case L'à':
            case L'ä':
            case L'ã':
            c='a';
            break;
            case L'Á':
            case L'Â':
            case L'À':
            case L'Ä':
            case L'Ã':
            c='A';
            break;
            case L'é':
            case L'ê':
            case L'è':
            case L'ë':
            c='e';
            break;
            case L'É':
            case L'Ê':
            case L'È':
            case L'Ë':
            c='E';
            break;
            case L'í':
            case L'î':
            case L'ì':
            case L'ï':
            c='i';
            break;
            case L'Í':
            case L'Î':
            case L'Ì':
            case L'Ï':
            c='I';
            case L'ó':
            case L'ô':
            case L'ò':
            case L'ö':
            case L'õ':
            c='o';
            break;
            case L'Ó':
            case L'Ô':
            case L'Ò':
            case L'Ö':
            case L'Õ':
            c='O';
            break;
        }
    }
    for(i=0;i<=wcslen(texto);i++){
        switch(texto[i]){
            case L'á':
            case L'â':
            case L'à':
            case L'ä':
            case L'ã':
            texto[i]='a';
            break;
            case L'Á':
            case L'Â':
            case L'À':
            case L'Ä':
            case L'Ã':
            texto[i]='A';
            break;
            case L'é':
            case L'ê':
            case L'è':
            case L'ë':
            texto[i]='e';
            break;
            case L'É':
            case L'Ê':
            case L'È':
            case L'Ë':
            texto[i]='E';
            break;
            case L'í':
            case L'î':
            case L'ì':
            case L'ï':
            texto[i]='i';
            break;
            case L'Í':
            case L'Î':
            case L'Ì':
            case L'Ï':
            texto[i]='I';
            case L'ó':
            case L'ô':
            case L'ò':
            case L'ö':
            case L'õ':
            texto[i]='o';
            break;
            case L'Ó':
            case L'Ô':
            case L'Ò':
            case L'Ö':
            case L'Õ':
            texto[i]='O';
            break;
        }
    }
    if(isCaseSensitive){
        for(i=0;i<wcslen(texto);i++){
            switch(c){
                case 'A':
                if(texto[i]=='A'){
                    qtdOcorrencias++;
                }
                break;
                case 'a':
                if(texto[i]=='a'){
                    qtdOcorrencias++;
                }
                break;
                case 'B':
                if(texto[i]=='B'){
                    qtdOcorrencias++;
                }
                break;
                case 'b':
                if(texto[i]=='b'){
                    qtdOcorrencias++;
                }
                break;
                case 'C':
                if(texto[i]=='c'){
                    qtdOcorrencias++;
                }
                break;
                case 'c':
                if(texto[i]=='c'){
                    qtdOcorrencias++;
                }
                break;
                case 'D':
                if(texto[i]=='D'){
                    qtdOcorrencias++;
                }
                break;
                case 'd':
                if(texto[i]=='d'){
                    qtdOcorrencias++;
                }
                break;
                case 'E':
                if(texto[i]=='E'){
                    qtdOcorrencias++;
                }
                break;
                case 'e':
                if(texto[i]=='e'){
                    qtdOcorrencias++;
                }
                break;
                case 'F':
                if(texto[i]=='F'){
                    qtdOcorrencias++;
                }
                break;
                case 'f':
                if(texto[i]=='f'){
                    qtdOcorrencias++;
                }
                break;
                case 'G':
                if(texto[i]=='G'){
                    qtdOcorrencias++;
                }
                break;
                case 'g':
                if(texto[i]=='g'){
                    qtdOcorrencias++;
                }
                break;
                case 'H':
                if(texto[i]=='H'){
                    qtdOcorrencias++;
                }
                break;
                case 'h':
                if(texto[i]=='h'){
                    qtdOcorrencias++;
                }
                break;
                case 'I':
                if(texto[i]=='I'){
                    qtdOcorrencias++;
                }
                break;
                case 'i':
                if(texto[i]=='i'){
                    qtdOcorrencias++;
                }
                break;
                case 'J':
                if(texto[i]=='J'){
                    qtdOcorrencias++;
                }
                break;
                case 'j':
                if(texto[i]=='j'){
                    qtdOcorrencias++;
                }
                break;
                case 'K':
                if(texto[i]=='K'){
                    qtdOcorrencias++;
                }
                break;
                case 'k':
                if(texto[i]=='k'){
                    qtdOcorrencias++;
                }
                break;
                case 'L':
                if(texto[i]=='L'){
                    qtdOcorrencias++;
                }
                break;
                case 'l':
                if(texto[i]=='l'){
                    qtdOcorrencias++;
                }
                break;
                case 'M':
                if(texto[i]=='M'){
                    qtdOcorrencias++;
                }
                break;
                case 'm':
                if(texto[i]=='m'){
                    qtdOcorrencias++;
                }
                break;
                case 'N':
                if(texto[i]=='N'){
                    qtdOcorrencias++;
                }
                break;
                case 'n':
                if(texto[i]=='n'){
                    qtdOcorrencias++;
                }
                break;
                case 'O':
                if(texto[i]=='O'){
                    qtdOcorrencias++;
                }
                break;
                case 'o':
                if(texto[i]=='o'){
                    qtdOcorrencias++;
                }
                break;
                case 'P':
                if(texto[i]=='P'){
                    qtdOcorrencias++;
                }
                break;
                case 'p':
                if(texto[i]=='p'){
                    qtdOcorrencias++;
                }
                break;
                case 'Q':
                if(texto[i]=='Q'){
                    qtdOcorrencias++;
                }
                break;
                case 'q':
                if(texto[i]=='q'){
                    qtdOcorrencias++;
                }
                break;
                case 'R':
                if(texto[i]=='R'){
                    qtdOcorrencias++;
                }
                break;
                case 'r':
                if(texto[i]=='r'){
                    qtdOcorrencias++;
                }
                break;
                case 'S':
                if(texto[i]=='S'){
                    qtdOcorrencias++;
                }
                break;
                case 's':
                if(texto[i]=='s'){
                    qtdOcorrencias++;
                }
                break;
                case 'T':
                if(texto[i]=='T'){
                    qtdOcorrencias++;
                }
                break;
                case 't':
                if(texto[i]=='t'){
                    qtdOcorrencias++;
                }
                break;
                case 'U':
                if(texto[i]=='U'){
                    qtdOcorrencias++;
                }
                break;
                case 'u':
                if(texto[i]=='u'){
                    qtdOcorrencias++;
                }
                break;
                case 'V':
                if(texto[i]=='V'){
                    qtdOcorrencias++;
                }
                break;
                case 'v':
                if(texto[i]=='v'){
                    qtdOcorrencias++;
                }
                break;
                case 'W':
                if(texto[i]=='W'){
                    qtdOcorrencias++;
                }
                break;
                case 'w':
                if(texto[i]=='w'){
                    qtdOcorrencias++;
                }
                break;
                case 'X':
                if(texto[i]=='X'){
                    qtdOcorrencias++;
                }
                break;
                case 'x':
                if(texto[i]=='x'){
                    qtdOcorrencias++;
                }
                break;
                case 'Y':
                if(texto[i]=='Y'){
                    qtdOcorrencias++;
                }
                break;
                case 'y':
                if(texto[i]=='y'){
                    qtdOcorrencias++;
                }
                break;
                case 'Z':
                if(texto[i]=='Z'){
                    qtdOcorrencias++;
                }
                break;
                case 'z':
                if(texto[i]=='z'){
                    qtdOcorrencias++;
                }
                break;
            }
        }
    }
    if(isCaseSensitive!=1){
        for(i=0;i<wcslen(texto);i++){
            switch(c){
                case L'A':
                case L'a':
                if(texto[i]==L'A'|| texto[i]==L'a'){
                    qtdOcorrencias++;
                }
                break;
                case L'B':
                case L'b':
                if(texto[i]==L'B'|| texto[i]==L'b'){
                    qtdOcorrencias++;
                }
                break;
                case L'C':
                case L'c':
                if(texto[i]==L'C'|| texto[i]==L'c'){
                    qtdOcorrencias++;
                }
                break;
                case L'D':
                case L'd':
                if(texto[i]==L'D'|| texto[i]==L'd'){
                    qtdOcorrencias++;
                }
                break;
                case L'E':
                case L'e':
                if(texto[i]==L'E'|| texto[i]==L'e'){
                    qtdOcorrencias++;
                }
                break;
                case L'F':
                case L'f':
                if(texto[i]==L'F'|| texto[i]==L'f'){
                    qtdOcorrencias++;
                }
                break;
                case L'G':
                case L'g':
                if(texto[i]==L'G'|| texto[i]==L'g'){
                    qtdOcorrencias++;
                }
                break;
                case L'H':
                case L'h':
                if(texto[i]==L'H'|| texto[i]==L'h'){
                    qtdOcorrencias++;
                }
                break;
                case L'I':
                case L'i':
                if(texto[i]==L'I'|| texto[i]==L'i'){
                    qtdOcorrencias++;
                }
                break;
                case L'J':
                case L'j':
                if(texto[i]==L'J'|| texto[i]==L'j'){
                    qtdOcorrencias++;
                }
                break;
                case L'K':
                case L'k':
                if(texto[i]==L'K'|| texto[i]==L'k'){
                    qtdOcorrencias++;
                }
                break;
                case L'L':
                case L'l':
                if(texto[i]==L'L'|| texto[i]==L'l'){
                    qtdOcorrencias++;
                }
                break;
                case L'M':
                case L'm':
                if(texto[i]==L'M'|| texto[i]==L'm'){
                    qtdOcorrencias++;
                }
                break;
                case L'N':
                case L'n':
                if(texto[i]==L'N'|| texto[i]==L'n'){
                    qtdOcorrencias++;
                }
                break;
                case L'O':
                case L'o':
                if(texto[i]==L'O'|| texto[i]==L'o'){
                    qtdOcorrencias++;
                }
                break;
                case L'P':
                case L'p':
                if(texto[i]==L'P'|| texto[i]==L'p'){
                    qtdOcorrencias++;
                }
                break;
                case L'Q':
                case L'q':
                if(texto[i]==L'Q'|| texto[i]==L'q'){
                    qtdOcorrencias++;
                }
                break;
                case L'R':
                case L'r':
                if(texto[i]==L'R'|| texto[i]==L'r'){
                    qtdOcorrencias++;
                }
                break;
                case L'S':
                case L's':
                if(texto[i]==L'S'|| texto[i]==L's'){
                    qtdOcorrencias++;
                }
                break;
                case L'T':
                case L't':
                if(texto[i]==L'T'|| texto[i]==L't'){
                    qtdOcorrencias++;
                }
                break;
                case L'U':
                case L'u':
                if(texto[i]==L'U'|| texto[i]==L'u'){
                    qtdOcorrencias++;
                }
                break;
                case L'V':
                case L'v':
                if(texto[i]==L'V'|| texto[i]==L'v'){
                    qtdOcorrencias++;
                }
                break;
                case L'W':
                case L'w':
                if(texto[i]==L'W'|| texto[i]==L'w'){
                    qtdOcorrencias++;
                }
                break;
                case L'X':
                case L'x':
                if(texto[i]==L'X'|| texto[i]==L'x'){
                    qtdOcorrencias++;
                }
                break;
                case L'Y':
                case L'y':
                if(texto[i]==L'Y'|| texto[i]==L'y'){
                    qtdOcorrencias++;
                }
                break;
                case L'Z':
                case L'z':
                if(texto[i]==L'Z'|| texto[i]==L'z'){
                    qtdOcorrencias++;
                }
                break;
            }
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. 
    Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. 
    Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". 
    Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(wchar_t *strTexto, wchar_t *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0,i,j,x=0,d=0;
    int inicio,fim;
    if(wcslen(strTexto)<wcslen(strBusca)){
        qtdOcorrencias=0;
        return qtdOcorrencias;
    }
    for(i=0,j=0;j<wcslen(strBusca) && i<wcslen(strTexto);){
        if(strTexto[i]==strBusca[j]){
            x++;
            i++;
            j++;
            if(x==wcslen(strBusca)){
                posicoes[d]=i-x+1;
                d++;
                posicoes[d]=i;
                d++;
                qtdOcorrencias++;
                j=0;
                x=0;
            }
        }
        else{
            i++;
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int var=10,i,nDigitos=0,n[999],aux1,aux2,j,div,pot=1,cont=0;
    for(i=-1,j=0;i!=0;j++){
        i=(num%var)/(var/10);
        if(i!=0){
            n[j]=i;
            var*=10;
            pot+=1;
            nDigitos++;
        }
        if(i==0 && var==10 && num%var==0){
            num/=10;
            i=-1;
            j--;
        }
    }   
    num=0;
    div=var/100;
    if(nDigitos%2==0){
        for(i=0,j=-1;i==nDigitos/2;i++,j--){
            aux1=n[i];
            aux2=n[nDigitos+j];
            n[i]=aux2;
            n[nDigitos+j]=aux1;
        }
        for(i=0;i<nDigitos;i++){
            num+=n[i]*var/(var/div);
            div/=10;
        }
    }
    if(nDigitos%2!=0){
        for(i=0,j=-1;i==(nDigitos-1)/2;i++,j--){
            aux1=n[i];
            aux2=n[nDigitos+j];
            n[i]=aux2;
            n[nDigitos+j]=aux1;
        }
        for(i=0;i<nDigitos;i++){
            num+=n[i]*var/(var/div);
            div/=10;
        }
    }
    return num;
}
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0,qtdDigitos1=0,i,j,div=10,qtdDigitos2=0;
    int numbu[999],numba[999];
    if (numerobusca>numerobase){
        qtdOcorrencias=0;
        return qtdOcorrencias;
    }
    for(i=-1,j=0;i!=0;j++){
        i=(numerobase%div)/(div/10);
        if(i!=0){
            numba[j]=i;
            div*=10;
            qtdDigitos1++;
        }
    }
    for(i=-1,j=0,div=10;i!=0;j++){
        i=(numerobusca%div)/(div/10);
        if(i!=0){
            numbu[j]=i;
            div*=10;
            qtdDigitos2++;
        }
    }
    for(i=0,j=0;i<qtdDigitos1;i++){
        if(numba[i]==numbu[j]){
            j++;
        }
        else{
            j=0;
        }
        if(j==qtdDigitos2){
            qtdOcorrencias++;

            j=0;
        }
    }
    return qtdOcorrencias;
}
