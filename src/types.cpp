#include "types.h"


GPValue::GPValue(int type, int* value) :
  type(type),
  value(value)
{}

GPValue::~GPValue() {
  switch(type) {
  case GPTYPE_ERR:
    delete[] (char*)value;
    break;
  case GPTYPE_INT:
    delete[] (int*)value;
    break;
  case GPTYPE_REAL:
    delete[] (double*)value;
    break;
  case GPTYPE_BOOL:
    delete[] (bool*)value; 
    break;
  default:
    delete[] value;
    break;
  }
}
