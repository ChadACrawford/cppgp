#include "mul.h"

gpf_mul = new FractionMul(2);
FunctionMul::FunctionAdd(int num_args) : Function(num_args, GPTYPE_REAL) {}

int FunctionMul::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue FunctionMul::evaluate(GPValue* args) {
  double *total = new double;
  *total = 1;
  for(int i = 0; i < num_args; i++) {
    *total *= *((double*)args[i]->value);
  }
  return GPValue(GPTYPE_REAL, total);
}
