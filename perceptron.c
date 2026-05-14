/*
* Author  : Shresth Dwivedi
* Date    : 11th May, 2026
* License : MIT
*/

#include <math.h>
#include <stdio.h>

float sigmoid(float w_sum){
    return (1/(1+exp(-w_sum)));
}
float cross_entropy(float pred, int y){
    return -(y * log10(pred) + (1-y) * log10(1 - pred));
}

int main(){

    float x[][3] = {
        {8, 9, 7},
        {7, 8, 6},
        {6, 7, 8},
        {9, 9, 5},
        {1, 2, 6},
        {2, 3, 5},
        {3, 4, 7},
        {4, 2, 4},
        {8, 5, 6},
        {2, 8, 3}
    };
    int y[] = {
        1,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        1,
        0
    };
    float w[3] = {0.4, 0.2, 0.6}, predictions[10];
    float b = 0.5, w_sum = 0, pred = 0, total_loss = 0;

    for(int e = 0; e < 1000; e++){
    // The loops sound like shit to me but nevertheless, it works, will maybe improve upon the efficiency in the future.
        for(int i = 0; i < 10; i++){
            w_sum = 0;
            for(int j = 0; j < 3; j++){
                w_sum += x[i][j] * w[j];
            }
            w_sum += b;
            predictions[i] = sigmoid(w_sum);
            total_loss+= cross_entropy(predictions[i], y[i]);
        }

        // for(int i = 0; i < 4; i++){
        //     printf("\nPREDICTION[%d] = %f",i,predictions[i]);
        // }
        // for(int i = 0; i < 4; i++){
        //     printf("\nLOSS[%d] = %f",i,loss[i]);
        // }
        printf("\n\n======== Epoch %d ========", e);
        printf("\nAverage Loss: %f\n\n", total_loss/4);
        total_loss = 0;

        //Gradient Decent
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 3; j++){
                w[j] += 0.01 * (y[j]-predictions[j]) * x[i][j];
            }
            // Cannot figure out what is making the bias so biased, lol
            b += 0.01 * (y[i]-predictions[i]);
        }
    }
    // Still not been able to test on new data with the updated weights and bias.
    printf("Weights = %f,%f,%f\n", w[0],w[1],w[2]);
    printf("Bias    = %f", b);
    return 0;
}
