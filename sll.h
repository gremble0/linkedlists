#pragma once

#include <stddef.h>

typedef struct sll_node_t {
  struct sll_node_t *next;
  char is_last;
} sll_node_t;

typedef struct {
  sll_node_t *first;
} sll_t;
