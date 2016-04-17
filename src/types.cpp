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
    clone = new GPVCategory(((GPVCategory*)this)->value, ((GPVCategory*)this)->model);
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

GPVCategoryModel::GPVCategoryModel(std::string name) :
  name(name)
{
  classes = vector<string>();
}

int GPVCategoryModel::size() {
  return classes.size();
}

std::string GPVCategoryModel::get_name() {\
  return name;
}

std::string GPVCategoryModel::get_class_name(int value) {
  return classes[value];
}

GPVCategory::GPVCategory(int value, GPVCategoryModel* model) :
  GPValue(GPTYPE_CATEGORY),
  value(value),
  model(model)
{}

std::string GPVCategory::class_name() {
  return model->get_class_name(value);
}
