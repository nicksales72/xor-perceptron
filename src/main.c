#include "../include/mlp.h"
#include "../include/utils.h"

int main(int argc, char **argv) {
  double (*input)[COLS] = read_xor("/home/nick/Programming/perceptron-c/datasets/Xor_Dataset.csv");
  size_t input_nodes = 2;
  size_t hidden_nodes = 2;
  size_t output_nodes = 1;
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

  double temp_input[] = {0.0, 1.0};
  mlp_forward(mlp, temp_input, output);
  
  free_mlp(mlp);

  for (int i = 0; i < 5; i++) {
    printf("%f, %f, %f\n", input[i][0], input[i][1], input[i][2]);
  }

  return 0;
}
