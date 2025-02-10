#include "../include/activation.h"

double sigmoid_activation(double x) {
  return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
  double sig = sigmoid_activation(x);
  return sig * (1 - sig); // apparently more efficient than my derivative done by hand?????? skill issue
  // return exp(-x) / ((1.0 + exp(-x)) * (1.0 + exp(-x)));
}
