#ifndef FUNCTION_GEQ_H
#define FUNCTION_GEQ_H

#include "../function.h"

class FunctionGEQ: public Function {
public:
  FunctionGEQ(int type);
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionGEQ* gpf_geq;

#endif
