#ifndef FUNCTION_MOD_H
#define FUNCTION_MOD_H

#include "../types.h"
#include "../function.h"

class FunctionMod : public Function {
public:
  FunctionMod();
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
};

extern FunctionMod* gpf_mod;

#endif
