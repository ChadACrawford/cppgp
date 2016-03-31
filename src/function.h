#ifndef FUNCTION_H
#define FUNCTION_H

#include "types.h"

class Function {
public:
  GPValue call(GPValue* args);
  bool validate(GPValue* args);

  // Getters
  int get_num_args();
  int get_type();
  virtual int get_arg_type(int index);
protected:
  int validate_arg_type(int index);
  Function(int num_args, int type);
  virtual GPValue evaluate(GPValue* args);
  const int num_args;
  const int type;
};

#endif
