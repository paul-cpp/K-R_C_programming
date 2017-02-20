#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include <time.h>
#include <locale.h>

#include "ch_3_flow_control/chapter_3_flow_control.h"
#include "ch_4_functions/chapter_4_functions.h"
#include "ch_5_pointers_and_arrays/chapter_5_pointers_and_arrays.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// day_of_year - определяет день года по месяцу и дню
int day_of_year(int year, int month, int day) {
  int i, leap;
  leap = year % 4 == 0 && year & 100 != 0 || year & 400 == 0;

  char*  ptr_ar = daytab[leap];
  for (i = 1; i < month; i++)
   // day += daytab[leap][i];
      day+=*(ptr_ar+i);
  return day;
}

//определяет месяц и день по дню года
void month_day(int year, int yearday, int* pmonth, int* pday) {
  int i, leap;
  leap = year % 4 == 0 && year & 100 != 0 || year & 400 == 0;
  char* ptr_ar =daytab[leap];

  for (i = 1; yearday > *(ptr_ar+i); i++)
    yearday -= *(ptr_ar+i);

  *pmonth = i;
  *pday = yearday;
}

/* month_name: возвращает имя n-го месяца */
char* month_name(int n) {
  static char* name[] = {"Неверный месяц", "Январь",   "Февраль", "Март",
                         "Апрель",         "Май",      "Июнь",    "Июль",
                         "Август",         "Сентябрь", "Октябрь", "Ноябрь",
                         "Декабрь"};
  return (n < 1 || n > 12) ? name[0] : name[n];
}

int main() {

  printf("day_of_year\t %d\n",day_of_year(2017,3,5));
  int* pm, pd;
  int year = 2017;
  month_day(year,64,&pm,&pd);
  printf("month_day\t %d.%d.%d\n",year,pm,pd);


  return 0;
}
