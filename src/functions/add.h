#ifndef FUNCTION_ADD_H
#define FUNCTION_ADD_H

#include "../function.h"

class FunctionAdd: public Function {
public:
  FunctionAdd(int num_args);
  int get_arg_type(int index);
protected:
  GPValue evaluate(GPValue* args);
};

FunctionAdd* gpf_add;

#endif
