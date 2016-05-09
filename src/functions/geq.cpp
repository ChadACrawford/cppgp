#include "geq.h"

FunctionGEQ* gpf_geq = new FunctionGEQ();

FunctionGEQ::FunctionGEQ() :
  Function("geq", 2, GPTYPE_BOOL)
{}

int FunctionGEQ::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue* FunctionGEQ::evaluate(ProgramRun* p, GPValue** args) {
  double arg1 = ((GPVReal*)args[0]).value;
  double arg2 = ((GPVReal*)args[1]).value;
  return new GPVBool(arg1 >= arg2);
}
