#ifndef FUNCTION_NOT_H
#define FUNCTION_NOT_H

#include "../function.h"

class FunctionNot: public Function {
public:
  FunctionNot();
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionNot* gpf_not;

#endif
