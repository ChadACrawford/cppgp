#ifndef REGRESSION_H
#define REGRESSION_H

#include "../fitness.h"
#include "../function.h"
#include "../types.h"

class Regression : public Fitness {
public:
  Regression(int num_params, int num_samples);
protected:
  double calculate(Program* p);
  double f(double* params);
private:
  double** x;
  GPValue*** gpx;
  double* y;
  int num_params;
  int num_samples;
};

int run_sample_regression(int argc, char* args[]);

#endif
