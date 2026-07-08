#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "gradient.h"

FILE* OpenLog(char* filename);
void LogLoss(FILE* log_path, int iteration, double loss, double A, double B, double R);
void CloseLog(FILE* log_path);

#endif