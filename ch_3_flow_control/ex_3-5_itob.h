/**
 * ex 3.5
 * Представлeние числа val в системе счисления radix
 * @param val число
 * @param s выходной буфер
 * @param radix система счисления
 */
void ch3_itob(const int val, char *s, int radix)
{
    int i, c;
    int n = val;
    int sign = (n < 0) ? -1 : 1;

    i = 0;
    do {
        c = sign * (n % radix);
        if (c < 10) {
            s[i++] = (char) (c + '0');
        } else s[i++] = (char) (c - 10 + 'A');

    } while ((n /= radix) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    ch3_reverse2(s, strlen(s));
}
