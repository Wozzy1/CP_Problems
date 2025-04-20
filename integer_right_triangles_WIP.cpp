#include <iostream>
#include <cmath>

int isValidTriangle(int a, int b, int c) {
  return (a * a + b * b) == (c * c);
}

//https://martin-ueding.de/posts/project-euler-solution-39-integer-right-triangles/
int p(int perimeter) {
  // assuming a < b < c
  for (int a = 1; a < perimeter / 3; a++) { // a is at most 1/3 of the perimeter
    for (int b = a; b < perimeter - (2 * a + 1); b++) { // a < b; b < p-2a + 1

    }
  }
  return 1;
}

int main(void) {
  // n = 1 to inf, n is perimeter
  // p(n) returns num of partitions
  // IVT returns if 3 num tuple form valid triangle

  return 0;
}