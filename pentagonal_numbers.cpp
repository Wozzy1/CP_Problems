#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define N 100

// void computePentagonal(std::vector<int>& v) {
//   v.resize(N + 1, 1);
//   // for (int i = 1; i <= N; i++) {
//   //   v[i] = (i * (3 * i - 1)) / 2;
//   //   // std::cout << v[i] << std::endl;
//   // }  
// }

int isPent(int x) {
  double n = (1 + std::sqrt(1 + 24.0 * x)) / 6.0;
  return n == static_cast<int>(n);
}

int old(void) {
  std::vector<int> v;
  // computePentagonal(v);
  int minFound = ((unsigned int)(~0)) >> 1; // max int value without library
                                            // all 0s, flipped to 1 then 
                                            // bit shift right 1 to remove neg
  int i_ = -1, j_ = -1;
  // std::cout << minFound << std::endl;
  // printf("here\n");
  for (int i = 1; i <= N; i++) {
    for (int j = 2; j <= N; j++) {
      if (i == j) continue;
      int diff = abs(v[j] - v[i]);
      int sum = v[i] + v[j];
      // if (std::find(v.begin(), v.end(), diff) != v.end() // if v contains diff
      //     && std::find(v.begin(), v.end(), sum) != v.end()) { 
      if (isPent(sum) && isPent(diff)) {
        // printf("Found sum: %d\n", sum);
        if (diff < minFound) {
          printf("Found new min: %d\n", diff);
          printf("The sum: %d\n", sum);
          minFound = diff;
          i_ = i;
          j_ = j;
        }
      }
    }
  }
  printf("Found v[%d]=%d, v[%d]=%d resulting in %d\n", i_, v[i_], j_, v[j_], minFound);

  return 0;
}

// solution from https://raw.org/puzzle/project-euler/problem-44/
// was a really tough problem :(
int main(void) {
  std::vector<int> v = {1, 5, 12};
  
  for (int n = 10, Pn = 22; ; n += 3, Pn += n) {
    // Pn is nth pentagonal num
    v.push_back(Pn);

    for (int i = 0; i < v.size(); i++) {
      int diff = Pn - v[i];
      int sum = Pn + v[i];

      if (isPent(diff) && isPent(sum)) {
        printf("first/min diff found: %d\n", abs(diff));  // 5482660
        return 0;
      }
    }
  }
}