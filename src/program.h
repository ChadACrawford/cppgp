#ifndef PROGRAM_H
#define PROGRAM_H

#include "types.h"
#include "program_run.h"
#include "program_node.h"

class Program {
public:
  Program(int num_params);
  Program(int num_params, ProgramNode* root);
  ~Program();
  
  GPValue* call(GPValue** params);
  // GPValue call_adf(int index, int *args);

  void print();
  
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


  
#endif
