#ifndef FUNCTION_H
#define FUNCTION_H

#include "program.h"
#include "types.h"

#include <vector>
using namespace std;

class Function {
public:
  GPValue call(ProgramRun* p, GPValue* args);
  bool validate(GPValue* args);

  // Getters
  unsigned int get_num_args();
  int get_type();
  virtual int get_arg_type(int index);
protected:
  bool validate_arg_type(int index, GPValue* arg);
  Function(unsigned int num_args, int type);
  virtual GPValue evaluate(ProgramRun* p, GPValue* args);
  const unsigned int num_args;
  const int type;
};


class FunctionList {
public:
  FunctionList();

  void add_function(Function f);

  vector<Function*>* get_functions(int type);
  vector<Function*>* get_terminal(int type);
private:
  vector<Function*>[GP_NUM_TYPES] functions;
  vector<Function*>[GP_NUM_TYPES] terminal;
};

#endif
