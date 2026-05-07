**Simple C++ Perceptron Implementation**

This repository contains a from-scratch implementation of a Perceptron, the fundamental building block of an artificial neural network. It demonstrates how a single neuron can learn to classify data that is linearly separable, such as logical gates (AND, OR) or clustered 2D points.

**🧠 The Idea**

A Perceptron is a supervised learning algorithm for binary classifiers. It mimics the behavior of a biological neuron: it takes multiple inputs, applies weights to them, adds a bias, and passes the result through an activation function to produce an output (0 or 1).


**How it works:**

Input Vector: Takes a set of features (e.g., {0, 1}).

Weighted Sum: Multiplies each input by a "weight" and adds a "bias" term.

              **sum = (input1 * w1) + (input2 * w2) + ... + bias**
Activation:   Uses a Step Function. If the sum is greater than 0, the output is 1; otherwise, it's 0.

Learning:     If the prediction is wrong, the Perceptron adjusts its weights and bias using the Perceptron Training Rule.


**🛠 Code Explanation**

Core Components

weights:      A vector representing the "strength" of each input connection.

bias:         An extra parameter that allows the decision boundary to move away from the origin.

learningRate: A small constant (e.g., 0.1) that controls how much the weights change during each error correction.


**Key Methods**
1. predict(vector<float> inputs): Performs the forward pass. It calculates the weighted sum and returns the binary classification.
2. train(...): The engine of the class. It iterates through the dataset for a set number of epochs. For every mistake (error), it updates the weights using the formula:

   **new_weight = old_weight + (learningRate * error * input)**

   **new_bias   = old_bias + (learningRate * error)**


**🚀 Usage**
The main.cpp includes three test scenarios (toggle them using #if 1/0):
1. AND Gate: Training the model to return 1 only when both inputs are 1.
2. Linear Separation: Classifying two distinct clusters of points in a 2D plane (Small values vs. Large values).
3. 3-Input AND Gate: Demonstrating scalability to higher-dimensional inputs.

**Compiling and Running**

_g++ main.cpp -o perceptron_

_./perceptron_



**📊 Example Output**

During training, the code logs the error and the weight adjustments for each epoch, allowing you to visualize the learning process:

_epoch:0

weights: 0 0

bias:0

inputs: {0,0} prediction: 0 error:0

inputs: {1,1} prediction: 0 error:1  <-- Learning happens here!

...

Prediction for {1,1}: 1_



**📝 Limitations**

Note that this is a Single-Layer Perceptron. It can only solve problems that are linearly separable. It cannot solve the "XOR" problem because XOR requires a non-linear decision boundary, which requires adding hidden layers (Multi-Layer Perceptron).
