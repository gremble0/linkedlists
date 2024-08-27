#include <stdlib.h>

#include "sll.h"

sll_t *sll_init(size_t type_size) {
  sll_t *sll = malloc(sizeof(*sll));
  sll->type_size = type_size;
  sll->first = NULL;

  return sll;
}

static sll_node_t *sll_create_node(void *value, size_t type_size,
                                   sll_node_t *next) {
  sll_node_t *node = malloc(sizeof(*node));
  node->value = value;
  node->next = next;

  return node;
}

void sll_add(sll_t *sll, void *value) {
  sll_node_t *prev_first = sll->first;
  sll_node_t *new_first = sll_create_node(value, sll->type_size, prev_first);

  sll->first = new_first;
}
