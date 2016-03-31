#ifndef PROGRAM_H
#define PROGRAM_H

#include "types.h"

class Program {
public:
  GPValue call(int *args);
  GPValue call_adf(int *args);
private:
  
}

#endif
