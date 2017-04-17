#ifndef __WUMBO_UTILS__
#define __WUMBO_UTILS__

#include <stdio.h>

#include "defs.h"

op_type str2optype(char *);
void wprintf(const char *, ...);
void wfprintf(FILE *, const char *, ...);
void print_spaces(int);
void panic(const char *, ...);

#endif