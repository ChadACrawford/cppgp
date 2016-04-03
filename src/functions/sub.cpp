#include "sub.h"

gpf_sub = new FunctionSub();

FunctionSub::FunctionSub() : Function(2, GPTYPE_REAL) {}

int FunctionSub::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue FunctionSub::evaluate(GPValue* args) {
  double *total = new double;
  double arg1 = *((double*) args[0]->value);
  double arg2 = *((double*) args[1]->value);
  *total = arg1 - arg2;
  return GPValue(GPTYPE_REAL, total);
}

