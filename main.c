#include <stdio.h>

#include "sll.h"

int main(void) {
  sll_t *sll = sll_init(sizeof(int));
  int value = 5;
  sll_add(sll, &value);
}
