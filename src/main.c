#include "mlp.h"
#include "utils.h"

int main(void) {
  size_t input_nodes = 2;
  size_t hidden_nodes = 2;
  size_t output_nodes = 1;
  double output[output_nodes];

  MLP *mlp = mlp_init(input_nodes, hidden_nodes, output_nodes);

  double (*input)[COLS] = read_xor("dataset/Xor_Dataset.csv");
  double *hidden = (double *)malloc(mlp->hidden_nodes * sizeof(double));
  if (!hidden) {
    fprintf(stderr, "hidden activation malloc failed");
    exit(1);
  }  

  mlp_train(mlp, input, hidden, output);

  for (int j = 0; j < ROWS; j++) {
    double target = input[j][2];
    mlp_forward(mlp, input[j], hidden, output);

    int predicted_class = (output[0] >= 0.5) ? 1 : 0;

    printf("Input: [%.1f, %.1f] -> Predicted: %d (Target: %.0f)\n", input[j][0], input[j][1], predicted_class, target);
  }

  free(hidden);
  free_mlp(mlp);

  return 0;
}
