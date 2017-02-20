/** \brief ex 3.2
 *  Печатает символы '\t','\n' в строке
 * \param *s const unsigned char
 * \param t unsigned char*
 * \return void
 */
void ch3_escape(const unsigned char *s, unsigned char *t)
{
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
        case '\t':
            t[j] = '\\';
            t[++j] = 't';
            break;
        case '\n':
            t[j] = '\\';
            t[++j] = 'n';
            break;
        default:
            t[j] = s[i];
            break;
        }
        i++;
        j++;
    }
}
