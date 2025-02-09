# perceptron-c
This is a multilayer perceptron built in the glorious C programming language made by the 
beautiful Dennis Ritchie.

# What it does rn
- Initializes a neural network with random weights and biases (mlp struct).
- Runs forward propagation on an arbitrary array using sigmoid for both the hidden and output 
layer.

# Need to do
- Dataset handling (will begin with xor I think).
- Implement backpropagation.
  - Add an option for mlp->task_type (regression, binary and multi-class classification);
    - Loss for regression will be MSE, binary will be BCE, and multi will be CCE.
- Add softmax and linear activation functions.
- Later: Change random weight and bias init to using both xavier and he:
  - Xavier for tanh and sigmoid;
  - He for relu.

# Usage
None yet!
