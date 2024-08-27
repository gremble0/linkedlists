#include <stdio.h>

#include "sll.h"

int main(void) {
  sll_t *sll = sll_init(sizeof(int));

  int value = 5;
  int value2 = 42;
  sll_add(sll, &value);
  sll_add(sll, &value2);

  int value3 = 420;
  int value4 = 69;
  sll_add(sll, &value3);
  sll_add(sll, &value4);

  sll_print(sll);
}
