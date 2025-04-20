#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdio.h>


typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int*) malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

// insert element at end of the array and handles extending array if needed
void insertArray(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int*) realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

// Performs a linear search to check if an element exists in the array.
// Returns 1 if the element is found, otherwise returns 0.
int arrayContains(Array *a, int element) {
  for (int i = 0; i < a->used; i++) {
    if (a->array[i] == element) {
      return 1;
    }
  }
  return 0;
}

void printArray(Array *a) {
  for (int i = 0; i < a->used; i++) {
    printf("%d ", a->array[i]);
  }
  printf("\n");
}

void addArrays(Array *des, Array *src) {
  for (int i = 0; i < src->used; i++) {
    insertArray(des, src->array[i]);
  }
}

#endif