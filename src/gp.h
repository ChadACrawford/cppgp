#ifndef GP_H
#define GP_H

#include "select.h"
#include "cross.h"
#include "mutate.h"

class GP {
public:
  GP();
  void run();
  void generation();

  Program* best_program();
private:
  GPSelect* select;
  GPCross* cross;
  GPMutate* mutate;
};

#endif
