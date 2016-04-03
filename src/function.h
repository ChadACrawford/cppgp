#ifndef FUNCTION_H
#define FUNCTION_H

#include "types.h"

class Function {
public:
  GPValue call(GPValue* args);
  bool validate(GPValue* args);

  // Getters
  unsigned int get_num_args();
  int get_type();
  virtual int get_arg_type(int index);
protected:
  bool validate_arg_type(int index, GPValue* arg);
  Function(unsigned int num_args, int type);
  virtual GPValue evaluate(GPValue* args);
  const unsigned int num_args;
  const int type;
};

#endif
