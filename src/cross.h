#ifndef CROSS_H
#define CROSS_H

#include "program.h"
#include "fitness.h"

class GPCross {
public:
  GPCross(Fitness* f);
  virtual Program** run(Program** pool, int pool_size, int new_pool_size);
private:
  Fitness* f;
};

class GPCrossTree : public GPCross {
public:
  GPCrossTree(Fitness* f, int max_depth, double cross_p);

  Program** run(Program** pool, int pool_size, int new_pool_size);
private:
  int max_depth;
  double cross_p;
};

#endif
