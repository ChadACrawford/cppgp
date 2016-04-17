#include "program_node.h"

#include <iostream>
using namespace std;

unsigned long ProgramNode::id_count = 0;

ProgramNode::ProgramNode(Function* f) :
  f(f)
{
  if( !f ) throw(200);
  id = id_count++;
  children = new ProgramNode*[get_num_children()];
}

ProgramNode::~ProgramNode() {
  for(int i = 0; i < get_num_children(); i++) {
    delete children[i];
  }
  // if( get_num_children() ) {
  //   delete[] children;
  // }
}

GPValue* ProgramNode::call(ProgramRun* p) {
  GPValue** args = new GPValue*[f->get_num_args()];
  for(int i = 0; i < f->get_num_args(); i++) {
    args[i] = children[i]->call(p);
  }
  GPValue* r = f->call(p, args);
  for(int i = 0; i < f->get_num_args(); i++) {
    delete args[i];
  }
  delete[] args;
  return r;
}

Function* ProgramNode::get_f() {
  return f;
}

void indent(int count) {
  for(int i = 0; i < count; i++) {
    cout << " ";
  }
}

void ProgramNode::print(int ind) {
  indent(ind);
  cout << "[ ";
  f->print();
  if( get_num_children() > 0 ) cout << "\n";
  for(int i = 0; i < get_num_children(); i++) {
    children[i]->print(ind+1);
  }
  if( get_num_children() > 0 ) indent(ind);
  cout << "]" << "\n";
}

unsigned long ProgramNode::get_id() {
  return id;
}

int ProgramNode::get_type() {
  return f->get_type();
}

unsigned int ProgramNode::get_num_children() {
  return f->get_num_args();
}

ProgramNode** ProgramNode::get_children() {
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
  ProgramNode* pn = new ProgramNode(f);
  return pn;
}

ProgramNode* ProgramNode::copy_deep() {
  ProgramNode* pn = copy_shallow();
  for(int i = 0; i < get_num_children(); i++) {
    pn->set_child(i, children[i]->copy_deep());
  }
  return pn;
}
