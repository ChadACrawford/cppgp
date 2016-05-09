#ifndef FUNCTION_H
#define FUNCTION_H

#include "program_run.h"
#include "types.h"

#include <vector>
#include <iostream>
using namespace std;

class Function {
public:
  GPValue* call(ProgramRun* p, GPValue** args);
  bool validate(GPValue** args);

  void print();
  
  // Getters
  unsigned int get_num_args();
  int get_type();
  virtual int get_arg_type(int index);
protected:
  bool validate_arg_type(int index, GPValue* arg);
  Function(const char* name, unsigned int num_args, int type);
  virtual GPValue* evaluate(ProgramRun* p, GPValue** args);
  const char* name;
  const unsigned int num_args;
  const int type;
};


class FunctionList {
public:
  FunctionList();

  void add_function(Function* f);

  vector<Function*>* get_functions(int type);
  vector<Function*>* get_terminals(int type);
private:
  vector<Function*> functions[GP_NUM_TYPES];
  vector<Function*> terminals[GP_NUM_TYPES];
};

#include "functions/add.h"
#include "functions/sub.h"
#include "functions/mul.h"
#include "functions/div.h"
#include "functions/mod.h"
#include "functions/param.h"
#include "functions/value.h"
#include "functions/and.h"
#include "functions/or.h"
#include "functions/not.h"
#include "functions/geq.h"
#include "functions/ge.h"

#endif
