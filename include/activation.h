#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <math.h>

double sigmoid_activation(double x);
double sigmoid_derivative(double x);
double relu_activation(double x);
double relu_derivative(double x);
double tanh_activation(double x);
double tanh_derivative(double x);

#endif 
