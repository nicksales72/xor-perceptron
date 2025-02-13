#ifndef UTILS_H
#define UTILS_H

#define ROWS 10000
#define COLS 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void init_random();
double xavier_init(double in, double out);
double binary_cross_entropy(double y_true, double y_pred);
double (*read_xor(const char *filename))[COLS];

// Activation stuff
double sigmoid_activation(double x);
double sigmoid_derivative(double sig);

#endif

