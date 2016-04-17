#ifndef FUNCTION_AND_H
#define FUNCTION_AND_H

#include "../function.h"

class FunctionAnd: public Function {
public:
  FunctionAnd(int num_args);
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionAnd* gpf_and;

#endif
