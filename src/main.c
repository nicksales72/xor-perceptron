#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Hyperparams
#define INPUT_NODES 2
#define HIDDEN_NODES 2
#define OUTPUT_NODES 1
#define LEARNING_RATE 0.5
#define EPOCHS 10000

double weights_input_hidden[INPUT_NODES][HIDDEN_NODES];
double weights_hidden_output[HIDDEN_NODES][OUTPUT_NODES];
double bias_hidden[HIDDEN_NODES];
double bias_output[OUTPUT_NODES];

double sigmoid(double x) {
  return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
  return exp(-x) / ((1.0 + exp(-x)) * (1.0 + exp(-x)));
}

double random_double() {
  // [-1,1]
  return ((double)rand() / RAND_MAX) * 2 - 1;
}

void init_weights() {
  for (int i = 0; i < INPUT_NODES; i++) {
    for (int j = 0; j < HIDDEN_NODES; j++) {
      weights_input_hidden[i][j] = random_double();
    }
  }

  for (int i = 0; i < HIDDEN_NODES; i++) {
    for (int j = 0; j < OUTPUT_NODES; j++) {
      weights_hidden_output[i][j] = random_double();
    }
  }

  for (int i = 0; i < HIDDEN_NODES; i++) {
    bias_hidden[i] = random_double();
  }

  for (int i = 0; i < OUTPUT_NODES; i++) {
    bias_output[i] = random_double();
  }
}

int main(int argc, char **argv) {
  srand(time(NULL)); 
  init_weights();

  for (int i = 0; i < INPUT_NODES; i++) {
    for (int j = 0; j < HIDDEN_NODES; j++) {
      printf("w_ih[%d][%d] = %f\n", i, j, weights_input_hidden[i][j]);
    }
  }

  for (int i = 0; i < HIDDEN_NODES; i++) {
    for (int j = 0; j < OUTPUT_NODES; j++) {
      printf("w_ho[%d][%d] = %f\n", i, j, weights_hidden_output[i][j]);
    }
  }

  return 0;
}
