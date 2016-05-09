#include "eq.h"

FunctionEQ* gpf_eq = new FunctionEQ();

FunctionEQ::FunctionEQ() :
  Function("ge", 2, GPTYPE_BOOL)
{}

int FunctionEQ::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue* FunctionEQ::evaluate(ProgramRun* p, GPValue** args) {
  double arg1 = ((GPVReal*)args[0])->value;
  double arg2 = ((GPVReal*)args[1])->value;
  return new GPVBool(arg1 == arg2);
}
