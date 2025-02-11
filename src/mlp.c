#include "../include/mlp.h"
#include "../include/utils.h"

MLP *mlp_init(size_t input, size_t hidden, size_t output) {  
  init_random();
  
  MLP *mlp = (MLP *)malloc(sizeof(MLP));
  if (!mlp) {
    fprintf(stderr, "malloc failed\n");
    exit(1);
  }

  mlp->input_nodes = input;
  mlp->hidden_nodes = hidden;
  mlp->output_nodes = output;

  mlp->weights_input_hidden = (double *)malloc(input * hidden * sizeof(double));
  mlp->weights_hidden_output = (double *)malloc(hidden * output * sizeof(double));
  mlp->bias_hidden = (double *)calloc(hidden, sizeof(double));
  mlp->bias_output = (double *)calloc(output, sizeof(double));

  if (!mlp->weights_input_hidden || !mlp->weights_hidden_output ||
    !mlp->bias_hidden || !mlp->bias_output) {
    fprintf(stderr, "callocs and mallocs failed\n");

    free(mlp->weights_input_hidden);
    free(mlp->weights_hidden_output);
    free(mlp->bias_hidden);
    free(mlp->bias_output);
    free(mlp);

    exit(1);
  }

  for (int i = 0; i < input; i++) {
    for (int j = 0; j < hidden; j++) {
      mlp->weights_input_hidden[i * hidden + j] = xavier_init(input, hidden);
    }
  }

  for (int i = 0; i < hidden; i++) {
    for (int j = 0; j < output; j++) {
      mlp->weights_hidden_output[i * output + j] = xavier_init(hidden, output);
    }
  }

  for (int i = 0; i < hidden; i++) mlp->bias_hidden[i] = 0.1;
  for (int i = 0; i < output; i++) mlp->bias_output[i] = 0.1;

  return mlp;
}

void mlp_forward(MLP *mlp, double *input, double *hidden, double *output) {
  for (int i = 0; i < mlp->hidden_nodes; i++) {
    hidden[i] = 0.0;
    for (int j = 0; j < mlp->input_nodes; j++) {
      hidden[i] += input[j] * mlp->weights_input_hidden[j * mlp->hidden_nodes + i];
    }
    hidden[i] += mlp->bias_hidden[i];
    hidden[i] = sigmoid_activation(hidden[i]);
  }

  for (int i = 0; i < mlp->output_nodes; i++) {
    output[i] = 0.0;
    for (int j = 0; j < mlp->hidden_nodes; j++) {
      output[i] += hidden[j] * mlp->weights_hidden_output[j * mlp->output_nodes + i];
    }
    output[i] += mlp->bias_output[i];
    output[i] = sigmoid_activation(output[i]); 
  }  
}

void mlp_backward(MLP *mlp, double input[COLS], double *hidden, double *output, double target, double learning_rate) {
  double *error_hidden = (double *)malloc(mlp->hidden_nodes * sizeof(double));
  double error_output = (output[0] - target) * sigmoid_derivative(output[0]);

  for (int i = 0; i < mlp->hidden_nodes; i++) {
    error_hidden[i] = 0.0;
    for (int j = 0; j < mlp->output_nodes; j++) {
        error_hidden[i] += error_output * mlp->weights_hidden_output[i * mlp->output_nodes + j];
    }
    error_hidden[i] *= sigmoid_derivative(hidden[i]);
  }

  for (int i = 0; i < mlp->hidden_nodes; i++) {
    for (int j = 0; j < mlp->output_nodes; j++) {
      mlp->weights_hidden_output[i * mlp->output_nodes + j] -= learning_rate * error_output * hidden[i];
    }
  }

  for (int i = 0; i < mlp->input_nodes; i++) {
    for (int j = 0; j < mlp->hidden_nodes; j++) {
      mlp->weights_input_hidden[i * mlp->hidden_nodes + j] -= learning_rate * error_hidden[j] * input[i];
    }
  }

  for (int i = 0; i < mlp->hidden_nodes; i++) {
    mlp->bias_hidden[i] -= learning_rate * error_hidden[i];
  }

  mlp->bias_output[0] -= learning_rate * error_output;

  free(error_hidden);
}

void mlp_train(MLP *mlp, double (*input)[COLS], double *hidden, double *output) {
  for (int i = 0; i < EPOCHS; i++) {
    double total_loss = 0.0;
    for (int j = 0; j < ROWS; j++) {
      double target = input[j][2];  
      mlp_forward(mlp, &input[j][0], hidden, output);  

      double loss = binary_cross_entropy(target, output[0]);
      total_loss += loss;

      mlp_backward(mlp, &input[j][0], hidden, output, target, LEARNING_RATE);
    }
    printf("Epoch %d, Loss: %f\n", i + 1, total_loss / ROWS);
  }
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
