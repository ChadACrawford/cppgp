#ifndef PROGRAM_RUN_H
#define PROGRAM_RUN_H

#include "types.h"
class Program;

class ProgramRun {
public:
  ProgramRun(Program* p, GPValue** params);
  ~ProgramRun();

  GPValue* get_param(int index);
private:
  Program* p;
  GPValue** params;
};

#endif
