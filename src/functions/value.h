#ifndef FUNCTION_CONSTANT_H
#define FUNCTION_CONSTANT_H

#include "../function.h"

class FunctionValue : public Function {
public:
  FunctionValue(GPValue* value);
  
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
private:
  GPValue* value;
};

#endif
