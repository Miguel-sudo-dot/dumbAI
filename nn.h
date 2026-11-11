#ifndef NN_H
#define NN_H

typedef struct{
    float w1;
    float w2;
    float b;
}NN;

float ReLu(float x);

void splitlist(int *newlist, int list[], int rows, int colm, int init, int end);
float randValue(int min, int max);

NN randNN();
float forward(NN nn, int data1, int data2);
float cost(NN nn, int di[], int dou[]);
NN dcost(NN nn, float eps, float lr, int di[], int dou[]);

#endif