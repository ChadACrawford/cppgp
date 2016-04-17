#include "mod.h"
#include <math.h>

FunctionMod* gpf_mod = new FunctionMod();

FunctionMod::FunctionMod() : Function("mod", 2, GPTYPE_REAL) {}

int FunctionMod::get_arg_type(int index) {
  return GPTYPE_REAL;
}

void FunctionMod::print() {
  cout << "mod";
}

GPValue* FunctionMod::evaluate(ProgramRun* p, GPValue** args) {
  double arg1 = ((GPVReal*)args[0])->value;
  double arg2 = ((GPVReal*)args[1])->value;
  double r;
  if(arg2 != 0) {
    r = fmod(arg1, arg2);
  }
  else {
    r = 0;
  }
  return new GPVReal(r);
}
