#include "value.h"

FunctionValue::FunctionValue(GPValue* value) :
  Function("value", 0, value->type),
  value(value)
{}

int FunctionValue::get_arg_type(int index) {
  return GPTYPE_ERR;
}

void FunctionValue::print() {
  switch(value->type) {
  case GPTYPE_ERR:
    cout << "err";
    break;
  case GPTYPE_INT:
    cout << "int(" << ((GPVInt*)value)->value << ")";
    break;
  case GPTYPE_REAL:
    cout << "real(" << ((GPVReal*)value)->value << ")";
    break;
  case GPTYPE_BOOL:
    cout << "bool(" << ((GPVBool*)value)->value << ")";
    break;
  case GPTYPE_CATEGORY:
    cout << "cat(" << ((GPVCategory*)value)->value << "/" << ((GPVCategory*)value)->num_categories << ")";
  default:
    cout << "value(type=" << value->type << ")";
  }
}

GPValue* FunctionValue::evaluate(ProgramRun* p, GPValue** args) {
  return value->copy();
}
