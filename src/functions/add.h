#ifndef FUNCTION_ADD_H
#define FUNCTION_ADD_H

#include "../function.h"

class FunctionAdd: public Function {
public:
  FunctionAdd(int num_args);
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionAdd* gpf_add;

#endif
