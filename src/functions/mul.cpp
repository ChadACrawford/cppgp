#include "mul.h"

FunctionMultiply* gpf_mul = new FunctionMultiply(2);
FunctionMultiply::FunctionMultiply(int num_args) : Function("mul", num_args, GPTYPE_REAL) {}

int FunctionMultiply::get_arg_type(int index) {
  return GPTYPE_REAL;
}

void FunctionMultiply::print() {
  cout << "mul";
}

GPValue* FunctionMultiply::evaluate(ProgramRun* p, GPValue** args) {
  double total = 1;
  for(int i = 0; i < num_args; i++) {
    total *= ((GPVReal*)args[i])->value;
  }
  return new GPVReal(total);
}
