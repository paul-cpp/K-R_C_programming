#ifndef CH_4_11_QUICK_SORT_H
#define CH_4_11_QUICK_SORT_H

#pragma once

void ch411_swap(char* data, int i, int j) {
  char temp;
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
void my_qsort(char* data, int left, int right) {
  int i, ptr;
  if (left >= right) {
    return;
  }
  ch411_swap(data, left, (left + right) / 2);
  ptr = left;
  for (i = left + 1; i <= right; i++) {
    if (data[i] < data[left])
      ch411_swap(data, ++ptr, i);
  }

  ch411_swap(data, left, ptr);
  my_qsort(data, left, ptr - 1);
  my_qsort(data, ptr + 1, right);
}

#endif  // CH_4_11_QUICK_SORT_H
