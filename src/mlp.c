#include "../include/mlp.h"
#include "../include/utils.h"

MLP mlp_init(size_t input, size_t hidden, size_t output) {
  MLP mlp;
  mlp.input_nodes = input;
  mlp.hidden_nodes = hidden;
  mlp.output_nodes = output;

  // mallocs
  mlp.weights_input_hidden = (double *)malloc(input * hidden * sizeof(double));
  mlp.weights_hidden_output = (double *)malloc(hidden * output * sizeof(double));
  mlp.bias_hidden = (double *)malloc(hidden * sizeof(double));
  mlp.bias_output = (double *)malloc(output * sizeof(double));

  // malloc failure
  if (!mlp.weights_input_hidden || !mlp.weights_hidden_output ||
    !mlp.bias_hidden || !mlp.bias_output) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  for (int i = 0; i < input; i++) {
    for (int j = 0; j < hidden; j++) {
      mlp.weights_input_hidden[i * hidden + j] = random_double();
    }
  }

  for (int i = 0; i < hidden; i++) {
    for (int j = 0; j < output; j++) {
      mlp.weights_hidden_output[i * output + j] = random_double();
    }
  }

  for (int i = 0; i < hidden; i++) {
    mlp.bias_hidden[i] = random_double();
  }

  for (int i = 0; i < output; i++) {
    mlp.bias_output[i] = random_double();
  }

  return mlp;
}

void free_mlp(MLP *mlp) {
  free(mlp->weights_input_hidden);
  free(mlp->weights_hidden_output);
  free(mlp->bias_hidden);
  free(mlp->bias_output);
}
