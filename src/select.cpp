#include "select.h"

#include <cstdlib>

double rand_double() {
  return ((double) rand() / (RAND_MAX));
}

// GPSelect

GPSelect::GPSelect(Fitness* f) : f(f) {}

Program* GPSelect::select(Program* pool, int pool_size, int new_pool_size) {}

// GPSelectTournament

GPSelectTournement::GPSelectTournament(Fitness* f, double p) :
  GPSelect(f),
  p(p)
{}

Program* GPSelectTournament::select(Program* pool,
                                    unsigned int pool_size,
                                    unsigned int new_pool_size) {
  Program* new_pool = new Program[new_pool_size];
  for(int i = 0; i < new_pool_size; i++) {
    int r1 = rand() % pool_size;
    int r2 = rand() % pool_size;
    double f1 = f->evaluate(pool[r1]);
    double f2 = f->evaluate(pool[r2]);
    if(f2 > f1) {
      int tmp = r1;
      r1 = r2;
      r2 = tmp;
    }
    if(rand_double() < p) {
      new_pool[i] = pool[r1];
    }
    else {
      new_pool[i] = pool[r2];
    }
  }
  return new_pool;
}
