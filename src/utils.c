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

int (*read_xor(const char *filename))[COLS] {  
  static int array[ROWS][COLS];

  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("couldnt open file");
    return NULL;
  }

  for (int i = 0; i < ROWS; i++) {
    if (fscanf(file, "%d,%d,%d", &array[i][0], &array[i][1], &array[i][2]) != 3) {
      fprintf(stderr, "error reading line %d\n", i + 1);
      fclose(file);
      return NULL;
    }
  }

  return array;
}
