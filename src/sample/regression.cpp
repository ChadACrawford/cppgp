#include "regression.h"

#include "../random.h"
#include "../gp.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


Regression::Regression(int num_params, int num_samples) :
  Fitness(GPTYPE_REAL),
  num_params(1),
  num_samples(num_samples)
{
  x = new double*[num_samples];
  gpx = new GPValue**[num_samples];
  y = new double[num_samples];
  for(int t = 0; t < num_samples; t++) {
    x[t] = new double[num_params];
    gpx[t] = new GPValue*[num_params];
    for(int p = 0; p < num_params; p++) {
      x[t][p] = rand_double();
      gpx[t][p] = new GPVReal(x[t][p]);
    }
    y[t] = f(x[t]);
  }
}

double Regression::calculate(Program* p) {
  double mse = 0;
  for(int t = 0; t < num_samples; t++) {
    GPValue* r = p->call(gpx[t]);
    double rd = ((GPVReal*)r)->value;
    mse += pow(rd - y[t], 2);
    delete r;
  }
  mse /= -num_samples;
  return mse;
}

double Regression::f(double* params) {
  return 2 * pow(params[0], 2) + 4 * params[0] + 3;
}

FunctionList* get_functions() {
  FunctionList* functions = new FunctionList();

  functions->add_function(gpf_add);
  functions->add_function(gpf_sub);
  functions->add_function(gpf_mul);
  functions->add_function(gpf_div);
  functions->add_function(gpf_mod);
  functions->add_function(new FunctionParam(0, GPTYPE_REAL));
  functions->add_function(new FunctionValue(new GPVReal(-1.)));
  // functions->add_function(new FunctionValue(new GPVReal(0.)));
  functions->add_function(new FunctionValue(new GPVReal(1.)));
  functions->add_function(new FunctionValue(new GPVReal(2.)));
  functions->add_function(new FunctionValue(new GPVReal(3.)));
  functions->add_function(new FunctionValue(new GPVReal(4.)));

  return functions;
}

int run_sample_regression(int argc, char* args[]) {
  int pool_size = 30;
  FunctionList* functions = get_functions();
  int max_depth = 5;
  int num_params = 1;
  Regression* fitness = new Regression(1, 400);
  GPGenerateRandom* generate = new GPGenerateRandom(functions, num_params, max_depth);
  GPSelectTournament* select = new GPSelectTournament(fitness, 0.7);
  GPCrossTree* cross = new GPCrossTree(fitness, max_depth, 0.9);
  GPMutateReplace* mutate = new GPMutateReplace(fitness, functions, max_depth, 0.05);
  GP* gp = new GP(pool_size, fitness, generate, select, cross, mutate);

  gp->init();
  for(int generation = 1; generation <= 1000; generation++) {
    gp->generation();
    Program* best_program = gp->best_program();
    cout << "Generation: " << generation << "\n";
    cout << "  Best fitness: " << fitness->evaluate(best_program) << "\n";
    best_program->print();
  }
}
