#include "mutate.h"

#include <cstdlib>

double rand_double() {
  return ((double) rand() / (RAND_MAX));
}

// GPMutate

GPMutate::GPMutate(Fitness* f, FunctionList* functions) :
  f(f),
  functions(functions)
{}

Program** GPMutate::mutate(Program** pool, int pool_size, int new_pool_size) {}

// GPMutateReplace

GPMutateReplace::GPMutateReplace(Fitness* f, FunctionList* functions, double p, int max_depth) :
  GPMutate(f, functions),
  p(p),
  max_depth(max_depth)
{}

ProgramNode* GPMutateReplace::mutate_tree(ProgramNode* tree, int max_depth) {
  if(rand_double() < p) {
    return random_tree(functions, tree->get_type(), max_depth);
  } else {
    ProgramNode* new_tree = tree->copy_shallow();
    for(int i = 0; i < new_tree->num_children(); i++) {
      new_tree->set_child(i, mutate_tree(tree->get_child(i), p, max_depth-1))
    }
    return new_tree;
  }
}

Program** GPMutateReplace::mutate(Program** pool, int pool_size) {
  Program** new_pool = new Program[pool_size];
  for(int i = 0; i < pool_size; i++) {
    Program* new_program = pool[i]->copy_shallow();
    ProgramNode* new_root = mutate_tree(pool->get_root(), max_depth);
    new_program->set_root(new_root);
    new_pool[i] = new_program;
  }
  return new_pool;
}
