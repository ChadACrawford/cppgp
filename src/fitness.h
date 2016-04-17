#ifndef FITNESS_H
#define FITNESS_H

#include "program.h"

class Fitness {
public:
  Fitness(int type);
  double evaluate(Program* p);
  int get_type();
private:
  virtual double calculate(Program* p);
  int type;
};

#endif
