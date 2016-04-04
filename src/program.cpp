#include "program.h"

// Program

Program::Program(int num_params) :
  num_params(num_params)
{
  fitness_set = false;
}

Program::Program(int num_params, ProgramNode* root) :
  num_params(num_params),
  root(root)
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

// ProgramRun

ProgramRun::ProgramRun(Program* p, GPValue* params) :
  p(p),
  params(params)
{}

GPValue ProgramRun::get_param(int index) {
  return *params[index];
}

// ProgramNode

ProgramNode::ProgramNode(Function* f) :
  f(f) {}

ProgramNode::~ProgramNode() {
  delete[] children;
}

int* ProgramNode::eval(ProgramRun* p) {
  GPValue* args = new GPValue[f->get_num_args()];
  for(int i = 0; i < f->get_num_args(); i++) {
    args[i] = f_args[i]->eval();
  }
  GPValue r = f->call(p, args);
  delete[] args;
  return r;
}

int ProgramNode::get_type() {
  return f->get_type();
}
unsigned int ProgramNode::get_num_children() {
  return f->get_num_args();
}
ProgramNode* ProgramNode::get_children() {
  return children;
}
int ProgramNode::get_child_type(int index) {
  return f->get_arg_type(index);
}
ProgramNode* ProgramNode::get_child(int index) {
  return children[index];
}
void ProgramNode::set_child(int index, ProgramNode* child) {
  children[index] = child;
}
ProgramNode* ProgramNode::copy_shallow() {
  ProgramINode* pn = new ProgramINode(f);
  return pn;  
}
ProgramNode* ProgramNode::copy_deep() 
  ProgramINode* pn = copy_shallow();
  for(int i = 0; i < get_num_children(); i++) {
    pn->set_arg(i, children[i]->copy());
  }
  return pn;
}
