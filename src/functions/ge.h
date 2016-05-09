#ifndef FUNCTION_GE_H
#define FUNCTION_GE_H

#include "../function.h"

class FunctionGE: public Function {
public:
  FunctionGE(int type);
  int get_arg_type(int index);
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionGE* gpf_ge;

#endif
