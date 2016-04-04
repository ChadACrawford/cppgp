#include "real.h"

FunctionReal::FunctionReal(GPValue value) : value(value) {}

int FunctionReal::get_arg_type(int index) {
  return GPTYPE_ERR;
}

GPValue FunctionReal::evaluate(ProgramRun* p, GPValue* args) {
  return value;
}
