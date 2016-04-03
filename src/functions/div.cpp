#include "div.h"

FunctionDiv::FunctionDiv() {}

int FunctionDiv::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue FunctionDiv::evaluate(GPValue* args) {
  double arg1 = &((double*)(args[0]->value));
  double arg2 = &((double*)(args[1]->value));
  double* r = new double;
  *r = arg1 / arg2;
  return GPValue(GPTYPE_REAL, &r);
}
