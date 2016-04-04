#include "generate.h"

#include <cstdlib>

ProgramNode* random_tree(FunctionList* functions, int type, int max_depth) {
  vector<Function*>* fs;
  if(max_depth == 0) {
    fs = functions->get_functions(type);
  }
  else {
    fs = functions->get_terminal(type);
  }
  Function* f = fs->at(rand() % fs->size());
  ProgramNode* p = new ProgramNode(f);
  for(int i = 0; i < p->get_num_children(); i++) {
    p->set_child(i, random_tree(functions, p->get_child_type(i), max_depth-1));
  }
  return p;
}

// GPGenerate

GPGenerate::GPGenerate(FunctionList* functions, int num_params) :
  functions(functions),
  num_params(num_params)
{}

Program* GPGenerate::generate(int pool_size, int type) {}

// GPGenerateRandom

GPGenerateRandom::GPGenerateRandom(FunctionList* functions, int num_params, int max_depth) :
  GPGenerate(functions, num_params),
  max_depth(max_depth)
{}

GPGenerateRandom::generate(int pool_size, int type) {
  Program** new_pool = new Program*[pool_size];
  for(int i = 0; i < pool_size; i++) {
    ProgramNode* root = random_tree(functions, type, max_depth);
    Program* p = new Program(num_params, root);
    new_pool[i] = p;
  }
  return new_pool;
}
