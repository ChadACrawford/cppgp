#include "div.h"

FunctionDiv* gpf_div = new FunctionDiv();

FunctionDiv::FunctionDiv() : Function("div", 2, GPTYPE_REAL) {}

int FunctionDiv::get_arg_type(int index) {
  return GPTYPE_REAL;
}

void FunctionDiv::print() {
  cout << "div";
}

GPValue* FunctionDiv::evaluate(ProgramRun* p, GPValue** args) {
  double arg1 = ((GPVReal*)args[0])->value;
  double arg2 = ((GPVReal*)args[1])->value;
  double r;
  if(arg2 != 0) {
    r = arg1 / arg2;
  }
  else {
    r = 0;
  }
  return new GPVReal(r);
}
