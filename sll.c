#include <assert.h>
#include <stdio.h>
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
  // Link to itself if its the only element in the list
  node->next = next == NULL ? node : next;

  return node;
}

static sll_node_t *sll_get_last(sll_t *sll) {
  assert(sll->first != NULL);

  sll_node_t *cur_node = sll->first;
  // Have to compare next so we don't walk past the actual last node
  while (cur_node->next != sll->first)
    cur_node = cur_node->next;

  return cur_node;
}

void sll_add(sll_t *sll, void *value) {
  if (sll->first == NULL) {
    sll->first = sll_create_node(value, sll->type_size, NULL);
    return;
  }

  sll_node_t *prev_last = sll_get_last(sll);
  prev_last->next = sll_create_node(value, sll->type_size, sll->first);
}

void *sll_get(sll_t *sll, size_t index) {
  sll_node_t *cur_node = sll->first;
  while (index > 0) {
    cur_node = cur_node->next;
    --index;
  }

  return cur_node->value;
}

void sll_print(sll_t *sll) {
  assert(sll->first != NULL);

  sll_node_t *cur_node = sll->first;
  do {
    cur_node = cur_node->next;
    printf("%p\n", cur_node);
  } while (cur_node != sll->first);
}
