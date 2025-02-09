#include "../include/mlp.h"

int main(int argc, char **argv) {
  size_t input_nodes = 2;
  size_t hidden_nodes = 2;
  size_t output_nodes = 1;
  double input[] = {0.5, -0.3};
  double output[1];

  MLP *mlp = mlp_init(input_nodes, hidden_nodes, output_nodes);

  for (int i = 0; i < input_nodes; i++) {
    for (int j = 0; j < hidden_nodes; j++) {
      printf("weights_input_hidden[%d][%d] = %f\n", i, j, mlp->weights_input_hidden[i * hidden_nodes + j]);
    }
  }

  for (int i = 0; i < hidden_nodes; i++) {
    for (int j = 0; j < output_nodes; j++) {
      printf("weights_hidden_output[%d][%d] = %f\n", i, j, mlp->weights_hidden_output[i * output_nodes + j]);
    }
  }

  for (int i = 0; i < hidden_nodes; i++) {
    printf("bias_hidden[%d] = %f\n", i, mlp->bias_hidden[i]);
  }

  for (int i = 0; i < output_nodes; i++) {
    printf("bias_output[%d] = %f\n", i, mlp->bias_output[i]);
  }

  mlp_forward(mlp, input, output);
  
  free_mlp(mlp);
  
  return 0;
}
