#include "add.h"

gpf_add = new FractionAdd(2);
FunctionAdd::FunctionAdd(int num_args) : Function(num_args, GPTYPE_REAL) {}

int FunctionAdd::get_arg_type(int index) {
  return GPTYPE_REAL;
}

GPValue FunctionAdd::evaluate(GPValue* args) {
  double *total = new double;
  *total = 0;
  for(int i = 0; i < num_args; i++) {
    *total += *((double*)args[i]->value);
  }
  return GPValue(GPTYPE_REAL, total);
}
