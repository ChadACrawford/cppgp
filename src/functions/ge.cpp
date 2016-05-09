#include "leq.h"

FunctionGE* gpf_ge = new FunctionGE();

FunctionGE::FunctionGE() :
  Function("ge", 2, GPTYPE_BOOL)
{}

int FunctionGE::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue* FunctionGE::evaluate(ProgramRun* p, GPValue** args) {
  double arg1 = ((GPVReal*)args[0]).value;
  double arg2 = ((GPVReal*)args[1]).value;
  return new GPVBool(arg1 > arg2);
}
