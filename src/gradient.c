#include <math.h>

#include "gradient.h"


// SSE
double ComputeLoss(Point* points, int num_points, double A, double B, double R) {
    double total_error = 0.0;

    for (int i = 0; i < num_points; i++) {
        double xi = points[i].x;
        double yi = points[i].y;

        double distance = sqrt((xi + A)*(xi + A) + (yi + B)*(yi + B));

        double error = distance - R;
        double squared_error = error*error;

        total_error += squared_error;
    }

    return total_error;
}



// Partial derivative of Loss with respect to A
double ComputePartialDerivative_A(Point* points, int num_points, double A, double B, double R) {
    double sum = 0.0;

    for (int i = 0; i < num_points; i++) {
        double xi = points[i].x;
        double yi = points[i].y;
        
        double radical = sqrt((xi + A)*(xi + A) + (yi + B)*(yi + B)); // distance from center circle to point

        double term = (2*(xi + A)*(radical - R)) / (radical);


        sum += term;
    }

    return sum;
}

// Partial derivative of Loss with respect to B
double ComputePartialDerivative_B(Point* points, int num_points, double A, double B, double R) {
    double sum = 0.0;

    for (int i = 0; i < num_points; i++) {
        double xi = points[i].x;
        double yi = points[i].y;
        
        double radical = sqrt((xi + A)*(xi + A) + (yi + B)*(yi + B));

        double term = (2*(yi + B)*(radical - R)) / (radical);


        sum += term;
    }

    return sum;
}

// Partial derivative of Loss with respect to R
double ComputePartialDerivative_R(Point* points, int num_points, double A, double B, double R) {
    double sum = 0.0;

    for (int i = 0; i < num_points; i++) {
        double xi = points[i].x;
        double yi = points[i].y;
        
        double radical = sqrt((xi + A)*(xi + A) + (yi + B)*(yi + B));

        double term = radical - R;


        sum += term;
    }

    return -2.0 * sum;
}
