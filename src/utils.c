#include "../include/utils.h"

// temporary
void init_random() {
  static int seeded = 0;
  if (!seeded) {
    srand(time(NULL));  
    seeded = 1;
  }
}

double random_double() {
  // [-1, 1]
  return ((double)rand() / RAND_MAX) * 2 - 1;
}

double binary_cross_entropy(int y_true, int y_pred) {
  // avoids log(0)
  const double epsilon = 1e-9;
  y_pred = fmax(epsilon, fmin(1.0 - epsilon, y_pred));

  // BCE = -(ylog(p) + (1 - y) * log(1 - p))
  return -((y_true * log(y_pred)) + (1.0 - y_true) * log(1.0 - y_pred));
}

double (*read_xor(const char *filename))[COLS] {  
  static double array[ROWS][COLS];

  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("couldnt open file");
    return NULL;
  }

  for (int i = 0; i < ROWS; i++) {
    if (fscanf(file, "%lf,%lf,%lf", &array[i][0], &array[i][1], &array[i][2]) != 3) {
      fprintf(stderr, "error reading line %d\n", i + 1);
      fclose(file);
      return NULL;
    }
  }

  return array;
}

// Activation functions

double sigmoid_activation(double x) {
  return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
  double sig = sigmoid_activation(x);
  return sig * (1 - sig); // apparently more efficient than my derivative done by hand?????? skill issue
  // return exp(-x) / ((1.0 + exp(-x)) * (1.0 + exp(-x)));
}

