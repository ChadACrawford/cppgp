#ifndef FUNCTION_DIV_H
#define FUNCTION_DIV_H

#include "../function.h"
#include "../types.h"

class FunctionDiv : public Function {
public:
  FunctionDiv();
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionDiv* gpf_div;

#endif
