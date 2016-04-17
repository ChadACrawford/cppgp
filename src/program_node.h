#ifndef PROGRAM_NODE_H
#define PROGRAM_NODE_H

class Program;

#include <iostream>
using namespace std;

#include "function.h"

class ProgramNode {
public:
  ProgramNode(Function* f);
  ~ProgramNode();
  
  GPValue* call(ProgramRun* p);

  Function* get_f();

  void print(int indent);
  
  unsigned long get_id();
  int get_type();
  unsigned int get_num_children();
  ProgramNode** get_children();
  int get_child_type(int index);
  bool is_leaf();
  ProgramNode* get_child(int index);
  void set_child(int index, ProgramNode* child);
  ProgramNode* copy_shallow();
  ProgramNode* copy_deep();
private:
  static unsigned long id_count;
  unsigned long id;
  Function* f;
  ProgramNode** children;
};

#endif
