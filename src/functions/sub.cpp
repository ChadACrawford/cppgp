#include "sub.h"

FunctionSubtract* gpf_sub = new FunctionSubtract();

FunctionSubtract::FunctionSubtract() : Function("sub", 2, GPTYPE_REAL) {}

int FunctionSubtract::get_arg_type(int index) {
  return GPTYPE_REAL;
}

void FunctionSubtract::print() {
  cout << "sub";
}

GPValue* FunctionSubtract::evaluate(ProgramRun* p, GPValue** args) {
  double arg1 = ((GPVReal*)args[0])->value;
  double arg2 = ((GPVReal*)args[1])->value;
  double total = arg1 - arg2;
  return new GPVReal(total);
}
