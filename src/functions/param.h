#ifndef FUNCTION_PARAM_H
#define FUNCTION_PARAM_H

#include "../function.h"

class FunctionParam : public Function {
public:
  FunctionParam(int param_index, int param_type);
  
  int get_arg_type(int index);
  void print();
protected:
  GPValue* evaluate(ProgramRun* p, GPValue** args);
private:
  int param_index;
};

#endif
