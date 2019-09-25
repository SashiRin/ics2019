#ifndef __EXPR_H__
#define __EXPR_H__

#include "common.h"

typedef struct token {
  int type;
  int precedence;
  char str[32];
} Token;

uint32_t expr(char *, bool *);

#endif
