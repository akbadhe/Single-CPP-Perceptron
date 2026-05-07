#include <iostream>
#include <vector>
using namespace std;

class Perceptron{
    vector<float> weights;
    float learningRate;
    float bias;

public:
    Perceptron(int inputs, float lr){
        weights.resize(inputs,0.0);
        learningRate = lr;
        bias = 0.0;
    }

    int predict(vector<float> inputs){
        float sum = bias;
        for(int i=0;i<inputs.size();i++){
            sum+= weights[i] * inputs[i];
        }
        return sum > 0? 1 : 0;
    }

    void train(vector<vector<float>> inputs, vector<int> labels, int epochs){
        for(int i=0; i< epochs ;i++){
            cout<<"epoch:"<<i<<endl;
            cout<<"weights: "<< weights[0]<<" "<<weights[1]<<endl;
            cout<<"bias:"<<bias<<"\n"<<endl;
            for(int j=0; j<inputs.size();j++){
                cout<<"inputs: {"<<inputs[j][0]<<","<<inputs[j][1]<<"}"<<endl;
                int prediction = predict(inputs[j]);
                cout<<"prediction: "<<prediction<<endl;
                int error = labels[j] - prediction;
                cout<<"error:"<<error<<"\n"<<endl;

                for(int k=0;k<weights.size();k++){
                    weights[k]+= learningRate * error * inputs[j][k];
                }
                bias+= learningRate*error;
            }
            cout<<"\n-----------------------------------------------\n";
        }
    }
};

int main(){

    //2 inputs
    Perceptron p(2, 0.1);
#if 1
    /* AND GATE
    */
    vector<vector<float>> inputs={{0,0},{0,1},{1,0},{1,1}};
    vector<int>           labels={0,0,0,1};

    p.train(inputs,labels,10);

    cout<<"Prediction for {0,0}"<< p.predict({0,0})<<endl;
    cout<<"Prediction for {0,1}"<< p.predict({0,1})<<endl;
    cout<<"Prediction for {1,1}"<< p.predict({1,1})<<endl;
#endif

#if 0
    /* Linear Separation: This test evaluates perceptron’s ability to create a linear
       decision boundary (a straight line) between two distinct clusters in a 2D coordinate space.
    */
    vector<vector<float>> inputs ={{1.2f, 0.7f}, {0.5f, 0.3f}, {0.8f, 0.1f},  // Group A (Small values)
                                   {5.5f, 4.2f}, {6.1f, 3.3f}, {4.8f, 5.0f}};  // Group B (Large values)
    vector<int> labels = {0, 0, 0, 1, 1, 1};

    p.train(inputs,labels,10);

    cout<<"Prediction for {0.2,0.5}"<< p.predict({0.2,0.5})<<endl;
    cout<<"Prediction for {4,5}"<< p.predict({4,5})<<endl;
    cout<<"Prediction for {1,2}"<< p.predict({1,2})<<endl;
#endif

#if 0
    Perceptron p(3,0.3);

    /* AND GATE with 3 inputs
    */
    vector<std::vector<float>> inputs = {
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 1.0f, 1.0f},
        {1.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f},
        {1.0f, 1.0f, 1.0f}
    };

    vector<int> labels = {0, 0, 0, 0, 0, 0, 0, 1};
    p.train(inputs,labels,10);

    cout<<"Prediction for {0,0,1}="<< p.predict({0,0,1})<<endl;
    cout<<"Prediction for {1,1,0}="<< p.predict({1,1,0})<<endl;
    cout<<"Prediction for {1,1,1}="<< p.predict({1,1,1})<<endl;
    cout<<"Prediction for {0,0,0}="<< p.predict({0,0,0})<<endl;
    cout<<"Prediction for {1,0,1}="<< p.predict({1,0,1})<<endl;
    cout<<"Prediction for {1,1,1}="<< p.predict({1,1,1})<<endl;
#endif
    return 0;
}