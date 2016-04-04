#ifndef SELECT_H
#define SELECT_H

#include "fitness.h"
#include "program.h"

class GPSelect {
public:
  GPSelect(Fitness* f);
  virtual Program** select(Program* pool, int pool_size, int new_pool_size);
protected:
  Fitness* f;
};


class GPSelectTournament : public GPSelect {
public:
  GPSelectTournament(Fitness* f, double p);
  Program** select(Program** pool, int pool_size, int new_pool_size);
private:
  double p;
};

#endif
