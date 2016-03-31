#ifndef FUNCTION_DIV_H
#define FUNCTION_DIV_H

#include "../function.h"

class FunctionDiv : public Function {
public:
  FunctionDiv();
protected:
  GPValue evaluate(GPValue* args);
};

FunctionDiv* gpf_div;

#endif
