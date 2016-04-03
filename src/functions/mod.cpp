#include "mod.h"
#include <math.h>

gpf_mod = new FunctionMod();

FunctionMod::FunctionMod() : Function(2, GPTYPE_REAL) {}

int FunctionMod::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue FunctionMod::evaluate(GPValue* args) {
  double arg1 = *((double*)(args[0]->value));
  double arg2 = *((double*)(args[1]->value));
  double *r = new double;
  *r = fmod(arg1, arg2);
  return GPValue(GPTYPE_REAL, r);
}
