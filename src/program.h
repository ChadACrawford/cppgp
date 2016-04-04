#ifndef PROGRAM_H
#define PROGRAM_H

#include "types.h"


class Program {
public:
  Program(int num_params);
  Program(int num_params, ProgramNode* root);
  ~Program();
  
  GPValue call(GPValue *params);
  // GPValue call_adf(int *args);

  int get_num_params();
  
  double* get_fitness();
  void set_fitness(double fit);

  ProgramNode* get_root();
  void set_root(ProgramNode* root);

  Program* copy_shallow();
  Program* copy();
private:
  ProgramNode* root;
  int num_params;
  bool fitness_set;
  double fitness;
};


class ProgramRun {
public:
  ProgramRun(Program* p, GPValue* params);
  
  GPValue get_param(int index);
private:
  Program* p;
  GPValue* params;
}


class ProgramNode {
public:
  ProgramNode(Function* f);
  ~ProgramNode();
  
  int* eval(ProgramRun* p);

  Function* get_f();

  unsigned int get_id();
  int get_type();
  unsigned int get_num_children();
  ProgramNode* get_children();
  int get_child_type(int index);
  bool is_leaf();
  ProgramNode* get_child(int index);
  void set_child(int index, ProgramNode* child);
  ProgramNode* copy_shallow();
  ProgramNode* copy_deep();
private:
  static unsigned int id_count = 0;
  unsigned int id;
  Function* f;
  ProgramNode* children;
};

  
#endif
