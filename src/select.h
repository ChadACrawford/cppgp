#ifndef SELECT_H
#define SELECT_H

#include "fitness.h"
#include "program.h"

class GPSelect {
public:
  GPSelect(Fitness* f);
  virtual Program** run(Program** pool, unsigned int pool_size, unsigned int new_pool_size);
protected:
  Fitness* f;
};


class GPSelectTournament : public GPSelect {
public:
  GPSelectTournament(Fitness* f, double p);
  Program** run(Program** pool, unsigned int pool_size, unsigned int new_pool_size);
private:
  double p;
};

#endif
