#ifndef ch_5_stuff_h
#define ch_5_stuff_h

void ch5_test_case()
{

    //тесты массивов, указателей и ссылок
    char c1[] = "123456";
    char* c2 = calloc(10, sizeof(char));

    for (int i = 0; i < 10; i++) {
        c2[i] = i;
        printf("%d ", c2[i]);
    }
    printf("\n");

    int a = 10;
    int* pa = &a;
    int* b = pa;

    printf("a, pa, b:               %d\t%d\t%d\n", &a, pa, b);
    b = &c1;
    printf("*(c2 + 4), c2[4]:       %5d\t%d\n", *(c2 + 4), c2[4]);
    printf("c1[3], *c1 + 3  :       %6d\t%d\n", c1[3], *c1 + 3);
    printf("&c1[3], c1 + 3) :       %11d\t%d\n", &c1[3], c1 + 3);
}


/**
 * @brief mystrlen - strlen по указателю
 * @param s
 * @return
 */
int ch5_mystrlen(char* s)
{
    int len = 0 ;
    while(*s++!='\0'){  //двигаем указатель в качестве итератора
        len++;
    }
    return len;
}

//следующие две функции эквивалентны
int* valueOf1(int* s, int index) {  return  &s[index]; }
int* valueOf2(int* s, int index) {  return  s+index; }

#define ALLOC_SIZE 10000       //размер доступного пространства

static char allocbuf[ALLOC_SIZE];           //память для alloc
static char* allocp = allocbuf;             //указатель на свободное место

char* alloc(int n){
    if(allocbuf+ALLOC_SIZE - allocp >=n ){   //если n влезет в оставшееся пространство allocbuf[ALLOC_SIZE] - allocp
        allocp+=n;
        return allocp - n ; //возвращаем старый указатель
    }
    else
        return 0;    //нет места. Си гарантирует, что нуль никогда не будет правильным адресом для данных!
}

void afree(char* p){
    if(p>=allocbuf && p<allocbuf + ALLOC_SIZE)  //если лежит в пределах массива
        allocp = p;
}

/**
 * @brief my_strcpy1 вариант с индексируемым массивом
 * @param dest
 * @param source
 */
void my_strcpy1(char* dest, char* source)
{
    int i=0;
    while((dest[i]=source[i])!='\0')
        i++;
}

/**
 * @brief my_strcpy2    с указателями
 * @param dest
 * @param source
 */
void my_strcpy2(char* dest, char* source)
{
    while((*dest++ = *source++)!='\0')
        ;

}

/**
 * @brief my_strcpy3 оптимизировано, используем ++ и убираем сравнение с нулем,
 *        так как ненулевое выражение в условии трактуется как истинность
 * @param dest
 * @param source
 */
void my_strcpy3(char* dest, const char* source)
{
    while(*dest++ = *source++)
        ;
}

/**
 * @brief my_strcmp1 выдает < 0 при s < t, 0 при s == t, > 0 при s > t
 * @param s
 * @param t
 * @return
 */
int my_strcmp1(char* s, char* t){

    int i;
    for(i=0;s[i]==t[i];i++) // при первом же отличии управление перейдет в return s[i] - t[i];
        if(s[i] == '\0')
            return 0;   //равны
    return s[i] - t[i];
}

/**
 * @brief my_strcmp2 с использованием указателей
 * @param s
 * @param t
 * @return
 */
int my_strcmp2( const char* s, const char* t){
    for(;*s==*t;s++,t++)
        if(*s=='\0')
            return 0;
    return *s - *t;
}

#endif //ch_5_stuff_h
