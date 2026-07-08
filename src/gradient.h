#ifndef GRADIENT_H
#define GRADIENT_H

typedef struct {
    double x, y;
} Point;


double ComputeLoss(Point* points, int num_points, double A, double B, double R);
double ComputePartialDerivative_A(Point* points, int num_points, double A, double B, double R);
double ComputePartialDerivative_B(Point* points, int num_points, double A, double B, double R);
double ComputePartialDerivative_R(Point* points, int num_points, double A, double B, double R);



#endif