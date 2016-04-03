#ifndef FUNCTION_MOD_H
#define FUNCTION_MOD_H

#include "../types.h"
#include "../functions.h"

class FunctionMod : public Function {
public:
  FunctionMod();
  int get_arg_type(int index);
protected:
  GPValue evaluate(GPValue* args);
};

FunctionMod* gpf_mod;

#endif
