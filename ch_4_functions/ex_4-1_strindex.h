#ifndef EX_4_1_STRINDEX_H
#define EX_4_1_STRINDEX_H

#pragma once

#include "bool.h"

/**
 * ex 4.1
 * Функция ищет вхождение строки t в строку s
 * @param s
 * @param t
 * @return Если найдено, но индекс элемента строки s. Иначе -1
 */
int ch4_strindex(char *s, char *t)
{
    int i, j, k;
    BOOL isEqual = false;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k != 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

#endif //EX_4_1_STRINDEX_H
