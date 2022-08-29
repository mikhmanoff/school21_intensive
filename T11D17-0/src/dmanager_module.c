#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void print_doors(struct door *doors);
void sort_doors(struct door *doors);
void initialize_doors(struct door *doors);

int main() {
  struct door doors[DOORS_COUNT];

#ifdef DOOR_STRUCT
  initialize_doors(doors);
  sort_doors(doors);
  print_doors(doors);
#endif

  return 0;
}

void print_doors(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].status = 0;
    if (doors[i].id == DOORS_COUNT - 1) {
        printf("%d, %d", doors[i].id, doors[i].status);
    } else {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
  }
}

void sort_doors(struct door *doors) {
  struct door doors_tmp[DOORS_COUNT];
  for (int i = 0; i < DOORS_COUNT; i++) {
    for (int j = 0; j < DOORS_COUNT - 1; j++) {
      if (doors[j].id > doors[i].id) {
        doors_tmp[i] = doors[j];
        doors[j] = doors[i];
        doors[i] = doors_tmp[i];
      }
    }
  }
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}
