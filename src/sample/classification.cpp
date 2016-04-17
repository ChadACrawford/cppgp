#include "classification.h"

#include <cstdlib>
#include "../gp.h"


Classification::Classification(int num_samples) :
  Fitness(GPTYPE_BOOL),
  num_samples(num_samples),
  num_params(6)
{
  x = new bool*[num_samples];
  gpx = new GPValue**[num_samples];
  y = new bool[num_samples];
  for(int i = 0; i < num_samples; i++) {
    x[i] = new bool[num_params];
    gpx[i] = new GPValue*[num_params];
    for(int j = 0; j < num_params; j++) {
      x[i][j] = rand() % 2;
      gpx[i][j] = new GPVBool(x[i][j]);
    }
    y[i] = f(x[i]);
  }
}

double Classification::calculate(Program* p) {
  double f = 0;
  for(int i = 0; i < num_samples; i++) {
    GPVBool* result = (GPVBool*)p->call(gpx[i]);
    f += result->value == y[i] ? 1 : 0;
  }
  return f;
}

double Classification::f(bool* params) {
  return params[0] || (params[1] && params[2] && !params[3]) || (!params[2] && params[4] && !params[5]) || !(params[0] || !params[2] && params[4]);
}

FunctionList* classification_get_functions() {
  FunctionList* functions = new FunctionList();

  functions->add_function(gpf_and);
  functions->add_function(gpf_or);
  functions->add_function(gpf_not);
  functions->add_function(new FunctionParam(0, GPTYPE_BOOL));
  functions->add_function(new FunctionParam(1, GPTYPE_BOOL));
  functions->add_function(new FunctionParam(2, GPTYPE_BOOL));
  functions->add_function(new FunctionParam(3, GPTYPE_BOOL));
  functions->add_function(new FunctionParam(4, GPTYPE_BOOL));
  functions->add_function(new FunctionParam(5, GPTYPE_BOOL));

  return functions;
}

int run_sample_classification(int argc, char* args[]) {
  int pool_size = 30;
  FunctionList* functions = classification_get_functions();
  int max_depth = 6;
  int num_params = 1;

  Classification* fitness = new Classification(800);
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
