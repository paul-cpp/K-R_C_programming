#ifndef EX_4_13_REVERSE_H
#define EX_4_13_REVERSE_H


#pragma once

void ch413_swap_recursive(char s[], int i, int len) {
  if (i >= len / 2 + 1)
    return;

  char t = s[i];
  s[i] = s[len - i];
  s[len - i] = t;

  ch413_swap_recursive(s, i + 1, len);
}

void ch4_reverse_recursive(char s[]) {
  int i = 0;

  ch413_swap_recursive(s, i, strlen(s) - 1);
}



#endif //EX_4_13_REVERSE_H
