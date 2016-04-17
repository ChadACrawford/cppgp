#ifndef MUTATE_H
#define MUTATE_H

#include "fitness.h"

class GPMutate {
public:
  GPMutate(Fitness* f, FunctionList* functions);

  virtual Program** run(Program** pool, int pool_size);
protected:
  Fitness* f;
  FunctionList* functions;
};

class GPMutateReplace : public GPMutate {
public:
  GPMutateReplace(Fitness* f, FunctionList* functions, int max_depth, double p);

  Program** run(Program** pool, int pool_size);
private:
  int max_depth;
  double p;
  ProgramNode* mutate_tree(ProgramNode* tree, int max_depth);
};

#endif
