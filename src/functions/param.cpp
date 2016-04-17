#include "param.h"

FunctionParam::FunctionParam(int param_index, int param_type) :
  Function("param", 0, param_type),
  param_index(param_index)
{}

int FunctionParam::get_arg_type(int index) {
  return GPTYPE_ERR;
}

void FunctionParam::print() {
  cout << "param(" << param_index << ", type=" << get_type() << ")";
}

GPValue* FunctionParam::evaluate(ProgramRun* p, GPValue** args) {
  return p->get_param(param_index)->copy();
}
