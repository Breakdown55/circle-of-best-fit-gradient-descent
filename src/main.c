#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "gradient.h"
#include "io.h"

#define MAX_ITERATIONS  100000
#define LEARNING_RATE   0.01
#define EPSILSON        1e-9



Point points[] = {
    {4.79, 1.4},
    {3.26, 0.56},
    {1.6, 0.41},
    {0.36, 1.67},
    {1.44, 3.8},
    {4.4, 3.2},
    {3.13, 4.34},
    {4.64, 0.43},
    {2.59, -0.45},
    {0.5, 0},
    {-0.86, 2.4},
    {-0.13, 3.5}
};



int main() {
    // seed RNG with current time
    srand(time(NULL));
    
    FILE* log_path = OpenLog("..//analysis//results.csv");

    if (!log_path) {
        printf("Failed to find log file path");
        return 1;
    }
    

    int num_points = sizeof(points) / sizeof(points[0]);

    // Randomly initialize parameters in [0,1]
    double A = (double)rand() / (double)RAND_MAX;
    double B = (double)rand() / (double)RAND_MAX;
    double R = (double)rand() / (double)RAND_MAX;


    double previous_loss = ComputeLoss(points, num_points, A, B, R);

    // Update loop
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        double previous_loss = ComputeLoss(points, num_points, A, B, R);

        double dLdA = ComputePartialDerivative_A(points, num_points, A, B, R);
        double dLdB = ComputePartialDerivative_B(points, num_points, A, B, R);
        double dLdR = ComputePartialDerivative_R(points, num_points, A, B, R);

        A = A - LEARNING_RATE*dLdA;
        B = B - LEARNING_RATE*dLdB;
        R = R - LEARNING_RATE*dLdR;

        double loss = ComputeLoss(points, num_points, A, B, R);

        LogLoss(log_path, i, loss, A, B, R);

        if (fabs(loss - previous_loss) < EPSILSON) {
            printf("Broke out at i=%d\n", i);
            break;
        }
        
        previous_loss = loss;
    }

    printf("A: %f\nB: %f\nR: %f\n\n", A, B, R);


    CloseLog(log_path);

    return 0;
}