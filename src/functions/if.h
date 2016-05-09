#ifndef FUNCTION_IF_H
#define FUNCTION_IF_H

#include "../function.h"

class FunctionIf: public Function {
public:
  FunctionIf(int type);
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionIf* gpf_if;

#endif
