#ifndef FUNCTION_SUB_H
#define FUNCTION_SUB_H

#include "../function.h"

class FunctionSubtract : public Function {
public:
  FunctionSubtract();
protected:
  bool validate(GPValue *args);
  GPValue evaluate(GPValue *args);
};
FunctionSubtract *gpf_sub;

#endif
