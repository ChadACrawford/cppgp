#include "or.h"

FunctionOr* gpf_or = new FunctionOr(2);

FunctionOr::FunctionOr(int num_args) :
  Function("or", num_args, GPTYPE_BOOL)
{}

int FunctionOr::get_arg_type(int index) {
  return GPTYPE_BOOL;
}

void FunctionOr::print() {
  cout << "and";
}

GPValue* FunctionOr::evaluate(ProgramRun* p, GPValue** args) {
  bool arg1 = ((GPVBool*)args[0])->value;
  bool arg2 = ((GPVBool*)args[1])->value;
  return new GPVBool(arg1 || arg2);
}
