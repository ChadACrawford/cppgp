#ifndef PROGRAM_H
#define PROGRAM_H

#include "types.h"


class Program {
public:
  Program(int num_params);
  ~Program();
  
  GPValue call(GPValue *params);
  // GPValue call_adf(int *args);

  double* get_fitness();
  void set_fitness(double fit);
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
  ProgramNode();
  
  virtual int type();
  virtual int* eval(ProgramRun* p);


  unsigned int get_num_children();
  ProgramNode* get_children();
  int get_child_type(int index);
  ProgramNode* set_child(int index, ProgramNode* child);
  ProgramNode* copy_shallow();
  ProgramNode* copy_deep();
};


class ProgramINode : public ProgramNode {
public:
  ProgramINode(Function* f);
  ~ProgramINode();

  int type();
  GPValue eval(ProgramRun* p);
  unsigned int get_num_children();
  ProgramNode* get_children();

  Function* get_f();

  ProgramNode* get_arg(int index);
  void set_arg(int index, ProgramNode* arg);

  ProgramNode* copy();
private:
  Function* f;
  ProgramNode* children;
};


class ProgramTNode: public ProgramNode {
public:
  ProgramTNode(ProgramRun* p, GPValue value);

  int type();
  GPValue eval(ProgramRun* p);
  unsigned int get_num_children();
  ProgramNode* get_children();

  ProgramNode* copy();
private:
  GPValue value;
};

class ProgramPNode: public ProgramNode {
public:
  ProgramPNode(int index);

  int type();
  GPValue eval(ProgramRun* p);
  unsigned int get_num_children();
  ProgramNode* get_children();

  ProgramNode* copy();
private:
  int param_index;
}
  
#endif
