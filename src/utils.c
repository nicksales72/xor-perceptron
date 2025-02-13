#include "utils.h"

void init_random() {
  static int seeded = 0;
  if (!seeded) {
    srand(time(NULL));  
    seeded = 1;
  }
}

double xavier_init(double in, double out) {
  return ((double)rand() / RAND_MAX - 0.5) * sqrt(2.0 / (in + out));
}

double binary_cross_entropy(double y_true, double y_pred) {
  const double epsilon = 1e-9;
  double clipped_pred = fmax(epsilon, fmin(1.0 - epsilon, y_pred));

  return -((y_true * log(clipped_pred)) + (1.0 - y_true) * log(1.0 - clipped_pred));
}

double (*read_xor(const char *filename))[COLS] {  
  static double array[ROWS][COLS];

  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("couldnt open file");
    exit(EXIT_FAILURE);
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

double sigmoid_derivative(double sig) {
  return sig * (1.0 - sig);
}

