#include "nn.h"
#include <stdlib.h>

float ReLu(float x){
    if(x<0){
        x=0;
    }
    return x;
}

void splitlist(int *newlist, int list[], int rows, int colm, int init, int end){
    int pos = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<colm; j++){
            if(j>=init && j<=end){
                newlist[pos] = list[i*colm+j];
                pos++;
            }
        }
    }
}

float randValue(int min, int max){
    float x = rand() % (max - min + 1) + min;
    return x;
}

NN randNN(){
    NN nn;
    nn.w1 = randValue(-10, 10)/10;
    nn.w2 = randValue(-10, 10)/10;
    nn.b = randValue(-10, 10)/10;
    return nn;
}

float forward(NN nn, int data1, int data2){
    return ReLu(data1*nn.w1 + data2*nn.w2 + nn.b);
}

float cost(NN nn, int di[], int dou[]){
    float error = 0;
    float x = 0;
    for(int i=0; i<4; i++){
        x = dou[i] - forward(nn, di[i*2], di[i*2+1]);
        error += x*x;
    }
    return error/4;
}

NN dcost(NN nn, float eps, float lr, int di[], int dou[]){
    NN gg;
    float nncost = cost(nn, di, dou);
    gg = nn;
    gg.w1+=eps;
    float dw1 = (cost(gg, di, dou) - nncost)/eps;
    gg = nn;
    gg.w2+=eps;
    float dw2 = (cost(gg, di, dou) - nncost)/eps;
    gg = nn;
    gg.b+=eps;
    float db = (cost(gg, di, dou) - nncost)/eps;
    nn.w1 -= dw1*lr;
    nn.w2 -= dw2*lr;
    nn.b -= db*lr;
    return nn;
}