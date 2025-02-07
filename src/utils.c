#include "../include/utils.h"

double random_double() {
  // [-1, 1]
  return ((double)rand() / RAND_MAX) * 2 - 1;
}
