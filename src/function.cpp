#include "function.h"


Function::Function(const char* name, unsigned int num_args, int type) :
  name(name),
  num_args(num_args),
  type(type)
{}

GPValue* Function::call(ProgramRun* p, GPValue** args) {
  if(validate(args))
    return evaluate(p, args);
  else
    return new GPVErr("Invalid type supplied to function");
}

bool Function::validate(GPValue** args) {
  for(int i = 0; i < num_args; i++) {
    if(!validate_arg_type( i, args[i] ))
      return false;
  }
  return true;
}

void Function::print() {}

unsigned int Function::get_num_args() {
  return num_args;
}

int Function::get_type() {
  return type;
}

int Function::get_arg_type(int index) {}

bool Function::validate_arg_type(int index, GPValue* arg) {
  return get_arg_type( index ) == arg->type;
}

GPValue* Function::evaluate(ProgramRun* p, GPValue** args) {}

// FunctionList

FunctionList::FunctionList() {
  // functions = vector<Function*>()[GP_NUM_TYPES];
  // terminals = vector<Function*>()[GP_NUM_TYPES];
  for(int i = 0; i < GP_NUM_TYPES; i++) {
    functions[i] = vector<Function*>();
    terminals[i] = vector<Function*>();
  }
}

void FunctionList::add_function(Function* f) {
  functions[f->get_type()].push_back(f);
  if( f->get_num_args() == 0 ) {
    terminals[f->get_type()].push_back(f);
  }
}

vector<Function*>* FunctionList::get_functions(int type) {
  return &functions[type];
}

vector<Function*>* FunctionList::get_terminals(int type) {
  return &terminals[type];
}
