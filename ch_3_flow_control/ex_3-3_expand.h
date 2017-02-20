#include "bool.h"

/**
 * ex 3.3
 * Печатает последовательности символов соглаcно ASCII таблице (Например, a-z: abcde....xyz)
 * @param s
 * @param t
 */
void ch3_expand(const char *s, char *t)
{
    int i = 0;
    int low = 0;
    int k = 0;
    int high = 0;
    int j = 0;
    BOOL isOk = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i + 1] == '-')
            low = s[i] - '0';
        if (s[i] == '-' && ((s[i + 1] - '0') > low))
            high = s[i + 1] - '0';
    }

    for (int j = low; j <= high; j++)
        t[k++] = (char) (j + '0');
}
