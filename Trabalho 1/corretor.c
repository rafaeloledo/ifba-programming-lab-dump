// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.c
#include "RafaelLedo2019116039.h"

void testSomar();    //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{
    printf("Teste q1:\n");
    testQ1();
    printf("Teste q2:\n");
    testQ2();
    printf("Teste q3:\n");
    testQ3();
    printf("Teste q4:\n");
    testQ4();
    printf("Teste q5:\n");
    testQ5();
    printf("Teste q6:\n");
    testQ6();
    system("PAUSE");
}
void testQ1()
{
    char str[11];
    setlocale(LC_ALL,"Portuguese");
    strcpy(str,"01/06/2015");
    printf("%d\n", q1(str)==1);
    strcpy(str, "29/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    printf("%d\n", q1(str) == 0);
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;
    setlocale(LC_ALL,"Portuguese");
    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 0);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    strcpy(datainicial, "29/02/2016");
    strcpy(datafinal, "28/02/2020");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 28);
    printf("%d\n", qtdMeses == 11);
    printf("%d\n", qtdAnos == 3);
    strcpy(datainicial, "29/02/2016");
    strcpy(datafinal, "29/02/2020");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 0);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 4);
    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "05/07/2018");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 29);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    strcpy(datainicial, "26/07/2017");
    strcpy(datafinal, "25/08/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 30);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 0);
    strcpy(datainicial, "26/06/2017");
    strcpy(datafinal, "26/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 0);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);
    
    strcpy(datainicial, "27/02/2016");
    strcpy(datafinal, "03/03/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 5);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    


    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    
    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 2);
    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 3);
    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 1);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);
}

void testQ3()
{
    wchar_t str[250];
    wcscpy(str, L"Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0) == 3);
    printf("%d\n", q3(str, 'b', 0) == 0);
    printf("%d\n", q3(str, 'l', 1) == 0);
    printf("%d\n", q3(str, 'l', 0) == 1);
    printf("%d\n", q3(str, 'L', 0) == 1);
}

void testQ4()
{
    wchar_t strTexto[250];
    wchar_t strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    wcscpy(strTexto, L"Laboratorio de programacao: para ratos de programação");
    wcscpy(strBusca, L"rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    wcscpy(strTexto, L"Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    wcscpy(strBusca, L"mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);
}

void testQ5()
{
    printf("%d\n", q5(345) == 543);
    printf("%d\n", q5(78) == 87);
    printf("%d\n", q5(3) == 3);
    printf("%d\n", q5(54300) == 345);
}

void testQ6()
{
    printf("%d\n", q6(34567368, 3) == 2);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3539343, 3) == 4);
    printf("%d\n", q6(3539343, 39) == 1);
}
