#ifndef CH_4_3_CALCULATOR_H
#define CH_4_3_CALCULATOR_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BUFSIZE 100
char buf [BUFSIZE]= {0};    //буфер для ungetch
int bufp = 0;               //свободная позиция в буфере

int ch4_getch()
{
    return (bufp>0) ? buf[--bufp] : getchar();
}

void ch4_ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("ungetch:\t нет места в буфере\n");
    else
        buf[bufp++] = c;
}

#define MAXOPERATIONS 100   //макс размер операнда или оператора
#define NUMBER '0'          //признак числа
#define STACKSIZE 100       //размер стека

int sp = 0 ;                //следующая свободная позиция в стеке
double stack[STACKSIZE]= {0};  //стек

void ch4_push(double val)
{
    if(sp<STACKSIZE) {
        stack[sp++] = val;      //указатель сдвигается вперед на 1 единицу  [0][1][2][3][-> 4 = val] >>> [0][1][2][3][4] ->...
    } else {
        printf("ОШИБКА\t стек полон!\n");
        //return;
    }
}

double ch4_pop()
{
    if(sp>0)
        return stack[--sp];
    else {

        //("ОШИБКА\t стек пуст\n");
        return 0.0;
    }
}

int ch4_getop(char s [])
{
    int i,c;
    int sign=1;
    while((s[0]= c = ch4_getch()) ==' ' || c=='\t' )
        ;
    s[1] = '\0';

    i=0;

    if(!isdigit(c) && c!='.' )
        return c; //не является числом

    if(isdigit(c))
        while(isdigit((s[++i] = c  = ch4_getch()))) //получаем целую часть
            ;
    if(c=='.' || c==',')
        while(isdigit(s[++i] = c  = ch4_getch())) //получаем дробную часть
            ;
    s[i]='\0';

    if(c!=EOF)
        ch4_ungetch(c);

    return NUMBER;
}

void ch4_do_calculations()
{
    setlocale(LC_ALL,"rus");
    printf("mega polish calc by c.. v0.1\n");

    //calculator
    int type;
    double op2;
    char s[MAXOPERATIONS]= {0};

    while((type = ch4_getop(s)) !=EOF) {
        switch(type) {
        case NUMBER:
            ch4_push(atof(s));
            break;
        case '+':
            ch4_push(ch4_pop()+ch4_pop());
            break;
        case '*':
            ch4_push(ch4_pop()*ch4_pop());
            break;
        case '-':
            op2=ch4_pop();      //просто ch4_pop() - ch4_pop() Будет неправильно
            ch4_push(ch4_pop()-op2);
            break;
        case '/':
            op2=ch4_pop();
            if (op2==0.0)
                printf("ERROR:\t ошибка деления на ноль\n");
            else
                ch4_push(ch4_pop()/op2);
            break;
        case '%':
            op2 = ch4_pop();
            ch4_push(fmod(ch4_pop(), op2));
            break;
        case '\n':
            //перевод на новую строку, печатает число с вершины стека
            printf("\t%.8g\n", ch4_pop());
            break;
        default:
            printf("ERROR:\t неизвестная операция\n");
            break;
        }
    }
}



#endif //CH_4_3_CALCULATOR_H






