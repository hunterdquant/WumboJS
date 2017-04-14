#ifndef __WUMBO_UTILS__
#define __WUMBO_UTILS__

#include "defs.h"

op_type str2optype(char *);
void wprintf(const char *, ...);
void print_spaces(int);
void panic(const char *, ...);

#endif