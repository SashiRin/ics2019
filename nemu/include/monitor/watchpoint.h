#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"
#include "monitor/expr.h"

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  uint32_t val;
  char expression[64];

} WP;

WP* new_wp();
void free_wp(WP *wp);
WP* wp_no2ptr(int NO);
void wp_display();
bool wp_check();

#endif
