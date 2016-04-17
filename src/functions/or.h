#ifndef FUNCTION_OR_H
#define FUNCTION_OR_H

#include "../function.h"

class FunctionOr: public Function {
public:
  FunctionOr(int num_args);
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionOr* gpf_or;

#endif
