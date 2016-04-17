#include "add.h"

FunctionAdd* gpf_add = new FunctionAdd(2);
FunctionAdd::FunctionAdd(int num_args) : Function("add", num_args, GPTYPE_REAL) {}

int FunctionAdd::get_arg_type(int index) {
  return GPTYPE_REAL;
}

void FunctionAdd::print() {
  cout << "add";
}

GPValue* FunctionAdd::evaluate(ProgramRun* p, GPValue** args) {
  double total = 0;
  for(int i = 0; i < num_args; i++) {
    total += ((GPVReal*)args[i])->value;
  }
  return new GPVReal(total);
}
