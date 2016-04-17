#include "and.h"

FunctionAnd* gpf_and = new FunctionAnd(2);

FunctionAnd::FunctionAnd(int num_args) :
  Function("and", num_args, GPTYPE_BOOL)
{}

int FunctionAnd::get_arg_type(int index) {
  return GPTYPE_BOOL;
}

void FunctionAnd::print() {
  cout << "and";
}

GPValue* FunctionAnd::evaluate(ProgramRun* p, GPValue** args) {
  bool arg1 = ((GPVBool*)args[0])->value;
  bool arg2 = ((GPVBool*)args[1])->value;
  return new GPVBool(arg1 && arg2);
}
