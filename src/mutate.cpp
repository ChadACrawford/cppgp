#include "mutate.h"
#include "generate.h"
#include "random.h"

#include <cstdlib>

// GPMutate

GPMutate::GPMutate(Fitness* f, FunctionList* functions) :
  f(f),
  functions(functions)
{}

Program** GPMutate::run(Program** pool, int pool_size) {}

// GPMutateReplace

GPMutateReplace::GPMutateReplace(Fitness* f, FunctionList* functions, int max_depth, double p) :
  GPMutate(f, functions),
  p(p),
  max_depth(max_depth)
{}

ProgramNode* GPMutateReplace::mutate_tree(ProgramNode* tree, int max_depth) {
  if(rand_double() < p) {
    return random_tree(functions, tree->get_type(), max_depth);
  } else {
    ProgramNode* new_tree = tree->copy_shallow();
    for(int i = 0; i < new_tree->get_num_children(); i++) {
      new_tree->set_child(i, mutate_tree(tree->get_child(i), max_depth-1));
    }
    return new_tree;
  }
}

Program** GPMutateReplace::run(Program** pool, int pool_size) {
  // Program** new_pool = new Program*[pool_size];
  for(int i = 0; i < pool_size; i++) {
    // Program* new_program = pool[i]->copy_shallow();
    ProgramNode* old_root = pool[i]->get_root();
    ProgramNode* new_root = mutate_tree(pool[i]->get_root(), max_depth);
    pool[i]->set_root(new_root);
    delete old_root;
    // pool[i]->print();
    // new_pool[i] = pool[i];
  }
  return pool;
}
