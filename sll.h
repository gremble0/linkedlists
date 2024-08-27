#pragma once

#include <stddef.h>

typedef struct sll_node_t {
  struct sll_node_t *next;
  void *value;
} sll_node_t;

typedef struct {
  sll_node_t *first;
  size_t type_size;
} sll_t;

sll_t *sll_init(size_t type_size);

void sll_add(sll_t *sll, void *value);
