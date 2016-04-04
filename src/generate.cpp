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
