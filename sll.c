#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sll.h"

sll_t *sll_init(size_t type_size) {
  sll_t *sll = malloc(sizeof(*sll));
  sll->type_size = type_size;
  sll->first = NULL;
  sll->last = NULL;

  return sll;
}

static sll_node_t *sll_create_node(void *value, size_t type_size,
                                   sll_node_t *next) {
  sll_node_t *node = malloc(sizeof(*node));
  node->value = value;
  node->next = next == NULL ? node : next;

  return node;
}

void sll_add(sll_t *sll, void *value) {
  if (sll->first == NULL) {
    assert(sll->last == NULL);
    sll->first = sll_create_node(value, sll->type_size, NULL);
    sll->last = sll->first;
    return;
  }

  sll_node_t *prev_last = sll->last;
  sll_node_t *new_last = sll_create_node(value, sll->type_size, prev_last);
  sll->last->next = new_last;
  sll->last = new_last;
}

void *sll_get(sll_t *sll, size_t index) {
  sll_node_t *cur_node = sll->first;
  while (index > 0) {
    cur_node = cur_node->next;
    --index;
  }

  return cur_node->value;
}
