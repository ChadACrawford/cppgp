#include "program.h"

// Program

Program::Program(int num_params) :
  num_params(num_params)
{
  root = 0;
  fitness_set = false;
}

Program::Program(int num_params, ProgramNode* root) :
  num_params(num_params),
  root(root)
{
  fitness_set = false;
}

Program::~Program() {
  delete root;
}

GPValue* Program::call(GPValue** params) {
  ProgramRun* r = new ProgramRun(this, params);
  GPValue* result = root->call(r);
  delete r;
  return result;
}

void Program::print() {
  root->print(1);
}

int Program::get_num_params() {
  return num_params;
}

double* Program::get_fitness() {
  if(fitness_set) {
    return &fitness;
  }
  else {
    return 0;
  }
}

void Program::set_fitness(double fit) {
  fitness = fit;
  fitness_set = true;
}

ProgramNode* Program::get_root() {
  return root;
}

void Program::set_root(ProgramNode* root) {
  fitness_set = false;
  this->root = root;
}

Program* Program::copy_shallow() {
  Program* p = new Program(num_params);
  return p;
}

Program* Program::copy() {
  Program* p = new Program(num_params);
  p->fitness = fitness;
  p->fitness_set = fitness_set;
  p->root = root->copy_deep();
  return p;
}
