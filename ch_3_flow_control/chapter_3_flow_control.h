#ifndef KNR_EXERCISES_CH3_CONTROL_FLOW_H
#define KNR_EXERCISES_CH3_CONTROL_FLOW_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "ex_3-2_escape.h"
#include "ex_3-3_expand.h"
#include "ex_3-5_itob.h"


/**
 * Перевод целого в строку с учетом знака
 * @param s
 * @return
 */
int ch3_cool_atoi(char *s)
{
    int i = 0;
    int n = 0;
    int sign = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        //пропуск пробелов
        if (isspace(s[i])) {
            //i++;
            continue;
        }
        //проверка знака
        if (s[i] == '-' && isdigit(s[i + 1])) {
            sign = -1;
            continue;
        }
        if (isdigit(s[i])) {
            n = n * 10 + (s[i] - '0');
        }
    }

    return sign * n;
}

/**
 * @brief Переворот строки, способ 2
 * @param строка, которую нужно перевернуть
 * @param длина строки
 */
void ch3_reverse2(char *str, int len)
{
    char b = 0;
    int i = 0;
    while (i < len / 2) {
        b = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = b;

        i++;
    }
}

/**
 * Перевод числа в строку, в том числе и  отрицательного
 * @param val
 * @param s
 */
void ch3_my_itoa(int val, char *s)
{
    int i = 0;
    int sign = 0;

    if ((sign = val) < 0)
        val = -val;

    while ((val) > 0) {
        s[i++] = (char) (val % 10 + '0');
        val /= 10;
    }
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    ch3_reverse2(s, strlen(s));
}



#endif //KNR_EXERCISES_CH3_CONTROL_FLOW_H
