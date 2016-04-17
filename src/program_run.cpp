#include "program_run.h"

ProgramRun::ProgramRun(Program* p, GPValue** params) :
  p(p),
  params(params)
{}

ProgramRun::~ProgramRun() {
}

GPValue* ProgramRun::get_param(int index) {
  return params[index];
}
