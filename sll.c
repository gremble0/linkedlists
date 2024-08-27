#include <stdlib.h>

#include "sll.h"

sll_t *sll_init(size_t type_size) {
  sll_t *sll = malloc(sizeof(*sll));
  sll->type_size = type_size;
  sll->first = NULL;

  return sll;
}
