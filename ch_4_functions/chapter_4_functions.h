#ifndef KNR_EXERCISES_CH4_FUNCTIONS_H
#define KNR_EXERCISES_CH4_FUNCTIONS_H

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "ch_4-11_quick_sort.h"
#include "ex_4-1_strindex.h"
#include "ex_4-13_reverse_recursive.h"
#include "ch_4-3_calculator.h"


/**
 * Удаляет из строки завершающие символы, пробелы, табуляции
 * @param s
 */
void ch4_trim_right(char *s)
{
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            break;
        }
        s[i + 1] = '\0';
    }
}

/**
 * Преобразование строки в дробное число
 * @param s
 * @return
 * @remarks Если указатель равен нулю, но функция вернет 0;
 */
double ch4_atod(const char *s)
{
    int i = 0;
    double res = 0.0;
    double resP = 0.0;
    double d = 10.0;
    BOOL afterP = false;
    int sign = 0;

    ///Проверка на нулевой указатель
    if (s == 0)
        return 0;

    while (s[i] != '\0') {
        sign = (s[0] == '-') ? -1 : 1;
        if (s[i] == '.' || s[i] == ',')
            afterP = true;

        if (s[i] == '+' || s[i] == '-')
            i++;
        if (s[i] == '.' || s[i] == ',')
            i++;

        if (isdigit(s[i])) {
            if (afterP) {
                resP = resP + (s[i] - '0') / d;
                d *= 10.0;
            } else {
                res = res * 10.0 + (s[i] - '0');
            }
        }
        i++;
    }

    return sign * (res + resP);
}

/**
 * То же самое, что и atod, только работает с целыми числами
 * @param s
 * @return
 */
int ch4_atoi_d(const char *s)
{
    return (int) ch4_atod(s);
}



void ch4_swap(char* data, int i, int j){
    char temp ;
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

/**
 * @brief qsort быстрая сортировка, простой вариант
 * @param data массив данных
 * @param left
 * @param right
 */
void ch4_qsort(char* data , int left, int right){

    int i, ptr;
    if(left >= right){
        return;
    }
    ch4_swap(data, left, (left+right)/2);
    ptr = left;
    for(i=left+1; i<=right;i++){
        if( data[i]< data[left])
            ch4_swap(data,++ptr,i);
    }

    ch4_swap(data, left, ptr);
    ch4_qsort (data,left, ptr-1);
    ch4_qsort (data,ptr+1, right);


}


#endif //KNR_EXERCISES_CH4_FUNCTIONS_H
