#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10000
#define COLS 3

// temp
void init_random();

double random_double();
int (*read_xor(const char *filename))[COLS];

#endif

