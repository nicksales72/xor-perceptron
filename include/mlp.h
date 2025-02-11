#ifndef MLP_H
#define MLP_H

#define LEARNING_RATE 0.05
#define EPOCHS 10000
#define ROWS 10000
#define COLS 3

#include <stdio.h>
#include <stddef.h>

typedef struct {
    size_t input_nodes;
    size_t hidden_nodes;
    size_t output_nodes;
    double *weights_input_hidden;
    double *weights_hidden_output;
    double *bias_hidden;
    double *bias_output;
} MLP;

MLP *mlp_init(size_t input, size_t hidden, size_t output);
void mlp_forward(MLP *mlp, double input[COLS], double *hidden, double *output);
void mlp_backward(MLP *mlp, double *input, double *hidden, double *output, double target, double learning_rate);
void mlp_train(MLP *mlp, double (*input)[COLS], double *hidden, double *output);
void free_mlp(MLP *mlp);

#endif

