#include "program.h"

// Program

Program::Program(int num_params) :
  num_params(num_params)
{
  fitness_set = false;
}

Program::~Program() {
  delete[] root;
}

GPValue Program::call(GPValue* params) {
  this.params = params;
  return root->call();
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
  fitness = new double;
  *fitness = fit;
  
  fitness_set = true;
}

// ProgramRun

ProgramRun::ProgramRun(Program* p, GPValue* params) :
  p(p),
  params(params)
{}

GPValue ProgramRun::get_param(int index) {
  return *params[index];
}

// ProgramNode

ProgramNode::ProgramNode(Program* p) : p(p) {}

int ProgramNode::type() {}
int* ProgramNode::eval() {}
unsigned int ProgramNode::get_num_children() {}
ProgramNode* ProgramNode::get_children() {}

ProgramNode* ProgramNode::copy() {}

// ProgramINode

ProgramINode::ProgramINode(Program* p, Function* f) :
  ProgramNode(p),
  f(f)
{}

ProgramINode::~ProgramINode() {
  delete[] children;
}

int ProgramINode::type() {
  return f->get_type();
}

GPValue ProgramINode::eval() {
  GPValue* args = new GPValue[f->get_num_args()];
  for(int i = 0; i < f->get_num_args(); i++) {
    args[i] = f_args[i]->eval();
  }
  GPValue r = f->call(args);
  delete[] args;
  return r;
}

unsigned int ProgramINode::get_num_children() {
  return f->get_num_args();
}

ProgramNode* ProgramINode::get_children() {
  return children;
}

Function* ProgramINode::get_f() {
  return f;
}

ProgramNode* ProgramINode::get_arg(int index) {
  return f_args[i];
}

void ProgramINode::set_child(int index, ProgramNode* child) {
  children[i] = child;
}

ProgramNode* ProgramINode::copy() {
  ProgramINode* pn = new ProgramINode(f);
  for(int i = 0; i < get_num_children(); i++) {
    pn->set_arg(i, children[i]->copy());
  }
  return pn;
}

// ProgramTNode

ProgramTNode::ProgramTNode(Program* p, GPValue value) :
  ProgramNode(p),
  value(value)
{}

int ProgramTNode::type() {
  return value.type;
}

GPValue ProgramTNode::eval() {
  return value;
}

unsigned int ProgramTNode::get_num_children() {
  return 0;
}

ProgramNode* ProgramTNode::get_children() {
  return 0;
}

// ProgramPNode

ProgramPNode::ProgramPNode(Program* p, int index) :
  ProgramNode(p),
  param_index(index)
{}

int ProgramPNode::type() {
  return p->get_param(param_index)->type;
}

GPValue ProgramPNode::eval() {
  return &(p->get_param(param_index));
}

unsigned int ProgramTNode::get_num_children() {
  return 0;
}

ProgramNode* ProgramTNode::get_children() {
  return 0;
}
