#include "function.h"


Function::Function(int num_args, int type) :
  num_args(num_args),
  type(type)
{}

GPValue Function::call(GPValue* args) {
  if(validate(args))
    return evaluate(args);
  else
    return GPValue(GPTYPE_ERROR, "Invalid type supplied to function");
}

bool Function::validate(GPValue* args) {
  for(int i = 0; i < num_args; i++) {
    if(!validate_arg_type( i, args[i] ))
      return false;
  }
  return true;
}

int Function::get_num_args() {
  return num_args;
}

int Function::get_type() {
  return type;
}

bool validate_arg_type(int index, GPValue* arg) {
  return get_arg_type( index ) == arg->type;
}

// FunctionList

FunctionList::FunctionList() {
  functions = new vector<Function>[50];
  for(int i = 0; i < GP_NUM_TYPES; i++) {
    functions[i] = new vector<Function>();
  }
}

void FunctionList::add_function(Function f) {
  functions[f->get_type()].push_back(f);
}

vector<Function>* FunctionList::get_functions(int type) {
  return functions[type];
}
