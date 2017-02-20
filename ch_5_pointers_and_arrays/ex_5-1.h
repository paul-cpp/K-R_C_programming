#ifndef EX_5-1_GETINT_H
#define EX_5-1_GETINT_H

#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <conio.h>
#include <string.h>

/**
 * ex 5-1
 * @brief ch5_getint -  читает целое число из ввода в *pn
 * @param n
 */
void ch5_getint(int* pn)
{
    int c, sign,tmp;
    //пропуск пробелов
    while(isspace(c=getch()))
        ;

    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetch(c); //если не число, то выкидываем
        return 0;
    }
    sign = (c=='-')? -1: 1;
    if(c=='+' || c=='-'){
        c=getch();
        if(!isdigit(c)){
            ungetch(sign == -1?'-':'+');
            return;
        }
    }
    for(*pn = 0;isdigit(c);c=getch())
        *pn=10* *pn+(c-'0');
    *pn *=sign;

    if(c!=EOF)
        ungetch(c);
    return c;
}

/**
 * ex_5-2
 * @brief ch5_getfloat - читает дробное число из ввода в *pf
 * @param pf
 */
void ch5_getfloat(double * pd)
{
    int c, sign;
    int dec=0;
    int pos = 0;

    while(isspace(c=getch()))
        ;

    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetch(c);
        return;
    }
    sign = (c=='-')? -1: 1;

    if(c=='+' || c=='-')
        c = getch();

    for(*pd= 0;isdigit(c) || c==46 ;c=getch())      //46 - Это точка в ascii таблице
    {
        if(c!=46){
            pos++;
            *pd = 10* *pd + (c-'0');
        }
        else if(c==46)
            dec = pos;
    }

    dec = pos-dec;
    for(; dec!=0;dec--)
        *pd /=(double)10.0;
    *pd *= sign;

    if(c!=EOF)
        ungetch(c);
}

/**
 * ex_5-3
 * @brief ch5_strcat копирует строку t в конец строки s
 * @param s
 * @param t
 */
void ch5_strcat(char* s, char* t)
{
    int len = strlen(s);
    for(s +=len; (*s = *t)!='\0'; s++, t++)
        ;
    //*s = '\0';
}

/**
 * ex_5-4
 * @brief ch5_strend выдает 1, если строка t расположена
 *      в конце строки s, и нуль в противном случае.
 * @param s
 * @param t
 * @return
 */
int ch5_strend( const char* s, const char* t)
{
    int slen = strlen(s);
    int tlen = strlen(t);
    int delta = slen-tlen;
    if(delta < 0)
        return -1;  //error
    s+=delta;

    while(*s++ == *t++){
        if(*s=='\0' || *t=='\0')
            return 1;
    }
    return 0;
}


/**
 * ex 5-5
 * @brief ch5_strncpy   реализация библиотечной функции strncpy
 * @param d             destination string
 * @param s             source string
 * @param n             number of elements of source string
 */
void ch5_strncpy(char* d, const char* s, int n)
{
    //BUG: если размера destination недостаточно, происходит нечто ужасное!
    int i;

    for(i=0; i < n; i++ ){
        *d++ = *s++;
    }
}

/**
 * ex 5-5
 * @brief ch5_strncat  реализация библиотечной функции strncat
 * @param d            destination string
 * @param s            source string
 * @param n            number of elements of source string
 */
void ch5_strncat(char* d, const char* s, int n)
{
    d+=strlen(d);

    int i;
    for( i=0; i < n && *(s+i)!='\0'; i++)
        *(d+i) = *(s+i);
    *(d+i) = '\0';
}

/**
 * ex 5-5
 * @brief ch5_strncmp  реализация библиотечной функции strncmp
 * @param d            destination string
 * @param s            source string
 * @param n            number of elements of source string
 */
int ch5_strncmp(const char* d, const char *s, int n)
{
    int i;
    int comp =0;
    for(i=0; i<n;d++, s++,i++){
        comp = (*d == *s)? 1 : 0;
        if(!comp)
            return 0;
    }
    return comp;
}












#endif  //EX_5-1_GETINT_H
