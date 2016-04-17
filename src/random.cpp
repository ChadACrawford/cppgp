#include "random.h"

#include <cstdlib>
using namespace std;

double rand_double() {
  return ((double) rand() / (RAND_MAX));
}
