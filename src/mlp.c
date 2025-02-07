#include "../include/mlp.h"
#include "../include/utils.h"

MLP *mlp_init(size_t input, size_t hidden, size_t output) {
  MLP *mlp = (MLP *)malloc(sizeof(MLP));
  if (!mlp) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  mlp->input_nodes = input;
  mlp->hidden_nodes = hidden;
  mlp->output_nodes = output;

  mlp->weights_input_hidden = (double *)calloc(input * hidden, sizeof(double));
  mlp->weights_hidden_output = (double *)calloc(hidden * output, sizeof(double));
  mlp->bias_hidden = (double *)calloc(hidden, sizeof(double));
  mlp->bias_output = (double *)calloc(output, sizeof(double));

  if (!mlp->weights_input_hidden || !mlp->weights_hidden_output ||
    !mlp->bias_hidden || !mlp->bias_output) {
    fprintf(stderr, "calloc failed\n");
    exit(1);
  }

  for (int i = 0; i < input; i++) {
    for (int j = 0; j < hidden; j++) {
      mlp->weights_input_hidden[i * hidden + j] = random_double();
    }
  }

  for (int i = 0; i < hidden; i++) {
    for (int j = 0; j < output; j++) {
      mlp->weights_hidden_output[i * output + j] = random_double();
    }
  }

  for (int i = 0; i < hidden; i++) mlp->bias_hidden[i] = random_double();
  for (int i = 0; i < output; i++) mlp->bias_output[i] = random_double();

  return mlp;
}

void free_mlp(MLP *mlp) {
  if (!mlp) return;
  
  free(mlp->weights_input_hidden);
  free(mlp->weights_hidden_output);
  free(mlp->bias_hidden);
  free(mlp->bias_output);

  // safe :)
  mlp->weights_input_hidden = NULL;
  mlp->weights_hidden_output = NULL;
  mlp->bias_hidden = NULL;
  mlp->bias_output = NULL;

  free(mlp);
}
