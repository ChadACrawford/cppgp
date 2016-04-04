#ifndef MUTATE_H
#define MUTATE_H

class GPMutate {
public:
  GPMutate(Fitness* f, FunctionList* functions);

  virtual Program** mutate(Program** pool, int pool_size, int new_pool_size);
private:
  Fitness* f;
  FunctionList* functions;
};

class GPMutateReplace {
public:
  GPMutateReplace(Fitness* f, FunctionList* functions, double p, int max_depth);

  Program** mutate(Program** pool, int pool_size, int new_pool_size);
private:
  int max_depth;
  ProgramNode* mutate_tree(ProgramNode* tree, double p, int level, int max_depth);
}

#endif
