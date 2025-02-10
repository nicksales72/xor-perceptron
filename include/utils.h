#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROWS 10000
#define COLS 3

// temp
void init_random();

double random_double();
double binary_cross_entropy(int y_true, int y_pred);
double (*read_xor(const char *filename))[COLS];

// Activation stuff
double sigmoid_activation(double x);
double sigmoid_derivative(double x);

#endif

