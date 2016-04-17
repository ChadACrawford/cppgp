#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include "../fitness.h"
#include "../function.h"
#include "../types.h"

class Classification : public Fitness {
public:
  Classification(int num_samples);
protected:
  double calculate(Program* p);
  double f(bool* params);
private:
  int num_samples;
  int num_params;
  bool** x;
  GPValue*** gpx;
  bool* y;
};

int run_sample_classification(int argc, char* args[]);

#endif
