#include "select.h"
#include "random.h"

#include <iostream>
#include <cstdlib>
using namespace std;

// GPSelect

GPSelect::GPSelect(Fitness* f) : f(f) {}

Program** GPSelect::run(Program** pool, unsigned int pool_size, unsigned int new_pool_size) {}

// GPSelectTournament

GPSelectTournament::GPSelectTournament(Fitness* f, double p) :
  GPSelect(f),
  p(p)
{}

Program** GPSelectTournament::run(Program** pool,
                                  unsigned int pool_size,
                                  unsigned int new_pool_size) {
  Program** new_pool = new Program*[new_pool_size];
  for(int i = 0; i < new_pool_size; i++) {
    int r1 = rand() % pool_size;
    int r2 = rand() % pool_size;
    // cout << "Tree 1:\n";
    // pool[r1]->print();
    // cout << "Tree 2:\n";
    // pool[r2]->print();
    double f1 = f->evaluate(pool[r1]);
    double f2 = f->evaluate(pool[r2]);
    // cout << f1 << " " << f2 << "\n";
    if(f2 > f1) {
      int tmp = r1;
      r1 = r2;
      r2 = tmp;
    }
    if(rand_double() < p) {
      new_pool[i] = pool[r1]->copy();
    }
    else {
      new_pool[i] = pool[r2]->copy();
    }
  }
  for(int i = 0; i < pool_size; i++)
    delete pool[i];
  delete[] pool;
  return new_pool;
}
