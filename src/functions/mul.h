#ifndef FUNCTION_MUL_H
#define FUNCTION_MUL_H

#include "../function.h"

class FunctionMultiply : public Function {
public:
  FunctionMultiply(int num_args);
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};
extern FunctionMultiply *gpf_mul;

#endif
