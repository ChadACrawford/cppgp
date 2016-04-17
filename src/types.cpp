#include "types.h"

#include <iostream>
using namespace std;

GPValue::GPValue(int type) :
  type(type)
{}

GPValue* GPValue::copy() {
  GPValue* clone;
  switch(type) {
  case GPTYPE_ERR:
    clone = new GPVErr(((GPVErr*)this)->message);
    break;
  case GPTYPE_INT:
    clone = new GPVInt(((GPVInt*)this)->value);
    break;
  case GPTYPE_REAL:
    clone = new GPVReal(((GPVReal*)this)->value);
    break;
  case GPTYPE_BOOL:
    clone = new GPVBool(((GPVBool*)this)->value);
    break;
  case GPTYPE_CATEGORY:
    clone = new GPVCategory(((GPVCategory*)this)->value, ((GPVCategory*)this)->num_categories);
    break;
  default:
    clone = 0;
  }
  return clone;
}

GPVErr::GPVErr(const char* message) :
  GPValue(GPTYPE_ERR),
  message(message)
{}

GPVInt::GPVInt(int value) :
  GPValue(GPTYPE_INT),
  value(value)
{}

GPVReal::GPVReal(double value) :
  GPValue(GPTYPE_REAL),
  value(value)
{}

GPVBool::GPVBool(bool value) :
  GPValue(GPTYPE_BOOL),
  value(value)
{}

GPVCategory::GPVCategory(int value, int num_categories) :
  GPValue(GPTYPE_CATEGORY),
  value(value),
  num_categories(num_categories)
{}
