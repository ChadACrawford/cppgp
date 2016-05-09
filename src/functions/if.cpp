#include "if.h"

FunctionIf* gpf_if = new FunctionIf();

FunctionIf::FunctionIf(int type) :
  Function("if", 3, type)
{}

int FunctionIf::get_arg_type(int index) {
  if(index == 0) {
    return GPTYPE_BOOL;
  }
  else if(index == 1 || index == 2) {
    return get_type();
  }
}

void FunctionIf::print() {
  cout << "if";
}

GPValue* FunctionIf::evaluate(ProgramRun* p, GPValue** args) {
  bool condition = ((GPVBool*)args[0])->value;
  return condition ? args[1] : args[2];
}
