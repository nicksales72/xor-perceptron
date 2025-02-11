# perceptron-c
This is a multilayer perceptron designed for learning the XOR dataset built in the glorious C programming
language made by the beautiful Dennis Ritchie.

# What it does
- Reads XOR dataset and stores it into a 2D array.
- Initialzes an MLP struct with 2 input nodes, 2 hidden layers, and 1 output node.
  - The weights are initialzed with Xavier.
  - Biases are initalized at 0.1.
- Trains the MLP with an epoch of 10000 and learning rate of 0.05.
  - Layers use the sigmoid activation function.
  - Loss is binary cross entropy.
- Frees memory correctly (I think).

# Need to do
- Efficiency/clean up code.
- Later: 
  - Extend the MLP into learning regression and multi-class problems.

# Usage
```shell
  make
  ./main
```
