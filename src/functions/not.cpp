#include "not.h"

FunctionNot* gpf_not = new FunctionNot();

FunctionNot::FunctionNot() :
  Function("not", 1, GPTYPE_BOOL)
{}

int FunctionNot::get_arg_type(int index) {
  return GPTYPE_BOOL;
}

void FunctionNot::print() {
  cout << "not";
}

GPValue* FunctionNot::evaluate(ProgramRun* p, GPValue** args) {
  bool arg1 = ((GPVBool*)args[0])->value;
  return new GPVBool(!arg1);
}
