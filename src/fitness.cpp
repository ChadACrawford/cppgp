#include "fitness.h"

Fitness::Fitness(int type) : type(type) {}

double Fitness::evaluate(Program* p) {
  if( !p->get_fitness() ) {
    double f = calculate(p);
    p->set_fitness(f);
  }
  return *p->get_fitness();
}

double Fitness::calculate(Program* p) {}

int Fitness::get_type() {
  return type;
}
