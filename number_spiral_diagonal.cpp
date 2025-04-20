#include <iostream>
#define N 1001
#define DEBUG 0
/**
NE: for 1 to n: n*n      50
NW: for 1 to n: n*n - n  44
SW: for 1 to n: n*n - 2n 38
SE: for 1 to n: n*n - 3n 31 


 */

int ne(void) {
    int sum = 0;
    for (int i = 3; i <= N; i+=2) {
        sum += i * i;
        if (DEBUG) std::cout << i*i << std::endl;
    }
    return sum;
}

int nw(void) {
    int sum = 0;
    for (int i = 3; i <= N; i+=2) {
        sum += i * i - i + 1;
        if (DEBUG) std::cout << i * i - i + 1 << std::endl;
    }
return sum;
}

int sw(void) {
    int sum = 0;
    for (int i = 3; i <= N; i+=2) {
        sum += i * i - 2 * i + 2;
        if (DEBUG) std::cout << i*i - 2 * i + 2 << std::endl;
    }
    return sum;
}

int se(void) {
    int sum = 0;
    for (int i = 3; i <= N; i+=2) {
      sum += i * i - 3 * i + 3;
      if (DEBUG) std::cout << i*i - 3 * i + 3 << std::endl;
    }
    return sum;
}


int main(void) {
    int res = ne() + nw() + sw() + se() + 1;

    std::cout << "result for " << N << " : " << res << std::endl; // result = 669171001
    return 0;
}