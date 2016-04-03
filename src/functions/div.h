#ifndef FUNCTION_DIV_H
#define FUNCTION_DIV_H

#include "../function.h"
#include "../types.h"

class FunctionDiv : public Function {
public:
  FunctionDiv() : Function(2, GPTYPE_REAL);
  int get_arg_type(int index);
protected:
  GPValue evaluate(GPValue* args);
};

FunctionDiv* gpf_div;

#endif
