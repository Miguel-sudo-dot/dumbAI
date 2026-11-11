#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nn.h"

int data[] = {
    0, 0, 0,
    0, 1, 0,
    1, 0, 0,
    1, 1, 1
};

int main(){
    srand(time(NULL));
    
    NN nn = randNN();
    int di[2*4];
    int dou[1*4];
    splitlist(di, data, 4, (sizeof(data)/sizeof(data[0]))/4, 0, 1);
    splitlist(dou, data, 4, (sizeof(data)/sizeof(data[0]))/4, 2, 2);

    printf("w1: %f, w2: %f, b:%f\n", nn.w1, nn.w2, nn.b);
    printf("%f\n", cost(nn, di, dou));
    for(int i=0; i<500; i++){
        nn = dcost(nn, 0.01, 0.1, di, dou);
        printf("%i -> %f\n", i, cost(nn, di, dou));
    }
    printf("w1: %f, w2: %f, b:%f\n", nn.w1, nn.w2, nn.b);
    
   
    return 0;
}

/*
gcc -Wall -Wextra -std=c11 -O2 -o app main.c nn.c -lm
*/