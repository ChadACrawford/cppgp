#include "mod.h"
#include <math.h>

FunctionMod::FunctionMod() {}

int FunctionMod::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue FunctionMod::evaluate(GPValue* args) {
  double arg1 = &((double*)(args[0]->value));
  double arg2 = &((double*)(args[1]->value));
  return GPValue(GPTYPE_REAL, fmod(arg1, arg2));
}
