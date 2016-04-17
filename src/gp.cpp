#include "gp.h"

#include <iostream>
using namespace std;

GP::GP(int pool_size, Fitness* fit, GPGenerate* generate, GPSelect* select, GPCross* cross, GPMutate* mutate) :
  pool_size(pool_size),
  fit(fit),
  generate(generate),
  select(select),
  cross(cross),
  mutate(mutate)
{
  elitism = true;
}

void GP::init() {
  pool = generate->run(pool_size, fit->get_type());
}

void GP::run(int num_generations) {
  init();
  for(int t = 0; t < num_generations; t++) {
    generation();
  }
}

void GP::generation() {
  Program* best_program = 0;
  if(elitism) {
    best_program = this->best_program()->copy();
  }

  // cout << "Selection\n";
  Program** new_pool = select->run(pool, pool_size, pool_size);
  pool = new_pool;
  // cout << "Crossover\n";
  new_pool = cross->run(pool, pool_size, pool_size);
  pool = new_pool;
  // cout << "Mutation\n";
  mutate->run(pool, pool_size);

  if(best_program) {
    delete pool[0];
    pool[0] = best_program;
  }
}

Program* GP::best_program() {
  Program* best_program = pool[0];
  for(int i = 1; i < pool_size; i++) {
    if(fit->evaluate(best_program) < fit->evaluate(pool[i])) {
      best_program = pool[i];
    }
  }
  return best_program;
}
