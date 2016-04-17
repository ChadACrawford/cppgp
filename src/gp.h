#ifndef GP_H
#define GP_H

#include "function.h"
#include "program.h"
#include "generate.h"
#include "select.h"
#include "cross.h"
#include "mutate.h"

class GP {
public:
  GP(int pool_size, Fitness* fit, GPGenerate* generate, GPSelect* select, GPCross* cross, GPMutate* mutate);

  void init();
  void run(int num_generations);
  void generation();

  Program* best_program();
private:
  Program** pool;
  bool elitism;
  int pool_size;
  Fitness* fit;
  GPGenerate* generate;
  GPSelect* select;
  GPCross* cross;
  GPMutate* mutate;
};

#endif
