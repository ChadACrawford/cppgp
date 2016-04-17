#ifndef FUNCTION_SUB_H
#define FUNCTION_SUB_H

#include "../function.h"

class FunctionSubtract : public Function {
public:
  FunctionSubtract();
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionSubtract* gpf_sub;

#endif
