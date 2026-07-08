#include <stdio.h>

#include "gradient.h"


FILE* OpenLog(char* filename) {
    FILE* log_path = fopen(filename, "w");

    fprintf(log_path, "i,loss,A,B,R\n");
    return log_path;
}



void LogLoss(FILE* log_path, int iteration, double loss, double A, double B, double R) {
    char loss_buffer[32];
    snprintf(loss_buffer, sizeof(loss_buffer), "%f", loss);


    fprintf(log_path, "%d,%f,%f,%f,%f\n", iteration, loss, A, B, R);
}


void CloseLog(FILE* log_path) {
    fclose(log_path);
}