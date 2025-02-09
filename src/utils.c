#include "../include/utils.h"

// temporary
void init_random() {
  static int seeded = 0;
  if (!seeded) {
    srand(time(NULL));  
    seeded = 1;
  }
}

double random_double() {
  // [-1, 1]
  return ((double)rand() / RAND_MAX) * 2 - 1;
}
