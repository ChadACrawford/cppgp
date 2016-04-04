#ifndef FUNCTION_REAL_H
#define FUNCTION_REAL_H

#include "../function.h"

class FunctionReal {
public:
  FunctionReal(GPValue value);
  
  int get_arg_type(int index);
protected:
  GPValue evaluate(ProgramRun* p, GPValue* args);
private:
  GPValue value;
}

#endif
