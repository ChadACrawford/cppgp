#ifndef GENERATE_H
#define GENERATE_H

#include "function.h"
#include "program.h"

ProgramNode* random_tree(FunctionList* functions, int type, int max_depth);


class GPGenerate {
public:
  GPGenerate(FunctionList* functions, int num_params);

  virtual Program** run(int pool_size, int type);
protected:
  FunctionList* functions;
  int num_params;
};


class GPGenerateRandom : public GPGenerate {
public:
  GPGenerateRandom(FunctionList* functions, int num_params, int max_depth);

  Program** run(int pool_size, int type);
private:
  int max_depth;
};

#endif
